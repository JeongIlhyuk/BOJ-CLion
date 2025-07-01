# -*- coding: utf-8 -*-
import http.server
import json
import logging
import os
import re
import socketserver
import sys

import requests
from bs4 import BeautifulSoup

# 配置日志记录
LOG_FILE = "cp_setup.log"  # 日志文件名
logging.basicConfig(filename=LOG_FILE, level=logging.INFO,
                    format='%(asctime)s - %(levelname)s - %(message)s', encoding='utf-8')

PORT = 10043  # Competitive Companion 默认使用的端口

class CompetitiveCompanionHandler(http.server.SimpleHTTPRequestHandler):
    def do_POST(self):
        content_length = int(self.headers['Content-Length'])
        post_data = self.rfile.read(content_length)
        self.send_response(200)
        self.end_headers()

        data = json.loads(post_data.decode('utf-8'))
        process_data(data)


def scrape_problem_content(url):
    """백준 문제 URL에서 문제 내용을 스크래핑"""
    try:
        headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36'
        }
        response = requests.get(url, headers=headers)
        response.raise_for_status()

        soup = BeautifulSoup(response.content, 'html.parser')
        sections = {}

        # 문제 설명
        problem_desc = soup.find('div', {'id': 'problem_description'})
        if problem_desc:
            sections['description'] = problem_desc.get_text(strip=True)

        # 입력 설명
        input_desc = soup.find('div', {'id': 'problem_input'})
        if input_desc:
            sections['input'] = input_desc.get_text(strip=True)

        # 출력 설명
        output_desc = soup.find('div', {'id': 'problem_output'})
        if output_desc:
            sections['output'] = output_desc.get_text(strip=True)

        return sections

    except Exception as e:
        logging.error(f"Failed to scrape problem content: {str(e)}")
        return None


def format_comment_text(text):
    """텍스트를 주석 형태로 포맷팅하는 함수"""
    if not text:
        return " * N/A"
    lines = text.split('\n')
    formatted_lines = [f" * {line}" if line.strip() else " *" for line in lines]
    return '\n'.join(formatted_lines)

def process_data(data):
    try:
        print("process_data called!")
        # 处理题目信息
        problem_name = data.get('name', 'Unknown Problem')
        problem_url = data.get('url', 'No URL provided')
        time_limit = data.get('timeLimit', 'Unknown')
        memory_limit = data.get('memoryLimit', 'Unknown')

        # 문제 내용 스크래핑
        problem_content = scrape_problem_content(problem_url)

        # 创建项目目录，处理中文字符
        project_dir = problem_name.replace(' ', '_')
        # Windows에서 금지된 문자들을 제거/대체
        project_dir = re.sub(r'[<>:"/\\|?*]', '', project_dir)
        if not os.path.exists(project_dir):
            os.makedirs(project_dir)

        # 日志记录创建的项目目录
        logging.info(f"Project directory '{project_dir}' created for problem '{problem_name}'")

        # 处理内存限制的单位
        if isinstance(memory_limit, str):
            if 'GB' in memory_limit.upper():
                memory_limit = int(float(memory_limit.split()[0]) * 1024)  # 转换 GB 为 MB
            elif 'MB' in memory_limit.upper():
                memory_limit = int(float(memory_limit.split()[0]))
            else:
                memory_limit = int(float(memory_limit))  # 假设单位为 MB 或直接是数值
        elif isinstance(memory_limit, (int, float)):
            memory_limit = int(memory_limit)  # 处理没有单位的情况，假设为 MB
        else:
            memory_limit = 'Unknown'

        # 코드 템플릿 생성
        desc_formatted = format_comment_text(
            problem_content['description'] if problem_content and 'description' in problem_content else None)
        input_formatted = format_comment_text(
            problem_content['input'] if problem_content and 'input' in problem_content else None)
        output_formatted = format_comment_text(
            problem_content['output'] if problem_content and 'output' in problem_content else None)

        code_template = f"""// Problem: {problem_name}
// URL: {problem_url}
// Time Limit: {time_limit} ms
// Memory Limit: {memory_limit} MB

/*
 * 문제:
{desc_formatted}
 * 
 * 입력:
{input_formatted}
 * 
 * 출력:
{output_formatted}
 */

"""

        # 如果存在 template.cpp 文件，则读取其内容并附加到 code_template 之后
        template_file_path = 'template.cpp'
        if os.path.exists(template_file_path):
            with open(template_file_path, 'r', encoding='utf-8') as template_file:
                template_code = template_file.read()
            code_template += template_code
            logging.info(f"Appended content from template.cpp to {project_dir}/main.cpp")
        else:
            logging.warning(f"template.cpp not found in current directory. Skipping template appending.")

        # 写入 main.cpp 文件，使用 UTF-8 编码
        main_cpp_path = os.path.join(project_dir, 'main.cpp')
        with open(main_cpp_path, 'w', encoding='utf-8') as f:
            f.write(code_template)
        logging.info(f"Code template for '{problem_name}' written to {main_cpp_path}")

        # 处理测试用例
        if 'tests' in data:
            for i, test in enumerate(data['tests'], 1):
                input_file = os.path.join(project_dir, f'input{i}.txt')
                output_file = os.path.join(project_dir, f'output{i}.txt')
                with open(input_file, 'w', encoding='utf-8') as f:
                    f.write(test.get('input', ''))
                with open(output_file, 'w', encoding='utf-8') as f:
                    f.write(test.get('output', ''))
                logging.info(f"Sample test case {i} written to {input_file} and {output_file}")

        # 将内存和时间限制保存到 limits.txt
        limits_file = os.path.join(project_dir, 'limits.txt')
        with open(limits_file, 'w', encoding='utf-8') as f:
            f.write(f"TimeLimit: {time_limit} ms\n")
            f.write(f"MemoryLimit: {memory_limit} MB\n")
        logging.info(f"Limits for '{problem_name}' written to {limits_file}")

        # 保存最近的题目名称到文件
        with open('latest_problem.txt', 'w', encoding='utf-8') as f:
            f.write(project_dir)
        logging.info(f"Latest problem directory '{project_dir}' saved to latest_problem.txt")

    except Exception as e:
        logging.error(f"An error occurred: {str(e)}", exc_info=True)
        print(f"An error occurred: {str(e)}", file=sys.stderr)

def main():
    with socketserver.TCPServer(("", PORT), CompetitiveCompanionHandler) as httpd:
        logging.info(f"Serving at port {PORT}")
        print(f"Serving at port {PORT}")
        httpd.serve_forever()

if __name__ == "__main__":
    main()
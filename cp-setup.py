import html
import http.server
import json
import os
import re
import socketserver
import sys

import requests
from bs4 import BeautifulSoup

PORT = 10043

class CompetitiveCompanionHandler(http.server.SimpleHTTPRequestHandler):
    def do_POST(self):
        content_length = int(self.headers['Content-Length'])
        post_data = self.rfile.read(content_length)
        self.send_response(200)
        self.end_headers()

        data = json.loads(post_data.decode('utf-8'))
        process_data(data)

def get_algorithm_tags_from_solved_ac(problem_id):
    try:
        api_url = f"https://solved.ac/api/v3/problem/show?problemId={problem_id}"
        response = requests.get(api_url)
        response.raise_for_status()

        data = response.json()

        # 알고리즘 태그 추출
        if 'tags' in data:
            tags = []
            for tag in data['tags']:
                # 한국어 이름이 있으면 한국어로, 없으면 영어로
                if 'displayNames' in tag:
                    korean_name = None
                    for display_name in tag['displayNames']:
                        if display_name['language'] == 'ko':
                            korean_name = display_name['name']
                            break

                    if korean_name:
                        tags.append(korean_name)
                    else:
                        # 영어 이름 fallback
                        for display_name in tag['displayNames']:
                            if display_name['language'] == 'en':
                                tags.append(display_name['name'])
                                break

            return ', '.join(tags)

        return None

    except Exception as e:
        print(f"Failed to get tags from solved.ac: {str(e)}")
        return None

def scrape_problem_content(url):
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
            text = html.unescape(problem_desc.get_text(strip=True))
            text = re.sub(r'\s+', ' ', text)
            sections['description'] = text

        # 입력 설명
        input_desc = soup.find('div', {'id': 'problem_input'})
        if input_desc:
            text = html.unescape(input_desc.get_text(strip=True))
            text = re.sub(r'\s+', ' ', text)
            sections['input'] = text

        # 출력 설명
        output_desc = soup.find('div', {'id': 'problem_output'})
        if output_desc:
            text = html.unescape(output_desc.get_text(strip=True))
            text = re.sub(r'\s+', ' ', text)
            sections['output'] = text

        return sections

    except Exception as e:
        print(f"Failed to scrape problem content: {str(e)}")
        return None

def process_data(data):
    try:
        print("process_data called!")
        # 문제 정보
        problem_name = data.get('name', 'Unknown Problem')
        problem_url = data.get('url', 'No URL provided')
        time_limit = data.get('timeLimit', 'Unknown')
        memory_limit = data.get('memoryLimit', 'Unknown')  # 단순화

        # 문제 내용 스크래핑
        problem_content = scrape_problem_content(problem_url)

        # solved.ac에서 알고리즘 분류 가져오기
        if 'acmicpc.net/problem/' in problem_url:
            problem_id = problem_url.split('/')[-1]
            solved_ac_tags = get_algorithm_tags_from_solved_ac(problem_id)
            if solved_ac_tags:
                if problem_content:
                    problem_content['tags'] = solved_ac_tags
                else:
                    problem_content = {'tags': solved_ac_tags}

        # 프로젝트 디렉토리 생성
        if 'acmicpc.net/problem/' in problem_url:
            problem_id = problem_url.split('/')[-1]
            project_dir = f"BOJ_{problem_id}"
        else:
            project_dir = problem_name.replace(' ', '_')

        project_dir = re.sub(r'[<>:"/\\|?*]', '', project_dir)
        if not os.path.exists(project_dir):
            os.makedirs(project_dir)

        code_template = f"""// Problem: {problem_name}
// URL: {problem_url}
// Time Limit: {time_limit}
// Memory Limit: {memory_limit}

/*
문제:
{problem_content['description'] if problem_content and 'description' in problem_content else 'N/A'}

입력:
{problem_content['input'] if problem_content and 'input' in problem_content else 'N/A'}

출력:
{problem_content['output'] if problem_content and 'output' in problem_content else 'N/A'}

알고리즘 분류:
{problem_content['tags'] if problem_content and 'tags' in problem_content else 'N/A'}
*/

"""

        # template.cpp 파일이 있으면 추가
        template_file_path = 'template.cpp'
        if os.path.exists(template_file_path):
            with open(template_file_path, 'r', encoding='utf-8') as template_file:
                template_code = template_file.read()
            code_template += template_code

        # main.cpp 파일 생성
        main_cpp_path = os.path.join(project_dir, 'main.cpp')
        with open(main_cpp_path, 'w', encoding='utf-8') as f:
            f.write(code_template)

        # 테스트 케이스 생성
        if 'tests' in data:
            for i, test in enumerate(data['tests'], 1):
                input_file = os.path.join(project_dir, f'input{i}.txt')
                output_file = os.path.join(project_dir, f'output{i}.txt')
                with open(input_file, 'w', encoding='utf-8') as f:
                    f.write(test.get('input', ''))
                with open(output_file, 'w', encoding='utf-8') as f:
                    f.write(test.get('output', ''))

        # 최근 문제 저장
        with open('latest_problem.txt', 'w', encoding='utf-8') as f:
            f.write(project_dir)

    except Exception as e:
        print(f"An error occurred: {str(e)}", file=sys.stderr)

def main():
    with socketserver.TCPServer(("", PORT), CompetitiveCompanionHandler) as httpd:
        print(f"Serving at port {PORT}")
        httpd.serve_forever()

if __name__ == "__main__":
    main()
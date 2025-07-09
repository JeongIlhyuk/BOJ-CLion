import os
import subprocess
import sys

def run_tests(project_dir):
    # 컴파일
    print("Compiling...")
    compile_cmd = f"g++ {os.path.join(project_dir, 'main.cpp')} -o {os.path.join(project_dir, 'solution')}"
    try:
        subprocess.run(compile_cmd, shell=True, check=True)
        print("Compilation successful.")
    except subprocess.CalledProcessError:
        print("Compilation failed.")
        return

    # 테스트 파일 찾기
    test_files = [f for f in os.listdir(project_dir) if f.startswith('input') and f.endswith('.txt')]
    test_files.sort()

    for input_file in test_files:
        test_num = input_file[5:-4]
        output_file = f"output{test_num}.txt"

        print(f"\nRunning Test {test_num}:")

        # 입력 읽기
        with open(os.path.join(project_dir, input_file), 'r', encoding='utf-8') as f:
            input_data = f.read()

        # 실행
        try:
            result = subprocess.run([os.path.join(project_dir, 'solution')],
                                    input=input_data, text=True,
                                    capture_output=True, timeout=3)

            if result.returncode != 0:
                print("Runtime Error")
                if result.stderr:
                    print(f"Error: {result.stderr.strip()}")
            else:
                # 출력을 한 줄씩 처리해서 보기 좋게 출력
                output_lines = result.stdout.strip().split('\n')
                if len(output_lines) == 1:
                    print(f"Output: {output_lines[0]}")
                else:
                    print("Output:")
                    for line in output_lines:
                        print(f"  {line}")

                # 정답과 비교 (output 파일이 있으면)
                output_path = os.path.join(project_dir, output_file)
                if os.path.exists(output_path):
                    with open(output_path, 'r', encoding='utf-8') as f:
                        expected = f.read().strip()
                    if result.stdout.strip() == expected:
                        print("✓ Correct")
                    else:
                        print("✗ Wrong Answer")
                        expected_lines = expected.split('\n')
                        if len(expected_lines) == 1:
                            print(f"Expected: {expected_lines[0]}")
                        else:
                            print("Expected:")
                            for line in expected_lines:
                                print(f"  {line}")

        except subprocess.TimeoutExpired:
            print("Time Limit Exceeded")

def get_latest_problem():
    if os.path.exists("latest_problem.txt"):
        with open("latest_problem.txt", 'r', encoding='utf-8') as f:
            return f.read().strip()
    return "."

if __name__ == "__main__":
    project_dir = sys.argv[1] if len(sys.argv) > 1 else get_latest_problem()
    run_tests(project_dir)
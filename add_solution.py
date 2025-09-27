import argparse
import os
import urllib.parse

def create_solution_file(online_judge_platform, problem_display_name, lang, source_content):
    """Creates the solution file with the correct name and content."""
    ext = ''
    if online_judge_platform == 'LeetCode':
        ext = 'md'
    else:
        ext = lang

    filename = f"{problem_display_name}.{ext}"
    filepath = os.path.join(online_judge_platform, filename)

    # Create directory if it doesn't exist
    os.makedirs(online_judge_platform, exist_ok=True)

    if online_judge_platform == 'LeetCode':
        content = f"# {problem_display_name}\n\n"
        content += "## 程式碼\n\n"
        content += f"```{lang}\n"
        content += source_content
        content += "\n```\n"
    else:  # For UVa and others
        content = source_content

    with open(filepath, 'w', encoding='utf-8') as f:
        f.write(content)

    print(f"[INFO] Successfully created file: {filepath}")
    return filename

def update_readme(online_judge_platform, category, filename):
    """Updates the corresponding README.md file."""
    readme_path = os.path.join(online_judge_platform, 'README.md')
    
    if not os.path.exists(readme_path):
        with open(readme_path, 'w', encoding='utf-8') as f:
            f.write(f"# {online_judge_platform}\n\n## 題目\n")
        print(f"Created new README.md: {readme_path}")

    url_encoded_filename = urllib.parse.quote(filename)
    display_text = os.path.splitext(filename)[0]
    new_line = f"- [{display_text}](./{url_encoded_filename})\n"
    category_header = f"### {category}"

    with open(readme_path, 'r+', encoding='utf-8') as f:
        lines = f.readlines()
        try:
            header_indices = [i for i, line in enumerate(lines) if line.strip() == category_header]
            if not header_indices:
                raise ValueError("Category header not found")
            
            header_index = header_indices[0]
            
            insert_index = header_index + 1
            while insert_index < len(lines) and not lines[insert_index].strip().startswith('###'):
                insert_index += 1
            
            final_insert_index = insert_index
            while final_insert_index > header_index + 1 and not lines[final_insert_index - 1].strip():
                 final_insert_index -= 1

            lines.insert(final_insert_index, new_line)

        except ValueError:
            if lines and lines[-1].strip() != '':
                lines.append('\n')
            lines.append(f"{category_header}\n\n")
            lines.append(new_line)

        f.seek(0)
        f.writelines(lines)
        f.truncate()

    print(f"[INFO] Successfully updated README.md: {readme_path}")

def get_parser():
    """Gets the argument parser."""
    parser = argparse.ArgumentParser(description="Automates adding Online Judge solutions and updating READMEs.")
    parser.add_argument('file',
                        help='Path to the source code file. The filename (without extension) will be used as the solution title.')
    parser.add_argument('-p', '--platform', required=True, choices=['LeetCode', 'UVa'],
                        help='Platform name (LeetCode or UVa)')
    parser.add_argument('-c', '--category', required=True,
                        help='Category name (e.g., Easy, 2025/05/20 CPE)')
    return parser

def main(args):
    try:
        with open(args.file, 'r', encoding='utf-8') as f:
            source_content = f.read()
    except FileNotFoundError:
        print(f"Error: Source file not found: {args.file}")
        return
    except Exception as e:
        print(f"Error reading source file: {e}")
        return

    base_filename = os.path.basename(args.file)
    problem_display_name = os.path.splitext(base_filename)[0]
    lang_ext = os.path.splitext(base_filename)[1][1:]
    new_filename = create_solution_file(args.platform, problem_display_name, lang_ext, source_content)
    update_readme(args.platform, args.category, new_filename)
    print("Automation script finished!")

if __name__ == '__main__':
    parser = get_parser()
    args = parser.parse_args()
    main(args)

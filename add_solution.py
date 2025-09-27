import argparse
import os
import urllib.parse
from pathlib import Path

def create_solution_file(online_judge_platform, problem_display_name, lang, source_content):
    """Creates the solution file with the correct name and content."""
    project_root = Path(__file__).resolve().parent
    
    target_dir = project_root / online_judge_platform
    target_dir.mkdir(parents=True, exist_ok=True) # Create directory if it doesn't exist
    file_path = target_dir / f"{problem_display_name}.md"

    content = (
        f"# {problem_display_name}\n\n"
        f"## 程式碼\n\n"
        f"```{lang}\n"
        f"{source_content}\n"
        f"```\n"
    )
    file_path.write_text(content, encoding='utf-8')
    print(f"[INFO] Successfully created file: {file_path}")
    return file_path.name

def update_readme(online_judge_platform, category, file_name):
    """Updates the corresponding README.md file."""
    project_root = Path(__file__).resolve().parent
    
    target_dir = project_root / online_judge_platform
    target_dir.mkdir(parents=True, exist_ok=True)
    readme_path = target_dir / 'README.md'
    
    display_text = Path(file_name).stem
    url_encoded_file_name = urllib.parse.quote(file_name)
    category_header = f"### {category}"
    new_line = f"- [{display_text}](./{url_encoded_file_name})\n"
    
    if not readme_path.exists():
        initial_content = (
            f"# {online_judge_platform}\n\n"
            f"## 題目\n\n"
            f"{category_header}\n\n"
            f"{new_line}"
        )
        readme_path.write_text(initial_content, encoding='utf-8')
        print(f"[INFO] Successfully created new README.md: {readme_path}")
        return
    
    # If README.md exists, read its content and update it in place
    lines = readme_path.read_text(encoding='utf-8').splitlines(keepends=True)
    
    # Try to find the category header (### Category) line
    try:
        header_indices = [i for i, line in enumerate(lines) if line.strip() == category_header]
        if not header_indices:
            raise ValueError("Category header not found")
        
        # Start searching from the line after the header, find the next "### <header>" or end of file
        header_index = header_indices[0]
        insert_index = header_index + 1
        while insert_index < len(lines) and not lines[insert_index].strip().startswith('###'):
            insert_index += 1
        
        final_insert_index = insert_index
        while final_insert_index > header_index + 1 and not lines[final_insert_index - 1].strip():
            final_insert_index -= 1
        
        lines.insert(final_insert_index, new_line)
    
    except ValueError:  # If the category header is not found, append it at the end
        if lines and lines[-1].strip() != '':
            lines.append('\n')
        lines.append(f"{category_header}\n\n")
        lines.append(new_line)

    readme_path.write_text("".join(lines), encoding='utf-8')
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
        source_path = Path(args.file)
        source_content = source_path.read_text(encoding='utf-8')
    except FileNotFoundError:
        print(f"Error: Source file not found: {args.file}")
        return
    except Exception as e:
        print(f"Error reading source file: {e}")
        return

    problem_display_name = source_path.stem
    lang_ext = source_path.suffix[1:]  # Remove the dot
    new_file_name = create_solution_file(args.platform, problem_display_name, lang_ext, source_content)
    update_readme(args.platform, args.category, new_file_name)
    print("Automation script finished!")

if __name__ == '__main__':
    parser = get_parser()
    args = parser.parse_args()
    main(args)

from os import path, mkdir, chdir, system
from sys import argv, exit
from json import load
from glob import glob
from subprocess import check_output, CalledProcessError

def create_file(file_name: str, content: str = ""):
    with open(file_name, "w") as f:
        f.write(content)

def create_project(directory, project_data, include_bonus=False):
    if not path.exists(directory):
        mkdir(directory)
    chdir(directory)

    c_files = project_data["base"] + project_data["additional"]
    if include_bonus:
        c_files += project_data["bonus"]

    for func in c_files:
        create_file(f"{func}.c")

    for header, content in project_data["h_files"].items():
        create_file(f"{header}.h", content)

    create_file("Makefile", project_data['Makefile'])

if __name__ == "__main__":
    if len(argv) < 2:
        print("Usage: py helper.py [-d <directory>] [--bonus] [--test] [--skip-norm]")
        exit(1)

    include_bonus = "--bonus" in argv
    test = "--test" in argv

    # -d flag to select the directory
    if "-d" in argv: directory = argv[argv.index("-d") + 1]
    else: directory = "ftlib-dev"

    # --skip-norm flag to skip the norm check
    skip_norm = "--skip-norm" in argv


    with open("project.json", "r") as f:
        project_data = load(f)
    
    if not test:
        create_project(directory, project_data, include_bonus)
        print(f"Project 'libft' created successfully in {directory} directory{'' if not include_bonus else ' with all the bonus files'}!")
        exit(0)

    if not skip_norm:
        # Check if all the files are normed
        required_files = project_data["base"] + project_data["additional"]
        if include_bonus: 
            required_files += project_data["bonus"]
        
        files = glob(f"./{directory}/*.c")

        # Get the list of the missing files
        missing_files = [file for file in required_files if f"{file}.c" not in [file.split("/")[-1] for file in files]]
        if missing_files:
            print("Missing files:")
            for file in missing_files:
                print(f"    {file}.c")
            exit(1)
        print("All required files found!")

        for file in files:
            if not file:
                continue
            try:
                norm = check_output(f"/Users/glizzykingdreko/Documents/GitHubCloned/42School-CommandCore-Projects/venv/bin/python -m norminette {file}", shell=True).decode()
            except CalledProcessError as e:
                print(f"Norm error in {file}\nDetails: {e.output.decode()}")
                exit(1)
            if "Error" in norm:
                print(f"Norm error in {file}\nDetails: {norm}")
                exit(1)
            else:
                print(f"Normed {file}!")
        
        print("All files normed successfully!")

    # Compile the tester and run it from the tester directory
    chdir("tester")
    print("Compiling tester...")
    system(f"make {'bonus' if include_bonus else ''} LIBFT_DIR='../{directory}'")
    system("./test_libft")
    print("Tester compiled successfully!")

    print("Cleaning up...")
    # Make clean
    system("make fclean")
    # Make clean as well the directory created
    chdir("..")
    chdir(directory)
    system("make fclean")
    
    print("Done!")

    exit(0)

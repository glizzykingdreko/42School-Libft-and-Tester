from os import path, mkdir, chdir, system
from sys import argv, exit
from json import load
from glob import glob
from subprocess import check_output, CalledProcessError

def create_file(file_name: str, content: str = "") -> None:
    """
    Create a file with the given name and content

    Args:
        file_name (str): The name of the file to create
        content (str, optional): The content of the file. Defaults to "".
    """
    with open(file_name, "w") as f:
        f.write(content)

def create_project(directory: str, project_data: dict, include_bonus: bool = False) -> None:
    """
    Create the project in the given directory with the given data

    Args:
        directory (str): The directory to create the project in
        project_data (dict): The data of the project
        include_bonus (bool, optional): Whether to include the bonus files or not. Defaults to False.
    """
    
    # Create the directory if it doesn't exist
    if not path.exists(directory):
        mkdir(directory)
    
    # Change the directory to the project directory
    chdir(directory)

    # Load the necessary .c files
    c_files = project_data["base"] + project_data["additional"]
    if include_bonus:
        c_files += project_data["bonus"]

    # Create the .c files
    for func in c_files:
        create_file(f"{func}.c")

    # Create the .h files (if any)
    for header, content in project_data["h_files"].items():
        create_file(f"{header}.h", content)

    # Create the Makefile
    create_file("Makefile", project_data['Makefile'])

if __name__ == "__main__":
    if len(argv) < 2:
        print("Usage: py helper.py <action> [-d <directory>] [--bonus] [--no-test] [--no-norm]")
        exit(1)
    
    # --help flag
    if "--help" in argv or "-h" in argv:
        # No valid action
        if argv[1] not in ["setup", "check"]:
            print("Usage: py helper.py <action> [-d <directory>] [--bonus] [--no-test] [--no-norm]")
            print("    <action>: 'setup' to create the project or 'check' to check the project")
            print("    -d <directory>: The directory to create the project in or to check the project from")
            print("    --bonus: Include the bonus files")
            print("    --no-test: Skip the test")
            print("    --no-norm: Skip the norm check")
        # Setup action
        elif argv[1] == "setup":
            print("Usage: py helper.py setup [-h] [-d <directory>] [--bonus]")
            print("    -h: Show this help message and exit")
            print("    -d <directory>: The directory to create the project in")
            print("    --bonus: Include the bonus files")
        # Check action
        elif argv[1] == "check":
            print("Usage: py helper.py check [-h] [-d <directory>] [--bonus] [--no-test] [--no-norm]")
            print("    -h: Show this help message and exit")
            print("    -d <directory>: The directory to check the project from")
            print("    --bonus: Include the bonus files")
            print("    --no-test: Skip the test")
            print("    --no-norm: Skip the norm check")
        exit(0)

    # Check if the action is valid
    action = 'setup' if argv[1].lower() == 'setup' else 'check'

    # --bonus flag to include the bonus files
    include_bonus = "--bonus" in argv

    # -d flag to select the directory
    if "-d" in argv: directory = argv[argv.index("-d") + 1]
    elif "--directory" in argv: directory = argv[argv.index("--directory") + 1]
    else: directory = "ftlib-dev" # Default directory

    # --no-norm flag to skip the norm check
    skip_norm = "--no-norm" in argv

    # --no-test flag to skip the test
    skip_test = "--no-test" in argv

    # Load the project data
    with open("project.json", "r") as f:
        project_data = load(f)
    
    # Create the project if the action is setup
    if action == "setup":
        create_project(directory, project_data, include_bonus)
        print(f"Project 'libft' created successfully in {directory} directory{'' if not include_bonus else ' with all the bonus files'}!")
        exit(0)

    # Else, check if the project is valid
    if not skip_norm:
        # Load the required files
        required_files = project_data["base"] + project_data["additional"]
        if include_bonus: 
            required_files += project_data["bonus"]
        
        # Get the list of the files in the directory
        files = glob(f"./{directory}/*.c")

        # Get the list of the missing files
        missing_files = [file for file in required_files if f"{file}.c" not in [file.split("/")[-1] for file in files]]
        if missing_files:
            print("Missing files:")
            for file in missing_files:
                print(f"    {file}.c")
            exit(1)
        print("All required files found!")

        # Norm the files
        files_arguments = " ".join([file for file in files])
        for file in files:
            if not file: continue
        
        try:
            norm = check_output(f"norminette {files_arguments}", shell=True).decode()
        except CalledProcessError as e:
            print(f"Norm error in {file}\nDetails: {e.output.decode()}")
            exit(1)
        if "Error" in norm:
            print(f"Norm error in {file}\nDetails: {norm}")
            exit(1)
        print(norm)
        print("All files normed successfully!")

    if skip_test:
        exit(0)
    
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

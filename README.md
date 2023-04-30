# 42School Libft + Tester
This project let you start with [the first project of 42School cursus](en.subject.pdf).
The aim of this project is to code a C library regrouping usual functions that you’ll be allowed to use in all your other projects.

You'll be quickly able to setup your project by [creating all the needed .c files](#project-setup) and [testing your functions](#project-check) with the tester folder after checking the norm.

Let's get a closer look at everyhting.

![Library FT](https://i.imgur.com/0EAOhSw.png)

## Table of contents
- [42School Libft + Tester](#42school-libft--tester)
  - [Table of contents](#table-of-contents)
  - [The libft folder](#the-libft-folder)
  - [The tester](#the-tester)
  - [helper.py](#helperpy)
    - [How to use it?](#how-to-use-it)
      - [Project setup](#project-setup)
      - [Project check](#project-check)
  - [Some screenshots](#some-screenshots)
  - [Conclusion](#conclusion)

## The libft folder
This folder contains my full libft project with all the functions and bonuses. I suggest you to use it as a reference to compare your code with mine but don't copy it or you'll get a 0.

## The tester
This folder contains a tester for the libft project. It will help you to check the norm and test your functions. You can find more information about it in the [tester README](tester/README.md).

## helper.py
This script will help you with different tasks:
- Create all the needed .c files for the project and setup the environment.
- Test your functions with the tester folder after checking the norm.

### How to use it?
After cloning the repo, you'll need to run the script with the following command

#### Project setup
```sh
python3 helper.py setup
```
This command will create all the needed .c files for the project and setup the environment. Inside the `libft-dev` folder.

If you want to create the files in a different folder, you can use the `-d` option to specify the path. For example, if you want to create the files in the `~/Desktop` folder, you can run the following command:
```sh
python3 helper.py setup -dp ~/Desktop
```

If you want to create the files for the bonus part as well, you can use the `--bonus` argument. For example let's setup the project with the bonus part included:
```sh
python3 helper.py setup --bonus
```

Here's the full list of arguments you can use:
```sh
usage: helper.py setup [-h] [-d DIRECTORY] [--bonus]

optional arguments:
    -h, --help            show this help message and exit
    -d DIRECTORY, --directory DIRECTORY
                            The directory where the files will be created (default: ./libft-dev)
    --bonus               Create the files for the bonus part as well
```

#### Project check
After you've finished coding your project, you can use the script to check the norm and test your functions with the tester folder. To do so, you can run the following command:
```sh
python3 helper.py check
```

If you want to extend the check to the bonus part as well, you can use the `--bonus` argument. Example:
```sh
python3 helper.py check --bonus
```

If you want to check the norm without testing your functions, you can use the `--no-test` argument. Example:
```sh
python3 helper.py check --no-test
```

Else, if you want to test your functions without checking the norm, you can use the `--no-norm` argument. Example:
```sh
python3 helper.py check --no-norm
```

Here's the full list of arguments you can use:
```sh
usage: helper.py check [-h] [--bonus] [--no-test] [--no-norm]

optional arguments:
    -h, --help  show this help message and exit
    --bonus     Check the bonus part as well
    --no-test   Don't test the functions
    --no-norm   Don't check the norm
```

**Note:** Be sure to have norminette installed on your computer. If you don't have it, you can install it with the following command:
```sh
pip3 install norminette
```

Take a look at the [tester README](tester/README.md) for more information about the tester.

## Some screenshots
![Setup](https://i.imgur.com/wbztEUu.png)
![Check](https://i.imgur.com/KM7cKXB.png)


## Conclusion
I hope this will help you with your project. If you have any question, feel free to contact me via [mail](mailto:glizzykingdreko@protonmail.com) or on [twitter](https://twitter.com/GlizzyKingDreko), I'll be happy to help you.

Last but not least, if you find any mistake or if you have any suggestion, feel free to contact me as well.

Leave a ⭐ if you found this helpful.

Enjoy. 😉
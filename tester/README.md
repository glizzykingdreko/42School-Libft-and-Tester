# Libft Tester

This tester is designed to facilitate the process of verifying your Libft project's correctness and performance. The tester ensures that all basic, additional, and bonus functions are thoroughly examined, providing you with a solid foundation to build upon for future projects.

![Libft Tester](https://i.imgur.com/gIJfot5.png)

## Table of Contents
- [Libft Tester](#libft-tester)
  - [Table of Contents](#table-of-contents)
  - [Requirements](#requirements)
  - [Usage](#usage)
    - [Compiling and Running the Tester](#compiling-and-running-the-tester)
      - [With bonus functions](#with-bonus-functions)
    - [Example](#example)
    - [Improvements](#improvements)
  - [Conclusion](#conclusion)

## Requirements
- You must have a functional Makefile that compiles your Libft project with the appropriate flags.

## Usage

### Compiling and Running the Tester

#### With bonus functions
```sh
make bonus LIBFT_PATH=/path/to/libft
```

If you do not wish to test the bonus functions, simply run `make` instead.

```sh
make LIBFT_PATH=/path/to/libft
```

The `LIBFT_PATH` variable is required to compile the tester. It should be set to the path of your Libft project. (e.g. `~/Desktop/libft`) by default it is set to `../libft` which is the relative path to the libft folder from the tester folder.

Once the tester has been compiled, you can run it with the following command:

```sh
./test_libft
```

The output will look something like this:

```sh
$> ./test_libft
==================== BASIC FUNCTIONS ====================
ft_memset: [OK]
ft_bzero: [OK]
ft_memcpy: [OK]
ft_memccpy: [OK]
ft_memmove: [OK]
ft_memchr: [OK]
ft_memcmp: [OK]
ft_isalpha: [OK]
ft_isdigit: [OK]
ft_isalnum: [OK]
...
```

### Example
```sh
make bonus LIBFT_PATH=../libft
./test_libft
```

### Improvements
Take a look into the [tester.c](tester.c) file and you'll find more information about the tester and how it works. This is a first version of the tester, I need to leave some work to do for you guys. 😅 (jk is enough to get 125 points with bonus functions)


## Conclusion
This tester aims to streamline the process of verifying your Libft project's correctness and functionality. By utilizing this tester, you can ensure that your implementation performs as expected, ultimately enhancing the quality of your work.

If you have any questions or suggestions, feel free to contact me via [mail](mailto:glizzykingdreko@protonmail.com) or on [twitter](https://twitter.com/GlizzyKingDreko), I'll be happy to help you.

Let's get those points! 🚀
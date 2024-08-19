# simple_shell

![Angry linux](/pingu.png)

## Repository Description

This repository contains the files to simulate a basic **Unix Shell** with its respective commands. It uses the POSIX API to implement many of the Shell's features and is designed for the Holberton School (https://www.holbertonschool.com).

The predominantly used calls are **read**, **write**, **open**, **execve**, **exit**, **fflush**, **fork**, **free**, **malloc**, **getline**, **isatty**, **perror**, **strtok** and **wait**.

This simple shell is a Shell interface written in the C programming language that gives the user the power to execute a command in a separate process called a child process.

## Requirements:

* Operating System: [Ubuntu 20.04 LTS](http://releases.ubuntu.com/20.04/)

* Compiler: [GCC 11.5.0](https://gcc.gnu.org/gcc-11/)

### General.

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 22.04 LTS
- Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` `-pedantic`and `-std=gnu89`
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project is mandatory
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl "betty-doc.pl")
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded

## Basic beggining

To run this shell with its respective commands its necessary to clone this repository in your terminal. Do it like this:
- HTTPS:

```c
git clone https://github.com/Lucasleg24/holbertonschool-shell.git
```

- SSH:

```
git clone git@github.com:Lucasleg24/holbertonschool-shell.git
```

## Compiling, Debugging and Runing

- Your shell will be compiled this way: 
 ```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

- If you want to **debugging** the shell, use valgrind:
```
valgrind --leak-check=full ./hsh
```
- Or just **run** and try this shell using:
```
./hsh
```
- Or **execute** a command by trying the shell directly:
```
ls | ./hsh
```
- This program provides a simple manual to know and get familiar with the shell. Open it by typing: 
```
man ./man_1_simple_shell
```

## This shell provides the following features:

* This program displays a prompt and waits that the user types a command. 
* A command line always ends with a new line (when user push *ENTER* key).
* The prompt is displayed again each time a command has been executed.
* When the user enters exit, the shell will end and returns the status 0.
* The shell handles the command lines with arguments and pathways.
* The program prints the current enviroment when the user types *env*.
* This program executes the most common shell commands as *ls*, *grep*, *find*, *pwd*, *rm*, *cp*, *mv*, *exit*, *env*, *history*, etc... with arguments.
* If an executable cannot be found, It prints an error message and displays the prompt again.
* The program does not quit when the user imputs ^C (Ctrl+C).
* The user could stop the program using *Ctrl+D* (end of file).
* The user can display the 100 last commands with *history*.


## Process Description

The next steps are a brief description about how the shell works:

1. First, the parent process is created when the user run the program.
2. Then, the *isatty()* function using *STDIN_FILENO* file descriptor -fd- to tests if there is an open file descriptor referring to a terminal. If *isatty()* returns 1, the prompt is showed using *write()* with *STDOUT_FILENO* as fd and waits for an input user command line.
3. When the user types a command, *getline()* function reads an entire line from the stream and *strtok()* function breaks the inputted command into a sequence of non-empty tokens.
4. Next, it creates a separate child process suing *fork()* that performs the inputted command. Unless otherwise is specified, the parent process waits for the child to exit before continuing.
5. After tokening the command, *execve()* function brings and executes it, the it frees all allocated memory with *free()*.
6. Finally, the program returns to main process: prints the prompt, and waits for another user input.

## Flowchart

![Flowchart](/flowchart.jpeg)

## Examples

Here are shown some examples of the usage of the Shell:

- ls

```shell
$ ls
README.md     change_directory.c  free_continue.c  history.c  input.c  parse.c
process_command.c  shell_exit.c build_path.c  execute.c           
get_location.c   hsh        main.c   print_env.c  shell.h            sigint.c
```

```shell
$ /bin/ls
README.md     change_directory.c  free_continue.c  history.c  input.c  parse.c
process_command.c  shell_exit.c build_path.c  execute.c
get_location.c   hsh        main.c   print_env.c  shell.h            sigint.c
```

```shell
$ ls -lat
total 96
drwxr-xr-x 3 root root  4096 Aug 18 09:14 .
-rw-r--r-- 1 root root     1 Aug 18 09:14 README.md
drwxr-xr-x 8 root root  4096 Aug 18 09:13 .git
-rw-r--r-- 1 root root   295 Aug 18 09:13 build_path.c
-rw-r--r-- 1 root root   447 Aug 18 09:13 change_directory.c
-rw-r--r-- 1 root root   836 Aug 18 09:13 execute.c
-rw-r--r-- 1 root root   285 Aug 18 09:13 free_continue.c
-rw-r--r-- 1 root root  1172 Aug 18 09:13 history.c
-rwxr-xr-x 1 root root 22080 Aug 18 09:13 hsh
-rw-r--r-- 1 root root   425 Aug 18 09:13 input.c
-rw-r--r-- 1 root root   664 Aug 18 09:13 main.c
-rw-r--r-- 1 root root   870 Aug 18 09:13 parse.c
-rw-r--r-- 1 root root   680 Aug 18 09:13 process_command.c
-rw-r--r-- 1 root root  1350 Aug 18 09:13 shell.h
-rw-r--r-- 1 root root   314 Aug 18 09:13 shell_exit.c
-rw-r--r-- 1 root root   181 Aug 18 09:13 sigint.c
-rw-r--r-- 1 root root   983 Aug 18 09:13 get_location.c
-rw-r--r-- 1 root root   358 Aug 18 09:13 print_env.c
drwxr-xr-x 1 root root  4096 Aug 18 09:13 ..
```
- pwd

```shell
$ pwd
/holbertonschool-simple_shell
```
- echo

```shell
$ echo Hello World
Hello World
```


## Authors:

- *Lucas Legrand* - [@Lucasleg24](https://github.com/Lucasleg24) 
- *Xabi Martinez*  - [@Basco64](https://github.com/Basco64)

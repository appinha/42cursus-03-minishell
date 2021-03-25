<h1 align="center">
	42cursus' minishell
</h1>

<p align="center">
	<b><i>Development repo for 42cursus' minishell project</i></b><br>
	For further information about 42cursus and its projects, please refer to <a href="https://github.com/appinha/42cursus"><b>42cursus repo</b></a>.
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/appinha/42cursus-03-minishell?color=blueviolet" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/appinha/42cursus-03-minishell?color=blueviolet" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/appinha/42cursus-03-minishell?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/appinha/42cursus-03-minishell?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/appinha/42cursus-03-minishell?color=brightgreen" />
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#-index">Index</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
	<span> · </span>
	<a href="#-useful-links">Useful Links</a>
	<span> · </span>
	<a href="#-study-summary">Study Summary</a>
</h3>

---

## 🗣️ About

> _The objective of this project is for you to create a simple shell. Yes, your own little bash or zsh. You will learn a lot about processes and file descriptors._

For detailed information, refer to the [**subject of this project**](https://github.com/appinha/42cursus/tree/master/_PDFs).

	🚀 TLDR: this project consists of coding a basic shell.

## 📑 Index

`@root`

* [**📁 includes:**](includes/) contains the program's headers.
* [**📁 libft:**](libft/) contains the source code of the `libft` library, which is used in the program.
* [**📁 srcs:**](libft/) contains the source code of the program.
* [**Makefile**](Makefile) - contains instructions for compiling the program and testing it.

_Note: program covers only mandatory requirements of the project's subject._

## 🛠️ Usage

### Requirements

The program is written in C language for **Linux** distributions and thus needs the **`clang` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the program**

To compile the program, run:

```shell
$ make
```

**2. Executing the program**

To execute the program, run:

```shell
$ ./minishell
```

## 📋 Testing

(to be written)

## 📌 Useful Links

* [My notes on Shell & Shell Scripting](https://www.notion.so/Shell-Shell-Scripting-6e0f0290a0304dad93a1d25ba15d92fe)
* [The Open Group Base Specifications - Shell Command Language](https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html)
* [harm-smits' 42 Docs - minishell](https://harm-smits.github.io/42docs/projects/minishell)

## 🤓 Study Summary

### Definition

The shell is a command language interpreter. - _Source: [The Open Group Base Specifications](https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html)_

### Allowed functions

| Function		| Manual Page		| From lib			| Description
| :--			| :--				| :--				| :--
| **printf**	| `man 3 printf`	| `<stdio.h>`		| write output to stdout
| **malloc**	| `man malloc`		| `<stdlib.h>`		| allocate dynamic memory
| **free**		| `man 3 free`		| `<stdlib.h>`		| free dynamic memory
| **read**		| `man 2 read`		| `<unistd.h>`		| read from a file descriptor
| **write**		| `man 2 write`		| `<unistd.h>`		| write to a file descriptor
| **open**		| `man 2 open`		| `<fcntl.h>`		| open and possibly create a file
| **close**		| `man 2 open`		| `<unistd.h>`		| close a file descriptor
| **fork**		| `man fork`		| `<unistd.h>`		| create a child process
| **wait**		| `man wait`		| `<sys/wait.h>`	| wait for process to change state
| **waitpid**	| `man waitpid`		| `<sys/wait.h>`	| wait for process to change state
| **wait3**		| `man wait3`		| `<sys/wait.h>`	| (obsolete) wait for process to change state, BSD style
| **wait4**		| `man wait4`		| `<sys/wait.h>`	| (obsolete) wait for process to change state, BSD style
| **signal**	| `man signal`		| `<signal.h>`		| ANSI C signal handling
| **kill**		| `man 2 kill`		| `<signal.h>`		| send signal to a process
| **exit**		| `man exit`		| `<stdlib.h>`		| cause normal process termination
| **getcwd**	| `man getcwd`		| `<unistd.h>`		| get current working directory
| **chdir**		| `man chdir`		| `<unistd.h>`		| change working directory
| **stat**		| `man 2 stat`		| `<sys/stat.h>`	| get file status by pathname
| **lstat**		| `man lstat`		| `<sys/stat.h>`	| get file status by pathname (for symlinks)
| **fstat**		| `man fstat`		| `<sys/stat.h>`	| get file status by fd
| **execve**	| `man execve`		| `<unistd.h>`		| execute program
| **dup**		| `man dup`			| `<unistd.h>`		| duplicate a file descriptor
| **dup2**		| `man dup2`		| `<unistd.h>`		| duplicate a file descriptor
| **pipe**		| `man pipe`		| `<unistd.h>`		| create pipe
| **opendir**	| `man opendir`		| `<dirent.h>`		| open a directory
| **readdir**	| `man readdir`		| `<dirent.h>`		| read a directory
| **closedir**	| `man closedir`	| `<dirent.h>`		| close a directory
| **strerror**	| `man strerror`	| `<string.h>`		| return string describing error number
| **errno**		| `man errno`		| `<errno.h>`		| number of last error
| **termcap**	| `man termcap`		| `<term.h>`		| direct curses interface to the terminfo capability database

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
* [**📁 srcs:**](srcs/) contains the source code of the program.
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

* [My personal notes on Shell & Shell Scripting](https://www.notion.so/Shell-Shell-Scripting-6e0f0290a0304dad93a1d25ba15d92fe)
* [harm-smits' 42 Docs - minishell](https://harm-smits.github.io/42docs/projects/minishell)
* [Bash Guide for Beginners](https://tldp.org/LDP/Bash-Beginners-Guide/html/index.html)
* [The Open Group Base Specifications - Shell Command Language](https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html)
* [Introduction to Systems Programming: a Hands-on Approach - Chapter 5. Writing Your Own Shell ](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)


## 🤓 Study Summary

### Definition

**TLDR:** The shell is a command language interpreter. - [_Source_](https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html)

> The UNIX shell program interprets user commands, which are either directly entered by the user, or which can be read from a file called the shell script or shell program. Shell scripts are interpreted, not compiled. The shell reads commands from the script line per line and searches for those commands on the system, while a compiler converts a program into machine readable form, an executable file - which may then be used in a shell script.
>
> Apart from passing commands to the kernel, the main task of a shell is providing a user environment, which can be configured individually using shell resource configuration files. - [_Source_](https://tldp.org/LDP/Bash-Beginners-Guide/html/sect_01_01.html)

* [**Shell types**](https://tldp.org/LDP/Bash-Beginners-Guide/html/sect_01_01.html) (sh, bash, etc)

### Parts of a Shell Program

The shell implementation is divided into three parts: **The Parser**, **The Executor**, and **Shell Subsystems**.

* **The Parser:** reads the command line and puts it into a data structure called _Command Table_ that will store the commands that will be executed.
* **The Executor:** takes the Command Table and for every _SimpleCommand_ in the array it  creates a new process; also, if necessary, it creates pipes to communicate the output of one process to the input of the next one; additionally, it redirects the standard input, standard output, and standard error if there are any redirections.
* **Shell Subsystems:** such as _Environment Variables_ expansions, _Wildcards_ expansions, _Subshells_ executions.

**The Parser**

A parser is divided into two parts: a _Lexical Analyzer_ or _Lexer_ takes the input characters and puts the characters together into words called _tokens_, and a _Parser_ that processes the tokens according to a grammar and build the Command Table.

**The Command Table**

The _Command Table_ is an array of  _SimpleCommand_ structs. A SimpleCommand struct
contains members for the command and arguments of a single entry in the pipeline. The
parser will look also at the command line and determine if there is any input or output
redirection based on symbols present in the command (i.e. < infile, or > outfile).

\- [_Source_](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)

### Shell Variables

Shell variable names are in uppercase characters by convention. Bash keeps a list of two types of variables:

* **Global / environment variables** - are available in all shells. The `env` or `printenv` commands can be used to display environment variables.
* **Local variables** - are only available in the current shell. Using the `set` built-in command without any options will display a list of all variables (including environment variables) and functions. Child processes of the current shell will not be aware of local variables.

Variables are case sensitive and capitalized by default. Giving local variables a lowercase name is a convention which is sometimes applied. However, you are free to use the names you want or to mix cases. Variables can also contain digits, but a name starting with a digit is not allowed.

To set a local variable in the shell, use:

```shell
VARNAME="value"
```

**Exporting variables**

In order to pass variables to a subshell, we need to export them using the `export` built-in command. Variables that are exported are referred to as **environment variables**. A subshell can change variables it inherited from the parent, but the changes made by the child don't affect the parent.

Setting and exporting is usually done in one step:

```shell
export VARNAME="value"
```

\- [_Source_](https://tldp.org/LDP/Bash-Beginners-Guide/html/sect_03_02.html)

More information:

* [refspecs.linuxbase.org - __environ](https://refspecs.linuxbase.org/LSB_5.0.0/LSB-Core-generic/LSB-Core-generic/baselib---environ.html)
* [environ(7) - Linux manual page](https://man7.org/linux/man-pages/man7/environ.7.html)

### Termination Signals

These signals are all used to tell a process to terminate, in one way or another. They have different names because they’re used for slightly different purposes, and programs might want to handle them differently.

* **SIGINT** - program interrupt signal (**ctrl + C**).
* **SIGQUIT** - program interrupt signal (**ctrl + \\**), produces a core dump when it terminates the process, just like a program error signal.

\- [_Source_](https://www.gnu.org/software/libc/manual/html_node/Termination-Signals.html)


### Exit status

Each command executed in a shell returns an **exit status** (sometimes referred to as a _return status_ or _exit code_). The exit status is often used in shell scripts to display an error message or take an action.

Exit statuses fall between 0 and 255, though the shell may use values above 125 specially. For the shell's purposes, a command which exits with a **zero exit status** has succeeded. A **non-zero exit status** indicates failure. This seemingly counter-intuitive scheme is used so there is one well-defined way to indicate success and a variety of ways to indicate various failure modes.

There is a special shell variable called **`$?`** that expands to the exit status of the most recently executed command.

\- [_Source 1_](https://www.gnu.org/software/bash/manual/html_node/Exit-Status.html), [_Source 2_](https://tldp.org/LDP/abs/html/exit-status.html)

### Termcap - Terminal Capabilities

Termcap is a **library and data base** that enables programs to use display terminals in a terminal-independent manner.

The **termcap data base** describes the capabilities of hundreds of different display terminals in great detail. Some examples of the information recorded for a terminal could include how many columns wide it is, what string to send to move the cursor to an arbitrary position (including how to encode the row and column numbers), how to scroll the screen up one or several lines, and how much padding is needed for such a scrolling operation.

The **termcap library** is provided for easy access this data base in programs that want to do terminal-independent character-based display output. It contains functions for the following purposes:

* Finding the description of the user’s terminal type (`tgetent`).
* Interrogating the description for information on various topics (`tgetnum`, `tgetflag`, `tgetstr`).
* Computing and performing padding (`tputs`).
* Encoding numeric parameters such as cursor positions into the terminal specific form required for display commands (`tparam`, `tgoto`).

```shell
int	tgetent (char *buffer, char *termtype);
```

This function finds the description and remembers it internally so that you can interrogate it about specific terminal capabilities.

* **`@param termtype`** - a string which is the name for the type of terminal to look up. Usually you would obtain this from the environment variable `TERM` using `getenv ("TERM")`.
* **`@param buffer`** - if you are using the GNU version of termcap, you can alternatively ask `tgetent` to allocate enough space. Pass a null pointer for `buffer`, and `tgetent` itself allocates the storage using malloc.
* **`@returns int`** - `1` if there is some difficulty accessing the data base of terminal types, `0` if the data base is accessible but the specified type is not defined in it, and some other value otherwise.

No matter how the space to store the description has been obtained, `termcap` records its address internally for use when you later interrogate the description with `tgetnum`, `tgetstr` or `tgetflag`. If the buffer was allocated by termcap, it will be freed by termcap too if you call `tgetent` again.

Each piece of information recorded in a terminal description is called a _capability_. Each defined **terminal capability** has a two-letter code name and a specific meaning. For example, the number of columns is named 'co'. See section [Definitions of the Terminal Capabilities](https://www.gnu.org/software/termutils/manual/termcap-1.3/html_mono/termcap.html#SEC23), for definitions of all the standard capability names. Capability values can be numeric, boolean (capability is either present or absent) or strings. There are three functions to use to get the value of a capability, depending on the type of value the capability has.

```shell
int	tgetnum (char *name);
```

Used to get a capability value that is **numeric**.

* **`@param char *name`** - the two-letter code name of the capability.
* **`@returns int`** - if the capability name is present in the terminal description, the numeric value (which is nonnegative); else `-1`.

```shell
int	tgetflag (char *name);
```

Used to get a **boolean** value.

* **`@param char *name`** - the two-letter code name of the capability.
* **`@returns int`** - if the capability name is present in the terminal description, `1`; else `0`.

```shell
char	*tgetstr (char *name, char **area);
```

Used to get a **string** value.

* **`@param char *name`** - the two-letter code name of the capability.
* **`@param char **area`** - pointer to where the return will be copied to. If given a null pointer, `tgetstr` will use `malloc` to allocate storage big enough for the value; you should free it when you are finished with it.
* **`@returns char *`** - a pointer to a string which is the capability value, or a `null` pointer if the capability is not present in the terminal description.

```shell
int	tputs(const char *str, int affcnt, int (*putc)(int));
```

Applies padding information to the string `str` and outputs it (`STDOUT`).

* **`@param const char *str`** - a terminfo string variable or the return value from `tparm`, `tiparm`, `tgetstr`, or `tgoto`.
* **`@param int affcnt`** - the number of lines affected, or `1` if not applicable.
* **`@param int (*putc)(int)`** - a `putchar`-like routine to which the characters are passed, one at a time.
* **`@returns char *`** - `ERR` upon failure (if the string parameter is null) and `OK` upon successful completion.

**The termios Structure**

Routines that need to control certain terminal I/O (Input/Output) characteristics do so by using the **termios structure** (see code below) as defined in the header `<termios.h>`.

```C
typedef unsigned char	cc_t;
typedef unsigned int	speed_t;
typedef unsigned int	tcflag_t;

#define NCCS 32
struct termios
  {
    tcflag_t c_iflag;		/* input mode flags */
    tcflag_t c_oflag;		/* output mode flags */
    tcflag_t c_cflag;		/* control mode flags */
    tcflag_t c_lflag;		/* local mode flags */
    cc_t c_line;		/* line discipline */
    cc_t c_cc[NCCS];		/* control characters */
    speed_t c_ispeed;		/* input speed */
    speed_t c_ospeed;		/* output speed */
#define _HAVE_STRUCT_TERMIOS_C_ISPEED 1
#define _HAVE_STRUCT_TERMIOS_C_OSPEED 1
  };
```

Two general kinds of input processing are available, determined by whether the terminal device file is in [canonical](https://pubs.opengroup.org/onlinepubs/7908799/xbd/termios.html#tag_008_001_006) mode or [non-canonical](https://pubs.opengroup.org/onlinepubs/7908799/xbd/termios.html#tag_008_001_007) mode. When and how data is provided to a process reading from a terminal device file is dependent on whether the terminal file is in canonical or non-canonical mode. Additionally, input characters are processed according to the `c_iflag` and `c_lflag` fields. The special control characters values are defined by the array `c_cc`.

In **non-canonical mode input processing**, input bytes are not assembled into lines, and erase and kill processing does not occur. The values of the `MIN` and `TIME` members of the `c_cc` array are used to determine how to process the bytes received. `MIN` represents the minimum number of bytes that should be received when the `read()` function returns successfully. `TIME` is a timer of 0.1 second granularity that is used to time out bursty and short-term data transmissions.



```shell
int	tcgetattr(int fd, struct termios *termios_p);
```

Gets the parameters associated with the terminal referred by `fd` and stores them in the `termios` structure referenced by `termios_p`. This function may be invoked from a background process; however, the terminal attributes may be subsequently changed by a foreground process.

* **`@param int fd`** - an open file descriptor associated with a terminal.
* **`@param struct termios *termios_p`** - a pointer to a termios structure.
* **`@returns int`** - upon successful completion, `0`; otherwise, `-1` and `errno` is set to indicate the error.

```shell
int	tcsetattr(int fd, int optional_actions, const struct termios *termios_p);
```

Sets the parameters associated with the terminal referred to by the open file descriptor `fd` (an open file descriptor associated with a terminal) from the `termios` structure referenced by `termios_p` as follows:

* If `optional_actions` is `TCSANOW`, the change will occur immediately.
* If `optional_actions` is `TCSADRAIN`, the change will occur after all output written to fd is transmitted. This function should be used when changing parameters that affect output.
* If `optional_actions` is `TCSAFLUSH`, the change will occur after all output written to fd is transmitted, and all input so far received but not read will be discarded before the change is made.

.

* **`@param int fd`** - an open file descriptor associated with a terminal.
* **`@param struct termios *termios_p`** - a pointer to a termios structure.
* **`@returns int`** - will return successfully if it was able to perform any of the requested actions, even if some could not be performed. It will set all the attributes that implementation supports as requested and leave all the attributes not supported by the implementation unchanged. If no part of the request can be honoured, it will return `-1` and set `errno`.

\- [_Source 1_](https://www.gnu.org/software/termutils/manual/termcap-1.3/), [_Source 2_](https://pubs.opengroup.org/onlinepubs/7908799/xbd/termios.html), [_Source 3_](https://man7.org/linux/man-pages/man3/termios.3.html)

### Functions allowed in this project

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
| **termcap**	| `man termcap`, `man termios`		| `<term.h>`		| direct curses interface to the terminfo capability database

---

## TO DO

* Corrigir bugs quando se usa algum `signal` - revisar lógica do termcaps pra evitar possíveis segfaults dependendo do momento em que o signal for acionado.
* Refatorar `get_environ()` para caso de mais de um `=` na string (i.e. valor da variável de ambiente contendo o caracter separador `=`).

﻿# Basic-Shell

This is a basic non-built in shell (i.e., the shell does not contain the code of the commands to be executed) implemented on Linux. The shell accepts user commands and then executes each command in a separate process.
This shell interface has the parent process first read what the user enters on the command line, and then create a separate child process that performs the command. Then, the parent process waits for the child to exit before continuing.

This shell supports only the following commands (with no attributes): ls, generate, sum, substract, tee.
 
### ls: 
Lists the set of files and directories in the current directory.
### generate:
Prints two random integers from 0 to 10 to the standard output.
### sum:
Takes two integers from the standard input and prints their sum to the standard output.
### subtract:
Takes two integers from the standard input and prints their difference to the standard
output.
### tee:
Reads from the standard input and writes to standard output and files.
tee command supports double redirection to standard input and a file at the same time (i.e., piping while keeping the output on the terminal)


All commands (i.e., ls, generate, sum, subtract) are written in Java! However, the shell interpreter is written in C.


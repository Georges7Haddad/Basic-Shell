# Basic-Shell
A basic non-built in shell (i.e., the shell does not contain the code of the commands to be executed). The shell accepts user commands and then executes each command in a separate process.
This shell interface has the parent process first read what the user enters on the command line, and then create a separate child process that performs the command. Then, the parent process waits for the child to exit before continuing.

This shell supports only the following commands (with no attributes): ls, generate, sum, substract, tee. 
• ls: lists the set of files and directories in the current directory.
• generate: prints two random integers from 0 to 10 to the standard output.
• sum: takes two integers from the standard input and prints their sum to the standard output.
• subtract: takes two integers from the standard input and prints their difference to the standard
output.
• tee: reads from the standard input and writes to standard output and files.
tee command can be used to support double redirection to standard input and a file and input at the same time (i.e., piping while keeping the output on the terminal)

This shell supports one pipe operation using "|".

All commands (i.e., ls, generate, sum, subtract) are written in Java! However, the shell interpreter is written in C.

# Minishell

Welcome to the Minishell project! This is a group project written in C with the goal of creating a functional clone of the bash shell. Minishell allows you to execute shell commands, handle input/output redirections, pipes, environment variables, and also includes the implementation of some signals and a few specific built-in commands.

## Features

- Shell command execution: Minishell provides a command line interface where you can enter shell commands and have them executed.
- Input/Output Redirections: You can redirect the input or output of a command to or from a file.
- Pipes: Minishell supports the use of pipes to connect the output of one command to the input of another.
- Environment Variables: You can set, modify, and access environment variables within the shell.
- Signals: Minishell handles some signals, allowing you to gracefully terminate or interrupt running processes.
- Built-in Commands: Minishell includes a set of built-in commands that provide additional functionality.

## Getting Started

Dependencies:
	The readline library is necessary please find out how to install readline library on your system!

To get started with Minishell, follow these steps:

1. Clone the repository:				`git clone https://github.com/cerdelen/42_minishell.git minishell`
2. Navigate to the project directory:	`cd minishell`
3. Build the project:					`make`
4. Run Minishell:						`./minishell`

## Usage

Once you have Minishell up and running, you can start using it to execute shell commands. Here are some examples of how you can interact with the shell:

```
$ ls -l              			# Execute the 'ls' command with the '-l' option
$ echo "Hello!"      			# Print the string "Hello!"
$ pwd                			# Print the current working directory
$ cat file.txt       			# Display the contents of a file
$ ls > files.txt     			# Redirect the output of 'ls' to a file
$ grep "pattern" < input.txt    # Redirect a file as input for 'grep'
$ command1 | command2           # Pipe the output of 'command1' to 'command2'
$ export VAR=value              # Set an environment variable
$ echo $VAR                     # Access the value of an environment variable
$ cd /path/to/directory         # Change the current directory
$ exit                          # Exit Minishell
```

Feel free to explore and experiment with different commands and features offered by Minishell.

# Simple Unix Shell Documentation
ALX project by Julien Barbier
Weight: 10
Team: Mustorpha Jamiu and Victor Ukpongette

## Introduction

This Unix Shell Program is a simple command-line interface (CLI) tool that allows users to interact with the Unix operating system. It provides basic functionality for running commands and managing files and directories.

## Getting Started

### Installation

To use the Unix Shell Program, no installation is required. Simply open your terminal and clone this repository for compilation. Then go on and run the shell to start the prompt indefinitely.<br>
``sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
``

### Running the Program

To run the program, use the following command:

```sh
./hsh
```

This will start the Unix Shell Program and display a command prompt.

## Features

### Basic Commands

The Unix Shell Program supports a variety of basic Unix commands, including:

- `ls`: List files and directories in the current directory.
- `cd`: Change the current directory.
- `pwd`: Display the current working directory.
- `mkdir`: Create a new directory.
- `touch`: Create a new file.
- `rm`: Remove files and directories.
- `cp`: Copy files and directories.
- `mv`: Move or rename files and directories.

### Command Syntax

Commands are entered in the following format:

```sh
command [options] [arguments]
```

For example:

```sh
ls -l /path/to/directory
```

### Exiting the Shell

To exit the Unix Shell Program, simply type:

```sh
exit
```

## Contributions

Contributions to this project are welcome! If you'd like to contribute, please fork the repository, make your changes, and submit a pull request.

## Authors
Mustorpha Jamiu<br>
Victor Ukpongette

## License

This program is open-source and available under the [MIT License](LICENSE).

## Contact

For any questions or issues, please contact Mustorpha @ [mustorphajamiu@gmail.com] OR MrVeeJon @ [sirviczo123@gmail.com]

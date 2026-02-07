This project was created as part of the 42 curriculum by foehler-.
# get_next_line

![Language](https://img.shields.io/badge/language-C-blue.svg)
![Standard](https://img.shields.io/badge/standard-C99-green.svg)
![License](https://img.shields.io/badge/license-MIT-orange.svg)

## Description

**get_next_line** is a function that reads a file descriptor line by line. This project introduces the concept of static variables in C and file descriptor manipulation.

The goal is to provide a convenient way to read text from a file descriptor, whether it is a file, standard input, or even a network connection, returning one line at a time including the newline character.

## Algorithm

The function `get_next_line` follows a three-step process to manage reading and buffering:

1.  **Read and Stack**:
    The function reads from the file descriptor in chunks of `BUFFER_SIZE` bytes, which can be changed with through flags. Each chunk is appended to a static variable (the "stash") until a new line character (`\n`) is found or the end of the file is reached. This ensures that we have at least one full line stored in memory.

2.  **Extract Line**:
    Once the new line is found, the function identifies the line's boundaries inside the stash. It allocates memory and copies characters from the beginning of the stash up to and including the new line character.

3.  **Clean Stash**:
    After extracting the line, the remaining part of the data (characters after the new line) is kept in the stash for the next function call. The old stash is freed, and the new "cleaned" stash takes its place.

## Installation & Compilation

### Requirements

- GCC or Clang compiler

### Compilation

Since `get_next_line` is typically used as a utility within other projects rather than a standalone library, you usually compile it directly with your source files.

You must accept a compiler flag `-D BUFFER_SIZE=n` to define the buffer size used for `read()`. If it is not manually defined, then it takes 42 as a default value.

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o main
```

## Usage

### Function Prototype

```c
char *get_next_line(int fd);
```

| Parameter | Description |
| :---: | :--- |
| `fd` | The file descriptor to read from. |

**Return Value**: Read line: correct behavior; `NULL`: there is nothing else to read, or an error occurred.

### Main Template

You can use the following template to test the function. It opens a file named `test.txt` (create one before running) or you can modify it to read from standard input usage `0` as the file descriptor.

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    // Open a file (ensure test.txt exists)
    fd = open("test.txt", O_RDONLY);
    
    // Check for errors
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    // Read lines until NULL is returned
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // Don't forget to free the line!
    }

    // Close the file descriptor
    close(fd);
    return (0);
}
```

## Resources

* **UNIX Man Pages**: `read`, `malloc`, `free`, `open`.
* **C Reference**: Static variables and memory management.
* **AI Assistance**: AI usage was strictly limited to specific concept clarifications, test case generation, and code verification. All AI outputs were thoroughly reviewed and validated under human control.

## Author

**foehler** - [@feli-ohl](https://github.com/feli-ohl)

# ft_printf

## Project Description

This is the ft_printf project for the 42 school curriculum. The project focuses on recreating the standard C library function `printf`. The goal is to implement a versatile and extensible printf function that can handle various format specifiers and modifiers.

## Features

- **Basic Conversion Specifiers:** Support for `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%o`.
- **Width and Precision:** Handle minimum field width and precision.
- **Flags:** Implement flags such as `0`, `-`, `+`, `#`, and ` ` (space).
- **Length Modifiers:** Recognize length modifiers like `hh`, `h`, `l`, and `ll`.

## Getting Started

### Prerequisites

- GCC compiler
- GNU Make

### Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/yourusername/ft_printf.git
    ```

2. Change into the project directory:

    ```bash
    cd ft_printf
    ```

3. Build the project:

    ```bash
    make
    ```

4. Use ft_printf in your project:

    Include the header file in your source code and link with the compiled library.

    ```c
    #include "ft_printf.h"
    ```

## Usage

Use the `ft_printf` function as a drop-in replacement for the standard `printf` function:

```c
#include "ft_printf.h"

int main() {
    ft_printf("Hello, %s!\n", "World");
    return 0;
}

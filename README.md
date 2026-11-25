*This project has been created as part of the 42 curriculum by ral-saye.*

# ft_printf

## Description

The `ft_printf` project is a recreation of the standard C `printf()` function.

The goal is to understand variadic functions in C and learn how to handle a variable number of arguments while formatting and printing different data types.

The function reads a format string character by character. When it encounters a conversion specifier (such as `%d` or `%s`), it retrieves the corresponding argument and prints it using the appropriate helper function.

The project supports the following mandatory conversions:

| Conversion | Description |
|---|---|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints an unsigned hexadecimal number in lowercase |
| `%X` | Prints an unsigned hexadecimal number in uppercase |
| `%%` | Prints a percent sign |

The function returns the total number of characters printed, excluding the null terminator.

## Instructions

### Compilation

The project uses a Makefile to compile the source files and create a static library named `libftprintf.a`.

Run the following command at the root of the repository:

```bash
make
```

Available Makefile rules:

- `make`: Compiles the source files and creates `libftprintf.a`.
- `make clean`: Removes the object files.
- `make fclean`: Removes the object files and the compiled library.
- `make re`: Cleans and recompiles the project.

### Usage

Include the project header in your C file:

```c
#include "ft_printf.h"
```

Compile your program with the library:

```bash
cc main.c -L. -lftprintf
```

Example:

```c
#include "ft_printf.h"

int main(void)
{
    int age = 20;
    char *name = "Sara";

    ft_printf("Name: %s, Age: %d\n", name, age);
    return (0);
}
```

Expected output:

```text
Name: Sara, Age: 20
```

## Algorithm and Data Structures

### Algorithm

The implementation follows a character-by-character parsing approach.

1. **Initialize the argument list:** Use `va_start()` to initialize a `va_list`, allowing the function to access the additional arguments passed to `ft_printf()`.

2. **Parse the format string:** Iterate through the format string one character at a time.

3. **Handle regular characters:** If the current character is not `%`, print it directly and increment the character counter.

4. **Handle conversion specifiers:** When `%` is encountered, pass the conversion character to a format-handling function.

5. **Retrieve the corresponding argument:** Use `va_arg()` to retrieve the next argument with the appropriate type, depending on the conversion specifier.

6. **Print the argument:** Call the corresponding helper function to print the value. The helper functions update a shared character counter.

7. **Finish:** Call `va_end()` to clean up the argument list and return the total character count.

### Data Structures

The main data structure used is `va_list`, provided by the `<stdarg.h>` header.

It allows the function to access arguments passed through the variadic parameter (`...`). The format string determines which type of argument must be retrieved and in what order.

A pointer to an integer (`int *count`) is also passed to the helper functions. It allows all functions to update the same character counter without needing to return the count individually.

The project does not require complex data structures such as linked lists, trees, or arrays for its mandatory functionality.

### Number Conversion Algorithm

The integer-printing functions use recursion to convert numbers into their textual representation.

For decimal numbers, the number is repeatedly divided by 10. For hexadecimal numbers, it is repeatedly divided by 16.

The remainder determines the digit to print, while the quotient is passed recursively to process the remaining digits.

The recursive call happens before printing the current digit, which ensures that digits are printed in the correct order, from left to right.

For example, converting `42` to hexadecimal:

- `42 / 16` gives `2`, with remainder `10`.
- The recursive call processes `2` first.
- The remainder `10` corresponds to `a`.
- The final output is `2a`.

Pointer addresses are also printed in hexadecimal, using an integer type large enough to handle the address.

## Resources

The following resources were used to understand the concepts and develop the project:

- [Linux manual pages – printf(3)](https://man7.org/linux/man-pages/man3/printf.3.html): Reference for the behavior of the original `printf()` function and its conversion specifiers.
- [Linux manual pages – stdarg(3)](https://man7.org/linux/man-pages/man3/stdarg.3.html): Documentation for variadic functions and the `va_list`, `va_start`, `va_arg`, and `va_end` macros.
- 42 subject PDF: Project requirements and mandatory conversion specifications.

### AI Usage

AI tools were used as a learning and support resource throughout the project.

They were used for:
- Explaining variadic functions and how `va_list`, `va_start`, `va_arg`, and `va_end` work.
- Clarifying the expected argument types for each conversion specifier.
- Understanding pointer conversion and hexadecimal pointer printing.
- Preparing the README documentation.
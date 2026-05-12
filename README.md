# Generic Dynamic Array Library in C

A lightweight, single-header C library for managing dynamic arrays. This library supports multiple data types (`int`, `float`, `double`, `char`, `string`) and provides built-in functions for memory management, searching, sorting, and I/O operations.

## Features

* **Multi-type Support:** Handle integers, floating-point numbers, characters, and strings using a unified structure.
* **Dynamic Memory Management:** Automatically handles `malloc`, `realloc`, and `free` operations.
* **Variadic Initialization:** Fill arrays easily using variable arguments.
* **Built-in Algorithms:** Includes linear search and bubble sort implementations.
* **Input/Output:** Helper functions to print arrays and scan user input.

## Supported Data Types

The library defines a `type_t` enum to specify the data type:

* `TYPE_INT`
* `TYPE_FLOAT`
* `TYPE_DOUBLE`
* `TYPE_CHAR`
* `TYPE_STRING`

## Data Structures

### Array Struct
The core structure used to manage the data:

```c
typedef struct Array{
    int size;      // Number of elements
    type_t type;   // Data type (enum)
    void *data;    // Pointer to the raw data
} array;
```

## Quick Start Example
Here is a complete example showing how to create, fill, sort, and free an integer array.
```
#include <stdio.h>
#include "array_ops.h"

int main() {
    // 1. Create an array of 5 integers
    array *myArr = create_array(5, TYPE_INT);

    // 2. Fill with values
    fill_array(myArr, 50, 10, 40, 20, 30);

    printf("Original Array:\n");
    print_array(myArr);

    // 3. Add a new element dynamically
    int newVal = 99;
    add_new_element(&newVal, myArr);

    // 4. Sort the array
    sort_array(myArr);

    printf("Sorted Array:\n");
    print_array(myArr);

    // 5. Clean up
    free_array(myArr);

    return 0;
}
```
### Expected Output
```
Original Array:
{ 50  10  40  20  30 } 
Sorted Array:
{ 10  20  30  40  50  99 }
```

## API Reference
### Creation & Memory Management
| Function | Description |
|---|---|
| ``` array* create_array(int size, type_t type) ``` | Allocates memory for an array of the specified size and type. |
| ``` array* create_filled_array(int size, type_t type) ``` | Creates an array filled with random test data. |
| ``` void free_array(array *arr) ``` | Frees the memory allocated for the array struct and its data. |

### Initialization & Modification
| Function | Description |
|---|---|
| ``` void fill_array(array *arr, ...) ``` | Fills the array using variadic arguments. |
| ``` void add_new_element(void *data, array *arr) ``` | Appends a new element to the end (reallocates memory). |
| ``` void push_element_at_pos(int pos, void *data, array *arr) ``` | Overwrites the value at the specified index. |
| ``` void delete_element_at_pos(int pos, array *arr) ``` | Removes element at index and shifts remaining data. |

### Access & IO
| Function | Description |
|---|---|
| ``` void print_array(array *arr) ``` | Prints all elements formatted in braces { ... } |
| ``` void get_array_input(array *arr) ``` | Populates the array using scanf from stdin. |
| ``` void* get_element_at_pos(int pos, array *arr) ``` | Returns a pointer to the element at the specific index. |

### Search & Sort
| Function | Description |
|---|---|
| ``` void sort_array(array *arr) ``` | Sorts the array in ascending order (Bubble Sort). |
| ``` int search_value_exists(void *value, array *arr) ``` | Returns 1 if the value exists, 0 otherwise. |
| ``` void search_pos_by_value(void *val, array *arr, int *idxs, int *cnt) ``` | Populates idxs array with positions where val is found. |

## Contribution
First off, thank you for considering contributing to this project! It’s people like you that make the open-source community such an amazing place to learn, inspire, and create.
### How Can I Contribute?
* **Reporting Bugs:** If you find a bug, please open an issue and include a detailed description of the problem and steps to reproduce it.
* **Suggesting Enhancements:** Have an idea for a new function/feature? Open an issue to discuss it with the community.
  
### Pull Requests:

- Fork the repository.
- Create a new branch for your feature or bug fix (git checkout -b feature/YourFeature).
- Commit your changes with clear, descriptive messages.
- Push your branch to your fork.
- Open a Pull Request describing your changes.

### Code of Conduct
Please be mindful and respectful in all your interactions. I aim to foster a welcoming and inclusive environment for everyone.

### Getting Help
If you have questions or need guidance on where to start, feel free to open an issue or reach out to the me. Every contribution, no matter how small is valuable!

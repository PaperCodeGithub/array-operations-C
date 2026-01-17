/*
    Following program demonstrates the usage of a custom Array Operations Library in C.
    The library provides functionalities to create, manipulate, and manage arrays of various data types.
    Supports multiple data types: int, float, double, char, string.
    Sorting and searching works for all types.

    Comments in the code explain the usage of each function and feature.
    Unused code snippets are omitted for clarity.
*/

#include <stdio.h>
#include "headers/array_ops.h" // Array operations library

/*This code shows the usage of array operations library*/

int main(){

    // Creating an integer array of size 5
    
    array *int_array = create_array(5, TYPE_INT);

    /* To create other arrays write:
        array *float_array = create_array(5, TYPE_FLOAT);
        array *double_array = create_array(5, TYPE_DOUBLE);
        array *char_array = create_array(5, TYPE_CHAR);
        array *str_array = create_array(5, TYPE_STRING);
    */

    // Filling the integer array with values
    fill_array(int_array, 34, 12, 5, 67, 23);

    // Printing the integer array
    print_array(int_array);

    /* You can also create a array filled with random numbers by... */
    array *filled_int_array = create_filled_array(5, TYPE_INT);

    print_array(filled_int_array); // Print the array with random values

    /* You can update values in an array by... */
    push_element_at_pos(2, &(int){99}, int_array); // Push 99 at index 2, overwriting existing value

    /* You can add elements to an array at end by... */
    add_new_element(&(int){45}, int_array); // Add 45 at the end of the array, increasing its size by 1

    /* delete elements from an array by... */
    delete_element_at_pos(1, int_array); // Delete element at index 1, decreasing its size by 1

    /* Get element at a given position */
    int data = *(int*) get_element_at_pos(3, int_array);
    printf("Element at index 3: %d\n", data);

    /* Get size of the array */
    size_t size = get_size(int_array);
    printf("Size of the array: %zu\n", size);

    /* Search for a value in the array */
    int search_val = 67;
    int exists = search_value_exists(&search_val, int_array);
    if(exists){
        printf("Value %d found in the array.\n", search_val);
    } else {
        printf("Value %d not found in the array.\n", search_val);
    }

    /* Search index by value */
    
    // As same data can repeat in multiple indexes, we will store all indexes in an array
    int count, indexs[5]; // count -> number of occurrences, indexs -> indexes of occurrences
    search_pos_by_value(&search_val, int_array, indexs, &count);
    printf("%d results found! Value %d found at indexes: ", count, search_val);
    
    // Printing all found indexes
    for(int i = 0; i < count; i++){
        printf("%d ", indexs[i]);
    }

    /* Sorting the array */

    sort_array(int_array); // Sorting the integer array
    printf("\nSorted Array:\n");
    print_array(int_array);

    // Freeing the allocated memory for arrays
    free_array(int_array);
    free_array(filled_int_array);

    return 0;
}

/* 
    Arrays can be integer, float, double, char or string.
    Sorting and searching works for all types.

    Sorting in char arrays is done based on ASCII values.
    Sorting in string arrays is done in lexicographical order.

    Searching works by comparing values for all types.
    Searching in string arrays is done using strcmp function.
        
    search_value_exists() returns 1 if value is found, else 0.
    search_value_at_index() returns 1 if value is found at given index, else 0

*/
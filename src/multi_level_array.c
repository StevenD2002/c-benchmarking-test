#include "../include/multi_level_array.h"
#include <stdio.h>
#include <stdlib.h>

MultiLevelArray *createMultiLevelArray(int num_rows, int num_cols) {
  MultiLevelArray *array = (MultiLevelArray *)malloc(sizeof(MultiLevelArray));
  if (array == NULL) {
    return NULL; // Memory allocation failed
  }

  array->num_rows = num_rows;

  // Allocate memory for the array of pointers to rows
  array->rows = (int **)malloc(num_rows * sizeof(int *));
  array->num_cols = (int *)malloc(num_rows * sizeof(int));

  if (array->rows == NULL || array->num_cols == NULL) {
    free(array->rows);
    free(array->num_cols);
    free(array);
    return NULL; // Memory allocation failed
  }

  // Initialize each row with a dynamically allocated array of integers
  for (int i = 0; i < num_rows; i++) {
    array->num_cols[i] =
        num_cols; // Set the number of columns for each row to 'num_cols'
    array->rows[i] = (int *)malloc(num_cols * sizeof(int));

    if (array->rows[i] == NULL) {
      // Handle memory allocation failure
      for (int j = 0; j < i; j++) {
        free(array->rows[j]);
      }
      free(array->num_cols);
      free(array->rows);
      free(array);
      return NULL; // Memory allocation failed
    }

    // Initialize the elements in the row to zero
    for (int j = 0; j < num_cols; j++) {
      array->rows[i][j] = 0;
    }
  }

  return array;
}

// get an item from our array of arrays
int getFromMultiLevelArray(MultiLevelArray *array, int row, int col) {
  // Check if the array is NULL, the row is out of bounds, or the column is out
  // of bounds
  if (array == NULL || row < 0 || row >= array->num_rows || col < 0 ||
      col >= array->num_cols[row]) {
    return -1; // Handle invalid access
  }

  // Retrieve the value at the specified row and column
  return array->rows[row][col];
}

void setMultiLevelArray(MultiLevelArray *array, int row, int col, int value) {
  // Check if the array is NULL, the row is out of bounds, or the column is out
  // of bounds
  if (array != NULL && row >= 0 && row < array->num_rows && col >= 0 &&
      col < array->num_cols[row]) {
    // Set the value at the specified row and column
    array->rows[row][col] = value;
  }
};

MultiLevelArray *addTwoMultiLevelArrays(MultiLevelArray *array1,
                                        MultiLevelArray *array2) {
  // Check if either array is NULL
  if (array1 == NULL || array2 == NULL) {
    return NULL;
  }
  // Check if the arrays have the same number of rows
  if (array1->num_rows != array2->num_rows) {
    return NULL;
  }
  // Check if the arrays have the same number of columns in each row
  for (int i = 0; i < array1->num_rows; i++) {
    if (array1->num_cols[i] != array2->num_cols[i]) {
      return NULL;
    }
  }
  // Create a new array with the same dimensions as the input arrays
  MultiLevelArray *sum =
      createMultiLevelArray(array1->num_rows, array1->num_cols[0]);
  // Check if the array creation failed
  if (sum == NULL) {
    return NULL;
  }
  // Add the elements in the input arrays and store the result in the new array
  for (int i = 0; i < array1->num_rows; i++) {
    for (int j = 0; j < array1->num_cols[i]; j++) {
      setMultiLevelArray(sum, i, j,
                         getFromMultiLevelArray(array1, i, j) +
                             getFromMultiLevelArray(array2, i, j));
    }
  }
  return sum;
}

void freeMultiLevelArray(MultiLevelArray *array) {
  // Check if the array is NULL
  if (array != NULL) {
    // Free each row
    for (int i = 0; i < array->num_rows; i++) {
      free(array->rows[i]);
    }
    // Free the array of rows
    free(array->rows);
    // Free the array of column lengths
    free(array->num_cols);
    // Free the array itself
    free(array);
  }
}

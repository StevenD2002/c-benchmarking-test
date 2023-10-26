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

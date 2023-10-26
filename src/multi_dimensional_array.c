#include "../include/multi_dimensional_array.h"
#include <stdio.h>
#include <stdlib.h>

MultiDimensionalArray *createMultiDimensionalArray(int rows, int cols) {
  MultiDimensionalArray *array =
      (MultiDimensionalArray *)malloc(sizeof(MultiDimensionalArray));
  if (array == NULL) {
    return NULL; // Memory allocation failed
  }

  array->rows = rows;
  array->cols = cols;

  // Allocate memory for the 2D array
  array->data = (int **)malloc(rows * sizeof(int *));
  if (array->data == NULL) {
    free(array);
    return NULL; // Memory allocation failed
  }

  for (int i = 0; i < rows; i++) {
    array->data[i] = (int *)malloc(cols * sizeof(int));
    if (array->data[i] == NULL) {
      // If memory allocation for a row fails, free all allocated memory and
      // return NULL
      for (int j = 0; j < i; j++) {
        free(array->data[j]);
      }
      free(array->data);
      free(array);
      return NULL; // Memory allocation failed
    }
  }

  // Initialize the array elements to zero
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      array->data[i][j] = 0;
    }
  }

  return array;
}

int getFromMultiDimensionalArray(MultiDimensionalArray *array, int row,
                                 int col) {
  if (array == NULL || row < 0 || col < 0 || row >= array->rows ||
      col >= array->cols) {
    // Handle out-of-bounds or NULL array
    return -1;
  }

  return array->data[row][col];
}

void setMultiDimensionalArray(MultiDimensionalArray *array, int row, int col,
                              int value) {
  if (array != NULL && row >= 0 && col >= 0 && row < array->rows &&
      col < array->cols) {
    array->data[row][col] = value;
  }
}

void freeMultiDimensionalArray(MultiDimensionalArray *array) {
  if (array != NULL) {
    for (int i = 0; i < array->rows; i++) {
      free(array->data[i]);
    }
    free(array->data);
    free(array);
  }
}

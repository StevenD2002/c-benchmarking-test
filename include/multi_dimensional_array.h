#ifndef MULTI_DIMENSIONAL_ARRAY_H
#define MULTI_DIMENSIONAL_ARRAY_H

// data structure for the multi dimensional array
typedef struct{
    int ** data;
    int rows;
    int cols;
} MultiDimensionalArray;

// function prototypes

MultiDimensionalArray* createMultiDimensionalArray(int rows, int cols);
int getFromMultiDimensionalArray(MultiDimensionalArray *array, int row, int col);
void setMultiDimensionalArray(MultiDimensionalArray *array, int row, int col, int value);
void freeMultiDimensionalArray(MultiDimensionalArray *array);

#endif //MULTI_DIMENSIONAL_ARRAY_H



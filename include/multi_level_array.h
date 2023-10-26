#ifndef MULTI_LEVEL_ARRAY_H
#define MULTI_LEVEL_ARRAY_H


//header file for a 2d array that uses an array of pointers
// to point to each row of the array
typedef struct{
  int ** rows;
  int* num_cols;// array to store the number of items in each collumn
  int num_rows;

} MultiLevelArray;

MultiLevelArray* createMultiLevelArray(int num_rows, int num_cols);
MultiLevelArray* addTwoMultiLevelArrays(MultiLevelArray* array1, MultiLevelArray* array2);
int getFromMultiLevelArray(MultiLevelArray *array, int row, int col);
void setMultiLevelArray(MultiLevelArray *array, int row, int col, int value);
void freeMultiLevelArray(MultiLevelArray *array);

#endif // ndef

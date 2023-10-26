#include "../include/multi_dimensional_array.h"
#include "../include/multi_level_array.h"
#include <stdio.h>
int main() {

  MultiDimensionalArray *MDArray1 = createMultiDimensionalArray(1000, 1000);
  MultiDimensionalArray *MDArray2 = createMultiDimensionalArray(1000, 1000);

  MultiLevelArray *MLArray1 = createMultiLevelArray(1000, 1000);
  MultiLevelArray *MLArray2 = createMultiLevelArray(1000, 1000);

  // we are going to perform matric multiplciation between these two sets of
  // arrays to try and see if we can bemnchamrk with one is more efficent
  // starting with 1000x1000 arrays
  // lets first fill the arrays with some values
  // we will use the same values for both arrays
  //

  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      setMultiDimensionalArray(MDArray1, i, j, 1000);
      setMultiDimensionalArray(MDArray2, i, j, 1000);
      setMultiLevelArray(MLArray1, i, j, 1000);
      setMultiLevelArray(MLArray2, i, j, 1000);
    }
  }

  // now lets perform the multiplication
  // for the multi dimensional array

  MultiDimensionalArray *MDArrayResult =
      createMultiDimensionalArray(1000, 1000);
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      int sum = 0;
        sum += getFromMultiDimensionalArray(MDArray1, i, j) +
               getFromMultiDimensionalArray(MDArray2, i, j);
      setMultiDimensionalArray(MDArrayResult, i, j, sum);
    }
  }

  // now lets perform the multiplication
  // for the multi level array

  MultiLevelArray*MLArrayResult = createMultiLevelArray(1000, 1000);

  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      int sum = 0;
        sum += getFromMultiLevelArray(MLArray1, i, j) +
               getFromMultiLevelArray(MLArray2, i, j);
      setMultiLevelArray(MLArrayResult, i, j, sum);
    }
  }

  // lets print out the very last element of the arrays to make sure they are
  //  the same

  printf("MDArrayResult[999][999] = %d\n",
         getFromMultiDimensionalArray(MDArrayResult, 999, 999));
  printf("MLArrayResult[999][999] = %d\n",
         getFromMultiLevelArray(MLArrayResult, 999, 999));

  return 0;
}

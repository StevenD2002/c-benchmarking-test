# Conclusion:
For this project, i created two "classes" that create a multi dimensional array and a multi level array
For the sake of time, i only did simple matrix addition with 1000 x 1000 size arrays
(i will go back and do much more extensive tests because the results were really interesting)


Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  ms/call  ms/call  name    
 50.00      0.02     0.02  3000000     0.00     0.00  setMultiLevelArray
 25.00      0.03     0.01        3     3.33     3.33  createMultiDimensionalArray
 25.00      0.04     0.01        1    10.00    13.33  addTwoMultiDimensionalArrays
  0.00      0.04     0.00  2000001     0.00     0.00  getFromMultiLevelArray
  0.00      0.04     0.00  2000000     0.00     0.00  setMultiDimensionalArray
  0.00      0.04     0.00        3     0.00     0.00  createMultiLevelArray
  0.00      0.04     0.00        1     0.00     6.67  addTwoMultiLevelArrays

As you can see from this analysis, it seems that there are tradeoffs to each type of array.
In terms of runtime of the entire program, setting the multiLevel array seemed to take the most time.
But in terms of doing computations with the two arrays, it looks like the multi level
array blew the multi dimensional array out of the water.

### Remember:
it is important to remeber that this is a very small test at this moment, and depends on the machine.


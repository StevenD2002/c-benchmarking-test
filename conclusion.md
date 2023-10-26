# Conclusion:
For this project, i created two "classes" that create a multi dimensional array and a multi level array
For the sake of time, i only did simple matrix addition with 1000 x 1000 size arrays
(i will go back and do much more extensive tests because the results were really interesting)


Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  ms/call  ms/call  name    
 33.33      0.02     0.02  2000001     0.00     0.00  getFromMultiDimensionalArray
 16.67      0.03     0.01  3000000     0.00     0.00  setMultiDimensionalArray
 16.67      0.04     0.01        3     3.33     3.33  createMultiDimensionalArray
 16.67      0.05     0.01        3     3.33     3.33  createMultiLevelArray
 16.67      0.06     0.01                             main
  0.00      0.06     0.00  3000000     0.00     0.00  setMultiLevelArray
  0.00      0.06     0.00  2000001     0.00     0.00  getFromMultiLevelArray

as you can see from this analysis, the Multi Dimensional array functions took WAY more time
than the multi level array functions. I am not yet quite sure why, but i will continue looking into
this. I hav gotten very intersted in lower-level programming, and want to learn more about efficency.

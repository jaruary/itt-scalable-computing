# Summary #

This wiki discusses the Average & Variance C-program and it's performance.

# Introduction #

Labs 01 and 02 dealt with designing and coding a C-program which would generate an array (of a given length) and populate the array with data.  The program would then calculate the average and the variance of the data an output the results in the terminal.  We were also required to analyse our algorithms and determine the big-O notation.


# Details #

The Average\_Variance C-program took on three functions, 'populateArray', 'getAverage', and 'getVariance'.  When the program is executed, an optional piece of functionality in the main function asks the user to enter the size of the array.  This was added as the extra functionality was considered to be beneficial.

Once the user has entered the intended array size, an array of that size is created.  The first function (populateArray) is called and it takes the array and arraySize as arguments.  The array is passed by reference and the arraySize is passed by value.

The 'populateArray' uses a for loop which stops at the arraySize.  It uses the 'rand' function, "rand() % 100", which is part of the <stdlib.h> library, to enter in a number into each index of the array.  The rand() function only allows numbers 0 - 99.

The 'getAverage' is then called as part of a printf() statement in the main program.  Like the 'populateArray', the array and arraySize are passed as arguments into the 'getAverage' function.  The most intensive part of the code uses a for loop, with a limit of the arraySize.  All the values in each index of the array are added together using the code, " average = average + array[i](i.md);".  Then the answer is divided by the arraySize to give the average.  The result is returned and printed out to the terminal.

```
        for(i = 0; i < count; i++)
        {
                average = average + array[i];
                //printf ("%f\n", average);
        }
```

The 'getVariance' function is called the same way as the 'getAverage'.  It is calculated by the algorithm,

```
 for(i = 0; i < count; i++)
        {
                variance = variance + (pow((array[i] - average), 2));
        }

        variance = variance / (count - 1);
```

The code summates each number in the array to the limit of the arraySize, less the average value, all squared.

The final answer is divided by the (arraySize - 1)

The variance is returned and both the average and the variance is displayed in the terminal.

# Big O-Notation #

The O-Notation (aka big O- Notation) is an indication of the efficiency of the algorithms used in the program.  There are two requirements when considering O-notation,

(i)   -  the scalar or 'm' factor is not relevant
(ii)  -  the algorithm with the greatest workload is only considered

Since both the getAverage and getVariance methods both have the same work load, (ie, both have for loops to the limit of count), the O-notation for the Average\_Variance can be considered by either function.

If we considered the getAverage function, we get the mathematical formula

![http://farm9.staticflickr.com/8390/8505685416_81d08f5f46_m.jpg](http://farm9.staticflickr.com/8390/8505685416_81d08f5f46_m.jpg)

This summation simplifies to,

> ### O(n) ###

in big O-notation.
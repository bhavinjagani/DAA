# DAA
DAA assignments
# Student Id : 1002223241

 # Here is my system information:

* OS Name	Microsoft Windows 11 Home Single Language
* Version	10.0.22631 Build 22631
* Processor	Intel(R) Core(TM) i5-8265U CPU @ 1.60GHz   1.80 GHz.
* Installed RAM	8.00 GB (7.82 GB usable).
* System type	64-bit operating system, x64-based processor.
* Pen and touch	No pen or touch input is available for this display.


# 1 benchmarking for Insertion sort :
* I took input of Random number between 0 and 999.
* I took input sizes from 5,10,20...upto 50000.
* input_sizes = [5, 10, 20, 50, 100, 500, 1000, 5000,10000,20000,30000,40000,50000]
* times_algo = [2e-07,5e-07,1.3e-06,4.5e-06,2.22e-05,0.0004893,0.0017502,0.0369939,0.146127,0.572828,1.25735,2.20588,3.51983];


# 2 benchmarking for Selection sort:
* I took input of Random number between 0 and 999.
* I took input sizes from 5,10,20...upto 50000.
* input_sizes = [5, 10, 20, 50, 100, 500, 1000, 5000,10000,20000,30000,40000,50000]
* times_algo = [5e-07,1.3e-06,2.2e-06,9.5e-06,3.08e-05,0.000627,0.0023517,0.0569425,0.217667,0.90598,1.97542,3.48149,5.37219]


# 3 benchmarking for Bubble sort :
* I took input of Random number between 0 and 999.
* I took input sizes from 5,10,20...upto 30000.
* input_sizes = [5, 10, 20, 50, 100, 500, 1000, 5000,10000,20000,30000,40000,50000]
* times_algo = [8e-07, 2.2e-06,2.6e-06, 1.45e-05, 6.66e-05, 0.001408, 0.0057132, 0.150659,0.585995,2.34572,5.23766,9.30433,22.0952];



# Benchmark All Algorithms File
* Python File For plot Input Vs Time
[plot time vs input](plot_time_vs_input.ipynb)

![benchmark_sorting_algorithms](benchmark_sorting_algorithms.png)


# Selection Sort Correctness Argument
To demonstrate that the Selection Sort algorithm correctly sorts an array, we can use the concept of a loop invariant. A loop invariant is a condition that is true before and after each iteration of a loop. For Selection Sort, we can define the loop invariant as:
At the start of the I th iteration, the portion of the array before index I is sorted, and every element in this portion is less than or equal to all elements in the unsorted portion arr[i..n-1].
# Proof of Correctness:
1. Initialization:
    - Before any iterations occur, the sorted portion of the array is effectively empty, which we consider trivially sorted. Therefore, the loop invariant holds at the start of the process.
2. Maintenance:
    - At each iteration, the algorithm identifies the smallest element in the unsorted part of the array and swaps it with the first element of the unsorted portion. This ensures that after each swap, the element at position i is in its correct position.
    - After this swap, the portion of the array up to i is sorted, as the smallest element from the remaining unsorted section has been moved to its correct place. The remaining unsorted portion still satisfies the invariant, as no elements in it are smaller than those already placed in the sorted section.
3. Termination:
    - When the loop finishes, the entire array has been processed, and the invariant tells us that the entire array is now sorted. Since every element has been compared and placed in the correct position, the algorithm has correctly sorted the array.

# Time Complexity:
- Worst-case and best-case: The algorithm always performs \(O(n^2)\) comparisons and swaps because it goes through the entire array for each element, even if the array is already sorted.
- Space Complexity: \(O(1)\), as the algorithm performs the sorting in place without requiring additional space.
By following the steps of initialization, maintenance, and termination, we can see that Selection Sort is guaranteed to work correctly, placing each element in its proper place while maintaining a sorted portion of the array. The argument relies on the fact that at each step, the smallest element is moved to the appropriate position, and this ensures that the sorted section grows correctly and that no elements are left unsorted.




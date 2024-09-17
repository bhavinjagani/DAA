# Problem 0
x = fib(n)</br>
    if n == 0</br>
        return 0</br>
    if n == 1</br>
         return 1</br>
    return fib(n-1) + fib(n-2)</br>


##  Call Stack for fib(5):
1.	fib(5):	Calls fib(4) and fib(3)
2.	fib(4):	Calls fib(3) and fib(2)
3.	fib(3): Calls fib(2) and fib(1)
4.	fib(2): Calls fib(1) and fib(0)
5.	fib(1): Returns 1
6.	fib(0): Returns 0
At this point, fib(2) returns 1 + 0 = 1
7.	fib(2) returns 1 from the previous call stack.
8.	fib(3) continues by calling fib(1) again (returns 1), so fib(3) returns 1 + 1 = 2
9.	fib(4) continues by calling fib(2) again (returns 1), so fib(4) returns 2 + 1 = 3
10.	fib(5) continues by calling fib(3) again (returns 2), so fib(5) returns 3 + 2 = 5


# Problem 1
### Code for Problem 1 is [`problem1.0.cpp`](problem1.0.cpp)</br>
### Prove the time complexity of the algorithms
The algorithm merges K sorted arrays, each of size N, into a single sorted array</br>
Step 1: Merging all elements from the K arrays into a single vector (result).</br>
Step 2: Sorting the merged vector using an insertion sort algorithm within each loop of K.
Step-by-Step Time Complexity Analysis
**Merging the Arrays (Outer Loop)**</br>
In this step, iterating through each array and pushing all its elements into the result vector. This step has the following time complexity:
*	Outer Loop (over K arrays):
*	loop through each of the K arrays of size N, appending elements to the result vector.
*	Time complexity for this step: O(K * N) because you are visiting each element once from all arrays.
**Insertion Sort (Inner Loop)**
After appending the elements of each array, performing insertion sort on the entire result vector at every stage. The time complexity of insertion sort is as follows:
*	Insertion Sort:
*	The time complexity of insertion sort in the worst case is O(m^2), where m is the size of the array to be sorted.
Analyzing the Whole Process
Merging the arrays is done in O(K * N) time.
Sorting complexity: O((K * N)^2).

### Comment on way's you could improve your implementation

Use std::sort() or Merge Sort:
* Instead of using insertion sort, use std::sort() which uses a more efficient sorting algorithm (Timsort in most cases, which has a time complexity of O(n log n)).
*	After merging the arrays into a single vector, you can sort the vector in O(K * N log(K * N)) time.

# Problem 2

### Code for Problem 2 is [`problem2.0.cpp`](problem2.0.cpp)

## Prove the time complexity of the algorithms

**Step-by-Step Time Complexity Analysis**
1.	Outer Loop:
	while loop that iterates through the vector, comparing each element to its next element. This loop runs as long as i is less than nums.size() - 1.
2.	erase() Operation:
	The erase(nums.begin() + i) operation removes the element at position i and shifts all subsequent elements to the left by one position. The time complexity of erase() for a vector is O(n).

3. **Best Case** :
*	In this case, the loop runs O(n) times, where n is the size of the vector. There are no erase operations in this scenario.
*	Best-case time complexity: O(n).
2. **Worst Case (All Duplicates)**:
*	If every element is a duplicate, you will call erase() for every element except the first one.
*	The erase() operation takes O(n - i) for each iteration, where n is the size of the vector and i is the current index.
*	In the worst case, the time complexity is approximately: O(n+(n−1)+(n−2)+⋯+1)=O(n2)O(n + (n - 1) + (n - 2) + \dots + 1) = O(n^2)O(n+(n−1)+(n−2)+⋯+1)=O(n2)
*	Worst-case time complexity: O(n^2).
3. **Average Case:**
*	The average case is somewhere between the best and worst cases. If the array has a mix of duplicates and unique elements, the number of erase() operations will be fewer than in the worst case.
*	The time complexity would still depend on how often you call erase(), and it could vary between O(n) and O(n^2).

## Optimization Suggestion
To improve the time complexity, avoid the erase() operation and use a two-pointer technique instead, which has linear time complexity O(n).

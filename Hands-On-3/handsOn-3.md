# Hands-On 3

function x = f(n)
   x = 1;
   for i = 1:n
        for j = 1:n
             x = x + 1;

1) Find the runtime of the algorithm mathematically (I should see summations).

This function has two nested loops, each running from 1 to n

* The outer loop runs n times, iterating over i = 1 to n.
* For each iteration of the outer loop, the inner loop runs n times, iterating over j = 1 to n.
So, in total, the number of operations is the product of the iterations of the two loops.

# We can express this summations as  
T(n)=
$$
\sum_{i=1}^n \sum_{j=1}^n 1
$$ 
we can interpreted this as:
* For each iteration of the outer loop which runs n times, the inner loop runs n times.
* Therefore, the inner loop executes 𝑛 operations for each of the 𝑛 iterations of the outer loop.

# let's simplify the double summation:
T(n)=
$$
\sum_{i=1}^n n = n*n = n^n
$$ 
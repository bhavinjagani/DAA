# Hands-On 3

function x = f(n)</br>
   x = 1;</br>
   for i = 1:n</br>
        for j = 1:n</br>
             x = x + 1;</br>

1) Find the runtime of the algorithm mathematically.
![ans1](ans1.jpg)</br>

2) Time this function for various n e.g. n = 1,2,3.... You should have small values of n all the way up to large values. Plot "time" vs "n" (time on y-axis and n on x-axis). Also, fit a curve to your data, hint it's a polynomial. 
**ANS 2**
![time_VS_N](time_VS_n.png)</br>

3) Find polynomials that are upper and lower bounds on your curve from #2. From this specify a big-O, a big-Omega, and what big-theta is.
**ANS 3**
Big-O: 𝑂(𝑛^2 ),which means the upper bound of the algorithm is quadratic.</br>
Big-Omega: Ω(𝑛^2),meaning the lower bound is also quadratic.</br>
Big-Theta: Θ(𝑛^2),meaning the runtime is exactly 𝑛^2.</br>
**ANS 4**
4) Find the approximate (eye ball it) location of "n_0" . Do this by zooming in on your plot and indicating on the plot where n_0 is and why you picked this value. Hint: I should see data that does not follow the trend of the polynomial you determined in #2.</br>
![N_)](N_0.png)

* Why n_0=50? 
For 𝑛 < 50,the measured times closely follow the quadratic fit.</br>
After 𝑛 0 = 50 n 0 ​ =50, there is noticeable fluctuation and deviation in the measured runtime.</br>

# If I modified the function to be:</br>
x = f(n)</br>
   x = 1;</br>
   y = 1;</br>
   for i = 1:n</br>
        for j = 1:n</br>
             x = x + 1;</br>
        y = i + j;</br>

4) Will this increate how long it takes the algorithm to run (e.x. you are timing the function like in #2)?</br>
**ANS 4**</br>
Adding the line y = i + j; will not change the overall time complexity. The operation y = i + j; is still O(1) and runs inside the nested loops, so the number of operations remains n^2 .

5) Will it effect your results from #1?</br>
Not a remarkable effect as adding one summation line will not increase significant time as it take constant time O(1).

It does not generate a remarkable effect. Adding one summation line will not significantly increase time, as it takes constant time O(1).
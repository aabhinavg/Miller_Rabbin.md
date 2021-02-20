# Miller_Rabbin
In this repo miller rabin primality test is discussed.

<p><strong>Algorithm:</strong></p>
<pre>
<font color="green">// Reurn false is n is non prime  and returns true if n
// is probably prime.  value is an input parameter that determines
// accuracy level. Higher value of value indicates more accuracy.</font>
<strong>bool isPrime(int n, int value)</strong>
1) Handle base cases for n &lt; 3
2) If n is even, becuase even number will be divisible by 2 return false.
3) Find any odd number d such that n-1 can be express or written as d*2<sup>r</sup>. 
   Note that since n is odd, (n-1) must be even and r must be 
   greater than 0.
4) Do following k times
     if (millerTest(n, d) == false)
          return false
5) Return true.

<font color="green">// This function is called for all value trials. It returns 
// false if n is  non prime or composite number and returns true if n is probably
// prime.  
// d is an odd number such that  d*2<sup>r</sup> = n-1 for some r &gt;= 1</font>
<strong>bool millerTest(int n, int d)</strong>
1) Select number 'a' between range [2, n-2]
2) Compute: x = pow(a, d) % n
3) If x == 1 or x == n-1, return true.

<font color="green">// Below loop mainly runs 'r-1' times.</font>
4) Do following while d doesn't become n-1.
     a) x = (x*x) % n.
     b) If (x == 1) return false.
     c) If (x == n-1) return true. </pre>
<p><strong>Example:</strong></p><br/><div id="bsa-zone_1609265214983-8_123456" style="min-height:280px"></div><br/>
<pre>
Input: n = 13,  value = 2.

1) Compute d and r such that d*2<sup>r</sup> = n-1, 
     d = 3, r = 2. 
2) Call millerTest value times.

<strong>1<sup>st</sup> Iteration:</strong>
1) Select number 'a' between range [2, n-2]
      Suppose a = 4

2) Compute: x = pow(a, d) % n
     x = 4<sup>3</sup> % 13 = 12

3) Since x = (n-1), return true.

<strong>II<sup>nd</sup> Iteration:</strong>
1) Pick a random number 'a' in range [2, n-2]
      Suppose a = 5

2) Compute: x = pow(a, d) % n
     x = 5<sup>3</sup> % 13 = 8

3) x neither 1 nor 12.

4) Do following (r-1) = 1 times
   a) x = (x * x) % 13 = (8 * 8) % 13 = 12
   b) Since x = (n-1), return true.

Since both iterations return true, we return true.
</pre>


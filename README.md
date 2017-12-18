# Chapter11
#### 0) Time
Modify the example `Time` class (which can add and subtract with operator overloading) so all the overloaded operators are implemented using friend functions.
#### 1) Complex
Define a `Complex` class that represents a complex number and overloads arithmetic and stream operators:
`
Enter a complex number (q to quit):
real: 10
imaginary: 12
c is (10, 12i)
complex conjugate is (10, -12i)
a is (3, 4i)
a + c is (13, 16i)
a - c is (-7, -9i)
a * c is (-18, 76i)
2 * c is (20, 24i)
Enter a complex number (q to quit):
real: q
`
#### 2) Random Walk
Create a `Vector` class that is used in the Random Walk problem, which takes a given location and moves a certain distance in a random direction (a step) and counts the amount of steps it takes to get a given distance:
`
Enter target distance: 50
Enter step length: 10
After 5 steps, the subject has the following location:
(x, y) = (49.2404, 8.68241)
or
(m, a) = (50, 10)
Average outward distance per step: 10
`

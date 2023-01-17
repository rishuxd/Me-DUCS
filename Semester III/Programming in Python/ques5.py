"""
5.Write a function that finds the sum of the n terms of the following series. Import the factorial function created in question4.

    1–x2/2!+x4/4!–x6/6!+…xn/n!
"""

import math
 
def Series( x , n ):
    sum = 1
    term = 1
    y = 2
    for i in range(1,n):
        fct = 1
        for j in range(1,y+1):
            fct = fct * j

        term = term * (-1)
        m = term * math.pow(x, y) / fct
        sum = sum + m
        y += 2

    return sum
 
x = int(input("Enter the number : "))
n = int(input("Enter the value of n : "))
print('%.4f'% Series(x, n))
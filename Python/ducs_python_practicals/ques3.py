"""
3. Write a Python function to find the nth term of Fibonacci sequence and its factorial. Return the result as a list.
"""

fibolist = [0,1]
mylist = list()

def fibo(n):
    for i in range(3, n + 1):
        value = fibolist[i - 2] + fibolist[i - 3]
        fibolist.append(value)

def factorial(num):
    mylist.append(num)
    fact = 1
    for i in range(1, num):
        fact = fact * i
    mylist.append(fact)

n = int(input("Enter the Nth number : "))
fibo(n)
factorial(fibolist[n-1])
print(fibolist)
print(mylist)
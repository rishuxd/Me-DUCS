"""
6.Consider a tuple t1 = {1,2,5,7,9,2,4,6,8,10}.Write a program to perform following
operations:
"""

"""
a)Print another tuple whose values are even numbers in the given tuple.
"""
t1 = (1,2,5,7,9,2,4,6,8,10)
l1 = list()
length = len(t1)
for i in range(0, length, 1):
    if(t1[i] % 2 == 0):
        l1.append(t1[i])
t3 = tuple(l1)
print("Even number present in the given tuple :",t3)

"""
b)Concatenate a tuple t2 = (11,13,15) with t1.
"""
t2=(11,13,15)
t4 = t1 + t2
print("Concatenated tuple is :", t4)

"""
c)Return maximum and minimum value from this tuple.
"""
max = t4[0]
min = t4[0]
for i in range(1, len(t4), 1):
    if(t4[i]>max):
        max = t4[i]
    if(t4[i]<min):
        min = t4[i]
print("Maximum :",max, "\tMinimum :", min)
"""
4.Write a function that takes a number (>=10) as an input and return the digits of the number as a set.
"""

def myfun( num ):
    if(num >= 10):
        thisset = set()
        while(num > 0):
            thisset.add(num%10)
            num = num//10
        return thisset
    else:
        print("Your number is less than 10.")    

a = int(input("Enter the number : "))
print(myfun(a))
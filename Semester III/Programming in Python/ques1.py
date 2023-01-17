"""
1.Write a function that takes the lengths of three sides: side1, side2 and side3 of the triangle as the input from the user using input function and return the area and perimeter of the triangle as a tuple. Also, assert that sum of the length of any two sides is greater than the third side.
"""

def triangle(a, b, c):
    s = (a+b+c)/2
    area = (s*(s-a)*(s-b)*(s-c))**0.5
    perimeter = 2*s
    t = (perimeter, area)
    return t

def triangleCheck(a,b,c):
    if((b+c)>a):
        print("side2 + side3 : ", b+c, " > ", " side1 = ", a)
    if((a+c)>b):
        print("side1 + side3 : ", a+c, " > ", " side2 = ", b)
    if((a+b)>c):
        print("side1 + side2 : ", a+b, " > ", " side3 = ", c)

a = float(input("Enter the length of side1 : "))
b = float(input("Enter the length of side2 : "))
c = float(input("Enter the length of side3 : "))

print("Perimeter & Area of the triangle : ",triangle(a,b,c))

triangleCheck(a,b,c)
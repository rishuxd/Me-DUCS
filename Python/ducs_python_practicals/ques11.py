"""
h)accept 2 lists and find the common members in them.
"""
x = int(input("Enter the number of elements in list1 : "))
list1 = []
for i in range(x):
    n = int(input("Enter the element : "))
    list1.append(n)


y = int(input("Enter the number of elements in list2 : "))
list2 = []
for i in range(y):
    n = int(input("Enter the element : "))
    list2.append(n)


for i in list1:
    for j in list2:
        if(i == j):
            print(i, "is common.")
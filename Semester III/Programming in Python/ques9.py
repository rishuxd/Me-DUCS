"""
9.Use dictionary to store marks of the students in 4 subjects.Write a function to
find the name of the student securing highest percentage.(Hint:Names of
students are unique).
"""
dict = {}

number_of_student = int(input("Enter the number of students: "))
for i in range(number_of_student):
    name = input("Enter the name of student: ")
    per = 0.0
    for j in range(4):
        print("Enter the marks in subject ", j+1,": ")
        marks = float(input(""))
        per += marks
    per = per/4
    dict[name] = per
    
def highest():
    a = -1
    for i in dict:
        a = max(dict[i], a)
    for i in dict:
        if(dict[i] == a):
            print(i,"has the highest percentage of", a, ".")

highest()

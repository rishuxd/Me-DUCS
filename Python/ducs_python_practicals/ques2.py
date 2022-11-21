"""
2.Considera showroom of electronic products, where there are various salesmen. Each salesman is given a commission of 5%, depending on the sales made per month. In case the sale done is less than 50000, then the salesman is not given any commission. Write a function to calculate total sales of a salesman in a month, commission and remarks for the salesman. Sales done by each salesman per week is to be provided as input. Use tuples/list to store data of salesmen.

Assign remarks according to the following criteria:

Excellent: Sales>=80000
Good: Sales>=60000and<80000
Average: Sales>=40000and<60000
WorkHard: Sales<40000
"""

def sales_done(mylist):
    a, b= mylist
    print("Name : ", a)
    print("Weekly sale : ", b)
    print("Monthly sale : ", b*4)
    y = 0
    z = ""
    if(b*4 > 50000):
        print("Comission : ", b*4/20)
    else:
        print("Comission : ", 0)

    if(b*4 > 80000):
        print("Remark : Excellent")
    elif(b*4<80000 and b*4>=60000):
        print("Remark : Good")
    elif(b*4<60000 and b*4>=40000):
        print("Remark : Average")
    else:
        print("Remark : Work Hard")

noofsalesmen = int(input("Enter the number of salesmen : "))
salesmen_data = []

for i in range(noofsalesmen):
    a = input("Name : ")
    b = float(input("Sales per week : "))
    salesmen_data.append([a,b])

print("----------------------")

for i in salesmen_data:
    print(sales_done(i))
    print("----------------------")

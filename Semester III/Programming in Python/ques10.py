"""
10.Write a function that takes a sentence as input from the user and calculates the frequency of each letter.
Use a variable of dictionary type to maintain the count.
"""
frequency = {}
def freq(s):
    for i in s:
        if i in frequency:
            frequency[i] += 1
        else:
            frequency[i] = 1
    del frequency[' ']
    
s = input("Enter your sentence : ")
freq(s)
print(frequency)
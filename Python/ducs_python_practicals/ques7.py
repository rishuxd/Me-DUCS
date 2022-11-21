print("1 : Find length of your string.")
print("2 : Return maximum of three strings.")
print("3 : Replace all vowels with #.")
print("4 : Find number of words in your string.")
print("5 : Check if it is palindrome or not.")

n = int(input("Enter what to do : "))

if(n == 1):
    s = input("Enter your string : ")
    print("String's length : ", s.length())

elif(n == 2):
    s1 = input("Enter your 1st string : ")
    s2 = input("Enter your 2nd string : ")
    s3 = input("Enter your 3rd string : ")
    print("Maximum : ", max(s1, s2, s3))

elif(n == 3):
    s = input("Enter your string : ")
    vl = ['A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u']
    ns = []
    slist = list(s)
    for char in slist:
        for char1 in vl:
            if char == char1:
                ns.append("#")
                break
        else:
            ns.append(char)
    print(''.join(ns))  

elif(n == 4):
    c = 0 
    s = input("Enter your string : ")
    for i in s:
        if(i == " "):
            c += 1
    print("Number of words : ", c)

elif(n == 5):
    s = input("Enter your string : ")
    def isPalindrome(s):
        for i in range(0, int(len(s)/2)):
            if s[i] != s[len(s)-i-1]:
                return False
        return True

    ans = isPalindrome(s)
    if (ans):
        print("Yes, Its a Palindrome.")
    else:
        print("No, Its not a Palindrome.")

else:
    print("You entered a invalid option.")


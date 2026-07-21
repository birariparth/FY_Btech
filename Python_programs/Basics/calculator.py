print("Calculator")
a = int(input("Enter 1st number "))
b = int(input("Enter 2nd number "))
c = input("Operation you want to perform ")

if '+' in c:
    d = a + b
    print("Sum = ",d)
elif '-' in c:
    d = a - b
    print("Subtraction = ",d)
elif '*' in c:
    d = a * b
    print("Multiplication = ",d)
elif '/' in c:
    if b != 0:
        d = a / b
        print("Division = ",d)
    else:
        print("Error")
else:
    print("Please enter valid input")
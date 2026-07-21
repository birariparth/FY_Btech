num = int(input("Enter number to find factorial of: "))

if num < 0:
    print("Invalid")
elif num == 0:
    print("Factorial = 1")
else:
    factorial = 1
    for i in range(1, num + 1):
        factorial *= i
    print("Factorial = ", factorial)
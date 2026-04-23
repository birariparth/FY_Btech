num = input("Enter numbers sperated by space: ").split()
for n in num:
    a = list(n)
    b = a.copy()
    b.reverse()
    if a==b:
        print("Pallindrome")
    else:
        print("Not pallindrome")


numbers = [121, 1111, 1234, 4224]
for numb in numbers:
    temp = numb
    rev = 0
    while temp > 0:
        digit = temp % 10
        rev = rev*10 + digit
        temp = temp//10
    if numb==rev:
        print("Pallindrome")
    else:
        print("Not pallindrome")
for i in range(1, 6):
    for j in range(1, i + 1):
        print(j, end='')
    print("\n")


text = "Python,Java,C++,C#,R "
langs = text.split(",")
print(langs)
result = " | ".join(langs)
print(result)

for i in range(5, 0, -1):
    for j in range(1, i + 1):
        print(j, end='')
    print("\n")
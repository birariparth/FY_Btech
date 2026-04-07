fruits = ["apple", "banana", "cherry", "date"]

# Display elements
print("List:", fruits)
# Length
print("Length:", len(fruits))
# Insert element at index 1
fruits.insert(1, "mango")
print("After insert:", fruits)
# Delete by value
fruits.remove("banana")
print("After remove:", fruits)
# Delete by index
del fruits[0]
print("After del[0]:", fruits)
# pop() - removes last element
popped = fruits.pop()
print("Popped:", popped)
print("Final list:", fruits)
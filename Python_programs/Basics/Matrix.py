A = [[1,2], [3,4]]
B = [[3,5], [9,1]]

def print_array(arr):
    for row in arr:
        print(row)

def array_operation(A,B,op):
    result = []
    for i in range(len(A)):
        row = []
        for j in range(len(A[i])):
            if op == 'add':
                row.append(A[i][j]+B[i][j])
            elif op == 'sub':
                row.append(A[i][j] - B[i][j])
            elif op == 'mul':
                row.append(A[i][j] * B[i][j])
            elif op == 'div':
                row.append(A[i][j] / B[i][j])
        result.append(row)
    return result

print("Array A:")
print_array(A)
print("\nArray B:")
print_array(B)

print("\nAddition (A + B):")
print_array(array_operation(A, B, 'add'))


print("\nSubtraction (A - B):")
print_array(array_operation(A, B, 'sub'))


print("\nMultiplication (A * B):")
print_array(array_operation(A, B, 'mul'))


print("\nDivision (A / B):")
print_array(array_operation(A, B, 'div'))


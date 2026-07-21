print ("hello world")
wird = 'word'
print (wird)   #comment
'''
multi line comment which leaves space in output box or teminal
'''
#input("\n\nPress enter to exit")    #waits for user to exit

var = 100
print(var)
del var
#print(var)     aint defined as var doenst exist

x = 10
y = 0.3
print(type(x))
print(type(y))

#casting
z = str(10)
print("z = ", z)

a,b,c = 10,20,30
print(a,b,c)


#local variables
def sum(X,Y):        # just like function
    sum = X+Y
    return sum
print(sum(5,10))


#global variables
e = -4
E = 4
def sum():
    sum = e+E
    return sum
print(sum())

for i in range(2,5):
    print(i)           #prints i 2,3,4

list = [ 10, 'asfda', 12.3]
tuple = ( 'asdas', 43, 132.3)

#conversion

a = int(10)
a = float(10)    #conversion done
 
# Online Python compiler (interpreter) to run Python online.
# Write Python 3 code in this online editor and run it.
print("Taking inputs when size is not given")

s = str(input())
temp = s.split(' ')
print(temp)

arr = []
for i in range(len(temp)):
    arr.append(int(temp[i]))

print(arr)
print(type(arr[0]))


# taking input when number is coma separated
print("Taking input when the values are coma separeted")
s = str(input())
temp = s.split(',')
print(temp)

arr = []

for i in range(len(temp)):
    arr.append(int(temp[i]))

print(arr)
print(type(arr[0]))
class Dogs:
    count = 1  # Class variable (static member)

# Accessing and modifying the class variable
dog1 = Dogs()
dog2 = Dogs()

print(Dogs.count)  # Output: 1

dog1.count = dog1.count + 1
print(Dogs.count)  # Output: 1
print(dog2.count)  # Output: 1

# Modify the class variable correctly
Dogs.count += 1
print(Dogs.count)  # Output: 2
print(dog1.count)  # Output: 2
print(dog2.count)  # Output: 2

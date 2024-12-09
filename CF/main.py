import random

# Generate an array of random length (e.g., 5 to 15) with values 0, 1, or 2
array = [random.choice([0, 1, 2]) for _ in range(random.randint(5, 15))]

# Ensure the array contains at least one `1`
if 1 not in array:
    array[random.randint(0, len(array) - 1)] = 1

print(len(array))
print(" ".join(list(map(str,array))))

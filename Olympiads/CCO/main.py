import sys

def generate_worst_case(n):
    assert n % 2 == 0, "n must be even for pairing colors"
    colors = []
    # Assign each color to exactly two positions
    for i in range(1, n//2 + 1):
        colors.append(i)
        colors.append(i)
    print(n)
    print(' '.join(map(str, colors)))

if __name__ == "__main__":
    n = 500000  # Must be even
    generate_worst_case(n)
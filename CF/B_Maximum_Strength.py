def calculate_strength(x, y):
    # Convert numbers to strings and pad with leading zeros if necessary
    x_str = str(x)
    y_str = str(y)
    max_len = max(len(x_str), len(y_str))
    x_str = x_str.zfill(max_len)
    y_str = y_str.zfill(max_len)
    
    # Calculate the sum of absolute differences between corresponding digits
    strength = sum(abs(int(x_str[i]) - int(y_str[i])) for i in range(max_len))
    return strength

def max_weapon_strength(L, R):
    # Consider pairs of L, R and their neighbors to maximize the strength
    candidates = [(L, R), (L, R-1), (L+1, R)]
    
    # Compute the maximum possible strength from these pairs
    max_strength = 0
    for x, y in candidates:
        if L <= x <= R and L <= y <= R:  # Ensure the numbers are within bounds
            max_strength = max(max_strength, calculate_strength(x, y))
    
    return max_strength

# Example usage:
L = 179
R = 239
print(max_weapon_strength(L, R))

def find_contributing_indices(n, k):
    result = []
    # We start with the segment [1, n]
    l, r = 1, n
    
    while r - l + 1 >= k:
        # Calculate the middle index
        m = (l + r) // 2
        # If the length of the segment is odd, this m is a contributing index
        if (r - l + 1) % 2 == 1:
            result.append(m)
        
        # Move to the next smaller segments
        # If the segment length is odd, we can split into [l, m-1] and [m+1, r]
        # If the segment length is even, we split into two equal halves
        if (r - l + 1) % 2 == 0:
            # Even length segment -> split into two halves
            r = m - 1
        else:
            # Odd length segment -> process recursively into two subsegments
            l = m + 1
            r = m - 1

    return result

# Example usage
n = 7
k = 3
contributing_indices = find_contributing_indices(n, k)
print(contributing_indices)

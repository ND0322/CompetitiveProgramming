s = int(input())
e = int(input())

if s in range(20,24) and e in range(6,10) and 24 - s + e in range(8,11):
    print("Healthy")
else:
    print("Unhealthy")
f = open("in.txt", "w")
f.write("200000 199999\n")

for i in range(1,200001):
    f.write(str(i) + " " + str(i+1) + "\n")
f.close()

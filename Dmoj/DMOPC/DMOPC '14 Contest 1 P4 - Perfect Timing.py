import datetime

sa,sb = map(int,input().split(" "))

ea, eb = map(int,input().split(" "))

l = list(map(int,input().split(":")))

#print(l)
d = datetime.datetime(l[0], l[1], l[2], l[3], l[4], l[5])
delta = abs(sa-ea) + abs(sb-eb)

d = d+datetime.timedelta(seconds = delta)

print(f"{d.year:04d}" + ":" + f"{d.month:02d}" + ":" + f"{d.day:02d}" + ":" + f"{d.hour:02d}" + ":" + f"{d.minute:02d}" + ":" + f"{d.second:02d}")




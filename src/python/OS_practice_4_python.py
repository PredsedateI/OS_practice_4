import time
from datetime import timedelta

def f(i):
    if i == basic:
        return 0
    temp = 0
    for n in range(100000000):
        temp += 2 * b + c - i
    return f(i - 1) + temp

with open("langs/temp/hub.txt") as fin:
    basic, b, c, i = [int(x) for x in next(fin).split()]

ts = time.monotonic()
result = f(i)
te = time.monotonic()
dt = te - ts

fout = open("langs/temp/python.txt", "w")
fout.write(str(result) + ' ' + str(round(dt, 3)))
fout.close()

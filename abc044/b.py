import itertools
import statistics
import math

w = input()

v = [0]*26

for _ in w:
    print(_)
    v[int(_)]+=1

ok=True
for _ in v:
    if _ %2 != 0:
        print("No")
        ok=False

if ok:
    print("Yes")
else:
    print("No")

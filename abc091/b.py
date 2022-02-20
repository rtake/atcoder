import itertools
import statistics
import math

n = int(input())
s = [input() for i in range(n)]
m = int(input())
t = [input() for i in range(m)]

dict={}

for _ in s:
    dict[s]+=1


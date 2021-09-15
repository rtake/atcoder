import itertools
import statistics
import math

n=int(input())

p=0
for i in range(1,int(math.sqrt(n))+1):
  if(n%i == 0):
    p=max(i,p)

print(p+int(n/p)-2)

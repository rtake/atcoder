import itertools
import statistics
import math

n=int(input())
xy=[map(int,input().split()) for _ in range(n)]
x,y=[list(i) for i in zip(*xy)]

dist=list()

for itr in itertools.permutations( range(n) ):
  d=0

  for i in range(n-1):
    d_x=(x[itr[i+1]]-x[itr[i]])**2
    d_y=(y[itr[i+1]]-y[itr[i]])**2
    d+=math.sqrt(d_x+d_y)

  dist.append(d)

print(statistics.mean(dist))

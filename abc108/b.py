import itertools
import statistics
import math

x1,y1,x2,y2=list(map(int,input().split()))

a=x2-x1
b=y2-y1

c=-b
d=a
x3=x2+c
y3=y2+d

e=-d
f=c
x4=x3+e
y4=y3+f

print(x3,y3,x4,y4)
#print(a,b,c,d,e,f)

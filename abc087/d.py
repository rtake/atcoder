n,m=map(int, input().split())

lrd=[map(int, input().split()) for _ in range(m)]
l,r,d=[list(_) for _ in zip(*lrd)]


for _ in l:
  print(_)

for _ in r:
  print(_)

# ab=[list(map(int, input().split())) for _ in range(m)]

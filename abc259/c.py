s=input()
t=input()

ss=list()
tt=list()

cnt=1
for i in range(len(s)-1):

  if s[i+1] == s[i]:
    cnt+=1
  else:
    ss.append((s[i],cnt))
    cnt=1;

if cnt > 0:
  ss.append((s[len(s)-1],cnt))
    

cnt=1
for i in range(len(t)-1):

  if t[i+1] == t[i]:
    cnt+=1
  else:
    tt.append((t[i],cnt))
    cnt=1;

if cnt > 0:
  tt.append((t[len(t)-1],cnt))

"""
for key,value in tt:
  print (key, value)
"""

if len(ss) != len(tt):
  print("No")
  exit(0)

for i in range(len(tt)):
  s_key=ss[i][0]
  s_val=ss[i][1]

  t_key=tt[i][0]
  t_val=tt[i][1]

  if t_key != s_key:
    print("No")
    exit(0)

  if s_val > t_val:
    print("No")
    exit(0)

  if s_val == 1 and t_val != 1:
    print("No")
    exit(0)
  
    
print("Yes")
exit(0)

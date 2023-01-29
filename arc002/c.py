n=int(input())
s=input()

abxy="ABXY"

ans=1e9

for i in range(4):
  for j in range(4):
    l=abxy[i]+abxy[j]

    for ii in range(4):
      for jj in range(4):
        r=abxy[ii]+abxy[jj]

        if l == r:
          continue

        cnt=0
        idx=0

        while idx < n:
          if idx == n-1:
            cnt+=1
            break

          if s[idx]+s[idx+1] == l or s[idx]+s[idx+1] == r:
            idx+=2
          else:
            idx+=1

          cnt+=1

        ans=min(ans,cnt)

print(ans)

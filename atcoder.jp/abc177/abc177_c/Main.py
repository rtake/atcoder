n=int(input())
a=list(map(int,input().split()))
mod=10**9+7

sum1=sum(a)
sum1-=a[0]

ans=0
for i in range(n-1):
  ans=(ans+a[i]*sum1)%mod
  sum1-=a[i+1]

print(ans)

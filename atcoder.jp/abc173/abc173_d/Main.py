N = int(input()) # print (N)
# A = [int(input()) for i in range(N)]

A = list(map(int,input().split()))
A.sort()
A.reverse()

ans=A[0]
for i in range(1,N//2):
        ans += 2*A[i]

if N%2 == 1:
        ans += A[N//2]

print(ans)
#include <stdio.h>

int main(void)
{
  int N,M,i,ans;
  scanf("%d %d",&N,&M);
  int L[M],R[M];
  int L_max = 1,R_min = N;
  for(i = 0;i < M;i++) {
    scanf("%d %d",&L[i],&R[i]);    
  }
  for(i = 0;i < M;i++) {
    if(L_max < L[i]) L_max = L[i];
    if(R_min > R[i]) R_min = R[i];
  }
  ans = R_min - L_max + 1;
  if(ans >= 0) printf("%d\n",ans);
  else printf("0\n");
  return 0;
}
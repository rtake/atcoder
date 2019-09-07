# include <stdio.h>

int main(void)
{
  int i,N;
  scanf("%d",&N);
  int A[N],B[N],C[N];
  
  for(i = 0;i < N;i++) scanf("%d",&A[i]);
  for(i = 0;i < N;i++) scanf("%d",&B[i]);
  for(i = 0;i < N - 1;i++) scanf("%d",&C[i]);
  
  int sum = 0;
  for(i = 0;i < N;i++) {
  	sum += B[ A[i] - 1];

    if(i > 0 && A[i] == A[i - 1] + 1) sum += C[ A[i - 1] - 1];
   
  }
  
  printf("%d\n",sum);

  return 0;
}
  
int main(void)
{
  int A,B;
  scanf("%d %d",&A,&B);
  if(A <= 5) printf("0\n");
  else if(A >= 6 && A <= 12) printf("%d\n",B / 2);
  else if(A >= 13) printf("%d\n",B);
  return 0;
}
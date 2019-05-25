int main(void)
{
  int r,D,i;
  long long int x;
  scanf("%d %d %d",&r,&D,&x);
  for(i = 0;i < 10;i++) {
    x = r * x - D;
    printf("%lld\n",x);
  }

  return 0;
}
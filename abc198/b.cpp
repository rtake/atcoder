# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }

lint C(lint n, lint k) {
  if(n == k) { return 1; }
  else if(n < k) { return 0; }
  else if(k == 0) { return 1; }
  else if(k == 1) { return n; }
  else return C(n-1,k-1) + C(n-1,k);
}

lint P(lint n, lint k) {
  if(k == 1) { return n; }
  return (n*(P(n-1,k-1)%1000000007)%1000000007);
}


int main() {
  lint N;
  scanf("%lld", &N);

  if(N == 0) {
    printf("Yes\n");
    return 0;
  }

  while(N %10 == 0) { N /= 10; }

  int l=to_string(N).length();
  char nstr[l];
  sprintf(nstr, "%lld", N);

  vector<int> ivec;

  for(int i=0;i<l;i++) {
    if(nstr[i] == 'x') {
      break;
    } else {
      ivec.push_back((int)nstr[i]);
    }
  }    


  int size=(int)ivec.size();
  for(int i=0;i<size;i++) {
    if(ivec[i] == ivec[size-i-1]) { continue; }
    else {
      printf("No\n");
      return 0;
    }
  }

  printf("Yes\n");
  return 0;
}

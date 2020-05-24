# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }

map<lint,int> mp;

lint f(lint x, lint a, lint b, lint c, lint d) {
  // printf("x %d\n",x);

  lint ret=1000000000000000000;

  if(x == 0) { mp[0] = 0; return 0; }
  else if(x == 1) { mp[1] = 1; return d; }

  if(mp[x] > 0) { return mp[x]; }

  mp[x] = ret;

  if(x%2 == 0) { ret = min(f(x/2,a,b,c,d) + a,ret); }
  if(x%3 == 0) { ret = min(f(x/3,a,b,c,d) + b,ret); }
  if(x%5 == 0) { ret = min(f(x/5,a,b,c,d) + c,ret); }

  ret = min(f(x-1,a,b,c,d)+d, ret );
  mp[x] = ret;
  return ret;
}


int main() {
  lint t; cin >> t;

  for(lint i=0;i<t;i++) {
    lint n,a,b,c,d; cin >> n >> a >> b >> c >> d;
    mp.clear();
    cout << min(f(n,a,b,c,d),f(n+1,a,b,c,d)+d) << endl;
  }

  return 0;
}

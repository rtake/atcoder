# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x*y)/gcd(x,y); }


int main() {
  lint a,b,c,d,ans; cin >> a >> b >> c >> d; 
  lint c_num = b/c-(a-1)/c, d_num = b/d-(a-1)/d, cd_num = (b/lcm(c,d))-(a-1)/lcm(c,d);
  /*
  cout << c_num << endl;
  cout << d_num << endl;
  cout << cd_num << endl;
  */
  ans = (b-a+1) - (c_num + d_num - cd_num);
  cout << ans << endl;
  return 0;
}

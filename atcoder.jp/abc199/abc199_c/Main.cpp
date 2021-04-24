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
  lint n; scanf("%lld", &n);
  char s[2*n]; scanf("%s", s);
  lint q; scanf("%lld", &q);
  vector<lint> t(q), a(q), b(q);
  for(lint i=0;i<q;i++) { scanf("%lld %lld %lld\n", &t[i], &a[i], &b[i]); }

  string lstr=string(s).substr(0,n), rstr=string(s).substr(n,n); // cout << lstr << endl << rstr << endl;

  for(lint i=0;i<q;i++) {
    if(t[i] == 2) {
      swap(lstr, rstr);

      /*
      string buf=lstr;
      lstr=rstr;
      rstr=buf; // swap
      */
    } else if(t[i] == 1) {

      if(a[i] <= n) {
        if(b[i] <= n) {
          swap(lstr[a[i]-1], lstr[b[i]-1]);
        } else {
          swap(lstr[a[i]-1], rstr[b[i]-n-1]);
        }
      } else {
        if(b[i] <= n) {
          swap(rstr[a[i]-n-1], lstr[b[i]-1]);
        } else {
          swap(rstr[a[i]-n-1], rstr[b[i]-n-1]);
        }
      }


      // string str=lstr+rstr; // cout << str << endl;
      // swap(str[a[i]-1], str[b[i]-1]);


      /*
      char buf_a=str[a[i]-1], buf_b=str[b[i]-1];
      str[a[i]-1]=buf_b; // cout << buf_a << endl;
      str[b[i]-1]=buf_a; // cout << buf_b << endl;
      */

      /*
      char buf_a=str[a[i]-1];
      str[a[i]-1]=str[b[i]-1]; // cout << buf_a << endl;
      str[b[i]-1]=buf_a; // cout << buf_b << endl;
      */

      // lstr=str.substr(0,n);
      // rstr=str.substr(n,n);
    }

    // cout << lstr + rstr << endl;
  }

  cout << lstr + rstr << endl;

  return 0;
}
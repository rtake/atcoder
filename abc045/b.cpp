# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }


int main() {
  string sa,sb,sc; cin >> sa >> sb >> sc;
  int index_a=0,index_b=0,index_c=0,size_a=(int)sa.size(),size_b=(int)sb.size(),size_c=(int)sc.size();

  char next='a';
  while(true) {
    if(next == 'a') {
      if(index_a > size_a-1) { cout << "A\n"; break; }
      else { next = sa[index_a]; index_a++; }
    } else if(next == 'b') {
      if(index_b > size_b-1) { cout << "B\n"; break; }
      else { next = sb[index_b]; index_b++; }
    } else if(next == 'c') {
      if(index_c > size_c-1) { cout << "C\n"; break; }
      else { next = sc[index_c]; index_c++; }
    }
  }

  return 0;
}

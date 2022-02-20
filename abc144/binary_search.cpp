# include <bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<ll> a={1,2,3,4,5,6,7,8,9,10};

bool isok(ll index, ll key) {
  if (a[index] >= key) return true;
  else return false;
}

ll binary_search(ll key) { 
  ll ng=-1,ok=(ll)a.size();

  while(abs(ok-ng) > 1) {
    ll m=(ok+ng)/2;
    if(isok(m,key)) ok=m;
    else ng=m;
  }

  return ok;
}


int main() {

  cout<<binary_search(8)<<endl;

  return 0;
}

# include <bits/stdc++.h>
# include <atcoder/all>

typedef long long ll;

using namespace std;
using namespace atcoder;

#define rep(i,n) for (ll i=0; i<(ll)(n);i++)
#define ALL(a)  (a).begin(),(a).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;

#ifdef LOCAL
#define dump(x) do{} while(0)
#endif


struct Eratosthenes {
  vector<bool> isprime;
  vector<ll> minfactor;

  Eratosthenes(ll n) : isprime(n+1,true),minfactor(n+1,-1) {
    isprime[1]=false;
    minfactor[1]=1;

    for (ll p=2;p<=n;p++) {
      if (!isprime[p]) continue;

      minfactor[p]=p;

      for(ll q=p*2;q<=n;q+=p) {
        isprime[q] = false;
        if (minfactor[q] == -1) minfactor[q]=p;
      }
    }
  }

  vector< pair<ll,ll> > factorize(ll n) {
    vector< pair<ll,ll> > res;

    while (n > 1) {
      ll p=minfactor[n];
      ll exp=0;

      while(minfactor[n] == p) {
        n/=p;
        exp++;
      }

      res.emplace_back(p, exp);
    }

    return res;
  }  

};


int main() {




  return 0;
}

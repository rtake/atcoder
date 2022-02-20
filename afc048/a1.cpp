# include <bits/stdc++.h>
// # include <atcoder/all>

typedef long long ll;

using namespace std;
// using namespace atcoder;

#define rep(i,n) for (ll i=0; i<(ll)(n);i++)
#define ALL(a)  (a).begin(),(a).end()

ll gcd(ll x, ll y) { return (x==0)? y : gcd(y%x,x); }
ll lcm(ll x, ll y) { return x/gcd(x,y)*y; }
ll P(ll n, ll k) { return (k==1) ? n : n*(P(n-1,k-1)); }

ll mod=1000000007;
ll comb[2000][2000];
ll nCr(ll n, ll r) {
  if(n==r) return comb[n][r] = 1;
  if(r==0) return comb[n][r] = 1;
  if(r==1) return comb[n][r] = n;
  if(comb[n][r]) return comb[n][r]%mod;
  return comb[n][r] = (nCr(n-1,r) + nCr(n-1,r-1))%mod;
}

ll inv(ll x) {
  ll res=1, k=mod-2;
  while(k>0) {
    if(k&1 == 1) res=(res*x)%mod;
    x=(x*x)%mod;
    k/=2;
  }
  return res;
}

ll nCr_mod_memo[1010101];

void nCr_mod_init() {
  nCr_mod_memo[0]=1;
  for(ll i=1;i<1010101;i++) nCr_mod_memo[i]=(nCr_mod_memo[i-1]*i)%mod;
}

ll nCr_mod(ll n, ll k) {
  // ll a=1,b=1;
  // for(int i=0;i<k;i++) a=(a*(n-i))%mod;
  // for(int i=0;i<k;i++) b=(b*(k-i))%mod;

  ll a=nCr_mod_memo[n];
  ll b=nCr_mod_memo[n-k];
  ll c=nCr_mod_memo[k];
  ll bc=(b*c)%mod;

  return (a*inv(bc))%mod;
}


/*
ll binpower(ll a, ll b) {
  ll ans=1;
  while (b != 0) {
    if (b%2 == 1) ans = (ans*a)%mod;
    a=(a*a)%mod;
    b/=2;
  }
  return ans;
}
*/


ll binpower(ll a, ll b, ll m) {
  ll ans=1;

  a%=m;

  while (b != 0) {
    if (b%2 == 1) ans = (ans*a)%m;
    a=(a*a)%m;
    b/=2;
  }
  return ans;
}


bool judgeIentersected
(ll ax, ll ay, ll bx, ll by, ll cx, ll cy, ll dx, ll dy) {

  ll ta = (cx - dx) * (ay - cy) + (cy - dy) * (cx - ax);
  ll tb = (cx - dx) * (by - cy) + (cy - dy) * (cx - bx);
  ll tc = (ax - bx) * (cy - ay) + (ay - by) * (ax - cx);
  ll td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx);

  return tc * td < 0 && ta * tb < 0;
  // return tc * td <= 0 && ta * tb <= 0; // 端点を含む場合
};



int main() {
  ll t;
  cin>>t;

  string atcoder="atcoder";
  ll inf=1e9;

  rep(i,t) {
    string s;
    cin>>s;

/*
    if(s == atcoder) {
      cout<<-1<<endl;
      continue;
    }
*/

    ll ans=inf;

    vector< vector<ll> > G(26);

    rep(j,s.length()) {
      G[s[j]-'a'].push_back(j);
    }

    bool fin=false;

    rep(j,7) {
      if(j >= s.length()) {
        ans=-1;
        fin=true;
        break;
      }

      if(atcoder[j] < s[j]) {
        ans=0;
        fin=true;
        break;
      } else if(atcoder[j] == s[j]) {
        continue;
      }

      for(ll k=25;k>=0;k--) {

        if(k < atcoder[j]-'a') {
          ans=-1;
          fin=true;
          break;
        } else if(atcoder[j]-'a' == k) {
          sort(ALL(G[k]));

          rep(l,G[k].size()) {
            // cout<<j<<" "<<G[k][l]<<" "<<atcoder[j]-'a'<<" "<<k<<endl;

            if(j < G[k][l]) {
              // cout<<j<<" "<<G[k][l]<<" "<<atcoder[j]-'a'<<" "<<k<<endl;
              ans=1;
              fin=true;
              break;
            }
          }

          if(fin) break;

        } else if(atcoder[j]-'a' < k) {
          sort(ALL(G[k]),greater<ll>());
        
          rep(l,G[k].size()) {
            if(j < G[k][l]) {
              ans=1;
              fin=true;
              break;
            }
          }
        }
      }

      if(fin) break;
    }

/*
    if(!fin) {
      if(s.length() > atcoder.length()) ans=0;
      else ans=-1;
    }
*/

    cout<<ans<<endl;
  }

  return 0;
}

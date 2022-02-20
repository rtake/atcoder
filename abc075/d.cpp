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


ll binpower(ll a, ll b) {
  ll ans=1;
  while (b != 0) {
    if (b%2 == 1) ans = (ans*a)%mod;
    a=(a*a)%mod;
    b/=2;
  }
  return ans;
}


int main() {
  int n,k;
  cin>>n>>k;
  vector<ll> x(n),y(n);
  rep(i,n) cin>>x[i]>>y[i];

  vector< pair<ll,ll> > xy(n);
  rep(i,n) xy[i].first=x[i],xy[i].second=y[i];

  ll ans=9e18;

  for(ll i0=0;i0<n;i0++) {
    for(ll i1=i0+1;i1<n;i1++) {
      ll xl=min(xy[i0].first,xy[i1].first);
      ll xu=max(xy[i0].first,xy[i1].first);
      ll yl=min(xy[i0].second,xy[i1].second);
      ll yu=max(xy[i0].second,xy[i1].second);

      int cnt=2;
      for(ll i2=i1+1;i2<n;i2++) {
        if(xl <= xy[i2].first && xy[i2].first <= xu) {
          if(yl <= xy[i2].second && xy[i2].second <= yu) {
            cnt++;
          }
        }
      }

      if(cnt >= k) ans=min(ans,(yu-yl)*(xu-xl));
    }
  }

  for(ll i0=0;i0<n;i0++) {
    for(ll i1=i0+1;i1<n;i1++) {
      for(ll i2=i1+1;i2<n;i2++) {
        ll xl=min(min(xy[i0].first,xy[i1].first),xy[i2].first);
        ll xu=max(max(xy[i0].first,xy[i1].first),xy[i2].first);
        ll yl=min(min(xy[i0].second,xy[i1].second),xy[i2].second);
        ll yu=max(max(xy[i0].second,xy[i1].second),xy[i2].second);

        int cnt=3;
        for(ll i3=i2+1;i3<n;i3++) {
          if(xl <= xy[i3].first && xy[i3].first <= xu) {
            if(yl <= xy[i3].second && xy[i3].second <= yu) {
              cnt++;
            }
          }
        }

        if(cnt >= k) ans=min(ans,(yu-yl)*(xu-xl));
      }
    }
  }

  for(ll i0=0;i0<n;i0++) {
    for(ll i1=i0+1;i1<n;i1++) {
      for(ll i2=i1+1;i2<n;i2++) {
        for(ll i3=i2+1;i3<n;i3++) {

          ll xl=min(min(xy[i0].first,xy[i1].first),min(xy[i2].first,xy[i3].first));
          ll xu=max(max(xy[i0].first,xy[i1].first),max(xy[i2].first,xy[i3].first));
          ll yl=min(min(xy[i0].second,xy[i1].second),min(xy[i2].second,xy[i3].second));
          ll yu=max(max(xy[i0].second,xy[i1].second),max(xy[i2].second,xy[i3].second));
          
          int cnt=4;
          for(ll i4=0;i4<n;i4++) {
            if(i0 == i4 || i1 == i4 || i2 == i4 || i3 == i4) continue;

            if(xl <= xy[i4].first && xy[i4].first <= xu) {
              if(yl <= xy[i4].second && xy[i4].second <= yu) {
                cnt++;
                // printf("%lld %lld %lld %lld\n", i0, i1, i2, i3);
              }
            }
          }

          if(cnt >= k) ans=min(ans,(yu-yl)*(xu-xl));
        }
      }
    }
  }

  cout<<ans<<endl;

  return 0;
}

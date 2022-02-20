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
  int n;
  cin>>n;

  vector<int> v(200,0);

  for(int i=2;i<=n;i++) {

    int test=i;
    for(int j=2;j*j<=i;j++) {
      while(test%j == 0) {
        test/=j;
        v[j]++;
      }
    }

    if(test > 1) v[test]++;
  }

  vector<int> w(200,0);
  for(int i=2;i<=n;i++) if(v[i] > 0) w[v[i]]++;

  vector<int> cum(200,0);
  rep(i,200) cum[i+1]=cum[i]+w[i];


  int ans=0;
  ans+=(cum[200]-cum[74]);
  ans+=(cum[200]-cum[24])*(cum[200]-cum[2]-1);
  ans+=(cum[200]-cum[14])*(cum[200]-cum[4]-1);
  ans+=((cum[200]-cum[4])*(cum[200]-cum[4]-1)*(cum[200]-cum[2]-2))/2;
  
  cout<<ans<<endl;


/*
  int ans=0;
  ans+=(cum[200]-cum[74])*(cum[200]-cum[74]-1)/2;
  ans+=(cum[200]-cum[74])*(cum[73]-cum[1]-1);

  ans+=(cum[200]-cum[24])*(cum[200]-cum[24]-1)/2;
  ans+=(cum[200]-cum[24])*(cum[23]-cum[2]-1);

  ans+=(cum[200]-cum[14])*(cum[200]-cum[14]-1)/2;
  ans+=(cum[200]-cum[14])*(cum[13]-cum[4]-1);

  ans+=(cum[200]-cum[4])*(cum[200]-cum[4]-1)/2*(cum[3]-cum[2]);
  ans+=(cum[200]-cum[4])*(cum[200]-cum[4]-1)/2*(cum[200]-cum[4]-2)/3;

  // cout<<cum[200]-cum[4]<<endl;
  // cout<<cum[4]-cum[1]<<endl;

  // for(int i=1;i<=200;i++) cout<<v[i]<<" "; cout<<endl;
  // for(int i=1;i<=200;i++) cout<<w[i]<<" "; cout<<endl;
  // for(int i=1;i<=200;i++) cout<<cum[i]<<" "; cout<<endl;

  cout<<ans<<endl;
*/

  return 0;
}

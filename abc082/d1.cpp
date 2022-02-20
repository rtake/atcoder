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
  int x,y;
  string s;
  cin>>s>>x>>y;

  int len=s.length();
  
  
  vector< vector<int> > v(2,vector<int>(1,0));
  int is_x=1;
  int cnt=0;

  rep(i,len) {
    if(s[i] == 'T') {
      v[is_x].push_back(cnt);
      cnt=0;
      is_x^=1;
    } else cnt++;
  }

  if(cnt > 0) v[is_x].push_back(cnt);

  vector<int> dpx,dpy;
  dpx=dpy=vector<int>((len+1)*2,-1);

  dpx[v[1][0]+len]=0;
  dpy[v[0][0]+len]=0;
  dpy[-v[0][0]+len]=0;

  // for(auto itr:v[1]) cout<<itr<<" "; cout<<endl;
  // for(auto itr:v[0]) cout<<itr<<" "; cout<<endl;

///*
  for(int i=1;i<(int)v[1].size();i++) {
    for(int j=0;j<=2*len;j++) {
      if(dpx[j] == i-1) {
        dpx[j+v[1][i]]=dpx[j-v[1][i]]=dpx[j]+1;
      }
    }
  }
//*/

///*
  for(int i=1;i<(int)v[0].size();i++) {
    for(int j=0;j<=2*len;j++) {
      if(dpy[j] == i-1) {
        dpy[j+v[0][i]]=dpy[j-v[0][i]]=dpy[j]+1;
      }
    }
  }
//*/

  // rep(j,2*len+1) cout<<dpx[j]<<" "; cout<<endl;
  // rep(j,2*len+1) cout<<dpy[j]<<" "; cout<<endl;

  // cout<<v[0].size()<<" "<<v[1].size()<<endl;

  ///*
  if(dpx[x+len] == (int)v[1].size()-1) {
    if(dpy[y+len] == (int)v[0].size()-1) {
      cout<<"Yes"<<endl;
    } else cout<<"No"<<endl;
  } else cout<<"No"<<endl;
  //*/

  return 0;
}

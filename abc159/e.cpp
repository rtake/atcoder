# include <bits/stdc++.h>
// # include <atcoder/all>

typedef long long lint;
typedef long long ll;

using namespace std;
// using namespace atcoder;

#define rep(i,n) for (lint i=0; i<(lint)(n);i++)
#define ALL(a)  (a).begin(),(a).end()

lint gcd(lint x, lint y) { return (x==0)? y : gcd(y%x,x); }
lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }
lint P(lint n, lint k) { return (k==1) ? n : n*(P(n-1,k-1)); }

lint mod=1000000007;
lint comb[2000][2000];
lint nCr(lint n, lint r) {
  if(n==r) return comb[n][r] = 1;
  if(r==0) return comb[n][r] = 1;
  if(r==1) return comb[n][r] = n;
  if(comb[n][r]) return comb[n][r]%mod;
  return comb[n][r] = (nCr(n-1,r) + nCr(n-1,r-1))%mod;
}

lint inv(lint x) {
  lint res=1, k=mod-2;
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

ll nCr_mod(lint n, lint k) {
  // lint a=1,b=1;
  // for(int i=0;i<k;i++) a=(a*(n-i))%mod;
  // for(int i=0;i<k;i++) b=(b*(k-i))%mod;

  ll a=nCr_mod_memo[n];
  ll b=nCr_mod_memo[n-k];
  ll c=nCr_mod_memo[k];
  ll bc=(b*c)%mod;

  return (a*inv(bc))%mod;
}


// https://ei1333.github.io/luzhiled/snippets/structure/union-find.html
struct UnionFind {
  vector<ll> data; // store root | (-size)
 
  UnionFind(ll sz) { data.assign(sz, -1); }
 
  bool unite(ll x, ll y) {
    x=find(x);
    y=find(y);
    if(x == y) return false;
    if(data[x] > data[y]) swap(x,y);
    data[x] += data[y]; // size
    data[y] = x; // root
    return true;
  }
 
  int find(int k) {
    if(data[k] < 0) return k;
    return data[k]=find(data[k]);
  }
 
  int size(int k) { return (-data[find(k)]); }
};


ll binpower(ll a, ll b) {
  ll ans=1;
  while (b != 0) {
    if (b%2 == 1) ans = (ans*a)%mod;
    a=(a*a)%mod;
    b/=2;
  }
  return ans;
}


// Segment tree
lint op(lint a, lint b) { return a^b; }
lint e() { return 0LL; }


int main() {
  int h,w,k;
  cin>>h>>w>>k;
  vector<string> s(h);
  rep(i,h) cin>>s[i];

  int ans=1e9;
  for(int bit=0;bit<(1<<(h-1));bit++) {
    int ndiv=0, cur=0, cnt=0, white=0, maxwhite=0;
    bool left_white;
    deque<int> dq0,dq1;

    ndiv=0;
    rep(i,h) {
      if(bit&(1<<i)) ndiv++;
    }

    dq0=deque<int>(ndiv+1,0);
    // dq1=deque<int>(0);

///*
    for(int j=0;j<w;j++) {
      dq1=deque<int>(0);

      cur=dq0.front();
      dq0.pop_front();

      white=0, maxwhite=0;
      rep(i,h) {
        if(s[i][j] == '1') white++;

        if(bit&(1<<i)) {
          maxwhite=max(maxwhite,white);
          white=0;
        }
      }

      maxwhite=max(maxwhite,white);

      if(maxwhite > k) {
        // cout<<"break"<<endl;
        // cout<<endl;
        break;
      }

      rep(i,h) {
        left_white=true;

        if(s[i][j] == '1') {
          cur++;

          if(cur > k) {
            dq1=deque<int>(ndiv+1,0);
            cnt++;
            j--;
            left_white=false;
            break;
          }
        }

///*
        if(bit&(1<<i)) {
          dq1.push_back(cur);
          left_white=false;
          cur=dq0.front();
          dq0.pop_front();
        }
//*/

      }

      if(left_white) dq1.push_back(cur);

      dq0=dq1;
    }

    if(maxwhite > k) continue;

    ans=min(ans,cnt+ndiv);
    // cout<<ans<<" "<<ndiv<<endl;
  }

  cout<<ans<<endl;

  return 0;
}

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

// ll gcd(ll x, ll y) { return (x==0)? y : gcd(y%x,x); }
// ll lcm(ll x, ll y) { return x/gcd(x,y)*y; }
ll P(ll n, ll k) { return (k==1) ? n : n*(P(n-1,k-1)); }

ll mod=1000000007;

ll comb[2000][2000];
ll nCr(ll n, ll r) {
  if(n==r) return comb[n][r] = 1;
  if(r==0) return comb[n][r] = 1;
  if(r==1) return comb[n][r] = n;
  // if(comb[n][r]) return comb[n][r]%mod;
  if(comb[n][r]) return comb[n][r];
  // return comb[n][r] = (nCr(n-1,r) + nCr(n-1,r-1))%mod;
  return comb[n][r] = (nCr(n-1,r) + nCr(n-1,r-1));
}

//////////////////////////////////////////////////////////////////////
/*

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
  ll a=nCr_mod_memo[n], b=nCr_mod_memo[n-k], c=nCr_mod_memo[k];
  ll bc=(b*c)%mod;
  return (a*inv(bc))%mod;
}

*/
//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
// https://atcoder.jp/contests/abc234/editorial/3223 
///*

vector<ll> fac,finv,inv;

void binom_init() {
  const ll MAX=5010;

  fac.resize(MAX);
  finv.resize(MAX);
  inv.resize(MAX);
  fac[0] = fac[1] = 1;
  inv[1] = 1;
  finv[0] = finv[1] = 1;
  for(int i=2; i<MAX; i++){
      fac[i] = fac[i-1]*i%mod;
      inv[i] = mod-mod/i*inv[mod%i]%mod;
      finv[i] = finv[i-1]*inv[i]%mod;
  }
}

ll binom(ll n, ll r){
    if(n<r || n<0 || r<0) return 0;
    return fac[n]*finv[r]%mod*finv[n-r]%mod;
}

//*/
//////////////////////////////////////////////////////////////////////



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


int main() {
  ll n,m,e; cin>>n>>m>>e;
  vector<ll> u(e),v(e);
  rep(i,e) cin>>u[i]>>v[i],u[i]--,v[i]--;

  ll q; cin>>q;
  vector<ll> x(q); rep(i,q) cin>>x[i],x[i]--;

  set<ll> st; rep(i,q) st.insert(x[i]);


  UnionFind uf(n+m);
  vector<ll> light(n+m,0);

  rep(i,m) light[i+n]=1;

  rep(i,e) {
    if(st.find(i) == st.end()) {

      if(u[i] >= n && v[i] >= n) {

        // uf.unite(u[i],v[i]);

      } else if(u[i] >= n) {

        light[v[i]]=1;
        light[uf.find(v[i])]=1;
        uf.unite(u[i],v[i]);

      } else if(v[i] >= n) {

        light[u[i]]=1;
        light[uf.find(u[i])]=1;
        uf.unite(u[i],v[i]);

      } else {

        if(light[uf.find(u[i])] > 0 || light[uf.find(v[i])] > 0) {
          uf.unite(u[i],v[i]);
          light[uf.find(u[i])]=light[uf.find(v[i])]=1;
        } else {
          uf.unite(u[i],v[i]);
        }

      }

/*
      if(u[i] < n || v[i] < n) {

        if(u[i] >= n) {
          light[v[i]]=1;
        }

        if(v[i] >= n) {
          light[u[i]]=1;
        }

        ll u_root=uf.find(u[i]);
        ll v_root=uf.find(v[i]);

        uf.unite(u[i],v[i]);

        if(light[u_root] > 0 || light[v_root] > 0) {
          ll root=uf.find(u[i]);
          light[root]=1;
        }
      }
*/

    }
  }


/*
  rep(i,n+m) cout<<light[i]<<" ";
  cout<<endl;

  rep(i,n+m) cout<<uf.size(i)<<" ";
  cout<<endl;
*/



  ll sum=0;

  for(ll i=n;i<n+m;i++) sum+=(uf.size(i)-1);
  

  vector<ll> ans(q,0); 

  for(ll j=q-1;j>=0;j--) {

/*
    printf("j %lld, u %lld, v %lld\n", j, u[x[j]], v[x[j]]);
*/

    ans[j]=sum;

    ll i=x[j];

/*
    rep(i,n+m) cout<<uf.find(i)<<" ";
    cout<<endl;

    rep(i,n+m) cout<<light[i]<<" ";
    cout<<endl;
*/

      if(u[i] >= n && v[i] >= n) {

        // uf.unite(u[i],v[i]);

      } else if(u[i] >= n) {

        // light[v[i]]=1;

        if(light[uf.find(v[i])] > 0) {

        } else {
          light[uf.find(v[i])]=1;
          sum+=uf.size(v[i]);
        }

        uf.unite(u[i],v[i]);

      } else if(v[i] >= n) {

        // light[u[i]]=1;

        if(light[uf.find(u[i])] > 0) {

        } else {
          light[uf.find(u[i])]=1;
          sum+=uf.size(u[i]);

        }

        uf.unite(u[i],v[i]);


      } else {

        if(light[uf.find(u[i])] > 0 && light[uf.find(v[i])] > 0) {
          uf.unite(u[i],v[i]);
          // light[uf.find(u[i])]=light[uf.find(v[i])]=1;

        } else if(light[uf.find(u[i])] > 0) {
          sum+=uf.size(v[i]);

          uf.unite(u[i],v[i]);
          light[uf.find(u[i])]=light[uf.find(v[i])]=1;

        } else if(light[uf.find(v[i])] > 0) {
          sum+=uf.size(u[i]);

          uf.unite(u[i],v[i]);
          light[uf.find(u[i])]=light[uf.find(v[i])]=1;

        } else {
          uf.unite(u[i],v[i]);
        }

/*
        if(light[uf.find(u[i])] > 0 || light[uf.find(v[i])] > 0) {
          uf.unite(u[i],v[i]);
          light[uf.find(u[i])]=light[uf.find(v[i])]=1;
        } else {
          uf.unite(u[i],v[i]);
        }
*/

      }



/*
    if(u[x[i]] < n || v[x[i]] < n) {

      if(u[x[i]] >= n) {
        if(light[uf.find(v[x[i]])] == 0) {
          sum+=uf.size(v[x[i]]);
        } 
      }

      if(v[x[i]] >= n) {
        if(light[uf.find(u[x[i]])] == 0) {
          sum+=uf.size(u[x[i]]);
        } 
      }

      if(u[x[i]] < n && v[x[i]] < n) {
        if(light[uf.find(u[x[i]])] > 0 && light[uf.find(v[x[i]])] > 0) {

        } else if(light[uf.find(u[x[i]])] > 0) {
          sum+=uf.size(v[x[i]]);

        } else if(light[uf.find(v[x[i]])] > 0) {
          sum+=uf.size(u[x[i]]);

        }

      }

      ll u_root=uf.find(u[x[i]]);
      ll v_root=uf.find(v[x[i]]);

      uf.unite(u[x[i]],v[x[i]]);

      if(light[u_root] > 0 || light[v_root] > 0) {
        ll root=uf.find(u[x[i]]);
        light[root]=1;
      }

    }
*/

  }


  for(auto a:ans) cout<<a<<endl;

  return 0;
}

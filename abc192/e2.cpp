#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, M, X, Y;
int A[101010], B[101010], T[101010], K[101010];
// vector<pair<int, pair<int,int>>> E[101010];
vector<pair<int, pair<int,int>>> E(101010);
//---------------------------------------------------------------------------------------------------
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
int vis[101010];
ll D[101010];
ll dijk() {
    rep(i, 0, N) D[i] = infl;
    rep(i, 0, N) vis[i] = 0;

    min_priority_queue<pair<ll, int>> que;

    D[X] = 0;
    que.push({ 0, X });

    while (!que.empty()) {
        auto q = que.top(); que.pop();

        ll cst = q.first;
        int cu = q.second;

        if (cu == Y) return D[Y];

        if (vis[cu]) continue;
        vis[cu] = 1;

        fore(p, E[cu]) {
            int to = p.first;
            int T = p.second.first;
            int K = p.second.second;

            ll cst2 = (cst + K - 1) / K * K + T;
            if (chmin(D[to], cst2)) que.push({ D[to], to });
        }
    }

    return -1;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> X >> Y;
	X--; Y--;
	rep(i, 0, M) {
		cin >> A[i] >> B[i] >> T[i] >> K[i];
		A[i]--; B[i]--;

        E[A[i]].push_back({ B[i], {T[i], K[i]} });
        E[B[i]].push_back({ A[i], {T[i], K[i]} });
	}

    ll ans = dijk();
    cout << ans << endl;
}







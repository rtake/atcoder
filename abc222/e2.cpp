#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> A(M);
  for (int i = 0; i < M; i++){
    cin >> A[i];
    A[i]--;
  }
  vector<vector<pair<int, int>>> E(N);
  for (int i = 0; i < N - 1; i++){
    int U, V;
    cin >> U >> V;
    U--;
    V--;
    E[U].push_back(make_pair(i, V));
    E[V].push_back(make_pair(i, U));
  }
  vector<int> cnt(N - 1, 0);
  for (int i = 0; i < M - 1; i++){
    vector<int> pv(N, -1);
    vector<int> pe(N, -1);
    queue<int> Q;
    Q.push(A[i]);
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      for (auto P : E[v]){
        int w = P.second;
        if (w != pv[v]){
          pv[w] = v;
          pe[w] = P.first;
          Q.push(w);
        }
      }
    }
    for (int v = A[i + 1]; v != A[i]; v = pv[v]){
      cnt[pe[v]]++;
    }
  }
  int S = 0;
  for (int i = 0; i < N - 1; i++){
    S += cnt[i];
  }
  vector<long long> dp(S + 1, 0);
  dp[0] = 1;
  for (int i = 0; i < N - 1; i++){
    vector<long long> dp2(S + 1, 0);
    for (int j = 0; j <= S; j++){
      dp2[j] += dp[j];
      if (dp2[j] >= MOD){
        dp2[j] -= MOD;
      }

      if (j + cnt[i] <= S){
        dp2[j + cnt[i]] += dp[j];
        if (dp2[j + cnt[i]] >= MOD){
          dp2[j + cnt[i]] -= MOD;
        }
      }

    }

    swap(dp, dp2);

    for(int j=0;j<=S;j++) cout<<dp[j]<<" "; cout<<endl;

  }
  int ans = 0;
  for (int i = 0; i <= S; i++){
    if (i - (S - i) == K){
      ans = dp[i];
    }
  }
  cout << ans << endl;
}

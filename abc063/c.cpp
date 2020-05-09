# include <bits/stdc++.h>
using namespace std;

int n;
int s[100];

int solve() {
  int ret = 0;
  vector< vector<int> > dp( n, vector<int>(10,-1) );

  for(int i = 0;i < n;i++) {
    if(i > 0) {
      for(int j = 0;j < 10;j++) { dp[i][j] = dp[i-1][j]; } // init

      for(int j = 0;j < 10;j++) {
        if( dp[i-1][j] == -1 ) { continue; } // no value

        if( dp[i][(j + s[i]) % 10] < dp[i-1][j] + s[i] ) {
          dp[i][(j + s[i]) % 10] = dp[i-1][j] + s[i];
        }
      } // for all mods
    } 

    if( dp[i][s[i] %10] == -1 ) { dp[i][s[i] %10] = s[i]; } // no value
  } // for all s[i] elements

  for(int i = 1;i < 10;i++) { if(ret < dp[n-1][i]) ret = dp[n-1][i]; }
  return ret;
}


int main() {
  cin >> n;
  for(int i = 0;i < n;i++) { cin >> s[i]; }

  cout << solve() << endl;

  return 0;
}

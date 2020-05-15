# include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k; cin >> n >> k;
  vector<double> p(n,0); for(int i = 0;i < n;i++) { cin >> p[i]; }
  vector<double> e(n,0); for(int i = 0;i < n;i++) { e[i] = (p[i]+1)/2; }

  double sum=0,max;
  for(int i = 0;i < k;i++) { sum += e[i]; }

  max = sum;
  for(int i = 1;i+(k-1) < n;i++) {
    sum += (e[i+(k-1)] - e[i-1]);
    if(max < sum) { max = sum; }
  }

  //cout << max << endl;
  printf("%.10f\n",max);
  return 0;
}
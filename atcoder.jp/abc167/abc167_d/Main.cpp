# include <bits/stdc++.h>
using namespace std;

int main() {
  long long int n,k; cin >> n >> k;
  vector<int> a(n); for(long long int i = 0;i < n;i++) { cin >> a[i]; }

  int start,length = 0,point = 0,step = 0, mod;
  vector<int> scheck(n,-1); // start check

  if(k < n) {
    for(int i = 0;i < k;i++) { point = a[point]-1; }
    cout << point+1 << endl;
    return 0;
  }

  point = 0, step = 0;
  while(true) {
    if(scheck[point] == -1) { scheck[point] = step; point = a[point]-1; step++; }
    else if(scheck[point] >= 0) { start = point; step = scheck[point];  break; }
  } // start point and step for start

  length = 0;
  while(true) {
    length++;
    point = a[point]-1;
    if(point == start) { break; }
  } // loop length

  mod = (k-step)%length;

  point = start;
  for(int i = 0;i < length;i++) {
    if(i%length == mod) { break; }
    point = a[point]-1;
  } // solve

  cout << point+1 << endl;

  return 0;
}
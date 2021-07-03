# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }

lint C(lint n, lint k) {
  if(n == k) { return 1; }
  else if(n < k) { return 0; }
  else if(k == 0) { return 1; }
  else if(k == 1) { return n; }
  else return C(n-1,k-1) + C(n-1,k);
}

lint P(lint n, lint k) {
  if(k == 1) { return n; }
  return (n*(P(n-1,k-1)%1000000007)%1000000007);
}


/*
// quick sort for string //
int partition(vector<string> vec, int l, int r) {
  char pivot=vec[r][0];
  int pos=(l-1);

  for(int i=l; i<=r-1;i++) {
    if(vec[i][0] <= pivot) {
      pos++;
      swap(vec[pos], vec[i]);
    }
  }
  swap(&array[i + 1], &array[r]);
  return pos+1;
}

void quicksort_string(vector<string> vec, int l, int r) {
  if(vec[r][0] < vec[l][0]) {
    pivot = partition(vec, l, r)
    quicksort_string(vec, l, pivot-1)
    quicksort_string(vec, pivot+1, r)
  }
}
// quick sort for string end //
*/


int main() {
  int n,l; cin >> n >> l;
  vector< pair<char, string> > vec(n);
  for(int i=0;i<n;i++) {
    cin >> vec[i].second;
    vec[i].first = vec[i].second[0];
  }

  sort(vec.begin(), vec.end());
  for(auto x:vec) cout << x.second;
  cout << endl;

  // vector<string> s(n); for(int i=0;i<n;i++) { cin >> s[i]; }

  

  return 0;
}

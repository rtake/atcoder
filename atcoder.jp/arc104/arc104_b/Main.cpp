# include <bits/stdc++.h>

using namespace std;

int main(void) {
  int n;
  char s[5000];

  scanf("%d %s", &n, s);

  vector<int> a(n+1,0), t(n+1,0), c(n+1,0), g(n+1,0);

  for(int i=1;i<=n;i++) {
    a[i] = a[i-1];
    t[i] = t[i-1];
    c[i] = c[i-1];
    g[i] = g[i-1];

    if(s[i-1] == 'A') { a[i]++; }
    else if(s[i-1] == 'T') { t[i]++; }
    else if(s[i-1] == 'C') { c[i]++; }
    else if(s[i-1] == 'G') { g[i]++; }
  }

  long long int ans=0;
  for(int i=0;i<=n;i++) {
    for(int j=i-2;j>=0;j-=2) {

      if(a[i]-a[j] == t[i]-t[j] && c[i]-c[j] == g[i]-g[j]) { ans++; }
      /*
      if(a[i]>0 && t[i]>0 && a[i]-a[j] == t[i]-t[j]) { ans++; printf("%d %d\n", i, j); }
      else if(c[i]>0 && g[i]>0 && c[i]-c[j]>0 && c[i]-c[j] == g[i]-g[j]) { ans++; printf("%d %d\n", i, j); }
      else if(a[i]>0 && t[i]>0 && c[i]>0 && g[i]>0 && a[i]-a[j] == t[i]-t[j] && c[i]-c[j] == g[i]-g[j]) { ans++; printf("%d %d\n", i, j); }
      */
    }
  }


  cout << ans << endl;
  return 0;
}

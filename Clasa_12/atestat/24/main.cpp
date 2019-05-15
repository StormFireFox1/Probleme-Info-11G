#include <iostream>

using namespace std;

int t[101], n;

void S1(int &n, int t[101]) {
     cin >> n;
     for (int i = 1;i <= n; i++)
        cin >> t[i];
}

int S2(int n,int t[101],int k) {
  int nrfii = 0;
  for (int i = 1; i <= n; i++){
    if (t[i] == k) 
    nrfii++;
  }
  return nrfii;
}
int main() {
  S1(n, t);
  int m;
  cin >> m;
  for (int i = 1; i <= n; i++)
    if (S2(n, t, i) >= m)
      cout << i << " ";
  return 0;
}

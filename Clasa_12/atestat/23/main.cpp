#include <iostream>
using namespace std;
 struct arc {
     int a,b;
 };
  int gradext[30];
    int a[31][31],n;
    void S1 (int &n, int a[31][31]) {
        cin>>n;
        arc x;
        
            while (cin>>x.a>>x.b)
            a[x.a][x.b]=1;
        
    }
    int S2(int n,int v[30]) {
        int c=0;
        for (int i=0;i<=n;i++)
        if (v[i]) c++;
        return c;
    }
    int main () {
        int gradmax=0;
        S1(n,a);
        for (int i=1;i<=n;i++) {
            gradext[i]=S2(n,a[i]);
            if (gradext[i]>gradmax) gradmax=gradext[i];
            
        }
        cout<<gradmax<<endl;
        for (int i=1;i<=n;i++)
            if (gradext[i]==gradmax) cout<<i<<" ";
            
        return 0;
    }

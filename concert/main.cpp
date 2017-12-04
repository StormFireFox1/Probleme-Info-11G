#include<fstream>
#include<algorithm>

using namespace std;

ifstream fin("concert.in");
ofstream fout("concert.out");

int n, T, nr, s[101];
struct art {
    int t,ord;
} x[101];
int cmp(art A, art B)
{
    return A.t <= B.t;
}
int main()
{   fin >> n >> T;
    int i;
    for(i = 1;i <= n; i++)
    {   char v[7];
        fin >> v;
        int j = 0, a = 0, b = 0;
        while(v[j] != ':') 
            a = a * 10 + v[j++] - '0';
        a *= 60; j++;
        while(v[j] != '\0')
            b = b * 10 + v[j++] - '0';
        a += b;
        x[i].t = a;
     	x[i].ord= i;
    }
    sort(x + 1, x + n + 1, cmp);
    i = 1;
    while(i <= n && x[i].t <= T)
    {
        s[++nr] = x[i].ord;
        T -= x[i].t;
        ++i;
    }
    fout << nr << '\n';
    for(i = 1; i <= nr; i++)
        fout << s[i] << ' ';
	return 0;
}
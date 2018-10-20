#include <fstream>	
#include <queue>

using namespace std;
ifstream in("mexitate.in");
ofstream out("mexitate.out");

const int N = 400002;
const int MOD = 1000000007;

int n,m,k,l,f[N];
bool inh[N];	
long long p=1;
vector<int> a[N];
priority_queue<int> h;

void mex()
{
    while(f[-h.top()] != 0)	
    {
        inh[-h.top()] = false;
        h.pop();
    }
    p = p % MOD * (-h.top());
}
	
void nex(int starti, int startj, int fini, int finj)
{
    mex();	
    if(starti != fini)
    {
        for(int j = startj; j < startj + l; j++)
            f[a[fini][j]]++;

        for(int j = startj; j < startj + l; j++)
        {
            f[a[starti][j]]--;
            if(f[a[starti][j]] == 0 && a[starti][j] <= k * l + 1 && inh[a[starti][j]] == false)
            {
                h.push(-a[starti][j]);
                inh[a[starti][j]] = true;
            }
        }
    }
    else
    {
        for(int i = starti; i < starti + k; i++)
            f[a[i][finj]]++;
 
        for(int i = starti; i < starti + k; i++)	
        {
            f[a[i][startj]]--;
            if(f[a[i][startj]] == 0 && a[i][startj] <= k * l + 1 && inh[a[i][startj]] == false)
            {
                h.push(-a[i][startj]);
                inh[a[i][startj]] = true;
            }
        }
    }
}

int main()	
{
    in >> n >> m >> k >> l;
	if (n <= m)
    {
        for(int i = 1; i <= n; i++)
        {
            a[i].resize(m + 1);
            for(int j = 1; j <= m; j++)
            {
                in >> a[i][j];
                if(i <= k && j <= l)
                    f[a[i][j]]++;
            }
        }
    }
    else
    {
        swap(n,m);
        swap(k,l);

        for(int j = 1; j <= n; j++)
            a[j].resize(m + 1);
	
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                in >> a[j][i];
                if(i <= l && j <= k)
                    f[a[j][i]]++;
            }
        }
    }
    for(int i = 1; i <= l * k + 1; i++)
    {
        h.push(-i);
        inh[i] = true;
    }

    for(int i = 1; i <= n - k + 1; i++)
    {
        for(int j = 1; j <= m - l; j++)
            nex(i, j, i, j + l);
        if(i == n - k + 1)
            break;
        nex(i, m - l + 1, i + k, m - l + 1);
        i++;

        for(int j = m; j > l; j--)	
            nex(i, j, i, j - l);
	
        if(i == n - k + 1)
            break;
        nex(i, 1, i + k, 1);
    }
    mex();
    out << p % MOD;
    return 0;
}
#include <fstream>

using namespace std;

ifstream fin("permutari.in");
ofstream fout("permutari.out");

int n, v[11], k;

void afis()
{
	for(int i = 1; i <= n; i++)
	{
		fout << v[i] << " ";
	}
	fout << '\n';
}

int valid(int k)
{
  int i;
  for(i = 1; i < k; i++)
  {
    if(v[i] == v[k])
      return 0;
  }
  return 1;
}

void bt(int k) 
{
  if(k == n + 1)
    afis();
  else
  {
    for(int i = 1; i <= n; i++)
    {
      v[k] = i;
      if(valid(k))
        bt(k + 1);
    }
  }
}

int main()
{
  fin >> n;
  bt(1);
  return 0;
}

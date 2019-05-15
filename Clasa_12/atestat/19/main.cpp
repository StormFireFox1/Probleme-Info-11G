#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

char ss[251];
char v[] = "aeiou";
int n;

void s2(char s[21])
{
  int nr, j;
  nr = 0;
  for (j = 0; j < strlen (s); j++)
    if (strchr (v, s[j]))
      s[j] = '*';
}

int s1(char s[21])
{
  int j, m;
  m = strlen (s);
  for (j = 0; j < m / 2; j++)
    if (s[j] != s[m - 1 - j])
      return 0;
  return 1;
}

int main()
{
  int j, m, i;
  cin >> n;
  for (i = 1; i <= n; i++)
  {
      for (j = 0; j < 20; j++)
	    ss[j] = 0;
      cin >> ss;
      if (s1 (ss))
	  {
	    s2 (ss);
	    cout << ss << endl;
	  }
  }
  return 0;
}

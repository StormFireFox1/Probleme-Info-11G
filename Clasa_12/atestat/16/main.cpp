#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

char s[251], x[21];
int n;

void s2(char t[21])
{
  t[0] = t[0] - 32;
  t[strlen(t) - 1] = t[strlen(t) - 1] - 32;
}

int s1(char t1[21], char t2[21])
{
  int j, m;
  if (strstr(t2, t1) == t2)
    return 1;
  return 0;
}

int main()
{
  int j, m, i;
  cin.get(s, 250);
  cin.get();
  cin >> x;
  char *p = strtok(s, " ");
  while (p)
  {
    if (s1 (x, p) == 1)
	  s2(p);
    cout << p << " ";
    p = strtok(NULL, " ");
  }
  return 0;
}

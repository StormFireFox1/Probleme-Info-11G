#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;

struct nod
{
  int nr;
  nod *urm;
} *p, *d;
int
s2 (nod * &p)
{
  int m;
  m = p->nr;
  return m;
}

void
s1 (nod * &p, int k)
{
  if (p == NULL)
    {
      p = new nod;
      p->nr = k;
      p->urm = NULL;
    }
  else
    {
      nod *c;
      c = new nod;
      c->nr = k;
      c->urm = p;
      p = c;
    }
}

int
main ()
{
  int i, x, ok, xx, yy, y, n, okk;
  okk = 0;
  cin >> n;
  cin >> y;

  for (i = 1; i < n; i++)
    {
      cin >> x;
      yy = y;
      xx = x;
      ok = 0;
      while (yy != 0)
	{
	  if (y % 10 != x % 10)
	    {
	      ok = 1;
	      break;
	    }
	  yy = yy / 10;
	  xx = xx / 10;
	}
      if (ok == 0)
	{
	  okk = 1;
	  s1 (p, x);
	}
    }
  d = p;
  if (okk == 1)
    while (d)
      {
	cout << s2 (d) << " ";
	d = d->urm;
      }
  if (okk == 0)
    cout << "NU EXISTA";
  return 0;
}

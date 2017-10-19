#include <bits/stdc++.h>

using namespace std;
ifstream fin("intersectiesegmente.in");
ofstream fout("intersectiesegmente.out");
int main()
{
    float y1,y2,y3,y4,x1,x2,x3,x4;
    fin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    float m1=(y2-y1)/(x2-x1);
    float m2=(y4-y3)/(x4-x3);
    float x=(y3-y1+m1*x1-m2*x3)/(m1-m2);
    float y=y1+m1*(x-x1);
    if(x>x1&&x>x2)fout<<"NU";
    else if(x<x1&&x<x2)fout<<"NU";
    else if(y<y1&&y<y2)fout<<"NU";
    else if(x>y1&&x>y2)fout<<"NU";
    else if(x>x3&&x>x4)fout<<"NU";
    else if(x<x3&&x<x4)fout<<"NU";
    else if(y<y3&&y<y4)fout<<"NU";
    else if(x>y3&&x>y4)fout<<"NU";
    else fout<<"DA";

    return 0;
}
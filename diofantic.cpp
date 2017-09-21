int diofantic (int n, int s[], int a , int b, int c)
{ int total=0, d=n; 
 for(int i=1;i<n ;++i)
 {for(int j=i+1;j<=d ;++j)
 {if(a*s[i]*s[i]+b*s[j]*s[j]==c)
 {total+=2;d=j-1;break;}
 } 
 } 
 return total;
}
#include<stdio.h>
#include<conio.h>
#include<math.h>
long int ext_eucledian(long int m,long int b)
{
 long int a1=1,a2=0,a3=m,b1=0,b2=1,b3=b,q,t1,t2,t3;
 while(1)
 {
 if(b3==0)
 {
 return 0;
 }
 if(b3==1)
 {
DIGITAL SIGNATURES ALGORITHM
 if(b2<0)
 b2+=m;
 return b2;
 }
 q=a3/b3;
 t1=a1-(q*b1);
 t2=a2-(q*b2);
 t3=a3-(q*b3);
 a1=b1;
 a2=b2;
 a3=b3;
 b1=t1;
 b2=t2;
 b3=t3;
 }
}
long int power(long int a, long int j, long int c)
{
 long int f = 1;
 while (j > 0)
 {
 if (j % 2 == 1)
 f = (f * a) % c;
 a = (a * a) % c;
 j /= 2;
 }
 return f;
}
void main()
{
 long int p,q,g,x,hm,k,y,r,s,s1,w,u1,u2,v,v1,v2,v3;
 printf("enter the value of p:");
 scanf("%ld",&p);
 printf("enter the value of q:");
 scanf("%ld",&q);
 printf("enter the value of g:");
 scanf("%ld",&g);
 printf("enter the value of x:");
 scanf("%ld",&x);
 printf("enter the value of hm:");
 scanf("%ld",&hm);
 printf("enter the value of k:");
 scanf("%ld",&k);
 y=power(g,x,p);
 printf("\nvalue of y:%ld",y);
 r=power(g,k,p) % q;
 printf("\nvalue of r:%ld",r);
 s1 = ext_eucledian(q, k);
 s = (s1 * (hm + (x * r))) % q;
 printf("\nvalue of s:%ld",s);
 w = ext_eucledian(q, s);
 printf("\nvalue of w:%ld",w);
 u1=(hm*w)%q;
 printf("\nvalue of u1:%ld",u1);
 u2=(r*w)%q;
 printf("\nvalue of u2:%ld",u2);
 v1=power(g,u1,p);
 v2=power(y,u2,p);
 v3=((v1*v2) % p) % q;
 printf("\nvalue of v:%ld",v3);
 printf("\nsignature (r,s):%ld %ld",r,s);
 getch();
}

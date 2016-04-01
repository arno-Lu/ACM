#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int getdis(int a,int b)
{
	if(a>b)
	return a-b;
	else
	return b-a;
}
int main()
{
	int a,b,c,d,e,f,t,ans,y;
	t=0;
	while(scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f)!=EOF)
	{
		 ans=0;
		 y=0;
		 while(1)
		 {
		 	if(a==c||b==d) 
			break;
		 	if(a<c) a++;
		 	else    a--;
		 	if(b<d) b++;
		 	else    b--;
		 	if(a==e&&b==f)
			y=1;
		 	ans++;
		 }
		 if(a==c&&b==d&&y==1)
		 ans++;
		 else
		 {
		 ans+=getdis(a,c);
		 ans+=getdis(b,d);
		 }
		 printf("Case %d: %d\n",++t,ans);
		
    }
    return 0;
}

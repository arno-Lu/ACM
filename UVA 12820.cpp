#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int num[28];
char s[1111];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int i,j,n,m,ans,cas=1,T;
	while(scanf("%d",&T)!=EOF)
	{
		ans=0;
		for(i=0;i<T;i++)
		{
		scanf("%s",s);
		memset(num,0,sizeof(num));
		int len=strlen(s);
		for(int i=0;i<len;i++)
		{
			num[s[i]-'a']++;
		}
		sort(num,num+26,cmp);
		int f=1;
	    if(num[1]==0)
	    f=0;
		for(j=1;j<26;j++)
		{
			if(num[j]==0)
			break;
			if(num[j]==num[j-1])
			f=0;
		}
		if(f)
		ans++;
		
	}
	printf("Case %d: %d\n",cas++,ans);

	} 
		return 0;
}

#include<iostream> 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char str[1111];
int num[1111]={6,2,5,5,4,5,6,3,7,6};

int main()
{
	for(int i=10;i<=999;i++)
	{
		for(int j=i;j;j/=10)
		{
			num[i]+=num[j%10];
		}
	}
	int h,m,s;
	int T=0;
	while(scanf(" %s",str)!=EOF)
	{
		int H,M,S,ans,hm,gt;
		scanf("%d:%d:%d",&H,&M,&S);
		if(str[1]=='T')
		{
			ans=0;
			hm=gt=0;
			h=H;m=M;s=S;
		}
		else
		{
			while(h!=H||m!=M||s!=S)
			{
				ans+=num[hm]+num[gt];
				s++;
				if(s==60)
				{
					s=0;
					m++;
					if(m==60)
					{
						m=0;
						h++;
					}
				}
			}
			if(str[1]=='C')
			{
				char name[111];
                int x;
				scanf("%s",name);
				scanf("%d",&x);
				if(name[0]=='h')
				hm+=x;
				else
				gt+=x;
			}
			else if(str[1]=='N')
			{
				printf("Case %d: %d\n",++T,ans);
			}
		}
	}
	return 0;
}

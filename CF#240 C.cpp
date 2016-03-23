#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF){
	
	  
		if(n/2>k||(k!=0&&(n/2)==0)){
			printf("-1\n");
		}
		else if((n/2)==k)
		{
		
			for(int i=1;i<=n;i++)
			{
				printf("%d ",i);
			}
			printf("\n");
		}
		else
		{
		
			int ans = k-(n/2)+1;
			printf("%d %d",ans,ans*2);
			int i,j;
		    for(i=ans*2 + 1,j=1;j<n/2;i+=2,j++)  
                printf(" %d %d",i, i+1);  
            if(n%2==1)  
                printf(" %d", i);  
            printf("\n");  
		}
		
	}
	return 0;
}

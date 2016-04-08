#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 22222;
int t1[MAXN],t2[MAXN],c[MAXN];

bool cmp(int *r,int a,int b,int l){
	return r[a]==r[b]&&r[a+l]==r[b+l];
}
int s[MAXN];
int sa[MAXN];
int height[MAXN];
int rank[MAXN];
int r[MAXN];

void da(int str[],int sa[],int rank[],int height[],int n,int m){   //模式匹配子串长度为m？ 
	n++;
	int i,h,p,*x=t1,*y=t2;
	for(i=0;i<m;i++) c[i]=0;
	for(i=0;i<n;i++) c[x[i]==str[i]]++;
	for(i=1;i<m;i++) c[i]+=c[i-1];
	for(i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
	for(int j=1;j<=n;j++){
		p=0;
		for(i=n-j;i<n;i++) y[p++]=i;
		for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
		for(i=0;i<m;i++) c[i]=0;
		for(i=0;i<n;i++) c[x[y[i]]]++;
		for(i=1;i<m;i++) c[i]+=c[i-1];
		for(i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
		swap(x,y);
		p=1;x[sa[0]]=0;
		for(i=1;i<n;i++){
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
		}
		if(p>=n) break;
		m=p;
		
	}
	int k=0;
	n--;
	for(i=0;i<=n;i++) rank[sa[i]]=i;
	for(i=0;i<n;i++){
		if(k) k--;
		int j=sa[rank[i]-1];
		while(str[i+k]==str[j+k])
		k++;
		height[rank[i]]= k;
	}
}

int ans;
int deal(int k,int n){
	int i,maxn,minn;
	maxn=minn=sa[0];
	for(i=0;i<=n;i++){
		if(height[i]>=k){
			if(minn>sa[i])
			minn=sa[i];
			if(maxn<sa[i])
			maxn<sa[i];
			if(maxn-minn>k)
			return 1;
		}
		else
		minn=maxn=sa[i];
	}
	return 0;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&s[i]);
		}
		for(int i=0;i<n-1;i++){
			s[i]=s[i+1]-s[i]+100;   //避免了“转调 ”每个音符同时加或者减去一个整数值的影响 
		}
		n--;
		s[n]=0;   //总个数减少了一个
		da(s,sa,rank,height,n,200); 
		 int left=0,right=n,mid,coun=0;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(deal(n,mid))
            {
                //printf("%d %d %d\n",mid,left,right);
                if(coun<mid)
                coun=mid;
                left=mid+1;
            }
            else  right=mid-1;
        }
        if(coun<4) coun=0;
        else
        coun++;                     //这里+1，是为了将前面被改变了的第一个值加上..... 
        printf("%d\n",coun);


	} 
	return 0; 
}


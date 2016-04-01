#include<iostream>
#include<cstring>
#include<cstdio>
#define INF 9999
using namespace std;
char str[1050];

int Min(int a,int b,int c)
{
    if(a>b)
        a=b;
    if(a>c)
        a=c;
    return a;
}

int Max(int a,int b,int c)
{
    if(a<b)
        a=b;
    if(a<c)
        a=c;
    return a;
}

void change(int* t,int dir)
{
    int tt=t[0];
    if(dir)
    {
        t[0]=t[3];
        t[3]=t[1];
        t[1]=t[2];
        t[2]=tt;
    }
    else
    {
        t[0]=t[2];
        t[2]=t[1];
        t[1]=t[3];
        t[3]=tt;
    }
}

int main()
{
    int len;
    int t[4];
    int Case=1;
    while(~scanf("%s",str))
    {
        int a[4]= {0,-INF,-INF,-INF};
        int b[4]= {0,INF,INF,INF};
        int c[4]= {0,-INF,-INF,-INF};
        int d[4]= {0,INF,INF,INF};
        len=strlen(str);
        for(int i=0; i<len; i++)
        {
            if(str[i]=='F')
            {
                a[0]++,a[1]--;
                b[0]++,b[1]--;
                c[2]++,c[3]--;
                d[2]++,d[3]--;
            }
            else if(str[i]=='L')
            {
                change(a,1);
                change(b,1);
                change(c,1);
                change(d,1);
            }
            else if(str[i]=='R')
            {
                change(a,0);
                change(b,0);
                change(c,0);
                change(d,0);
            }
            else
            {
                t[0]=Max(a[0]+1,a[2],a[3]);
                t[1]=Max(a[1]-1,a[2],a[3]);
                t[2]=Max(a[0],a[1],a[2]);
                t[3]=Max(a[0],a[1],a[3]);
                memcpy(a,t,16);
                t[0]=Min(b[0]+1,b[2],b[3]);
                t[1]=Min(b[1]-1,b[2],b[3]);
                t[2]=Min(b[0],b[1],b[2]);
                t[3]=Min(b[0],b[1],b[3]);
                memcpy(b,t,16);
                t[0]=Max(c[0],c[2],c[3]);
                t[1]=Max(c[1],c[2],c[3]);
                t[2]=Max(c[0],c[1],c[2]+1);
                t[3]=Max(c[0],c[1],c[3]-1);
                memcpy(c,t,16);
                t[0]=Min(d[0],d[2],d[3]);
                t[1]=Min(d[1],d[2],d[3]);
                t[2]=Min(d[0],d[1],d[2]+1);
                t[3]=Min(d[0],d[1],d[3]-1);
                memcpy(d,t,16);
            }
        }
        t[0]=max(Max(a[0],a[1],a[2]),a[3]);
        t[1]=min(Min(b[0],b[1],b[2]),b[3]); 
        t[2]=max(Max(c[0],c[1],c[2]),c[3]);
        t[3]=min(Min(d[0],d[1],d[2]),d[3]);
        printf("Case %d: %d %d %d %d\n",Case++,t[1],t[0],t[3],t[2]);
    }
    return 0;
}


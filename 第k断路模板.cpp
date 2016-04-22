/*
 *�㷨���룺
 *�ڵ�Դ�����·��������,ʵ������ʱ����֪�����·����,�ζ�·���ߵ�����·;
 *��Ҫ֪���������·,���ų��䳤�����ӵ�˳��,��ΪK���·����;
 *
 *�㷨˼�룺
 *��Դ�����·��+�߼�����A*;
 *A*�㷨���������ʽ��������ʽ������;
 *����ʽ����ͨ���������ͼ��������Ϣ����̬������������ʹ����������󽵵�;
 *��ʽ������������ͼ��������Ϣ,����ͨ����ѧ����ʽ����;
 *
 *�㷨ͨ��һ�����ۺ���f(h)������ͼ�еĵ�ǰ��p���յ�ľ���,���ɴ˾���������������;
 *������·��ʧ��ʱ,���᳢������·��;
 *����A*,���ۺ���=��ǰֵ+��ǰλ�õ��յ�ľ���,��f(p)=g(p)+h(p),ÿ����չ���ۺ���ֵ��С��һ��;
 *
 *����K��·�㷨��˵,g(p)Ϊ��ǰ��s��p���ߵ�·���ĳ���;h(p)Ϊ��p��t�����·�ĳ���;
 *f(p)������Ϊ��s���յ�ǰ·���ߵ�p�����ߵ��յ�tһ������Ҫ�߶�Զ;
 *
 *Ϊ�˼��ټ���,h(p)��Ҫ��A*����֮ǰ����Ԥ����,ֻҪ��ԭͼ�����б߷���,�ٴ��յ�t��һ�ε�Դ�����·�����ܵõ�ÿ�����h(p)��;
 *
 *�㷨���裺
 *(1),������ͼ�����б߷���,��ԭ�յ�tΪԴ��,���t�����е����̾���;
 *(2),�½�һ�����ȶ���,��Դ��s���뵽������;
 *(3),�����ȼ������е���f(p)��С�ĵ�p,�����p����t,�����t���ӵĴ���;
 *�����ǰΪt�ĵ�k�γ���,��ǰ·���ĳ��Ⱦ���s��t�ĵ�k��·�ĳ���,�㷨����;
 *���������p���������еı�,����չ���ĵ�p���ڽӵ���Ϣ���뵽���ȼ�����;
 *
 *�㷨���ԣ�
 *PKU2449(Remmarguts' Date)
 *
 *��Ŀ���⣺
 *���s��t�ĵ�k��·�ĳ���;
 */

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;

const int INF=0xffffff;
const int N=1010;
const int M=100010;

struct node1
{
    int to;
    int w;
    int next;
};

node1 edge1[M],edge2[M];
int head1[M],head2[M];
int idx1,idx2;
int dist[N];

struct node2
{
    int to;
    //g(p)Ϊ��ǰ��s��p���ߵ�·���ĳ���;h(p)Ϊ��p��t�����·�ĳ���;
    int g,f;//f=g+h,f(p)������Ϊ��s���յ�ǰ·���ߵ�p�����ߵ��յ�tһ������Ҫ�߶�Զ;
    bool operator<(const node2 &r ) const
    {
        if(r.f==f)
            return r.g<g;
        return r.f<f;
    }
};

void Addedge1(int u,int v,int w)
{
    edge1[idx1].w=w;
    edge1[idx1].to=v;
    edge1[idx1].next=head1[u];
    head1[u]=idx1++;
}

void Addedge2(int u,int v,int w)
{
    edge2[idx2].w=w;
    edge2[idx2].to=v;
    edge2[idx2].next=head2[u];
    head2[u]=idx2++;
}

bool SPFA(int s,int n,int head[],node1 edge[],int dist[])
{
    queue<int>Q1;
    int inq[N];
    for(int i=0; i<=n; i++)
    {
        dist[i]=INF;
        inq[i]=0;
    }
    dist[s]=0;
    Q1.push(s);
    inq[s]++;
    while(!Q1.empty())
    {
        int q=Q1.front();
        Q1.pop();
        inq[q]--;
        if(inq[q]>n)//��Ȩ��
            return false;
        int k=head[q];
        while(k>=0)
        {
            if(dist[edge[k].to]>dist[q]+edge[k].w)
            {
                dist[edge[k].to]=edge[k].w+dist[q];
                if(!inq[edge[k].to])
                {
                    inq[edge[k].to]++;
                    Q1.push(edge[k].to);
                }
            }
            k=edge[k].next;
        }
    }
    return true;
}

int A_star(int s,int t,int n,int k,int head[],node1 edge[],int dist[])
{
    node2 e,ne;
    int cnt=0;
    priority_queue<node2>Q;
    if(s==t)//��s==tʱ,����Ϊ0��·����������k��·��,������Ҫ��k+1��·;
        k++;
    if(dist[s]==INF)
        return -1;
    e.to=s;
    e.g=0;
    e.f=e.g+dist[e.to];
    Q.push(e);

    while(!Q.empty())
    {
        e=Q.top();
        Q.pop();
        if(e.to==t)//�ҵ�һ�����·��
        {
            cnt++;
        }
        if(cnt==k)//�ҵ�k��·
        {
            return e.g;
        }
        for(int i=head[e.to]; i!=-1; i=edge[i].next)
        {
            ne.to=edge[i].to;
            ne.g=e.g+edge[i].w;
            ne.f=ne.g+dist[ne.to];
            Q.push(ne);
        }
    }
    return -1;
}

int main()
{
    int n,m;
    //freopen("C:\\Users\\Administrator\\Desktop\\kd.txt","r",stdin);
    while(~scanf("%d%d",&n,&m))
    {
        memset(head1, -1, sizeof(head1));
        memset(head2, -1, sizeof(head2));
        idx1=idx2=0;
        int u,v,w;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            Addedge1(u,v,w);
            Addedge2(v,u,w);
        }
        int s,t,k;
        scanf("%d%d%d",&s,&t,&k);
        SPFA(t,n,head2,edge2,dist);//��ԭ�յ�tΪԴ��,����ͼ��t�����е����̾���;
        int res=A_star(s,t,n,k,head1,edge1,dist);
        printf("%d\n",res);
    }
    return 0;
}


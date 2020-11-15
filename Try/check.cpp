#include<bits/stdc++.h>
using namespace std;
 
#define sd(mark) scanf("%d",&mark)
#define ss(mark) scanf("%s",mark)
#define sl(mark) scanf("%lld",&mark)
#define debug(mark) printf("check%d\n",mark)
#define clr(mark) memset(mark,0,sizeof(mark))
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ll long long
#define N 1000010

int bit[N],n;
void update(int i,int val)
{
	while(i<=n)
	{
		bit[i]=max(bit[i],val);
		i=i+(i&(-i));
	}
}
int query(int i)
{
	int ret=0;
	while(i)
	{
		ret=max(ret,bit[i]);
		i=i-(i&(-i));
	}
	return ret;
}

vector<int> v[N];
int last[N],maxx[N],a[N];
int Out[N];
vector<pair<int,int> > Q[N];

void update_DAG(int cur,int val)
{
	if(val>maxx[cur])
	{
		for(auto x:v[cur])
			update_DAG(x,val+1);
		maxx[cur]=val;
		update(cur,val);
	}
}


int main()
{
		int q,i,j,s;
		sd(n);sd(q);sd(s);
		for(i=0;i<=n;i++)
		{
			maxx[i]=last[i]=bit[i]=0;
			v[i].clear();
			Q[i].clear();
		}
		for(i=1;i<=n;i++)
		{
			sd(a[i]);
			last[a[i]]=i;
			int prev=0;
			for(j=a[i]-1;j>=1;--j)
				if(last[j]>prev)
				{
					prev=last[j];
					v[last[j]].PB(i);
				}
		}
		for(i=0;i<q;i++)
		{
			int x,y;
			sd(x);sd(y);
			Q[x].PB(MP(y,i));
		}
		for(i=n;i>=1;--i)
		{
			update_DAG(i,1);
			for(j=0;j<Q[i].size();j++)
				Out[Q[i][j].S]=query(Q[i][j].F);
		}
		for(i=0;i<q;i++)
			printf("%d\n",Out[i]);
}
#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
int primes[10001];
void generate_primes(){
    for(int i=2;i<=10000;i++)
    {
        if(primes[i]==1)
        {
            // cout<<i<<endl;
            for(int j=i*i;j<=10000;j+=i)
            {
                primes[j]=0;
            }
        }
    }
}
vector<int> adj[10001];
int visited[10001]={0};
bool check(int a,int b)
{
    int different=0;
    while(a>0)
    {
        if(a%10!=b%10)
        different++;
        a/=10;
        b/=10;
    }
    if(different==1)
    return true;
    else
    return false;
}
void make_graph()
{
    for(int i=1000;i<=9999;i++)
    {
        if(primes[i]==1)
        {
           for(int j=i+1;j<=9999;j++)
           {
               if(primes[j]==1)
               {
                   if(check(i,j))
                   {
                       adj[i].push_back(j);
                       adj[j].push_back(i);
                   }
               }
           }

        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0;i<=9999;i++)
    primes[i]=1;
    generate_primes();
    // for(int i=1000;i<=2000;i++)
    // if(primes[i]==1)
    // cout<<i<<endl;
    make_graph();
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        
        for(int i=1000;i<=9999;i++) visited[i]=0;

        
        queue<int > q;
        q.push(a);
        int dist[10001]={-1};
        dist[a]=0;
        visited[a]=1;
        while(!q.empty())
        {
            int val=q.front();
            // int dist=q.front().second;
            q.pop();
            for(int i=0;i<adj[val].size();i++)
            {
                if(!visited[adj[val][i]])
                {
                    visited[adj[val][i]]=1;
                    q.push(adj[val][i]);
                    dist[adj[val][i]]=dist[val]+1;
                    if(adj[val][i]==b)
                    {
                        // d=dist+1;
                        break;
                    }
                }
            }
        }
        if(dist[b]==-1)
        cout<<"Impossible"<<endl;
        else
        cout<<dist[b]<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
int dp[101][1001][1001];
int find(vector<int> arr,int i,int k,int w1,int w2,int items_1,int items_2)
{
    if(dp[i][w1][w2]!=-1)
    return dp[i][w1][w2];
    if(w1>=k && w2>=k)
    return items_1+items_2;
    if(i>=arr.size())
    return INT_MAX;
    
    // if(w2>=k)
    // return items_2;

    int a=INT_MAX,b=INT_MAX,c=INT_MAX;
    if(w1<k)
    a=find(arr,i+1,k,w1+arr[i],w2,items_1+1,items_2);
    if(w2<k)
    b=find(arr,i+1,k,w1,w2+arr[i],items_1,items_2+1);

    c=find(arr,i+1,k,w1,w2,items_1,items_2);

    return dp[i][w1][w2]=min(a,min(b,c));


}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int temp;
        vector<int> arr;
        int mx=INT_MIN;
        rep(i,n)
        {
            cin>>temp;
            arr.push_back(temp);
            mx=max(mx,temp);
        }
        rep(i,n+1) rep(j,k+mx) rep(l,k+mx) dp[i][j][l]=-1;
        int tp=find(arr,0,k,0,0,0,0);
        if(tp==INT_MAX)
        cout<<-1<<endl;
        else
        {
            cout<<tp<<endl;
        }
        
    }
    return 0;
}
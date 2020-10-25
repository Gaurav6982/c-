#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
int dp[1000001];
int find(int n)
{
   if(n<=0)
   return 0;
   if(n<10)
   return 1;
   if(dp[n]!=-1)
   return dp[n];
    set<int> digits;
    int temp=n;
    while(temp>0)
    {
        digits.insert(temp%10);
        temp/=10;
    }
    std::set<int>::iterator it;
    int min=INT_MAX;
    for(it=digits.begin();it!=digits.end();it++)
    {
        if(*it!=0)
        min=std::min(min,find(n-*it));
    }
    return dp[n]=(1+min);
   
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    rep(i,1000001) dp[i]=-1;
    cout<<find(n);
}
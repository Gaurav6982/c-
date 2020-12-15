#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int sum1=0,sum2=0,sum3=0;
    while(n--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        sum1+=a;
        sum2+=b;
        sum3+=c;
    }
    if(sum1==0 && sum2==0 && sum3==0)
    cout<<"YES";
    else
    {
        cout<<"NO";
    }
    
    return 0;
}
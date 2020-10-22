#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int num=n%10;
        int prev=(num-1)*10;
        int digits=0;
        while(n>0)
        {
            n/=10;
            digits++;
        }
        int ans=prev+((digits+1)*digits)/2;
        cout<<ans<<endl;
    }
}
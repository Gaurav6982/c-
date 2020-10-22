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
       vector<int> ones;
       for(int i=0;i<n;i++)
       {
           int temp;
           cin>>temp;
           if(temp==1)
           ones.push_back(i);
       }
    //    for(int i=0;i<ones.size();i++)
    //    cout<<ones[i]<<" ";
    //    cout<<endl;
       int ans=0;
       for(int i=1;i<ones.size();i++)
       {
           ans+=(ones[i]-ones[i-1]-1);
       }
       cout<<ans;
        cout<<endl;
       
    }
}
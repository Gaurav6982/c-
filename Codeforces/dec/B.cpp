#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
bool comp(string s)
{
    return s.compare("2020")==0;
}
bool check(string s)
{
    int n=s.length();
    if(
        comp(s.substr(0,4)) || 
        comp(s.substr(n-4,4))||
        (s.substr(0,1).compare("2")==0 && s.substr(n-3,3).compare("020")==0) ||
        (s.substr(0,2).compare("20")==0 && s.substr(n-2,2).compare("20")==0) ||
        (s.substr(0,3).compare("202")==0 && s.substr(n-1,1).compare("0")==0) 
        )
        return true;
        return false;
}
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
        string s;
        cin>>s;
        if(check(s))
        cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }
        
    }
    return 0;
}
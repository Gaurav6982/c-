#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;


bool check(string a , string b){
    int count_one_in_a=0,count_one_in_b=0;
    for(int i=0;i<a.length();i++)
    {
    if(a[i]=='1') count_one_in_a++;
    if(b[i]=='1') count_one_in_b++;
    }
    if(count_one_in_a%2!=0 || count_one_in_b%2!=0 || count_one_in_a!=count_one_in_b)
    {
        return false;
    }
    for(int i=0;i<a.length();i++)
    {
        if(a[i]!=b[b.length()-1-i])
        return false;
    }
    return true;
}
bool find(string a,string b)
{
    if(a.compare(b)==0)
    return true;
    if(check(a,b)) return true;
    bool flag=false;
    for(int k=1;k<a.length();k++)
    {
        if( 
            find(a.substr(0,k),b.substr(0,k)) 
            && 
            find(a.substr(k,a.length()-k),b.substr(k,b.length()-k)) 
            )
        {
            flag=true;
            break;
        }
    }

    if(flag)
    return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a,b;
    cin>>a>>b;
    cout<<find(a,b);
    return 0;
}
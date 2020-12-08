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
bool comp(string a,string b)
{
    return a.length()<b.length();
}
bool not_equal_one(string a,string b)
{
    int onea=0,oneb=0;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]=='1') onea++;
        if(b[i]=='1') oneb++;
    }
    return onea!=oneb;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        cin>>a;
        int n=a.length();
        // priority_queue<pair<int,string>, vector<pair<int,string> > ,greater<pair<int,string> > > q;
        set<string> substrings;
        for(int j=1;j<=n;j++)
        {
            for(int i=0;i<n;i++)
            {
                string sub=a.substr(i,j);
                substrings.insert(sub);
                // q.push(make_pair(j,sub));
            }
        }
        vector<string> subs;
        std::set<string>::iterator it=substrings.begin();
        for(;it!=substrings.end();it++)
        {
            string s=*it;
            subs.push_back(s);
        }
        sort(subs.begin(),subs.end(),comp);
        // for(int i=0;i<substrings.size();i++)
        // cout<<subs[i]<<endl;
        int ans=subs.size();
        for(int i=1;i<subs.size();i++)
        {
            string sub=subs[i];

            if(sub.length()<3) continue;

            for(int j=i+1;j<subs.size();j++)
            {
                if(subs[j].length()>sub.length()) break;
                if(not_equal_one(sub,subs[j])) continue;
                if(find(subs[i],subs[j])) ans--;
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}
/*TRied with a set*/
// for(;it!=substrings.end();it++)
        // {
        //     string sub=*it;
        //     if(sub.length()>=3)
        //     {
        //         std::set<string>::iterator it2=it+1;
        //         for(;it2!=substrings.end();it2++)
        //         {
        //             string sec=*it2;
        //             if(sec.length()!=sub.length())
        //             continue;

        //         }
        //     }
        // }
        // cout<<*it<<endl;
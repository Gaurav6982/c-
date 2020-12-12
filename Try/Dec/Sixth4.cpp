#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
void rotate(string& a,int i,int j)
{
    while(i<j)
    {
        char temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;
        j--;
    }
}
bool isPalindrome(string a,int i,int j)
{
    while(i<j)
    {
        if(a[i]!=a[j])
        return false;
        i++;
        j--;
    }
    return true;
}
int ones(string a,int i,int j)
{
    int one=0;
    while(i<=j)
    {
        if(a[i]=='1')
        one++;
        i++;
    }
    return one;
}
map<string,string> pairs;
bool find(string a,string b)
{
    std::map<string,string>::iterator st=pairs.find(a);
    if(st!=pairs.end())
    if(st->second==b)
    return true;
    int n=a.length();
    // if(isPalindrome(a,0,n-1) ||  isPalindrome(b,0,n-1))
    // return false;
    // if(ones(a,0,n-1)%2!=0 || ones(b,0,n-1)%2!=0)
    // return false;
    int oddes_a=0;
    int oddes_b=0;
    int evens_a=0;
    int evens_b=0;
    for(int i=0;i<n;i++)
    {
        // if(a[i]=='1' && b[i]=='1') continue;
        if(a[i]=='1')
        {
            if(i%2==0)
            evens_a++;
            else
            oddes_a++;
        }
        if(b[i]=='1')
        {
            if(i%2==0)
            evens_b++;
            else
            oddes_b++;
        }
    }
    if((evens_a+oddes_a)==1 || (evens_b+oddes_b)==1) return false;
    // if(a.compare("0110")==0||b.compare("0110")==0) cout<<a<<" "<<b<<" "<<evens_a<<" "<<oddes_a<<" "<<evens_b<<" "<<oddes_b<<endl;
    if(evens_a==evens_b && oddes_a==oddes_b)
    {
        cout<<a<<" "<<b<<endl;
        pairs.insert(make_pair(a,b));
        return true;
    }
    return false;
}
bool comp(string a,string b)
{
    return a.length()<b.length();
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
        // cout<<"size:"<<ans<<endl;
        for(int i=0;i<subs.size();i++)
        {
            string sub=subs[i];

            if(sub.length()<3) continue;

            for(int j=i+1;j<subs.size();j++)
            {
                if(subs[j].length()<sub.length()) continue;
                if(subs[j].length()>sub.length()) break;
                if(ones(sub,0,sub.length()-1)!=ones(subs[j],0,subs[j].length()-1)) continue;
                // string first=subs[i];
                // string second=subs[j];
                if(find(subs[i],subs[j]))
                {
                    // cout<<"subtracted for :"<<sub<<" "<<subs[j]<<endl;
                    // std::vector<string>::iterator in=std::find (subs.begin(), subs.end(), subs[j]);
                    // subs.erase(in);
                    subs[j]="";
                    ans--;
                }
            }
            // cout<<ans<<endl;
        }
        cout<<ans<<endl;
        
    }
    // std::map<string,string>::iterator l=pairs.begin();
    // for(;l!=pairs.end();l++)
    // {
    //     cout<<l->first<<" "<<l->second<<endl;
    // }
    return 0;
}
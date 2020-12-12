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
    int i=0,j=a.length()-1;
    string actual_b=b;
    while(i<j)
    {
        if(a[i]==b[i] && a[j]==b[j])
        {
            i++;
            j--;
        }
        else if(a[i]==b[i])
        {
            i++;
        }
        else if(a[j]==b[j])
        {
            j--;
        }
        else
        {
            int ones_in_a=ones(a,i,j);
            int ones_in_b=ones(b,i,j);
            if(ones_in_a!=ones_in_b) return false;
            int actual_j=j; 
            if(ones_in_b%2!=0)
            {
                int k;
                for(k=j;k>=i;k--)
                {
                    if(b[k]=='1')
                    {
                        actual_j=k;
                         if(ones(b,i,k)%2==0 && b[k]==a[i])
                        break;
                    }
                }
                if(k<=i)
                return false;
            }
            else if(isPalindrome(b,i,j))
            {
               // if(ones_in_b==2)
                // return false;

                int k;
                // int temp=2;
                for(k=j;k>=i;k--)
                {
                    // if(ones(b,i,k)%2==0 && b[k]==a[i])
                    // break;
                    if(b[k]==a[i])
                    {
                        actual_j=k;
                        // temp--;
                        if(ones(b,i,k)%2==0)
                        break;
                    }
                }
                if(k<=i)
                return false;
            }
            else if(b[j]!=a[i])
            {
                int k;
                for(k=j;k>=i;k--)
                {
                    if(b[k]==a[i])
                    {
                        actual_j=k;
                        if(k!=j && ones(b,i,k)%2==0)
                        {
                            // cout<<"break hua"<<endl;
                            break;
                        }
                    }
                }
                // cout<<k<<" "<<j<<" "<<i<<endl;
                if(k<=i)
                return false;
                // cout<<"idhar aaya"<<endl;
            }
            rotate(b,i,actual_j);
        }
    }
    if(a.compare(b)==0)
    {
        pairs.insert(make_pair(a,actual_b));
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
        // priority_queue<pair<int,string>, vector<pair<int,string> > ,greater<pair<int,string> > > subs;
        set<pair<int,string> > substrings;
        for(int j=1;j<=n;j++)
        {
            for(int i=0;i<n;i++)
            {
                string sub=a.substr(i,j);
                substrings.insert(make_pair(sub.length(),sub));
                // q.push(make_pair(j,sub));
            }
        }
        // vector<string> subs;
        std::set<pair<int,string> >::iterator it=substrings.begin();
        int ans=substrings.size();
        // cout<<"size:"<<ans<<endl;
        for(;it!=substrings.end();it++)
        {
            string sub=(*it).second;

            if(sub.length()<3) continue;
            std::set<pair<int,string> >::iterator in=it;
            // for(int j=i+1;j<subs.size();j++)
            in++;
            for(;in!=substrings.end();in++)
            {
                if((*in).second.length()<sub.length()) continue;
                if((*in).second.length()>sub.length()) break;
                if(ones(sub,0,sub.length()-1)!=ones((*in).second,0,(*in).second.length()-1)) continue;
                // string first=subs[i];
                // string second=subs[j];
                // cout<<subs[i]<<" "<<subs[j]<<endl;
                if(find(sub,(*in).second))
                {
                    // cout<<"subtracted for :"<<sub<<" "<<subs[j]<<endl;
                    // std::vector<string>::iterator in=std::find (subs.begin(), subs.end(), subs[j]);
                    substrings.erase(in);
                    // subs[j]="";
                    // j--;
                    in--;
                    ans--;
                }
            }
            // cout<<ans<<endl;
        }
        cout<<ans<<endl;
        
    }
    return 0;
}
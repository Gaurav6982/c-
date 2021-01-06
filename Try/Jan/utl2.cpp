#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
int ans;
void print_arr(vector<int> temp)
{
    rep(i,temp.size())
    {
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}
int smallest;
void find2(vector<int> arr,int i,int n,int k,int sum,vector<int> temp,int till_now)
{
    
    if(sum>=k)
    {
        print_arr(temp);
        cout<<"================"<<endl;
        ans=std::min((int)temp.size()+till_now,ans);
    }
    if(i==n)
    return;
    find2(arr,i+1,n,k,sum,temp,till_now);
    temp.push_back(arr[i]);
    sum+=arr[i];
    find2(arr,i+1,n,k,sum,temp,till_now);
    return ;

}
set<string> storage;
void find(vector<int> arr,int i,int n,int k,int sum,vector<int> temp)
{
    if(temp.size()>=smallest+2)
    return;
    if(sum>=k)
    {
        cout<<"++++++++++++++++++++++++++++"<<endl;
        print_arr(temp);
        smallest=min(smallest,(int)temp.size());
        vector<int> arr1;
        rep(i,n) arr1.push_back(arr[i]);
        rep(i,temp.size())
        {
            std::vector<int>::iterator it= find(arr1.begin(),arr1.end(),temp[i]);
            arr1.erase(it);
        }
        vector<int> t;
        string tel;
        rep(l,temp.size())
        {
            tel.push_back(temp[l]+'0');
        }
        // cout<<tel<<endl;
        // std::vector<string>::iterator iter=find(storage.begin(),storage.end(),tel);
        if(storage.find(tel)!=storage.end())
        return;
        storage.insert(tel);
        find2(arr1,0,arr1.size(),k,0,t,temp.size());
    }
    if(i==n)
    return;
    
    find(arr,i+1,n,k,sum,temp);
    temp.push_back(arr[i]);
    sum+=arr[i];
    find(arr,i+1,n,k,sum,temp);
    return ;
    
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
        int k;
        cin>>n>>k;
        vector<int> arr;
        int temp;
        rep(i,n)
        {
            cin>>temp;
            arr.push_back(temp);
        }
        ans=INT_MAX;
        smallest=INT_MAX;
        vector<int> t;
        find(arr,0,n,k,0,t);
        if(ans!=INT_MAX)
        cout<<ans<<endl;
        else
        cout<<-1<<endl;


    }
    return 0;
}
#include <bits/stdc++.h>

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
void find2(vector<int> arr,int i,int n,int k,int sum,vector<int> temp,int till_now,vector<int>& till)
{
    
    if(sum>=k)
    {
        // if((int)temp.size()+till_now<ans)
        // {
        //     cout<<"+++++++++++++++++"<<endl;
        //     print_arr(till);
        //     print_arr(temp);
        //     cout<<"================"<<endl;
        // }
        ans=std::min((int)temp.size()+till_now,ans);
    }
    if(i==n)
    return;
    find2(arr,i+1,n,k,sum,temp,till_now,till);
    temp.push_back(arr[i]);
    sum+=arr[i];
    find2(arr,i+1,n,k,sum,temp,till_now,till);
    return ;

}
set<string> storage;
void find(vector<int> arr,int i,int n,int k,int sum,vector<int> temp)
{
    if(sum>=k)
    {
        // cout<<"++++++++++++++++++++++++++++"<<endl;
        // print_arr(temp);
        vector<int> arr1;
        rep(i,n) arr1.push_back(arr[i]);
        rep(i,temp.size())
        {
            std::vector<int>::iterator it= find(arr1.begin(),arr1.end(),temp[i]);
            arr1.erase(it);
        }
        vector<int> t;
        find2(arr1,0,arr1.size(),k,0,t,temp.size(),temp);
    }
    if(i==n)
    return;
    
    find(arr,i+1,n,k,sum,temp);
    temp.push_back(arr[i]);
    sum+=arr[i];
    find(arr,i+1,n,k,sum,temp);
    return ;
    
}
int find3(vector<int> arr,int n,int k){
    sort(arr.begin(),arr.end());

        int i;
        vector<int> candidates;
        int sum=0;
        int till=-1;
        for(i=n-1;i>=0;i--)
        {
            
            if((sum+arr[i])>=k)
            {
                if(till==-1)
                till=i;
                candidates.push_back(i);
            }
            if(till==-1 && sum+arr[i]<k)
            sum+=arr[i];
        }
        if(till==-1|| sum+arr[till]<k)
        {
            return -1;
            // cout<<-1<<endl;
            // cout<<"+++++++++++++++++++++++++"<<endl;
            // continue;
        }
        // cout<<"till "<<till<<endl;
        int ans=n-till-1;
        int c;
        int mn=INT_MAX;
        // for(int j=0;j<candidates.size();j++)
        // {
        //     cout<<candidates[j]<<" ";
        // }
        // cout<<endl;
        for(int j=0;j<candidates.size();j++)
        {
            // cout<<candidates[j]<<" "<<endl;
            vector<int> dup;
            rep(l,till+1) dup.push_back(arr[l]);
            
            std::vector<int>::iterator it=find(dup.begin(),dup.end(),arr[candidates[j]]);
            dup.erase(it);
            // rep(l,dup.size()) cout<<dup[l]<<" " ;
            // cout<<endl;
            c=0;
            int sm=0;
            for(int l=(int)dup.size()-1;l>=0;l--)
            {
                c++;
                sm+=dup[l];
                if(sm>=k)
                break;
            }
            if(c!=0&& sm>=k)
            mn=min(mn,c);
        }
        // cout<<ans<<" "<<mn<<endl;
        if(mn!=INT_MAX)
        return ans+mn+1;
        else
        {
            return -1;
        }
        
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=15;
    cout<<t<<endl;
    cout<<"=============="<<endl;
    // cin>>t;
    while(t--)
    {
        int n=rand()%11+1;
        int k=rand()%11+1;
        // cin>>n>>k;
        // cout<<n<<" "<<k<<endl;
        vector<int> arr;
        int temp;
        rep(i,n)
        {
            // cin>>temp;
            temp=rand()%15+1;
            // cout<<temp<<" ";
            arr.push_back(temp);
        }
        cout<<"+++++++++++++++++++++"<<endl;
        ans=INT_MAX;
        smallest=INT_MAX;
        vector<int> t;
        find(arr,0,n,k,0,t);
        // if(ans!=INT_MAX)
        // cout<<ans<<endl;
        // else
        // cout<<-1<<endl;
        if(ans==INT_MAX)
        ans=-1;
        if(ans!=find3(arr,n,k))
        {
            cout<<n<<" "<<k<<endl;
            rep(i,n) cout<<arr[i]<<" ";
            cout<<endl;
            cout<<"ans : "<<ans<<" "<<find3(arr,n,k)<<endl;
        }

    }
    return 0;
}
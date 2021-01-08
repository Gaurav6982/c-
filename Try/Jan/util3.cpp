#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=20;
    // cin>>t;
    cout<<t<<endl;
    cout<<"==================="<<endl;
    while(t--)
    {
        int n,k;
        n=rand()%3+1;
        k=rand()%5+1;
        cout<<n<<" "<<k<<endl;
        // cin>>n>>k;
        vector<int> arr;
        int tp;
        rep(j,n)
        {
            // cin>>tp;
            tp=rand()%k+1;
            cout<<tp<<" ";
            arr.push_back(tp);
        }
        cout<<endl;
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
            cout<<-1<<endl;
            // cout<<"+++++++++++++++++++++++++"<<endl;
            continue;
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
            // int l;
            for(int l=(int)dup.size()-1;l>=0;l--)
            {
                c++;
                sm+=dup[l];
                if(sm>=k)
                break;
            }
            if(c!=0&& sm>=k)
            mn=min(mn,c);
            // cout<<mn<<endl;
        }
        // cout<<ans<<" "<<mn<<endl;
        if(mn!=INT_MAX)
        cout<<ans+mn+1<<endl;
        else
        cout<<-1<<endl;
        cout<<"+++++++++++++++++++++++++"<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

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
        int arr[n];
        vector<int> adj[n+1];
        map<int,int> occ;
        bool unique=true,same=true;
        int min_oc=INT_MAX,min_el;
        rep(i,n)
        {
            cin>>arr[i];
            if(i>0 && arr[i]!=arr[i-1])
            same=false;
            adj[arr[i]].push_back(i);
            // occ[arr[i]]++;
            int el=adj[arr[i]].size();
            if(el>1)
            unique=false;
        }
        for(int i=1;i<=n;i++)
        {
            int el=adj[i].size();
            if(el!=0 && el<min_oc)
            {
                min_oc=el;
                min_el=i;
            }
        }
        // cout<<unique<<" "<<same<<" "<<min_el<<endl;
        if(unique)
        {
            cout<<1<<endl;
        }
        else if(same)
        cout<<0<<endl;
        else
        {
            int s=adj[min_el].size();
            int uni_s=s;
            for(int i=1;i<s;i++)
            {
                if(adj[min_el][i]-1==adj[min_el][i])
                uni_s--;
            }
            // cout<<s<<" "<<uni_s<<" ";
            int ans=0;
            if(s==1)
            {
                if(arr[0]==min_el || arr[n-1]==min_el)
                ans=1;
                else ans=2;
                if(arr[0]==arr[n-1] && (adj[arr[0]].size()-1)<ans)
                ans=adj[arr[0]].size()-1;
            }
            else
            {
                
                if(arr[0]==min_el && arr[n-1]==min_el)
                ans=s-1;
                else if(arr[0]==min_el|| arr[n-1] == min_el)
                ans=s;
                else
                ans=s+1;
                if(arr[0]==arr[n-1] && (adj[arr[0]].size()-1)<ans)
                ans=adj[arr[0]].size()-1;
            }
            cout<<ans<<endl;
        }

    }
    return 0;
}
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
        int q;
        cin>>q;
        string str;
        cin>>str;
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            char copy[r-l+1];
            int k=0;
            for(int i=l;i<=r;i++)
            copy[k++]=str[i-1];
            bool print_yes=false;
            k=0;
            int i=0;
            bool continuous=true;
            int last=-1;
            // vector<int> indexes;
            while(i<n && k<r-l+1)
            {
                if(copy[k]==str[i])
                {
                    if(last!=-1 && last+1!=i)
                    continuous=false;
                    k++;
                    last=i;
                    if(continuous&&k==r-l)
                    i++;
                }
                    i++;

            }
            if(k==r-l+1)
            print_yes=true;
            if(print_yes && r-l+1>=2)
            cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
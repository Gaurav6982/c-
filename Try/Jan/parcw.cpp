#include<bits/stdc++.h>

#define ll long long
#define endl '\n' 

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
        char a[n],d[n];
        // char a[n],b[n],d[n];
        string b;
        // scanf("%s",b);
        cin>>b;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                a[0]='1';
                if(b[0]=='1')
                d[0]='2';
                else
                d[0]='1';
                continue;
            }
            if(b[i]=='0'){
                if(d[i-1]=='2')
                {
                    a[i]='1';
                    d[i]='1';
                }
                else if(d[i-1]=='1')
                {
                    a[i]='0';
                    d[i]='0';
                }
                else
                {
                    a[i]='1';
                    d[i]='1';
                }
            }
            else
            {
                if(d[i-1]=='2')
                {
                    a[i]='0';
                    d[i]='1';
                }
                else if(d[i-1]=='1')
                {
                    a[i]='1';
                    d[i]='2';
                }
                else
                {
                    a[i]='1';
                    d[i]='2';
                }
            }
        }
        for(int i=0;i<n;i++)
        cout<<a[i];
        cout<<endl;

    }
    return 0;
}
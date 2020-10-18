#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        long long x,y,x1,y1;
        cin>>x>>y>>x1>>y1;
        if(x==x1 && y==y1)
        cout<<0<<endl;
        else if(x==x1 && y!=y1)
            cout<<(abs(y-y1))<<endl;
        else if(x!=x1 && y==y1)
            cout<<(abs(x-x1))<<endl;
        else
            cout<<(abs(x1-x)+abs(y1-y)+2)<<endl;
    }
    return 0;
}
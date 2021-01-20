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
        int a,b;
        cin>>a>>b;
        int c,d;
        cin>>c>>d;
        if(a==c && b==d)
        {
            cout<<"SECOND"<<endl;
        }
        else if((a-1==c && b==d) || //right
                (a+1==c && b==d) || //left
                (a-1==c && b-1==d) || //bottom right
                (a+1==c && b+1==d) || //top left
                (a==c && b+1==d) || //up
                (a==c && b-1==d) || //down
                (a+1==c && b-1==d) || //top up
                (a-1==c && b+1==d)) //bottom left
                cout<<"FIRST"<<endl;
                else
                cout<<"DRAW"<<endl;
    }
    return 0;
}
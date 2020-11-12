#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
void calculate(int arr[],int i,int sum,char player,int turn,int ans[],int j)
{
    if(turn==36)
    return ;
    ans[j]=sum;
    if(arr[i]==1)
    {
        if(player=='l')
        calculate(arr,i+1,sum+1,'r',turn+1,ans,j+1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;
    int t=20;
    cout<<t<<endl;
    while(t--)
    {
        cout<<"=================="<<endl;
        int n;
        // cin>>n;
        n=abs(rand())%20+1;
        cout<<n<<endl;
        int arr[n];
        // rep(i,n) cin>>arr[i];
       
        for(int i=0;i<n;i++)
        {
            int r=abs(rand())%2+1;
            if(r==1)
            arr[i]=1;
            else
            arr[i]=abs(rand())%15+1;
        }
        rep(i,n) cout<<arr[i]<<" ";cout<<endl;
        int q;
        // cin>>q;
        q=abs(rand())%3+1;
        cout<<q<<endl;
         int ans[37]={0};
        calculate(arr,0,0,'l',1,ans,0);
        while(q--)
        {
            int a;
            
            a=abs(rand())%20+1;
            cout<<a<<endl;

            cout<<ans[a]<<endl;
            // cin>>a;
        }
    }
    return 0;
}
#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr;
    vector<int> left;
    // vector<int> right;
    int res=0;
    int temp;
    rep(i,n) {cin>>temp;arr.push_back(temp);res^=temp;}
    int one=0;
        int k=0;
        int tempo=res;
        while(res>0)
        {
            if(res&1)
            break;
            res=res>>1;
            k++;
        }
    rep(i,n)
    {
        int temp=arr[i];
        temp=arr[i]>>k;
            if((temp)&1)
            {
                one=one^arr[i];
            }
        
    }
    int two=tempo^one;
    cout<<min(one,two)<<" "<<max(one,two)<<endl;
    return 0;
}
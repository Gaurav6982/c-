#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int n,x;
    cin>>n>>x;
    vector<pair<ll,int> > arr;
    for(int i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        arr.push_back(make_pair(temp,i));
    }
    sort(arr.begin(),arr.end());
    int i=0;
    int j=n-1;
    bool print=false;
    while(i<j)
    {
        if(arr[i].first+arr[j].first==x)
        {
        print=true;
        break;
        }
        else if(arr[i].first+arr[j].first>x)
        {
            j--;
        }
        else
        {
            i++;
        }
        
    }
    if(print)
    cout<<(arr[j].second+1)<<" "<<(arr[i].second+1)<<endl;
    else
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    
    return 0;
}
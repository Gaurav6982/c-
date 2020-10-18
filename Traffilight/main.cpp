#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    long long x;        
    cin>>n>>x;
    set<long long> lights;
    lights.insert(0);
    lights.insert(n);
    multiset<long long> lengths;
    lengths.insert(n);
    std::set<long long>::iterator point;
    for(int i=0;i<x;i++)
    {
        long long temp;
        cin>>temp;       
        point=lights.upper_bound(temp);
        long long left,right;
        left=*prev(point);
        right=*point;
        
        lengths.erase(lengths.find(right-left));
        
        lengths.insert(temp-left);
        lengths.insert(right-temp);
        
        lights.insert(temp);
        
        cout<<*lengths.rbegin()<<" ";
    }
    return 0;
}
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<pair<long long,long long>> customers;
    for(int i=0;i<n;i++)
    {
        long long arrival,departure;
        cin>>arrival>>departure;
        customers.push_back(make_pair(arrival,departure));
    }
    sort(customers.begin(),customers.end());
    // rep(i,n) cout<<customers[i].first<<" "<<customers[i].second<<" ";
    set<long long> rooms;
    long long ans=0;
    vector<long long> list;
    for(int i=0;i<n;i++)
    {
        // auto pos=rooms.lower_bound(customers[i].first);
        std::set<long long>::iterator pos=rooms.begin();
        bool end=false;
        for(;pos!=rooms.end();pos++)
        {
            if(*pos<customers[i].first)
            break;
            else
            {
                end=true;
                break;
            }
        }
        if(pos==rooms.end() || end==true)
        rooms.insert(customers[i].second);
        else
        {
            rooms.erase(pos);
            rooms.insert(customers[i].second);
        }
        list.push_back(rooms.size());
        ans=max(ans,(long long)list.size());   
    }
    cout<<ans-1<<endl;
    for(int i=0;i<list.size();i++)
    cout<<list[i]<<" ";

}
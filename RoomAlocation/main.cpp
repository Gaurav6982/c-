#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
using namespace std;
bool sortBy(pair<pair<ll,ll>,ll> &a, pair<pair<ll,ll>,ll> &b)
{
    return a.first.first-b.first.first;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<pair<pair<ll,ll>,ll> > customers;
    for(int i=0;i<n;i++)
    {
        long long arrival,departure;
        cin>>arrival>>departure;
        customers.push_back(make_pair(make_pair(arrival,departure),i));
    }
    sort(customers.begin(),customers.end(),sortBy);
    cout<<"============"<<endl;
    rep(i,n) cout<<customers[i].first.first<<" "<<customers[i].first.second<<endl;
    multiset<long long> rooms;
   
    long long ans=0;
    vector<pair<ll,ll>> list;
    for(int i=0;i<n;i++)
    {
        // auto pos=rooms.lower_bound(customers[i].first);
        std::multiset<long long>::iterator pos=rooms.begin();
        bool end=false;
        for(;pos!=rooms.end();pos++)
        {
            if(*pos<customers[i].first.first)
            break;
            else
            {
                end=true;
                break;
            }
        }
        if(pos==rooms.end() || end)
        {
            rooms.insert(customers[i].second);
        }
        else
        {
            rooms.erase(*pos);
            rooms.insert(customers[i].second);
        }
        list.push_back(make_pair(customers[i].second,pos-rooms.begin()));
        ans=max(ans,(long long)rooms.size());   
        cout<<"++++++++++++++++++"<<endl;
        for(std::multiset<long long>::iterator p=rooms.begin();p!=rooms.end();p++)
        {
        cout<<*p<<" ";
        }
        cout<<endl;
    }
    cout<<ans<<endl;
    for(int i=0;i<list.size();i++)
    cout<<list[i].first<<" ";

}
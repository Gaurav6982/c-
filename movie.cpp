
#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
const lli mod = 1e9 + 7;

using namespace std;
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b){
                  return a.second<b.second;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<lli,lli> > customs;
    for(int i=0;i<n;i++)
    {
        lli x,y;
        cin>>x>>y;
        customs.push_back(make_pair(x,y));
    }
    sort(customs.begin(),customs.end(),sortbysec);
    lli ans=1;
    lli curr_end=customs[0].second;
    for(int i=1;i<n;i++)
    {
        if(customs[i].first>=curr_end)
        {
            ans++;
            curr_end=customs[i].second;
        }
    }
    cout<<ans<<endl;
    return 0;
}


#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
const lli mod = 1e9 + 7;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<lli,bool> > customs;
    for(int i=0;i<n;i++)
    {
        lli x,y;
        cin>>x>>y;
        customs.push_back(make_pair(x,true));
        customs.push_back(make_pair(y,false));
    }
    sort(customs.begin(),customs.end());
    lli temp=0,ans=0;
    for(unsigned int i=0;i<customs.size();i++)
    {
        if(customs[i].second)
            temp++;
        else
            temp--;
        ans=max(temp,ans);
    }
    printf("%lld\n",ans);
    return 0;
}

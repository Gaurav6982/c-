#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
class Demand{

    public:
    int start,depart,req;
    Demand(int a,int b,int c)
    {
        start=a;
        depart=b;
        req=c;
    }
};
bool check(int mid,vector<Demand>& dms,int upto[],int n)
{
    rep(i,n)
    {
        int d;
        d=dms[i].depart;
        if((d*mid)<upto[d])
        return false;
    }
    return true;
}
bool comp(Demand a,Demand b){
    return a.depart<b.depart;
}
void debug(vector<Demand> dms,int max_d,int upto[],int n){
    rep(i,max_d+1)
    {
        cout<<upto[i]<<" ";
    }
    rep(i,n)
    {
        cout<<dms[i].start<<" "<<dms[i].depart<<" "<<dms[i].req<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<Demand> dms;
        int max_range=INT_MIN;
        int max_d=INT_MIN;
        rep(i,n){
            int a,b,c;
            cin>>a>>b>>c;
            Demand d(a,b,c);
            dms.push_back(d);
        
            int temp=c/((b-a)!=0?(b-a):1);
            max_d=max(max_d,b);
            max_range=max(max_range,temp);
        }
        //max_d,max_range;
        int upto[max_d+1];
        rep(i,max_d+1) upto[i]=0;
        // debug(dms,max_d,upto,n);
        rep(i,n)
        {
            int cm=dms[i].req;
            // cout<<cm<<endl;
            int end=dms[i].depart;
            upto[end]+=cm;
        }
        // sort(dms.begin(),dms.end(),comp);
        upto[0]=0;
        rep(i,max_d+1)
        {
            upto[i+1]=upto[i+1]+upto[i];
        }
        // cout<<max_d<<" "<<max_range<<endl;
        // rep(i,max_d+1) cout<<upto[i]<<" ";
        // cout<<endl;
        int i=0;
        int j=upto[max_d];
        int mid=-1;
        while(i<=j)
        {
            mid=i+(j-i)/2;

            if(check(mid,dms,upto,n))
            {
                if(j==mid)
                break;
                j=mid;
            }
            else
            {
                i=mid+1;
            }
        }
        cout<<mid<<endl;
        // rep(i,max_range+1)
        // {
        //     cout<<upto[i]<<" ";
        // }
        // rep(i,n)
        // {
        //     cout<<dms[i].start<<" "<<dms[i].depart<<" "<<dms[i].req<<endl;
        // }

    }
    return 0;
}
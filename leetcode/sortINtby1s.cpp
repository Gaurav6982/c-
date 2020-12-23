#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;


    vector<int> sortByBits(vector<int>& arr) {
        vector<int> list[14];
        for(int i=0;i<arr.size();i++)
        {
            int num=arr[i];
            int num_one=0;
            while(num)
            {
                num=num&(num-1);
                num_one++;
            }
            list[num_one].push_back(arr[i]);
        }
        vector<int> ans;
        for(int i=0;i<14;i++)
        {
            sort(list[i].begin(),list[i].end());
            for(int a:list[i])
                ans.push_back(a);
        }
        return ans;
    }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> arr;
    int n;
    cin>>n;
    int temp;
    rep(i,n){
        cin>>temp;
        arr.push_back(temp);
    }
    sortByBits(arr);
    rep(i,n) cout<<arr[i]<<" ";

    return 0;
}
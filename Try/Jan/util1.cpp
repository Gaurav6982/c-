#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
int ans;
bool find(vector<int> arr,int n,int i,int boxes,vector<int> temp,int sum,int k)
{
    if(i==-1)
    {
        // rep(i,temp.size()) cout<<temp[i]<<" ";
        // cout<<endl;
        
    return false;
    }
    if(boxes==2)
    {
        // rep(i,temp.size()) cout<<temp[i]<<" ";
        // cout<<endl;
        ans=min(ans,(int)temp.size());
        return false;
    }
    sum+=arr[i];
    temp.push_back(arr[i]);
    if(sum>=k)
    {
        boxes++;
        sum=0;
    }
    if(find(arr,n,i-1,boxes,temp,sum,k)) return true;
    sum-=arr[i];
    std::vector<int>::iterator it=std::find(temp.begin(),temp.end(),arr[i]);
    temp.erase(it);
    return false;
}
void printArray(vector<int> arr, int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 
int k;
bool check(vector<int> subarr,int n)
{
    sort(subarr.begin(),subarr.end());
    int sum=0;
    int all=0;
    for(int i=n-1;i>=0;i--)
    {
        if(sum<k)
        sum+=subarr[i];

        all+=subarr[i];

    }
    if(all-sum>=k)
    return true;
    return false;

}
bool printSubsequences(vector<int> arr, int index,  
                       vector<int> subarr) 
{ 
    if (index == arr.size()) 
    { 
        int l = subarr.size(); 
        if (l != 0) 
        {
            if(check(subarr,l))
            {
                ans=min(ans,(int)subarr.size());
                // printArray(subarr, l); 
                return true;
            }
        }
            // printArray(subarr, l); 
    } 
    else
    { 
        if(printSubsequences(arr, index + 1, subarr)) return true; 
  
        subarr.push_back(arr[index]); 
  
        if(printSubsequences(arr, index + 1, subarr))return true; 
    } 
    return false; 
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
        cin>>n>>k;
        vector<int> arr;
        rep(i,n)
        {
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        // sort(arr.begin(),arr.end());
        ans=INT_MAX;
        vector<int> temp;
        // find(arr,n,n-1,0,temp,0,k);
        printSubsequences(arr,0,temp);
        cout<<ans<<endl;
    }
    return 0;
}
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        vector<int> scs(n+1,0);
        for(int i=1;i<=n;i++)
        {
            scs[i]=scs[i-1]^arr[i-1];
        }
        // for(int i=0;i<=n;i++)
        //     cout<<scs[i]<<" ";
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>i;j--)
            {
                for(int k=i+1;k<=j;k++)
                {
                    int left=scs[k]^scs[i];
                    int right=scs[j+1]^scs[k];
                    
                    if(left==right)
                        ans++;
                }   
            }
        }
        return ans;
    }
};
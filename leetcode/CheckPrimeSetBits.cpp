class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int ans=0;
        for(int i=L;i<=R;i++)
        {
            int num=i;
            int count_one=0;
            while(num>0)
            {
                num=num&(num-1);
                count_one++;
            }
            bool prime=true;
            for(int j=2;j*j<=count_one;j++)
            {
                if(count_one%j==0)
                {
                    prime=false;
                    break;
                }
            }
            if(count_one<=1)
                prime=false;
            if(count_one==2 || prime==true)
                ans++;
        }
        return ans;
    }
};
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count=0;
        while(n)
        {
            n&=(n-1);
            count++;
        }
        if(count==1)
            return true;
        return false;
    }
};
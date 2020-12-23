class Solution {
public:
    bool isPowerOfThree(int n) {
        bool check=true;
        while(n>1)
        {
            if(n%3!=0)
            {
                check=false;
                break;
            }
            n/=3;
            
        }
        if(n==1 && check)
            return true;
        return false;
    }
};

//faster
 class Solution {
    public:
     bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};
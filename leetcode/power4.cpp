 bool isPowerOfFour(int n) {
        if (n <= 0) {
            return false;
        }
        // Make sure that exactly one bit is set.
        if ((n & (n - 1)) != 0) { 
            return false;
        }
        // Make sure there are even number of zeroes.
        while (n > 1) {
            n >>= 2;
        }
        // After even number of shifting we should be
        // left with 1 bit set.
        return (n == 1);
    }
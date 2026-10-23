class Solution {
public:
    bool isPalindrome(int x) {
        int n=x;
        int rem=0;
        long long rev=0;
        if(x<0)
            return false;
        while(x>0)
        {
            rem=x%10;
            rev=rem+(rev*10);
            x/=10;
        }
        if(rev==n)
            return true;
        else
            return false;
    }
};
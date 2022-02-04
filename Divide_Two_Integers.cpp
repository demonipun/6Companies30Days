class Solution {
public:
    
    // https://leetcode.com/problems/divide-two-integers/
    
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1) //  if the quotient is strictly greater than 231 - 1, then return 231 - 1
            return INT_MAX;
        long dvd=labs(dividend), dvs=labs(divisor), ans=0; // labs() function in C++ returns the absolute value of a long or long int data.
        int sign=((dividend > 0) ^ (divisor > 0)) ? -1 : 1; // sign after division
        while(dvd>=dvs) {
            long temp=dvs, m=1;
            while((temp<<1)<=dvd) { // temp<<1 => temp*2
                temp=(temp<<1);     // temp<<1 => temp*2
                m=(m<<1);           // m<<1 => m*2
            }
            dvd-=temp;
            ans+=m;
        }
        return sign*ans;
    }
};

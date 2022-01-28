class Solution{
    public:
    
    // https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1/?company[]=Walmart&company[]=Walmart&page=1&query=company[]Walmartpage1company[]Walmart
    
    int M=1e9+7;
    long long power(int N,int R)
    {
        // recursive
        if(N==0)
            return 0;
        if(R==0)
            return 1;
        long long temp=power(N,R/2)%M;
        temp=(temp*temp)%M;
        if(R%2==0)
            return (temp)%M;
        if(R%2!=0) 
            return (N*temp)%M;
    }

};

class Solution{
public:
    
    // https://practice.geeksforgeeks.org/problems/maximum-height-tree4803/1/?page=2&company[]=Walmart&query=page2company[]Walmart
    
    int height(int N){
        int i=0;
        while(N>0){
            i++;
            N-=i;
        }
        if(N<0)
            i--;
        return i;
    }
};

class Solution
{
    
    // https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1/
    
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        int s1=0, s2=0;
        for(int i=0;i<n;i++){
            if(i%2)
                s1=max(s1+arr[i],s2);
            else
                s2=max(s2+arr[i],s1);
        }
        return max(s1,s2);
    }
};

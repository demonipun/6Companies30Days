class Solution{
public:
    
    // https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/
    
    int *findTwoElement(int *arr, int n) {
        int *ans=new int[2];
        int i=0;
        while(i<n){
            while(i<n&&arr[i]!=arr[arr[i]-1])
                swap(arr[i],arr[arr[i]-1]);
            i++;
        }
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1){
                ans[0]=arr[i], ans[1]=i+1;
                break;
            }
        }
        return ans;
    }
};

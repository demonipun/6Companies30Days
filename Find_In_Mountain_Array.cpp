/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    
    // https://leetcode.com/problems/find-in-mountain-array/
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // Triple Binary Search
        int n=mountainArr.length();
        
        // Binary find peak in the mountain.
        int low=0, high=n-1;
        while(low<high) {
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1))
                low=mid+1;
            else
                high=mid;
        }
        int peak=low;
        
        // Binary find the target in strict increasing array ( to return minimum index )
        low=0, high=peak;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)==target)
                return mid;
            else if(mountainArr.get(mid)<target)
                low=mid+1;
            else
                high=mid-1;
        }
        
        // Binary find the target in strict decreasing array ( binary search conditions reverses since it's decreasing array)
        low=peak+1, high=n-1;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)==target)
                return mid;
            else if(mountainArr.get(mid)>target)
                low=mid+1;
            else
                high=mid-1;
        }
        
        return -1;
    }
};

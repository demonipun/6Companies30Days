class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	
	// https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/
	
	ull getNthUglyNo(int n) {
	    long long ans=-1;
	    set<long long> s;
	    s.insert(1);
	    while(n--) {
	        auto itr=s.begin(); // Pointer to first element of the set
	        ans=*itr;           // Value of the first element
	        s.erase(itr);       // Erasing the first element from the set
	        s.insert(ans*2);
	        s.insert(ans*3);
	        s.insert(ans*5);
	    }
	    return ans;
	}
};

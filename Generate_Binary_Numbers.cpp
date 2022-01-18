// https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1/
//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	vector<string> ans(N);
	for(int num=1;num<=N;num++) {
	    string s=""; int i=num;
	    while(i>0){
	        s+= (i%2) ? '1' : '0';
	        i/=2;
	    }
	    reverse(s.begin(), s.end());
	    ans[num-1]=s;
	}
	return ans;
}

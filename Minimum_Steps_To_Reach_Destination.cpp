class Solution{
public:
    
    // https://practice.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1/
    
    int minSteps(int D){
        int sum=0, steps=0;
        while(sum<D) {
            steps++;
            sum+=steps;
        }
        // Agar (sum-D)%2==0, no steps needed as one of the previous steps can be made negative in order to achieve  target
        while((sum-D)%2){
            steps++;
            sum+=steps;
        }
        /*   Meaning of the second while statement
        if((sum-target)%2){
            if(steps%2==0) // last step agar even tha toh
                steps++;
            else
                steps+=2;
        }
        */
        return steps;
    }
};

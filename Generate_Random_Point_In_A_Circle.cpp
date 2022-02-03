class Solution {
public:
    
    // https://leetcode.com/problems/generate-random-point-in-a-circle/
    
    double X, Y, R;
    Solution(double radius, double x_center, double y_center) {
        X=x_center;
        Y=y_center;
        R=radius;
    }
    
    vector<double> randPoint() {
        // (double)rand()/RAND_MAX -----> used for generating random values between 0 and 1
        // M_PI -----> value of pre-defined pi in c++  =====>    pi	M_PI	3.14159265358979323846
        // Use sqrt((double)rand()/RAND_MAX) as it gives more uniform distribution of points inside the circle
        double r=sqrt((double)rand()/RAND_MAX)*R;
        double deg=2*M_PI*((double)rand()/RAND_MAX); // degree = between 0 and 2 * pi
        return {X+r*cos(deg), Y+r*sin(deg)} ;
    }
};

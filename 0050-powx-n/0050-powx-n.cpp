class Solution {
public:
    double myPow(double x, int n) {
        long long m=n;
        if(m<0){
            x=1/x;
            m=-m;
        }
        double ans=1;
        while(m>0){
            if(m%2==1){
                ans=ans*x;
                m=m-1;
            }
            else{
                m=m/2;
                x=x*x;
            }
        }
        return ans;

    }
};
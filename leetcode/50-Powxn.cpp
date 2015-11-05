#include <iostream>
using namespace std;

class Solution {
    public:
        double myPow(double x, int n) {
            double res = 1.0;
            long nn = (long)n;
            if (nn < 0) {
                x = 1 / x;
                nn = -nn;
            }
            if (nn == 0)  return 1.0;
            while(nn > 1){
                if (nn & 1) res *= x;
                x *= x;
                nn = nn >> 1;
            }
            return res * x;
        }
};
int main() {
    cout << (new Solution()) -> myPow(-1,-2147483648);
}

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec{3,4,-1,0,6,2,3}; //-1,0,2,3
    vector<int> dp(vec.size(), 1);
    for (int i = 1; i < vec.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (vec[j] < vec[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    auto it = max_element(dp.begin(), dp.end());
    cout << *it << endl;
    return 0;
}

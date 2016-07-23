#include <iostream>
#include <vector>

using namespace std;

int minval = INT_MAX;
vector< int > mem;

int dp(int total, vector<int> coins) {
    if (total == 0) return 0;
    if (mem[total] != -1) return mem[total];
    int tmpmin = INT_MAX;
    for (int i = 0; i < coins.size(); ++i) {
        if (total >= coins[i])
            tmpmin = min( tmpmin, 1 + dp(total-coins[i], coins) );
    }
    mem[total] = tmpmin;
    return tmpmin;
}

int main() {
    vector<int> coins {1,2,3, 6};
    int total = 9;
    mem.resize(total+1, -1);
    minval = dp(total, coins);
    cout << minval << endl;
    return 0;
}

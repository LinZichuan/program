#include <iostream>
#include <vector>

using namespace std;

int maxweight = -1;
vector< vector<int> > mem;

int dp(int total, vector<int> & value, vector<int> & weight, int index) {

    if (total == 0 || index >= value.size())  return 0;
    if (mem[total][index] != -1) return mem[total][index];
    int tmpmax = 0;
    if (total >= weight[index]) {
        tmpmax = max( value[index] + dp(total-weight[index], value, weight, index+1), dp(total, value, weight, index+1) );
    } else {
        tmpmax = dp( total, value, weight, index+1 );
    }
    mem[total][index] = tmpmax;
    maxweight = max(tmpmax, maxweight);
    return tmpmax;
}

int main() {
    vector<int> value  { 2,4,6,9 };
    vector<int> weight { 2,2,4,5 };
    int total = 8;
    mem.resize(total+1, vector<int>(weight.size(), -1));
    dp( total, value, weight, 0 );
    cout << maxweight << endl;
    return 0;

}

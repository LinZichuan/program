#include <iostream>
#include <vector>
using namespace std;

int tree[20];
int maxval = 0;
int c(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);  //减去最低位的1
    }
    return sum;
}
void update(int idx, int val) {
    while(idx <= maxval) {
        tree[idx] += val; 
        idx += (idx & -idx);  //加上最低位的1
    }
}
int main () {
    vector<int> vec(17);
    memset(tree, 0, 20*sizeof(int));
    for (int i = 1; i < 17; ++i) {
        int val = i % 6;
        vec[i] = val;
        maxval = max(maxval, val);
        cout << vec[i] << ' ';
        update(i, val);
    }
    cout << endl;
    //9-10
    cout << c(10) - c(8) << endl;
    update(9, 2);
    cout << c(10) - c(8) << endl;
    return 0;
}

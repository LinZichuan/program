#include <iostream>
#include <vector>

using namespace std;

void constructTree(vector<int>& vec, vector<int>& segTree, int low, int high, int pos) {
    if (low == high) {
        segTree[pos] = vec[low];
        return;
    }
    int mid = (low + high) / 2;
    constructTree(vec, segTree, low, mid, 2*pos+1);
    constructTree(vec, segTree, mid+1, high, 2*pos+2);
    segTree[pos] = min( segTree[ 2*pos+1 ], segTree[ 2*pos+2 ] );
}

int query(vector<int>& segTree, int pos, int low, int high, int r1, int r2) {
    if (low >= r1 && high <= r2) {
        return segTree[pos];
    }
    if (low > r2 || high < r1) {
        return INT_MAX;
    }
    int mid = (low + high) / 2;
    int leftres = query(segTree, pos*2+1, low, mid, r1, r2);
    int rightres = query(segTree, pos*2+2, mid+1, high, r1, r2);
    return min(leftres, rightres);
}

void update(vector<int>& segTree, int treepos, int low, int high, int vecpos, int value) {
    if (vecpos < low || vecpos > high) return;
    if (low == high) {
        if (low == vecpos) segTree[low] = value;
        return;
    }
    int mid = (low + high) / 2;
    update(segTree, treepos*2+1, low, mid, vecpos, value);
    update(segTree, treepos*2+2, mid+1, high, vecpos, value);
    segTree[treepos] = min( segTree[treepos*2+1], segTree[treepos*2+2] );
}
int main() {
    vector<int> vec{-1, 2, 4, 0, 10, -5, 6};
    int len = vec.size() * 2 - 1;
    vector<int> segTree( len, INT_MAX );
    constructTree(vec, segTree, 0, vec.size()-1, 0);
    for_each( segTree.begin(), segTree.end(), [](int &x) { cout << x << " "; } );
    cout << endl;
    int r1 = 0, r2 = 5;
    int res = query(segTree, 0, 0, vec.size()-1, r1, r2);
    cout << res << endl;
    vec[3] = -10;
    update(segTree, 0, 0, vec.size()-1, 3, -10);
    res = query(segTree, 0, 1, vec.size()-2, r1, r2);
    cout << res << endl;
    return 0;
}

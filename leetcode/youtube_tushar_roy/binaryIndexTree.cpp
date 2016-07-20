#include <iostream>
#include <vector>

using namespace std;

class BIT {
public:
    vector<int> vec;
    vector<int> tree;
    BIT(vector<int> & vec_)  {
        int size = vec_.size();
        tree.resize(size+1, 0);
        vec.resize(size, 0);
        for (int i = 0; i < size; ++i) {
            cout << vec_[i] << " ";
            update(i, vec_[i]);
        }
        cout << endl;
    }
    void update(int pos, int value) {
        int idx = pos + 1;
        int delta = value - vec[pos];
        vec[pos] = value;
        while (idx < tree.size()) {
            tree[idx] += delta;
            idx += (idx & -idx);
        }
    }
    int get(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
    int query(int a, int b) {
        return get(b+1) - get(a);
    }
};

int main() {
    vector<int> vec{3,2,-1,6,5,4,-3,3,7,2,3};
    BIT bit(vec);
    for_each( vec.begin(), vec.end(), [](int x){ cout << x << " "; }) ;
    cout << endl;
    for (int i = 1; i < bit.tree.size(); ++i) 
        cout << bit.get(i) << " ";
    cout << endl;
    cout << bit.query(2,8) << endl;
    return 0;
}

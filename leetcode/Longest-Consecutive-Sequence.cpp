#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int *father;
    int *rank;
    map<int, int> m;
    int find_set(int node) {
        if(father[node] != node) {
            father[node] = find_set(father[node]);
        }
        return father[node];
    }
    void merge(int a, int b) {
        int ancestor1 = find_set(a);
        int ancestor2 = find_set(b);
        if (ancestor1 != ancestor2) {
            if (rank[ancestor1] > rank[ancestor2]) {
                swap(ancestor1, ancestor2);
            }
            father[ancestor1] = ancestor2;
            rank[ancestor2] = max(rank[ancestor1]+1, rank[ancestor2]);
        }
    }
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        father = new int[size];
        rank = new int[size];
        for (int i = 0; i < size; ++i) {
            father[i] = i;
            rank[i] = 0;
            m[nums[i]] = i;
        }
        for (int i = 0; i < size; ++i) {
            int curr = nums[i];
            if (m.find(curr-1) != m.end()) {
                merge(m[curr-1], i);
            }
            if (m.find(curr+1) != m.end()) {
                merge(m[curr+1], i);
            }
        }
        cout << "ok" << endl;
        int maxval = 0;
        int *res = new int[size];
        memset(res, 0, sizeof(int)*size);
        map<int, int> exist;
        for (int i = 0; i < size; ++i) {
            if (exist[nums[i]]) continue;
            exist[nums[i]] = 1;
            int f = find_set(i);
            res[f]++;
            if (res[f] > maxval) {
                maxval = res[f];
            }
        }
        return maxval;
    }
};

int main () {
    vector<int> nums({0,0,-1}); //{100, 4, 200, 1, 3, 2});
    cout << (new Solution())->longestConsecutive(nums) << endl;
    return 0;
}

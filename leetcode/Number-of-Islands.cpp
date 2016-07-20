/*
 * Union Find Set
 * Tow optimized method(84ms -> rank -> 12ms -> compress path ->11ms)
 * */
#include <iostream>
using namespace std;

class Solution {
public:
    int *father;
    int *rank;
    int find_set(int node) {
        if (father[node] != node) {
            father[node] = find_set(father[node]);
        }
        return father[node];
    }
    void merge(int x, int y) {
        int ancestor1 = find_set(x);
        int ancestor2 = find_set(y);
        if (ancestor1 != ancestor2) {
            if (rank[ancestor1] > rank[ancestor2]) {
                swap(ancestor1, ancestor2);
            }
            father[ancestor1] = ancestor2;
            rank[ancestor2] = max(rank[ancestor1]+1, rank[ancestor2]);
        }
    }
    int numIslands(vector<vector<char> >& grid) {
        int row = grid.size();
        if (row == 0) return 0;
        int col = grid[0].size();
        int size = row * col;
        vector<int> nums(0, size);
        father = new int[size];
        rank = new int[size];
        for (int i = 0; i < size; ++i) {
            father[i] = i;
            rank[i] = 0;
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '1') {
                    int index = i*col + j;
                    int right = i*col + j+1;
                    int down = (i+1)*col + j;
                    if (i < row-1) {
                        if (grid[i+1][j] == '1') {
                            merge(index, down);
                        }
                    }
                    if (j < col-1) {
                        if (grid[i][j+1] == '1') {
                            merge(index, right);
                        }
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < size; ++i) {
            int ii = find_set(i) / col;
            int jj = find_set(i) % col;
            if (grid[ii][jj] == '1') {
                grid[ii][jj] = '0';
                res++;
            }
        }
        return res;
    }
};

int main() {
    
}

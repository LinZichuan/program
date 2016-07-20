#include <iostream>
#include <vector>
#include <queue>
//#include <utility>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char> >& board) {
        int row = board.size();
        if (row <= 2) return;
        int col = board[0].size();
        queue< pair<int,int> > q;
        vector<vector<bool> > visit(row);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                visit[i].push_back(0);
            }
        }
        for (int j = 0; j < col; ++j) {
            if (board[0][j] == 'O') {
                q.push(make_pair(0, j));
            }
        }
        for (int j = 0; j < col; ++j) {
            if (board[row-1][j] == 'O') {
                q.push(make_pair(row-1, j));
            }
        }
        for (int i = 0; i < row; ++i) {
            if (board[i][0] == 'O') {
                q.push(make_pair(i, 0));
            }
        }
        for (int i = 0; i < row; ++i) {
            if (board[i][col-1] == 'O') {
                q.push(make_pair(i, col-1));
            }
        }
        while(!q.empty()) {
            auto point = q.front();
            q.pop();
            int x = point.first;
            int y = point.second;
            visit[x][y] = 1;
            if (x-1>=0 && visit[x-1][y] == 0 && board[x-1][y] == 'O') {
                q.push(make_pair(x-1, y));
            }
            if (y+1<col && visit[x][y+1] == 0 && board[x][y+1] == 'O') {
                q.push(make_pair(x, y+1));
            }
            if (x+1<row && visit[x+1][y] == 0 && board[x+1][y] == 'O') {
                q.push(make_pair(x+1, y));
            }
            if (y-1>=0 && visit[x][y-1] == 0 && board[x][y-1] == 'O') {
                q.push(make_pair(x, y-1));
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == 'O' && visit[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main() {
    vector<vector<char> > board({{'X','X','X','X'}, {'X','O','O','X'}, {'X','X','O','X'}, {'X','O','X','X'}});
    (new Solution())->solve(board);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}

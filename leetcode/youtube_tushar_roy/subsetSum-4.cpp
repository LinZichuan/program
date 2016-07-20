//Dynamic Programming
#include <set>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;


int main () {
    //set <int> a({1,4,2,3,5,10,7});
    //for (int e: a) {
    //    cout << e << endl;
    //}
    int total = 30;
    int items[5] = {2,3,7,8,10};
    int num = 5;
    vector<vector<int> > dp(num, vector<int>(total+1, 0));
    for (int i = 0; i < num; ++i) {
        dp[i][0] = 1;
    }
    for (int j = 0; j <= total; ++j) {
        if (items[0] == j) dp[0][j] = 1;
    }
    vector< vector< pair<int, int> > > path(num, vector< pair<int,int> >(total+1, make_pair(0,0)));
    for (int i = 1; i < num; ++i) {
        for (int j = 1; j <= total; ++j) {
            //dp[i][j] = dp[i-1][j-items[i]] ;
            if (j >= items[i]) {
                dp[i][j] = dp[i-1][j-items[i]];
                path[i][j] = make_pair(i-1, j-items[i]);
                if (dp[i][j] == 0 && dp[i-1][j] == 1) {
                    dp[i][j] = dp[i-1][j];
                    path[i][j] = make_pair(i-1, j);
                }
            } else {
                dp[i][j] = dp[i-1][j];
                path[i][j] = make_pair(i-1, j);
            }
        }
    }
    cout << dp[4][total] << endl;
    int i = 4, j = total;
    vector<int> vec;
    while(i||j) {
        pair<int,int> & p = path[i][j];
        if (p.second < j) vec.push_back(i);
        i = p.first;
        j = p.second;
    }
    for (int i = 0; i < vec.size(); ++i) 
        cout << vec[i] << " ";
    cout << endl;
    return 0;
}



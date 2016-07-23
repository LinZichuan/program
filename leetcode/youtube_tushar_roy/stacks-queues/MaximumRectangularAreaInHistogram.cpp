#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
using namespace std;

int main() {
    /*
     * (1) Add to stack if current value is equal or bigger than top of stack.
     * (2) Otherwise keep removing from stack till a number which is equal or bigger than current is found;
     * (3) Calculate area every time you remove 
     * if (stack is empty)
     *      area = input[top] * i;
     * else 
     *      area = input[top] * (i - stack.top - 1);
     */
    vector<int> hist { 1,2,4 };
    stack<int> S;
    int len = hist.size();
    int area = 0;
    int maxarea = -1;
    int i;
    for (i = 0; i < len;) {
        //Elements in S are indices!!!
        if ( S.empty() || hist[i] >= hist[S.top()] ) {  //!!!important!!! hist[S.top()], not S.top()
            S.push(i++);
        } else {
            int topindex = S.top();
            S.pop();
            if ( S.empty() ) {
                area = hist[topindex] * i;
            } else {
                area = hist[topindex] * (i - 1 - S.top());
            }
            maxarea = max( area, maxarea );
        }
    }
    while (!S.empty()) {
        int topindex = S.top();
        S.pop();
        if ( S.empty() ) {
            area = hist[topindex] * i;
        } else {
            area = hist[topindex] * (i - 1 - S.top());
        }
        maxarea = max( area, maxarea );
    }
    cout << maxarea << endl;
    return 0;
}

#include <iostream>
#include <queue>
#include <vector>
using namespace std;


class MedianFinder {
public:
    priority_queue<int> large;
    priority_queue<int, vector<int>, greater<int> > small;
    // Adds a number into the data structure.
    
    void addNum(int num) {
        //kepp small.size==large.size+1 or small.size==large.size()
        //large.size() == small.size()
        //large.size() < small.size()
        //large.size() > small.size()
        if (small.size() == 0)
            small.push(num);
        else if (large.size() == 0)
            large.push(num);
        else if (large.size() > 0 && small.size() > 0) {
            if (num < large.top())
                large.push(num);
            else
                small.push(num);
        }
        while(small.size() > 0 && large.size() > 0 && small.top() < large.top()) {
            large.push(small.top());
            small.pop();
        }
        while(large.size() > small.size()) {
            small.push(large.top());
            large.pop();
        }
        while(large.size() + 1 < small.size()) {
            large.push(small.top());
            small.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (small.size() == large.size()) {
            return double(small.top()+large.top())/2.0;
        } else {
            return small.top();
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();


int main () {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    mf.addNum(3);
    mf.addNum(4);
    mf.addNum(5);
    cout << mf.findMedian() << endl;

    return 0;
}

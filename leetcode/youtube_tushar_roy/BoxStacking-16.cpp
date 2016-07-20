//Hard!!!  Assemble to "Longest Increasing Subsequence"
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct less_than_area 
{
    inline bool operator() (const vector<int> & a, const vector<int> & b) {
        return (a[0]*a[1] > b[0]*b[1]);
    }
};

int main() {
    vector<vector<int>> wlh( {{1,2,4}, {3,2,5}} );
    vector<vector<int>> boxs;
    for (vector<int> b: wlh) {
        map<int,int> h;
        vector<int> box;
        box.push_back(b[1]);
        box.push_back(b[2]);
        box.push_back(b[0]);
        h[b[0]] = 1;
        boxs.push_back(box);
        if (h[b[1]] == 0) {
            box.clear();
            box.push_back(b[0]);
            box.push_back(b[2]);
            box.push_back(b[1]);
            h[b[1]] = 1;
            boxs.push_back(box);
        }
        if (h[b[2]] == 0) {
            box.clear();
            box.push_back(b[0]);
            box.push_back(b[1]);
            box.push_back(b[2]);
            h[b[2]] = 1;
            boxs.push_back(box);
        }
    }
    sort( boxs.begin(), boxs.end(), less_than_area() );
    for (vector<int> & b: boxs) {
        sort(b.begin(), b.end()-1);
    }
    for (vector<int> b: boxs) {
        cout << b[0] << " " << b[1] << " " << b[2] << endl;
    }
    int num = boxs.size();
    vector<int> maxheight;
    vector<int> parentbox(num, 0);
    for (vector<int>& v: boxs) {
        maxheight.push_back(v[2]);
    }
    //for_each( boxs.begin(), boxs.end(), [maxheight](vector<int>& v) { maxheight.push_back(v[2]); } );
    for (int i = 1; i < num; ++i) {
        for (int j = 0; j < i; ++j) {
            if (boxs[i][0] < boxs[j][0] && boxs[i][1] < boxs[j][1]) {
                if (maxheight[i] < maxheight[j] + boxs[i][2]) {
                    maxheight[i] = maxheight[j] + boxs[i][2];
                    parentbox[i] = j;
                }
            }
        }
    }
    for_each( maxheight.begin(), maxheight.end(), [](int x){ cout << x << " "; } );
    cout << endl;
    for_each( parentbox.begin(), parentbox.end(), [](int x){ cout << x << " "; } );
    cout << endl;
    auto it = max_element(maxheight.begin(), maxheight.end());
    int maxindex = it - maxheight.begin();
    cout << "max height = " << *it << endl;
    vector<int> res;
    res.push_back(maxindex);
    while (parentbox[maxindex] != maxindex) {
        res.push_back(parentbox[maxindex]);
        maxindex = parentbox[maxindex];
    }
    cout << "boxs index: ";
    for_each( res.begin(), res.end(), [](int x){ cout << x << " "; } );
    cout << endl;
    return 0;
}

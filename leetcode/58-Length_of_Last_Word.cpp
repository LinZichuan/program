#include <iostream> 
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int tail = len - 1;
        int index = 0;
        while (s[tail] == ' ') tail--;
        for (int i = tail ; i >=0 ; i--) {
            if (s[i] == ' ') {
                index = i + 1;
                break;
            }
        }
        return tail - index + 1;
    }
};

int main() {
    cout << (new Solution()) -> lengthOfLastWord(" I am a student ") << endl;
    return 0;
}

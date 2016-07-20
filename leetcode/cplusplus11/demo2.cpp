#include <iostream>

using namespace std;

class Info {
public:
    Info() : Info(1, 'a') {}
    Info(int i): Info(i, 'a') {}
    Info(char e): Info(1, e) {}
    int getType() { return type; }
    char getName() { return name; }
private:
    Info(int i, char e): type(i), name(e) {}
    int type;
    char name;
};

int main() {
    Info info;
    cout << info.getType() << endl;
    cout << info.getName() << endl;
    cout << is_rvalue_reference<string&&>::value << endl;
    return 0;    
}

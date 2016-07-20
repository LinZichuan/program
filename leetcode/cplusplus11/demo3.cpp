//complie options !!! g++ -std=c++11 demo3.cpp -fno-elide-constructors
#include <iostream>
#include <sys/time.h>
using namespace std;


template<class T>
void moveswap(T& a, T& b) {
    T tmp(move(a));
    a = move(b);
    b = move(tmp);
}
template<class T>
void naiveswap(T& a, T&b) {
    T tmp = a;
    a = b;
    b = tmp;
}
class A {
public:
    A() {}
    A(A & a): p(new int(*a.p)) {
        cout << "copy construct" << endl;
    }
    A(A && a): p(a.p) {
        a.p = nullptr;
        cout << "move construct" << endl; 
    }
    int *p = new int(1);
};
A GetTemp() {
    A a;
    cout << "temp constructor: ";
    return a;
}
int main() {
    string a = "sdfasdfsafsfsasdfawdf";
    string b = "sdafwerqwddvdfbgdfgfigopdfiogs";
    int step = 1e6;
    float t;
    timeval t1,t2;
    gettimeofday(&t1, 0);
    for (int i = 0; i < step; ++i) 
        swap(a,b);
    gettimeofday(&t2, 0);
    t = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec) * 1e6;
    cout << "move time = " << t << endl;

    gettimeofday(&t1, 0);
    for (int i = 0; i < step; ++i) 
        naiveswap(a,b);
    gettimeofday(&t2, 0);
    t = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec) * 1e6;
    cout << "naive time = " << t << endl;

    A tmpB = GetTemp();
    A instanceB = tmpB;
    A instanceA = GetTemp();
    cout << "instanceA.p = " << *instanceA.p << endl;
    return 0;
}

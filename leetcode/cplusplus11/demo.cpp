#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <stdio.h>

using namespace std;
#if __cplusplus < 201103L
    #error "should use C++11 implementation"
#endif

//template<typename Head, typename... tail> 
//void Print(Head head, typename... tail) {
//    cout << head << endl;
//    Print(tail...);
//}
void LOG(...) {
    fprintf(stderr, "%s: Line %d:\t", __FILE__, __LINE__);
    fprintf(stderr, "\n");
}
int main () {
    vector<int> iv{5, 4, 3, 2, 1};  
    int a = 2, b = 1;  
     
    for_each( iv.begin(), iv.end(), [b](int &x) {cout << (x + b) << endl;} ); // (1)  
    for_each( iv.begin(), iv.end(), [=](int &x) {cout << (a+b+x) << endl;} );
    for_each( iv.begin(), iv.end(), [=](int &x) -> int { return x*(a+b); } );

    //lambda expression
    function<int(int)> func = [](int i) { return i * 10; } ;
    auto print = []() { cout << "haha" << endl; };
    cout << func(100) << endl;
    print();

    std::vector<int> c { 1,2,3,4,5,6,7 };
    int x = 5;
    c.erase(std::remove_if(c.begin(), c.end(), [x](int n) { return n < x; } ), c.end());
    
    auto t1 = make_tuple(10, "Test", 3.14);
    cout << get<0>(t1) << " " << get<1>(t1) << " " << get<2>(t1) << endl;

    int n = 1;
    auto t2 = make_tuple(ref(n), n);
    cout << get<0>(t2) << " " << get<1>(t2) << endl;
    n = 7;
    cout << get<0>(t2) << " " << get<1>(t2) << endl;
    
    auto t3 = tuple_cat(t1, t2);

    tuple<int, float, string> newtuple;
    newtuple = make_tuple(1, 1.1, "str");
    int a1;
    float a2;
    string a3;
    tie(a1, a2, a3) = newtuple; // => make_tuple( ref(a1), ref(a2), ref(a3) )
    tie(a1, ignore, a3) = newtuple; // => make_tuple( ref(a1), ignore, ref(a3) )
    cout << a1 << " " << a2 << " " << a3 << endl;
    //Print(a1, a2, a3);
    //
    //
    vector<int> newvec{1,2,3,4,5};
    int arr[3]{1, 2, 3};
    map<int, string>{{1, "a"}, {2, "b"}};

    LOG("x = %d", 3);

    unique_ptr<int> up1(new int(1));
    cout << *up1 << endl;
    unique_ptr<int> up2 = move(up1);
    up2.reset();
    shared_ptr<int> sp1(new int(1));
    shared_ptr<int> sp2 = sp1;
    cout << *sp1 << " " << *sp2 << endl;

    static_assert(1==1, "false");

    return 0;
}

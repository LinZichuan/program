#include <iostream>

#if __cplusplus < 201103L
    #error "should use c++11"
#endif

class Base {
    public:
        virtual double func() = 0;
        virtual void print() = 0;
};
class A: public Base {
    public:
        double func() override;  //声明这是重载函数，防止拼写错误或者参数错误等不一致的继承
        void print() final;  //声明这是final，A的继承类不能再重载此函数
};

template <typename T=int, typename U=int> 
class DefClass {
    public: 
        DefClass(T a_, U b_): a(a_), b(b_) {}
        T a;
        U b;
};

template <typename T>
void print(T a) {
    std::cout << a << std::endl;
}

int main() {
    DefClass<int,int> defclass(0, 1);
    print("aaa");
    return 0;
}

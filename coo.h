#ifndef COO_H
#define COO_H


#include <iostream>
class Coo{
private:
    int d; //特意将d放在最前面，但实际上Coo类的对象内存中
           //在d前面还有一个指向vtable数组的指针变量
           //C++标准没有规定虚函数如何实现，但大部分编译器都使用vtable，
           //并把指向它的指针放在实际数据成员的前面
    virtual void foo(); //私有的,并且是虚的，因此会有vtable！
public:
    Coo():d(100){

    }
};

int testCoo();

#endif // COO_H


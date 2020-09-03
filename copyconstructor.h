#ifndef COPYCONSTRUCTOR_H
#define COPYCONSTRUCTOR_H
#include <iostream>
using std::cout;

/*
 * 本类举例讲述,深拷贝与浅拷贝的区别
 *
 * Q: 什么情况应该用深拷贝?   A: 当成员为指针的时候应该使用深拷贝,否则浅拷贝
 *
 */


//#define DEEP_COPY  //这个宏开启,就为深拷贝,比较安全, 否则浅拷贝,不安全

class Person
{
private:
    int age;
    char *name;
public:
    Person(int age,char *name);

 #ifdef DEEP_COPY
    Person(const Person & person); //拷贝构造函数
    Person & operator=(const Person & person ); //重载赋值运算符函数
 #endif
    ~Person();
    void display();
    static void  testCopyFn();
};




#endif // COPYCONSTRUCTOR_H

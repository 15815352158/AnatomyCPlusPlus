#ifndef CLASSFUN_H
#define CLASSFUN_H
#include <iostream>

/**
 * @brief The ClassFun class
 *本类主要举例介绍一个类默认的6个成员函数,什么时候调用
 *
 * 默认成员函数有6个
 * 构造函数
    析构函数
    拷贝构造函数
    赋值操作符(=)重载
    const修饰的取地址操作符重载
    取地址操作符(&)重载
 */
class ClassFun
{

public:
    ClassFun(); //构造函数,初始化用的
    ClassFun(const ClassFun &obj); //拷贝构造函数

    ClassFun & operator= (const ClassFun &obj); //赋值运算符重载函数
    ClassFun * operator& (   ); //取地址操作符函数

    /* 下面后面的那个const,修饰的是 *this, 我们知道,成员函数隐藏第一个参数就为本类型的一个this指针,它被隐藏起来,
     * 但是现在要用const修饰*this,     * 怎么办,那么就放在函数括号后面就可可以了,所以普通函数与静态函数,在那里是
     * 不能用const修饰这里这个const修饰的是 *this ,表明this所指的成员都不能改变
    */
    const ClassFun * operator&()const  ;   // const修饰的取地址操作符函数

    /*
     * 下面这个析构函数与构造函数很相似,多了~,  ~取非符号,表明下面这个函数的功能与构造函数的功能恰恰相反,
     * 用来做清理化,回收资源的工作
     */
    ~ ClassFun(); //析构函数,清理工作

 /*   ClassFun getObject( )
    {
        ClassFun object;
        std::cout<<"object:"<<&object<<std::endl;
        return object;
    }*/
};


void testClassFun();
#endif // CLASSFUN_H

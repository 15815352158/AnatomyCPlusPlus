#include "classfun.h"
#include <iostream>
//https://blog.csdn.net/weixin_43737259/article/details/100995806
ClassFun::ClassFun() //构造函数,初始化用的
{
    std::cout<<"默认构造函数"<<std::endl;
}


ClassFun::ClassFun(const ClassFun &obj)//拷贝构造函数
{
     std::cout<<"拷贝构造函数"<<std::endl;
}

 ClassFun & ClassFun::operator=(const ClassFun &obj) //赋值运算符重载函数
{
    std::cout<<"赋值运算符重载函数"<<std::endl;
    return *this;
}

ClassFun * ClassFun::operator&()//取地址操作符函数
{
    std::cout<<"取地址操作符函数"<<std::endl;
    return this;
}

const ClassFun * ClassFun::operator&()const // const修饰的取地址操作符函数
{
    std::cout<<"const修饰的取地址操作符函数"<<std::endl;
    return this;
}
ClassFun::~ClassFun() //析构函数,清理工作
{
    std::cout<<"析构函数"<<std::endl;
}

void testClassFun()
{

    ClassFun a; //调用构造函数

   // ClassFun kk=a.getObject();
   // std::cout<<"kk:"<<&kk<<"\n";

    const ClassFun b=a; //因为是初始化，调用的是拷贝构造函数，而非=运算符
    ClassFun c=ClassFun(a);//因为是初始化，调用的是拷贝构造函数，而非=运算符

    c=b; //调用=运算符

    ClassFun *ptr=&a; //调用取地址操作符函数
    const ClassFun * ptr1=&b; //调用const修饰的取地址操作符函数

}

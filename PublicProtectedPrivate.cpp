#include "PublicProtectedPrivate.h"
#include "iostream"

using std::cout;
//#define TEST_ERROR

Base::Base():a(1),b(2)   //普通成员变量也可以在这儿初始化
{   
   // this->a=1;  //这句开启会报错,为什么呢,只读变量,不能重新赋值,只能初始化
    this->b=2;
    this->c=3;
    this->d=4;    
}

void Base::display()
{
    std::cout<<" a:"<<this->a<<" b:"<<this->b<<" c:"<<this->c<<" d:"<<this->d<<"\n";
}

void Sub1::display()
{
 #ifdef TEST_ERROR
    std::cout<<" a:"<<this->a<<" b:"<<this->b;//会报错
 #endif

    std::cout<<" c:"<<this->c<<" d:"<<this->d<<"\n";
}

void Sub2::display()
{
#ifdef TEST_ERROR
    std::cout<<" a:"<<this->a<<" b:"<<this->b;//会报错
#endif
    std::cout<<" c:"<<this->c<<" d:"<<this->d<<"\n";
}

void Sub3::display()
{
#ifdef TEST_ERROR
    std::cout<<" a:"<<this->a<<" b:"<<this->b;
#endif
    std::cout<<" c:"<<this->c<<" d:"<<this->d<<"\n";
}


void tesetPulicProtectedPrivate()
{
    Base base;
#ifdef TEST_ERROR
    base.b=100;  //会报错
    base.c=4;    //会报错
#endif
    base.d=56;


    Sub1 sub1;
#ifdef TEST_ERROR
    sub1.c=30; //会报错
    sub1.b=100; //会报错
#endif
    sub1.d=6;  //public: 外部可以访问修改

    sub1.display();

    Sub2 sub2;
#ifdef TEST_ERROR
    sub2.b=0;//会报错
    sub2.c=3;//会报错
    sub2.d=4;//会报错
#endif
    Sub3 sub3;
#ifdef TEST_ERROR
    sub3.b=0;//会报错
    sub3.c=3;//会报错
    sub3.d=4;//会报错
#endif

}




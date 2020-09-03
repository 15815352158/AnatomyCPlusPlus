#include "virtualfun.h"
#include "iostream"

 BaseA::BaseA(int a, int b)
 {
     this->a=a;
     this->b=b;
 }


MidleB::MidleB(int a,int b,int c):BaseA(a,b)
{
    this->c=c;
}

BaseD::BaseD(int d)
{
    this->d=d;
}

void BaseD::print()
{
    std::cout<<"d: "<<d<<std::endl;
}

VirtualFun::VirtualFun(int a,int b,int c):MidleB( a, b, c),BaseD(b)
{
    this->d++;
}

VirtualFun::display()
{
    std::cout<<"b: "<<b<<" c:"<<c<<std::endl;
}


void VirtualFun::testVirtualFun()
{
    VirtualFun virtualFun(1,2,3);
    virtualFun.display();
}

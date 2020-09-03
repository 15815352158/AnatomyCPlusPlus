#include "PublicProtectedPrivate.h"
#include "iostream"

using std::cout;
//#define TEST_ERROR

Base::Base():a(1),b(2)   //��ͨ��Ա����Ҳ�����������ʼ��
{   
   // this->a=1;  //��俪���ᱨ��,Ϊʲô��,ֻ������,�������¸�ֵ,ֻ�ܳ�ʼ��
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
    std::cout<<" a:"<<this->a<<" b:"<<this->b;//�ᱨ��
 #endif

    std::cout<<" c:"<<this->c<<" d:"<<this->d<<"\n";
}

void Sub2::display()
{
#ifdef TEST_ERROR
    std::cout<<" a:"<<this->a<<" b:"<<this->b;//�ᱨ��
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
    base.b=100;  //�ᱨ��
    base.c=4;    //�ᱨ��
#endif
    base.d=56;


    Sub1 sub1;
#ifdef TEST_ERROR
    sub1.c=30; //�ᱨ��
    sub1.b=100; //�ᱨ��
#endif
    sub1.d=6;  //public: �ⲿ���Է����޸�

    sub1.display();

    Sub2 sub2;
#ifdef TEST_ERROR
    sub2.b=0;//�ᱨ��
    sub2.c=3;//�ᱨ��
    sub2.d=4;//�ᱨ��
#endif
    Sub3 sub3;
#ifdef TEST_ERROR
    sub3.b=0;//�ᱨ��
    sub3.c=3;//�ᱨ��
    sub3.d=4;//�ᱨ��
#endif

}




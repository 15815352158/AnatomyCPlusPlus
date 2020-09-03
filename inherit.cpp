#include "inherit.h"
#include <QDebug>

using namespace  std;

//#define TEST;

A::A(int a,int b)
{
    this->a=a;
    this->b=b;
    qDebug()<<"A::A==>a:"<<a<<"b:"<<b<<"\n";
}

void A::f1()
{
   qDebug()<<"A::f1\n";
}
 void A::f2()
{
#ifdef TEST
   qDebug()<<"A::f2";
#else
   qDebug()<<"A::f2==>a:"<<a<<"b:"<<b<<"\n";
#endif
}
void A::f3()
{
#ifdef TEST
    qDebug()<<"A::f3";
#else
    qDebug()<<"A::f3==>a:"<<a<<"b:"<<b<<"\n";
#endif
}

B::B(int a,int c,int d)
{
    this->a=a;
    this->c=c;
    this->d=d;

    qDebug()<<"B::B==>a:"<<a<<"c:"<<c<<" d"<<d<<"\n";
}

 void B::f2()
{
#ifdef TEST
    qDebug()<<"B::f2";
#else
   qDebug()<<"B::f2==>a:"<<a<<"c:"<<c<<" d"<<d<<"\n";
#endif
}

void B::f3()
{
#ifdef TEST
    qDebug()<<"B::f3";
#else
   qDebug()<<"B::f3==>a:"<<a<<"c:"<<c<<" d"<<d<<"\n";
#endif
}

 void B::f4()
{
   qDebug()<<"B::f4\n";
}


/*
 子类的构造函数一定要初始化父类的构造函数,除非父类有缺省参数的构造函数,这样系统自动帮你初始化,
 不需要在子类构造函数的初始化列表中明确写出来,下面构造函数后冒号后面的为初始化列表
 此处,可以初始化父类的构造函数,本类中const修饰的只读成员或者非普通成员
*/
C::C(int a,int b,int c,int d,int e) : B(a-1,c-1,d-1),A(a+1,b+1)
{
   qDebug()<<"A::b"<<A::b<<"\n";
   this->b=b;
   qDebug()<<"A::b"<<A::b<<"\n";

   qDebug()<<"B::d"<<B::d<<"\n";
   this->d=d;
   qDebug()<<"B::d"<<B::d<<"\n";

   this->e=e;
   qDebug()<<"C::C==>"<<"b:"<<b<<" d:"<<d<<" e:"<<e<<"\n";
}

 void C::f1()
{
  qDebug()<<"C::f1\n";
}
 void C::f2()
{
#ifdef TEST
    qDebug()<<"C::f2";
#else
  qDebug()<<"C::f2==>"<<"b:"<<this->b<<" d:"<<this->d<<" e:"<<this->e<<"\n";
#endif
}
 void C::f5()
{
  qDebug()<<"C::f5\n";
}
void C::f3()
{
    qDebug()<<"C::f3"<<"\n";
}

void C::f6()
{
  this->A::f3();
  this->B::f3();
  qDebug()<<"C::f6\n";
}




typedef void ( * Fun)();
typedef void ( B::* Fun2)(); //定义类成员函数指针
typedef void ( C::* Fun3)();

void testFn()
{
    C *c=new C(1,2,3,4,5);
    qDebug()<<"=============0===============\n";
    c->f1();
    c->f2();
    c->f3();
    c->f4();
    c->f5();
    c->f6();

    qDebug()<<"=============1===============\n";


    B *b=c;
    A *a=c;


    a->f1();
    a->f2();
    a->f3();

    qDebug()<<"=============2===============\n";
    b->f2();
    b->f3();
    b->f4();

    qDebug()<<"==============3==============\n";
    qDebug("a:%p, b:%p,c:%p\n",a,b,c);// 这里思考一下看看三个指针值是否相同

    //这里思考一下三个类型的尺寸
    qDebug()<<"A::size="<<sizeof(A)<<"B::size="<<sizeof(B)<<"A::size="<<sizeof(C)<<"\n";

    int *num= (int *)(c);
    for(int i=0;i<8;i++)
    {
        qDebug("num:%0x\n",*num);
        num++;
    }
    qDebug()<<"==============4==============\n";

    int * vTableA=(int *) *(int *)a;
    int * vptrA=(int *) *vTableA;

    qDebug("A类虚函数表的地址:%p\n",vTableA);
    qDebug("A类虚函数表中第一个虚函数的地址:%p\n",vptrA);
#ifdef TEST
    int i=0;
    while(vptrA && i<3)
    {
        i++;
        Fun ff=(Fun)vptrA;
        ff();

        vTableA++;
        vptrA=(int *) *vTableA;

    }
    qDebug()<<"==============5==============\n";
#endif

    int * vTableB=(int *) *( ((int *)b) + 0);
    //int * vTableB=(int *) *( ((int *)c) + 3);
    int * vptrB=(int *) *vTableB;

    qDebug("B类虚函数表的地址:%p\n",vTableB);
    qDebug("B类虚函数表中第一个虚函数的地址:%p\n",vptrB);

#ifdef TEST

    i=0;
    while(vptrB && i<2)
    {
        i++;
        Fun ff=(Fun)vptrB;
        ff();

        vTableB++;
        vptrB=(int *) *vTableB;

    }
    qDebug()<<"==============6==============\n";
#endif

   // Fun3 fun=(Fun)vptr; //这里强制转换不了
    Fun3 fun=&C::f2;
    (c->*fun)();

    qDebug()<<"==============7==============\n";
}

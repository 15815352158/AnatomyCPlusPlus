#ifndef INHERIT_H
#define INHERIT_H

class A
{
private :
    int a;
public:
    int b;

    A(int a,int b);

    virtual void f1();   //–È∫Ø ˝”√ virtual –ﬁ Œ
    virtual void f2();

    void f3();

};

class B
{
private :
    int c;
    int a;
public:
    int d;

    B(int a,int c,int d);
    virtual void f2();
    void f3();
    virtual void f4();

};

class C:public A,public B
{

 private:
       int e;
 public:
       C(int a,int b,int c,int d,int e);

       virtual void f1();
       virtual void f2();
       virtual void f5();

       void f3();
       void f6();


};

void testFn();

#endif // INHERIT_H

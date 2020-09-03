#ifndef VIRTUALFUN_H
#define VIRTUALFUN_H

class BaseA
{
private :
    int a;
protected:
    int b;

public :
      BaseA(int a, int b);

};

class MidleB:protected BaseA
{
protected:
       int c;
public:
    MidleB(int a,int b,int c);

};

class BaseD
{
public:
    int d;
public:
     BaseD(int d);
     virtual void print();
};

class VirtualFun:public MidleB, BaseD
{
protected :
    int f;
public:
    VirtualFun(int a,int b,int c);
    virtual display();
    static void testVirtualFun();
};



#endif // VIRTUALFUN_H

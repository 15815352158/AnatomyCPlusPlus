#ifndef PUBLICPROTECTEDPRIVATE_H
#define PUBLICPROTECTEDPRIVATE_H
/*
 * 访问权限有: private, protected, public
 *
 * private修饰的成员或函数: 本类的成员函数可以访问,其它任何地方不可以访问     (一级保密) 自己的秘密,连自己亲生儿子都不能说
 * protected修饰的成员或函数: 本类的成员函数和派生类的成员函数可以访问,其它任何地方不可以访问,  (二级保密) 自己的密码,只对亲生儿子说
 * public修饰的成员或函数: 处处可以访问  (公开的秘密) 不用说,所有人都知道
 *
 * 访问权限排序:  private < protected < public
 *
 * 继承私有永不见, 其它继承最小化.  :  基类私有成员或者函数,在派生类中怎么也访问不了,其它方式继承取决于成员修饰与继承修饰的最小的那个权限.
 * 权限保持或缩小, 不可以妄想增大.  :  基础类中的成员或函数的权限,不可以加大, 因为如果可以加大,那么基类相应保密的全部你都可以公开,
 *                                    这就等于说一个儿子把他老子告诉他的密码,公之于众,肯定是他老爹不允许的(暴揍).
 */

class Base
{
    //缺省方式为private
    const int a;  //定义一个只读变量, 它是变量,非常量,但你可以把它当作常量来使用,本质是变量
private:  //私有
     int b;
protected: //保护
     int c;
public:  //公有
     int d;

     Base();//默认构造函数
     void display();

};


class Sub1: public Base
{
 public:
    void display();

};

class Sub2: protected Sub1
{
public:  //公有
    void display();
};

class Sub3: private Sub1
{
public:  //公有
    void display();
};

void tesetPulicProtectedPrivate();

#endif // PUBLICPROTECTEDPRIVATE_H

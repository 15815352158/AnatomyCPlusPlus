#include "copyconstructor.h"
#include <cstring>

#define  SHALLOW_COPY 0   //如果值为1,必然是浅拷贝

Person::Person(int age,char *name)
{
    this->age=age;
    this->name=new char[strlen(name)+1];
    strcpy(this->name,name);
}

 #ifdef DEEP_COPY
Person::Person(const Person & person) //拷贝构造函数
{    
    this->age=person.age;

#if SHALLOW_COPY
    this->name=person.name;//浅拷贝
#else
    //下面是深拷贝
    this->name=new char[strlen(person.name)+1];
    strcpy(this->name,person.name);
#endif
}

Person & Person::operator=(const Person & person ) //重载赋值运算符函数
{
    std::cout<<"=====\n";
    if( this!=&person )
    {
        this->age=person.age;

        if(this->name)
        {
            delete this->name;
        }

#if SHALLOW_COPY
        this->name=person.name;//浅拷贝
#else
        //下面是深拷贝
        this->name=new char[strlen(person.name)+1];
        strcpy(this->name,person.name);
#endif
    }

    return *this;
}
#endif

Person::~Person()
{
    if(this->name)
    {
        delete this->name;
        this->name=NULL;
    }
}

void Person::display()
{
    std::cout<<this->name<<" "<<this->age<<"\n";
}

/*下面不能再用static去修饰了,类的内部修饰就可以了,
另外,类的静态成员函数不能在类的内部定义,只能在类的内部声明
类的静态成员函数本质: 是将外部的普通函数加入到内的作用越中,并不是
把他加到内中,所以静态成员函数没有隐藏this指针
*/
/* static */ void  Person::testCopyFn()
{
     Person * zhangwuji= new Person(25,"zhangwuji");
     zhangwuji->display();

     Person zhaomin=*zhangwuji;
     zhaomin.display();

     Person zhouziru(22,"zhouziru");
     zhouziru.display();
     zhouziru=zhaomin;

     delete zhangwuji;

     zhaomin.display();
     zhouziru.display();

}


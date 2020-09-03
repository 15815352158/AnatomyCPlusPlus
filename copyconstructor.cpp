#include "copyconstructor.h"
#include <cstring>

#define  SHALLOW_COPY 0   //���ֵΪ1,��Ȼ��ǳ����

Person::Person(int age,char *name)
{
    this->age=age;
    this->name=new char[strlen(name)+1];
    strcpy(this->name,name);
}

 #ifdef DEEP_COPY
Person::Person(const Person & person) //�������캯��
{    
    this->age=person.age;

#if SHALLOW_COPY
    this->name=person.name;//ǳ����
#else
    //���������
    this->name=new char[strlen(person.name)+1];
    strcpy(this->name,person.name);
#endif
}

Person & Person::operator=(const Person & person ) //���ظ�ֵ���������
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
        this->name=person.name;//ǳ����
#else
        //���������
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

/*���治������staticȥ������,����ڲ����ξͿ�����,
����,��ľ�̬��Ա��������������ڲ�����,ֻ��������ڲ�����
��ľ�̬��Ա��������: �ǽ��ⲿ����ͨ�������뵽�ڵ�����Խ��,������
�����ӵ�����,���Ծ�̬��Ա����û������thisָ��
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


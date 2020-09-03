#ifndef COPYCONSTRUCTOR_H
#define COPYCONSTRUCTOR_H
#include <iostream>
using std::cout;

/*
 * �����������,�����ǳ����������
 *
 * Q: ʲô���Ӧ�������?   A: ����ԱΪָ���ʱ��Ӧ��ʹ�����,����ǳ����
 *
 */


//#define DEEP_COPY  //����꿪��,��Ϊ���,�Ƚϰ�ȫ, ����ǳ����,����ȫ

class Person
{
private:
    int age;
    char *name;
public:
    Person(int age,char *name);

 #ifdef DEEP_COPY
    Person(const Person & person); //�������캯��
    Person & operator=(const Person & person ); //���ظ�ֵ���������
 #endif
    ~Person();
    void display();
    static void  testCopyFn();
};




#endif // COPYCONSTRUCTOR_H

#include "classfun.h"
#include <iostream>
//https://blog.csdn.net/weixin_43737259/article/details/100995806
ClassFun::ClassFun() //���캯��,��ʼ���õ�
{
    std::cout<<"Ĭ�Ϲ��캯��"<<std::endl;
}


ClassFun::ClassFun(const ClassFun &obj)//�������캯��
{
     std::cout<<"�������캯��"<<std::endl;
}

 ClassFun & ClassFun::operator=(const ClassFun &obj) //��ֵ��������غ���
{
    std::cout<<"��ֵ��������غ���"<<std::endl;
    return *this;
}

ClassFun * ClassFun::operator&()//ȡ��ַ����������
{
    std::cout<<"ȡ��ַ����������"<<std::endl;
    return this;
}

const ClassFun * ClassFun::operator&()const // const���ε�ȡ��ַ����������
{
    std::cout<<"const���ε�ȡ��ַ����������"<<std::endl;
    return this;
}
ClassFun::~ClassFun() //��������,������
{
    std::cout<<"��������"<<std::endl;
}

void testClassFun()
{

    ClassFun a; //���ù��캯��

   // ClassFun kk=a.getObject();
   // std::cout<<"kk:"<<&kk<<"\n";

    const ClassFun b=a; //��Ϊ�ǳ�ʼ�������õ��ǿ������캯��������=�����
    ClassFun c=ClassFun(a);//��Ϊ�ǳ�ʼ�������õ��ǿ������캯��������=�����

    c=b; //����=�����

    ClassFun *ptr=&a; //����ȡ��ַ����������
    const ClassFun * ptr1=&b; //����const���ε�ȡ��ַ����������

}

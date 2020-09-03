#ifndef PUBLICPROTECTEDPRIVATE_H
#define PUBLICPROTECTEDPRIVATE_H
/*
 * ����Ȩ����: private, protected, public
 *
 * private���εĳ�Ա����: ����ĳ�Ա�������Է���,�����κεط������Է���     (һ������) �Լ�������,���Լ��������Ӷ�����˵
 * protected���εĳ�Ա����: ����ĳ�Ա������������ĳ�Ա�������Է���,�����κεط������Է���,  (��������) �Լ�������,ֻ����������˵
 * public���εĳ�Ա����: �������Է���  (����������) ����˵,�����˶�֪��
 *
 * ����Ȩ������:  private < protected < public
 *
 * �̳�˽��������, �����̳���С��.  :  ����˽�г�Ա���ߺ���,������������ôҲ���ʲ���,������ʽ�̳�ȡ���ڳ�Ա������̳����ε���С���Ǹ�Ȩ��.
 * Ȩ�ޱ��ֻ���С, ��������������.  :  �������еĳ�Ա������Ȩ��,�����ԼӴ�, ��Ϊ������ԼӴ�,��ô������Ӧ���ܵ�ȫ���㶼���Թ���,
 *                                    ��͵���˵һ�����Ӱ������Ӹ�����������,��֮����,�϶������ϵ��������(����).
 */

class Base
{
    //ȱʡ��ʽΪprivate
    const int a;  //����һ��ֻ������, ���Ǳ���,�ǳ���,������԰�������������ʹ��,�����Ǳ���
private:  //˽��
     int b;
protected: //����
     int c;
public:  //����
     int d;

     Base();//Ĭ�Ϲ��캯��
     void display();

};


class Sub1: public Base
{
 public:
    void display();

};

class Sub2: protected Sub1
{
public:  //����
    void display();
};

class Sub3: private Sub1
{
public:  //����
    void display();
};

void tesetPulicProtectedPrivate();

#endif // PUBLICPROTECTEDPRIVATE_H

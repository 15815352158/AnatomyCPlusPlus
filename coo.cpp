
#include "coo.h"

void Coo::foo(){
    //std::cout<<d<<" ~~~!!!~~~ "<<std::endl;
    std::cout<<"This:"<<this<<std::endl;
    std::cout<<"000000000000000000"<<std::endl;
    //std::cout<<d<<" ~~~!!!~~~ "<<std::endl;
}

int testCoo(){
    Coo o;
    int *p=(int*)(&o); //p是强制将o的地址转换为一个整数指针，这样
                       //p中存放的就是vtable的内存起始地址
    int addr=*(int*)(*p); //addr是将p中的内容，再强制当作是一个整数指针，
                         //然后取出该指针指向的内容，就是函数Coo::foo的地址

    //若Coo::foo不是virtual,则d前面不会有vtable，下面输出会是d的值100的，
    //但现在*p应该会输出vtable的内存地址
    std::cout<<"The vtable's address: "<<*p<<std::endl;
    printf("*p:%p,addr:%p",(int *)*p,(int *)addr);
    //现在输出的addr就是Coo::foo函数的地址
    std::cout<<"The Coo::foo's address: "<<addr<<std::endl;
    //为确认这一点，可以定义一个函数指针pfunc,并把addr(转换成函数指针后)赋给它,
    //然后调用这个函数指针，就会导致函数Coo::foo函数的执行
    typedef void (*PFUNC)(Coo*);
    PFUNC pfunc=(PFUNC)(addr);

    std::cout<<"o:"<<&o<<std::endl;

    pfunc(&o); //hack!直接调用了私有成员函数Coo::foo

    return 0;
}
//https://blog.csdn.net/qq_40927789/article/details/81294336

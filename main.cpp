#include <QCoreApplication>
#include <QDebug>

#include  "coo.h"
#include "classfun.h"
#include "inherit.h"
#include "copyconstructor.h"
#include "PublicProtectedPrivate.h"
#include "virtualfun.h"

int main(int argc, char *argv[])
{

    QCoreApplication aa(argc, argv);

    //tesetPulicProtectedPrivate();
   // testCoo();
   //testClassFun();

   //Person::testCopyFn();
    VirtualFun::testVirtualFun();

    VirtualFun virtualFun(1,2,3);
    virtualFun.display();

   return aa.exec();
}

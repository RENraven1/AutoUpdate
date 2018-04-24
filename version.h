#ifndef VERSION_H
#define VERSION_H
#include <QString>

class Version
{
    int major,minor,patch,build;



public:
QString version;
   Version(int zmajor, int zminor, int zpatch, int zbuild)
{
   major=zmajor;
   minor=zminor;
   patch=zpatch;
   build=zbuild;
}
   Version(QString zversion)
{
       version=zversion;
   }
   void Verss()
   {qDebug()<<"VERSS"<<version;}
   void Versl()
      {  qDebug()<<"magor"<<major;}
};


#endif // VERSION_H

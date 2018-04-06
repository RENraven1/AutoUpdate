#ifndef VERSION_H
#define VERSION_H
#include <QString>

class Version
{
    int major,minor,patch,build;

    QString version;

public:

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

};


#endif // VERSION_H

#include "autoup.h"
#include <QApplication>
#include <QFile>
#include <QtXml/QDomDocument>
#include <QLabel>
#include <QDebug>
#include <stdio.h>
#include <QtNetwork/QNetworkReply>
#include <downloader.h>
#include <QObject>
#include <version.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//printf("THE WORK !1  \n");
    qDebug() << "NACHALO" ;
autoup w;
w.show();
    QDomDocument d;
 QFile file("C:\\Users\\REN\\Documents\\eyecu\\components.xml");

 d.setContent(&file);

 QDomElement packages=d.documentElement();
/*
 for (QDomElement package=packages.firstChildElement("Package"); !package.isNull(); package=package.nextSiblingElement("Package"))
 {
 QString name=package.firstChildElement("Name").text();
   qDebug() << "name"<<name ;

 QString version=package.firstChildElement("Version").text();
 qDebug() << "version"<<version ;

 }*/

 Downloader *downloader = new Downloader();
 downloader->getData();



 qDebug() << "the end" ;
 //printf("THE END");

    return a.exec();
}

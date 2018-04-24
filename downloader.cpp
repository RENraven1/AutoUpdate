#include "downloader.h"
#include "QDomDocument"
#include<version.h>
#include<autoup.h>
Downloader::Downloader(QObject *parent) : QObject(parent)
{
    // Инициализируем менеджер ...
    manager = new QNetworkAccessManager();

    // ... и подключаем сигнал о завершении получения данных к обработчику полученного ответа
   // connect(manager, &QNetworkAccessManager::finished, this, &Downloader::onResult);
connect(manager,SIGNAL(finished(QNetworkReply*)),SLOT(onResult(QNetworkReply*)));
}

void Downloader::getData()
{

    QUrl url("http://www.eyecu.ru/repository/Updates.xml"); // URL, к которому будем получать данные
    QNetworkRequest request;    // Отправляемый запрос
    request.setUrl(url);        // Устанавлвиваем URL в запрос
    manager->get(request);      // Выполняем запрос

}

void Downloader::devas()
{



}


void Downloader::onResult(QNetworkReply *reply)
{     qDebug()<<"Qnetwork"<<reply->error();

     QDomDocument d;
   //QFile file("C:\\Users\\REN\\Documents\\eyecu\\components.xml");
//  QFile file("C:\\Program Files (x86)\\Road Works Software\\eyecu\\components.xml");
       QFile file("C:\\Users\\Ren\\Documents\\COMPONENTS\\components.xml");
   d.setContent(&file);
  if(file.isOpen()){qDebug() << "FILE OPEN";}

   QDomElement packages=d.documentElement();
  QHash<QString,QString> installedPackages;
  // QDomElement Updates=q.documentElement();
  //if(PackageUpdate.isNull())
  //{qDebug() << "isNull"<<PackageUpdate.isNull();}


     for (QDomElement PackageUpdate=packages.firstChildElement("Package"); !PackageUpdate.isNull(); PackageUpdate=PackageUpdate.nextSiblingElement("Package"))
     {// qDebug() << "Downloading COMPLETE ";



     QString name=PackageUpdate.firstChildElement("Name").text();
      qDebug() << "name1"<<name ;

     QString version=PackageUpdate.firstChildElement("Version").text();
     qDebug() << "version1"<<version ;
  //Version Vers(version);
     installedPackages.insert(name, version);
   QString vers=installedPackages.value(name);


     }

     QFile *files = new QFile("C:\\Users\\REN\\Documents\\file2.xml");

     if(files->open(QFile::WriteOnly)){

       files->write(d.toByteArray());

              files->close();}

 /////////////////////////////////////////////////////////////////////////////////////////////////
      QDomDocument q;
      q.setContent(reply);

      QDomElement Updates=q.documentElement();

        for (QDomElement PackageUpdate=Updates.firstChildElement("PackageUpdate"); !PackageUpdate.isNull(); PackageUpdate=PackageUpdate.nextSiblingElement("PackageUpdate"))
        {

        QString name=PackageUpdate.firstChildElement("Name").text();
          qDebug() << "name"<<name ;

        QString version=PackageUpdate.firstChildElement("Version").text();
     qDebug() << "version"<<version ;
       QStringList list=version.split(".", QString::SkipEmptyParts);
        QStringList list2;
       QString def="DEFINE";
        QString vers=installedPackages.value(name,def);
        if(vers==def)
        qDebug()<<"NO MATCH"<<name<<endl;
        else
    //    qDebug()<<"str"<<vers<<endl;
       { QStringList list2=vers.split(".",QString::SkipEmptyParts);
        for(int i=0;i<list.size();++i){

          QString siz=list.at(i);
          QString siz2=list2.at(i);
          if(siz!=siz2)
              qDebug()<<"NOT VERSION"<<endl;


           qDebug()<<"siz"<<siz<<i;
            qDebug()<<"siz2"<<siz2<<i;
           }

     //    qDebug()<<"LIST"<<list;

      //  qDebug()<<"LIST"<<list2;
  //    }
 //    qDebug()<<"Qnetwork"<<reply->error();
  // Если в процесе получения данных произошла ошибка
  //  if(reply->error()){
        // Сообщаем об этом и показываем информацию об ошибках
    //    qDebug() << "ERROR";
     //   qDebug() << reply->errorString();
    //} else {
        // В противном случае создаём объект для работы с файлом
      //  QFile *file = new QFile("D:\\Project\\autoupdate\\AutoUpdate\\file1.xml");
   //     QFile *file = new QFile("C:\\Users\\REN\\Documents\\file1.xml");
        // Создаём файл или открываем его на перезапись ...
  //      if(file->open(QFile::WriteOnly)){
//            qDebug() << "Downloading ";
//          file->write(q.toByteArray());
          //file->write(reply->readAll());

            // ... и записываем всю информацию со страницы в файл
    //        file->close();                  // закрываем файл


  //      qDebug() << "Downloading is completed";
        emit onReady(); }// Посылаем сигнал о завершении получения файла
        }}




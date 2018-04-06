#include "downloader.h"
#include "QDomDocument"
#include<version.h>
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
    qDebug()<<"getDAta pochla";
    QUrl url("http://www.eyecu.ru/repository/Updates.xml"); // URL, к которому будем получать данные
    QNetworkRequest request;    // Отправляемый запрос
    request.setUrl(url);        // Устанавлвиваем URL в запрос
    manager->get(request);      // Выполняем запрос

}
/*
void Downloader::devas(QIODevice *dev)
{

    QDomDocument q;
    q.setContent(dev);
    qDebug()<<"dddd";
    QFile *file2 = new QFile("C:\\Users\\REN\\Documents\\autoupdate2\\file2.xml");
    file2->write(dev->readAll());
    if(!dev->atEnd());
    dev->close();

}
*/
void Downloader::onResult(QNetworkReply *reply)
{     qDebug()<<"Qnetwork"<<reply->error();
      QDomDocument q;
      q.setContent(reply);

      QDomElement Updates=q.documentElement();

        for (QDomElement PackageUpdate=Updates.firstChildElement("PackageUpdate"); !PackageUpdate.isNull(); PackageUpdate=PackageUpdate.nextSiblingElement("PackageUpdate"))
        {
            QHash<QString,Version> installedPackages;


        QString name=PackageUpdate.firstChildElement("Name").text();
          qDebug() << "name"<<name ;

        QString version=PackageUpdate.firstChildElement("Version").text();
        qDebug() << "version"<<version ;

        installedPackages.insert(name, Version(version));
      }


  // Если в процесе получения данных произошла ошибка
  //  if(reply->error()){
        // Сообщаем об этом и показываем информацию об ошибках
    //    qDebug() << "ERROR";
     //   qDebug() << reply->errorString();
    //} else {
        // В противном случае создаём объект для работы с файлом
        QFile *file = new QFile("C:\\Users\\REN\\Documents\\autoupdate2\\file.xml");
        // Создаём файл или открываем его на перезапись ...
        if(file->open(QFile::WriteOnly)){
            file->write(reply->readAll());  // ... и записываем всю информацию со страницы в файл
            file->close();                  // закрываем файл
        qDebug() << "Downloading is completed";
        emit onReady(); // Посылаем сигнал о завершении получения файла
        }
    }
//}


#ifndef DOWNLOADER_H
#define DOWNLOADER_H
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QUrl>
#include <QDebug>

class Downloader : public QObject
{
    Q_OBJECT
public:
    explicit Downloader(QObject *parent = 0);
    void getData();
    void devas(QIODevice *dev);// Метод инициализации запроса на получение данных

signals:
    void onReady();

public slots:

    void onResult(QNetworkReply *reply);    // Слот обработки ответа о полученных данных

private:
    QNetworkAccessManager *manager; // менеджер сетевого доступа
};




#endif // DOWNLOADER_H

#ifndef JSCONTEXT_H
#define JSCONTEXT_H

#include <QMainWindow>
#include <QMessageBox>
#include <QWebEngineView>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QWebChannel>


class JsContext : public QObject
{
    Q_OBJECT
public:
    JsContext();
    ~JsContext();

public slots:
    void getCoordinates(QString lon, QString lat);
    void getObjectIndex(QString index);
signals:
    void CoordinatesGet(QString lon, QString lat);
    void ObjectIndexGet(QString index);
};

#endif // JSCONTEXT_H

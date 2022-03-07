#include "jscontext.h"
#include <QDebug>
JsContext::JsContext()
{

}

JsContext::~JsContext()
{

}

void JsContext::getCoordinates(QString lon, QString lat)
{
    QString tempLon = lon+"°";
    QString tempLat = lat+"°";
    emit CoordinatesGet(tempLon, tempLat);
}


void JsContext::getObjectIndex(QString index)
{
    emit ObjectIndexGet(index);
}

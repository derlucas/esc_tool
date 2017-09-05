/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef CONFIGPARAMS_H
#define CONFIGPARAMS_H

#include <QObject>
#include <QHash>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include "configparam.h"
#include "vbytearray.h"

class ConfigParams : public QObject
{
    Q_OBJECT
public:
    explicit ConfigParams(QObject *parent = 0);
    void addParam(const QString &name, ConfigParam param);
    void deleteParam(const QString &name);
    void setUpdateOnly(const QString &name);
    QString getUpdateOnly();
    bool getUpdatesEnabled() const;
    void setUpdatesEnabled(bool updatesEnabled);
    void clearParams();
    void clearAll();

    bool hasParam(const QString &name);
    ConfigParam *getParam(const QString &name);
    ConfigParam getParamCopy(const QString &name) const;
    double getParamDouble(const QString &name);
    int getParamInt(const QString &name);
    int getParamEnum(const QString &name);
    QString getParamQString(const QString &name);
    bool getParamBool(const QString &name);
    QString getLongName(const QString &name);
    QString getDescription(const QString &name);

    QStringList getParamOrder() const;
    void setParamOrder(const QStringList &order);

    QWidget *getEditor(const QString &name, QWidget *parent = 0);

    void getParamSerial(VByteArray &vb, const QString &name);
    void setParamSerial(VByteArray &vb, const QString &name, QObject *src = 0);

    QStringList getSerializeOrder() const;
    void setSerializeOrder(const QStringList &serializeOrder);
    void clearSerializeOrder();

    void serialize(VByteArray &vb);
    void deSerialize(VByteArray &vb);

    void getXML(QXmlStreamWriter &stream, QString configName);
    bool setXML(QXmlStreamReader &stream, QString configName);
    bool saveXml(QString fileName, QString configName);
    bool loadXml(QString fileName, QString configName);
    QString xmlStatus();

    void getParamsXML(QXmlStreamWriter &stream);
    bool setParamsXML(QXmlStreamReader &stream);
    bool saveParamsXml(QString fileName);
    bool loadParamsXml(QString fileName);

    bool saveCDefines(const QString &fileName, bool wrapIfdef = false);

    QStringList checkDifference(ConfigParams *config);

    // Operators
    ConfigParams& operator=(const ConfigParams &other);

signals:
    void paramChangedDouble(QObject *src, QString name, double newParam);
    void paramChangedInt(QObject *src, QString name, int newParam);
    void paramChangedEnum(QObject *src, QString name, int newParam);
    void paramChangedQString(QObject *src, QString name, QString newParam);
    void paramChangedBool(QObject *src, QString name, bool newParam);
    void updateRequested();
    void updateRequestDefault();
    void updated();
    void savingXml();

public slots:
    void updateParamDouble(QString name, double param, QObject *src = 0);
    void updateParamInt(QString name, int param, QObject *src = 0);
    void updateParamEnum(QString name, int param, QObject *src = 0);
    void updateParamString(QString name, QString param, QObject *src = 0);
    void updateParamBool(QString name, bool param, QObject *src = 0);
    void requestUpdate();
    void requestUpdateDefault();
    void updateDone();

private:
    QHash<QString, ConfigParam> mParams;
    QStringList mParamList;
    QString mUpdateOnlyName;
    bool mUpdatesEnabled;
    QStringList mSerializeOrder;
    QString mXmlStatus;

    bool almostEqual(float A, float B, float eps);

};

#endif // CONFIGPARAMS_H

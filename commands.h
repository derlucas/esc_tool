/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef COMMANDS_H
#define COMMANDS_H

#include <QObject>
#include <QTimer>
#include "vbytearray.h"
#include "datatypes.h"
#include "packet.h"
#include "configparams.h"

class Commands : public QObject
{
    Q_OBJECT
public:
    explicit Commands(QObject *parent = 0);

    void setLimitedMode(bool is_limited);
    bool isLimitedMode();
    void setSendCan(bool sendCan, int id = -1);
    bool getSendCan();
    void setCanSendId(unsigned int id);
    unsigned int getCanSendId();
    void setMcConfig(ConfigParams *mcConfig);
    void setAppConfig(ConfigParams *appConfig);
    void startFirmwareUpload(QByteArray &newFirmware, bool isBootloader = false);
    double getFirmwareUploadProgress();
    QString getFirmwareUploadStatus();
    void cancelFirmwareUpload();
    void checkMcConfig();

signals:
    void dataToSend(QByteArray &data);

    void fwVersionReceived(int major, int minor, QString hw, QByteArray uuid);
    void ackReceived(QString ackType);
    void valuesReceived(MC_VALUES values);
    void printReceived(QString str);
    void samplesReceived(QByteArray bytes);
    void rotorPosReceived(double pos);
    void experimentSamplesReceived(QVector<double> samples);
    void bldcDetectReceived(bldc_detect param);
    void decodedPpmReceived(double value, double last_len);
    void decodedAdcReceived(double value, double voltage, double value2, double voltage2);
    void decodedChukReceived(double value);
    void motorRLReceived(double r, double l);
    void motorLinkageReceived(double flux_linkage);
    void encoderParamReceived(double offset, double ratio, bool inverted);
    void customAppDataReceived(QByteArray data);
    void focHallTableReceived(QVector<int> hall_table, int res);
    void nrfPairingRes(NRF_PAIR_RES res);
    void mcConfigCheckResult(QStringList paramsNotSet);

public slots:
    void processPacket(QByteArray data);

    void getFwVersion();
    void getValues();
    void sendTerminalCmd(QString cmd);
    void setDutyCycle(double dutyCycle);
    void setCurrent(double current);
    void setCurrentBrake(double current);
    void setRpm(int rpm);
    void setPos(double pos);
    void setHandbrake(double current);
    void setDetect(disp_pos_mode mode);
    void samplePrint(debug_sampling_mode mode, int sample_len, int dec);
    void getMcconf();
    void getMcconfDefault();
    void setMcconf(bool check = true);
    void getAppConf();
    void getAppConfDefault();
    void setAppConf();
    void detectMotorParam(double current, double min_rpm, double low_duty);
    void reboot();
    void sendAlive();
    void getDecodedPpm();
    void getDecodedAdc();
    void getDecodedChuk();
    void setServoPos(double pos);
    void measureRL();
    void measureLinkage(double current, double min_rpm, double low_duty, double resistance);
    void measureEncoder(double current);
    void measureHallFoc(double current);
    void sendCustomAppData(QByteArray data);
    void sendCustomAppData(unsigned char *data, unsigned int len);
    void setChukData(chuck_data &data);
    void pairNrf(int ms);

private slots:
    void timerSlot();

private:
    void emitData(QByteArray data);
    void firmwareUploadUpdate(bool isTimeout);
    QString faultToStr(mc_fault_code fault);

    QTimer *mTimer;
    bool mSendCan;
    unsigned int mCanId;
    bool mIsLimitedMode;

    // FW upload state
    QByteArray mNewFirmware;
    bool mFirmwareIsUploading;
    int mFirmwareState;
    int mFimwarePtr;
    int mFirmwareTimer;
    int mFirmwareRetries;
    bool mFirmwareIsBootloader;
    QString mFirmwareUploadStatus;

    ConfigParams *mMcConfig;
    ConfigParams *mAppConfig;
    ConfigParams mMcConfigLast;
    bool mCheckNextMcConfig;

};

#endif // COMMANDS_H

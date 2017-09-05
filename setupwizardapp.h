/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef SETUPWIZARDAPP_H
#define SETUPWIZARDAPP_H

#include <QWizard>
#include <QLabel>
#include <QListWidget>
#include <QTimer>
#include <QPushButton>

#include "vescinterface.h"
#include "widgets/paramtable.h"
#include "widgets/nrfpair.h"
#include "widgets/displaypercentage.h"
#include "pages/pageconnection.h"
#include "widgets/ppmmap.h"
#include "widgets/adcmap.h"
#include "widgets/aspectimglabel.h"

class SetupWizardApp : public QWizard
{
    Q_OBJECT

public:
    enum {
        Page_Intro = 0,
        Page_Connection,
        Page_Firmware,
        Page_Multi,
        Page_MultiId,
        Page_General,
        Page_Nunchuk,
        Page_Ppm,
        Page_Adc,
        Page_Conclusion
    };

    enum {
        Input_Ppm = 0,
        Input_Adc,
        Input_Nunchuk,
        Input_NunchukNrf
    };

    enum {
        Multi_Single = 0,
        Multi_Master,
        Multi_Slave
    };

    SetupWizardApp(VescInterface *vesc, QWidget *parent = 0);

private slots:
    void idChanged(int id);

private:
    AspectImgLabel *mSideLabel;

};

class AppIntroPage : public QWizardPage
{
    Q_OBJECT

public:
    AppIntroPage(VescInterface *vesc, QWidget *parent = 0);
    int nextId() const Q_DECL_OVERRIDE;
    bool validatePage() Q_DECL_OVERRIDE;

private:
    VescInterface *mVesc;
    QLabel *mLabel;

};

class AppConnectionPage : public QWizardPage
{
    Q_OBJECT

public:
    AppConnectionPage(VescInterface *vesc, QWidget *parent = 0);
    int nextId() const Q_DECL_OVERRIDE;
    bool isComplete() const Q_DECL_OVERRIDE;

private:
    VescInterface *mVesc;
    PageConnection *mPageConnection;

};

class AppFirmwarePage : public QWizardPage
{
    Q_OBJECT

public:
    AppFirmwarePage(VescInterface *vesc, QWidget *parent = 0);
    int nextId() const Q_DECL_OVERRIDE;

private:
    VescInterface *mVesc;
    QLabel *mLabel;

};

class AppMultiPage : public QWizardPage
{
    Q_OBJECT

public:
    AppMultiPage(VescInterface *vesc, QWidget *parent = 0);
    int nextId() const Q_DECL_OVERRIDE;
    bool validatePage() Q_DECL_OVERRIDE;
    void showEvent(QShowEvent *event) Q_DECL_OVERRIDE;
    void cleanupPage() Q_DECL_OVERRIDE;

private:
    VescInterface *mVesc;
    QListWidget *mModeList;
    bool mLoadDefaultAsked;

};

class AppMultiIdPage : public QWizardPage
{
    Q_OBJECT

public:
    AppMultiIdPage(VescInterface *vesc, QWidget *parent = 0);
    int nextId() const Q_DECL_OVERRIDE;
    bool validatePage() Q_DECL_OVERRIDE;

private:
    VescInterface *mVesc;
    ParamTable *mParamTab;
    QLabel *mLabel;

};

class AppGeneralPage : public QWizardPage
{
    Q_OBJECT

public:
    AppGeneralPage(VescInterface *vesc, QWidget *parent = 0);
    int nextId() const Q_DECL_OVERRIDE;
    bool validatePage() Q_DECL_OVERRIDE;
    void cleanupPage() Q_DECL_OVERRIDE;

private:
    VescInterface *mVesc;
    QListWidget *mInputList;

};

class AppNunchukPage : public QWizardPage
{
    Q_OBJECT

public:
    AppNunchukPage(VescInterface *vesc, QWidget *parent = 0);
    int nextId() const Q_DECL_OVERRIDE;
    bool validatePage() Q_DECL_OVERRIDE;
    void initializePage() Q_DECL_OVERRIDE;

private slots:
    void decodedChukReceived(double value);
    void timerSlot();

private:
    VescInterface *mVesc;
    ParamTable *mParamTab;
    NrfPair *mNrfPair;
    DisplayPercentage *mDisplay;
    QTimer *mTimer;
    QPushButton *mWriteButton;

};

class AppPpmPage : public QWizardPage
{
    Q_OBJECT

public:
    AppPpmPage(VescInterface *vesc, QWidget *parent = 0);
    int nextId() const Q_DECL_OVERRIDE;
    bool validatePage() Q_DECL_OVERRIDE;
    void initializePage() Q_DECL_OVERRIDE;

private slots:
    void timerSlot();

private:
    VescInterface *mVesc;
    ParamTable *mParamTab;
    PpmMap *mPpmMap;
    QTimer *mTimer;
    QPushButton *mWriteButton;

};

class AppAdcPage : public QWizardPage
{
    Q_OBJECT

public:
    AppAdcPage(VescInterface *vesc, QWidget *parent = 0);
    int nextId() const Q_DECL_OVERRIDE;
    bool validatePage() Q_DECL_OVERRIDE;
    void initializePage() Q_DECL_OVERRIDE;

private slots:
    void timerSlot();

private:
    VescInterface *mVesc;
    ParamTable *mParamTab;
    AdcMap *mAdcMap;
    QTimer *mTimer;
    QPushButton *mWriteButton;

};

class AppConclusionPage : public QWizardPage
{
    Q_OBJECT

public:
    AppConclusionPage(VescInterface *vesc, QWidget *parent = 0);
    int nextId() const Q_DECL_OVERRIDE;
    void initializePage() Q_DECL_OVERRIDE;

private:
    VescInterface *mVesc;
    QLabel *mLabel;

};

#endif // SETUPWIZARDAPP_H

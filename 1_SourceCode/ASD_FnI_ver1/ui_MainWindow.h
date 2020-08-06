/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created: Sat Sep 14 13:45:44 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *s_mainWindowGridLayout;
    QGroupBox *s_controlsGB;
    QGridLayout *gridLayout_2;
    QPushButton *m_exit;
    QPushButton *m_pause;
    QPushButton *m_resume;
    QPushButton *m_play;
    QProgressBar *m_progress;
    QLabel *m_shieldL;
    QLabel *m_shield;
    QLabel *m_scoreL;
    QLabel *m_score;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        s_mainWindowGridLayout = new QGridLayout(centralwidget);
        s_mainWindowGridLayout->setObjectName(QString::fromUtf8("s_mainWindowGridLayout"));
        s_controlsGB = new QGroupBox(centralwidget);
        s_controlsGB->setObjectName(QString::fromUtf8("s_controlsGB"));
        QFont font;
        font.setFamily(QString::fromUtf8("PakTypeNaqsh"));
        font.setPointSize(11);
        s_controlsGB->setFont(font);
        gridLayout_2 = new QGridLayout(s_controlsGB);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        m_exit = new QPushButton(s_controlsGB);
        m_exit->setObjectName(QString::fromUtf8("m_exit"));
        m_exit->setFont(font);

        gridLayout_2->addWidget(m_exit, 8, 0, 1, 1);

        m_pause = new QPushButton(s_controlsGB);
        m_pause->setObjectName(QString::fromUtf8("m_pause"));
        m_pause->setFont(font);

        gridLayout_2->addWidget(m_pause, 1, 0, 1, 1);

        m_resume = new QPushButton(s_controlsGB);
        m_resume->setObjectName(QString::fromUtf8("m_resume"));

        gridLayout_2->addWidget(m_resume, 3, 0, 1, 1);

        m_play = new QPushButton(s_controlsGB);
        m_play->setObjectName(QString::fromUtf8("m_play"));
        m_play->setFont(font);

        gridLayout_2->addWidget(m_play, 0, 0, 1, 1);

        m_progress = new QProgressBar(s_controlsGB);
        m_progress->setObjectName(QString::fromUtf8("m_progress"));
        m_progress->setAcceptDrops(false);
        m_progress->setLayoutDirection(Qt::LeftToRight);
        m_progress->setValue(0);
        m_progress->setAlignment(Qt::AlignBottom|Qt::AlignJustify);
        m_progress->setOrientation(Qt::Vertical);
        m_progress->setInvertedAppearance(false);
        m_progress->setTextDirection(QProgressBar::TopToBottom);

        gridLayout_2->addWidget(m_progress, 4, 0, 1, 1);

        m_shieldL = new QLabel(s_controlsGB);
        m_shieldL->setObjectName(QString::fromUtf8("m_shieldL"));

        gridLayout_2->addWidget(m_shieldL, 7, 0, 1, 1);

        m_shield = new QLabel(s_controlsGB);
        m_shield->setObjectName(QString::fromUtf8("m_shield"));
        m_shield->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(m_shield, 7, 1, 1, 1);

        m_scoreL = new QLabel(s_controlsGB);
        m_scoreL->setObjectName(QString::fromUtf8("m_scoreL"));

        gridLayout_2->addWidget(m_scoreL, 5, 0, 1, 1);

        m_score = new QLabel(s_controlsGB);
        m_score->setObjectName(QString::fromUtf8("m_score"));
        m_score->setLayoutDirection(Qt::RightToLeft);
        m_score->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(m_score, 5, 1, 1, 1);


        s_mainWindowGridLayout->addWidget(s_controlsGB, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        s_mainWindowGridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Fruits and Insects", 0, QApplication::UnicodeUTF8));
        s_controlsGB->setTitle(QApplication::translate("MainWindow", "HelpYourSelf", 0, QApplication::UnicodeUTF8));
        m_exit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        m_pause->setText(QApplication::translate("MainWindow", "Pause", 0, QApplication::UnicodeUTF8));
        m_resume->setText(QApplication::translate("MainWindow", "Resume", 0, QApplication::UnicodeUTF8));
        m_play->setText(QApplication::translate("MainWindow", "Play", 0, QApplication::UnicodeUTF8));
        m_shieldL->setText(QApplication::translate("MainWindow", "Shield left", 0, QApplication::UnicodeUTF8));
        m_shield->setText(QApplication::translate("MainWindow", "10", 0, QApplication::UnicodeUTF8));
        m_scoreL->setText(QApplication::translate("MainWindow", "Score", 0, QApplication::UnicodeUTF8));
        m_score->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

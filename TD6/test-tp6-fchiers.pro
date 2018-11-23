#-------------------------------------------------
#
# Project created by QtCreator 2018-11-20T15:03:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test-tp6-fchiers
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp\
        groupe.cpp\
        depense.cpp\
        gestionnaireDepenses.cpp\
        gestionnaireUtilisateurs.cpp\
        groupe.cpp\
        transfert.cpp\
        TransfertInterac.cpp\
        TransfertPaypal.cpp\
        utilisateur.cpp\
        utilisateurPremium.cpp\
        utilisateurRegulier.cpp

HEADERS += \
        mainwindow.h\
        groupe.h\
        depense.h\
        gestionnaireGenerique.h\
        gestionnaireUtilisateurs.h \
        gestionnaireDepenses.h\
        transfert.h\
        transfertInterac.h\
        transfertPaypal.h\
        utilisateur.h\
        utilisateurPremium.h\
        utilisateurRegulier.h\
        exceptionArgumentInvalide.h \
        exceptionUtilisateurInexistant.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

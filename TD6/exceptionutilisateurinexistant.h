#ifndef EXCEPTIONUTILISATEURINEXISTANT_H
#define EXCEPTIONUTILISATEURINEXISTANT_H

#include <QException>
#include <QString>

class ExceptionUtilisateurInexistant : public QException {
public :
    ExceptionUtilisateurInexistant(QString s) : s_(s){}
    virtual QString what() { return s_; }
private :
    QString s_;
};
#endif // EXCEPTIONUTILISATEURINEXISTANT_H

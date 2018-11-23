#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "groupe.h"
#include "ExceptionArgumentInvalide.h"
#include <QMainWindow>


#include <QMainWindow>
#include <QListWidget>
#include <QLineEdit>
#include <QRadioButton>
#include <QPushButton>

#include <memory>
#include <list>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Groupe* groupe, QWidget *parent = 0);
    ~MainWindow();

public slots :

    void selectionnerUtilisateur(QListWidgetItem*);
    void selectionnerDepense(QListWidgetItem*);
    void nettoyerVue();
    void ajouterDepense();
    void ajouterUtilisateur();
    void equilibrerComptes();
    void afficherComptes();
    void filtrerListe(int);

private:

       //methodes locales
    void setup();
    void setMenu();
    void setUI();
    void afficherMessage(QString msg);
    void chargerUtilisateurs();
    void chargerDepenses();
    void chargerTransferts();
    void chargerComptes();
    bool filtrerMasque(Utilisateur* usager);


        // attribut

    int indexCourantDuFiltre_;

    Groupe* groupe_;

    QLineEdit* editeurNomDepense_;
    QLineEdit* editeurMontant_;
    QLineEdit* editeurLieu_;
    QLineEdit* editeurPayePar_;
    QPushButton* boutonAjouterDepense_;


    QLineEdit* editeurNomUtilisateur_;
    QLineEdit* editeurJoursRestants_;
    QLineEdit* editeurInterac_;
    QLineEdit* editeurPaypal_;

    QPushButton* boutonAjouterUtilisateur_;

    list<QRadioButton*> boutonsRadioMethodeDePaiement_;
    list<QRadioButton*> boutonsRadioUtilisateurs_;

    QListWidget* listeDepenses_;
    QListWidget* listeUtilisateurs_;
    QPushButton* boutonEquilibrerComptes_;
    QPushButton* boutonAfficherComptes_;

    QListWidget* comptes_;
    QListWidget* listeTransferts_;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

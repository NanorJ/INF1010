#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    Groupe vacance("Madrid");
        UtilisateurPremium* david = new UtilisateurPremium("David", Interac, 30, "david.dtw", "david_paypal");
        UtilisateurPremium* ryan = new UtilisateurPremium("Ryan", Paypal, 30, "ryan.polymlt", "Ryan_paypal");
        UtilisateurPremium* wassim = new UtilisateurPremium("Wassim", Interac, 30, "wassim.polymtl", "Wassim_paypal");
        UtilisateurPremium* rebecca = new UtilisateurPremium("Rebecca", Paypal, 30, "rebecca.polymtl", "Rebecca_paypal");
        UtilisateurRegulier* martine = new UtilisateurRegulier("Martine", Paypal, "martine.bellaiche", "martine_Paypal");

        ((((vacance+= david)+= martine)+=ryan)+=wassim)+=rebecca;

        vacance.ajouterDepense(100, "David", "Resto", "Bruxelles");

    QApplication a(argc, argv);
    MainWindow w(&vacance);
    w.show();
    return a.exec();
}

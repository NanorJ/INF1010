/********************************************
* Titre: Travail pratique #5 - groupe.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include "groupe.h"

// Constructeurs

Groupe::Groupe() {
    nom_ = "";
    gestionnaireDepenses_ = new GestionnaireDepenses();
    gestionnaireUtilisateurs_ = new GestionnaireUtilisateurs();
}

Groupe::Groupe(const string& nom) : nom_(nom) {
    gestionnaireDepenses_ = new GestionnaireDepenses();
    gestionnaireUtilisateurs_ = new GestionnaireUtilisateurs();
}

Groupe::~Groupe() {
    for (int i = 0; i < gestionnaireDepenses_->getNombreElements(); i++) {
        delete gestionnaireDepenses_->getElementParIndex(i);
    }
    for (int i = 0; i < transferts_.size(); i++) {
        delete transferts_[i];
    }

    delete gestionnaireDepenses_;
    delete gestionnaireUtilisateurs_;
}

// Methodes d'acces
string Groupe::getNom() const {
    return nom_;
}

int Groupe::getNombreUtilisateurs() const {
    return gestionnaireUtilisateurs_->getNbUtilisateurs();
}
vector<Depense*> Groupe::getDepenses() const
{
    return gestionnaireDepenses_->getConteneur();
}

map<Utilisateur*, double> Groupe::getUtilisateurs() const
{
    return gestionnaireUtilisateurs_->getConteneur();
}

vector<Transfert*> Groupe::getTransferts() const
{
    return transferts_;
}

vector<double> Groupe::getComptes() const{
    return gestionnaireUtilisateurs_->getComptes();
}

double Groupe::getTotalDepenses() const {
    return gestionnaireDepenses_->getTotalDepenses();
}

GestionnaireUtilisateurs * Groupe::getGestionnaireUtilisateurs() const
{
    return gestionnaireUtilisateurs_;
}

GestionnaireDepenses * Groupe::getGestionnaireDepenses() const
{
    return gestionnaireDepenses_;
}

int Groupe::getNombreDepenses() const {
    return gestionnaireDepenses_->getNombreDepense();
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
    nom_ = nom;
}

// Methodes d'ajout
Groupe& Groupe::ajouterDepense(double montant, const string& nomUtilisateur, const string& nom, const string& lieu)
{
    try{

    Utilisateur* user = gestionnaireUtilisateurs_->trouverUtilisateurParNom(nomUtilisateur);

    Depense* depense = new Depense(nom, montant, lieu);

    gestionnaireDepenses_->ajouter(depense);

    *user += depense;

    gestionnaireUtilisateurs_->mettreAJourComptes(user, depense->getMontant());

    return *this;
    }catch (ExceptionUtilisateurInexistant &e ){
        throw e;
    }
}

Groupe& Groupe::operator+=(Utilisateur* utilisateur)
{
    gestionnaireUtilisateurs_->ajouter(utilisateur);
    return *this;
}

void Groupe::equilibrerComptes() {

    bool calcul = true;
    transferts_.clear();
    int count = 0;
    while (calcul) {
        // Ajout? :

        pair<Utilisateur*, double> utilisateurMin = gestionnaireUtilisateurs_->getMin();
        pair<Utilisateur*, double> utilisateurMax = gestionnaireUtilisateurs_->getMax();

        // On cherche lequel des deux a la dette la plus grande
        if (-utilisateurMin.second <= utilisateurMax.second && utilisateurMin.second != 0 && utilisateurMax.second != 0) {
            if (utilisateurMin.first->getMethodePaiement() == Interac) {
                TransfertInterac* transfert = new TransfertInterac(-utilisateurMin.second, utilisateurMin.first, utilisateurMax.first);
                transferts_.push_back(transfert);
                transfert->effectuerTransfert();
            }
            else {
                TransfertPaypal* transfert = new TransfertPaypal(-utilisateurMin.second, utilisateurMin.first, utilisateurMax.first);
                transferts_.push_back(transfert);
                transfert->effectuerTransfert();
            }
            // Ajout? :
            utilisateurMax.second += utilisateurMin.second;
            utilisateurMin.second = 0;

            gestionnaireUtilisateurs_->setCompte(utilisateurMax);
            gestionnaireUtilisateurs_->setCompte(utilisateurMin);
        }
        else if (-utilisateurMin.second > utilisateurMax.second  && utilisateurMin.second != 0 && utilisateurMax.second != 0) {
            if (utilisateurMin.first->getMethodePaiement() == Interac) {
                TransfertInterac* transfert = new TransfertInterac(utilisateurMax.second, utilisateurMin.first, utilisateurMax.first);
                transferts_.push_back(transfert);
                transfert->effectuerTransfert();
            }
            else {
                TransfertPaypal* transfert = new TransfertPaypal(utilisateurMax.second, utilisateurMin.first, utilisateurMax.first);
                transferts_.push_back(transfert);
                transfert->effectuerTransfert();
            }

            utilisateurMax.second = 0;
            utilisateurMin.second += utilisateurMax.second;

            gestionnaireUtilisateurs_->setCompte(utilisateurMax);
            gestionnaireUtilisateurs_->setCompte(utilisateurMin);
        }

        // On incremente le nombre de comptes mis a 0
        count++;
        if (-utilisateurMin.second == utilisateurMax.second) {
            count++;
        }
        if (count >= gestionnaireUtilisateurs_->getNombreElements() - 1) {
            calcul = false;
        }
    }

}

// Methode d'affichage
ostream & operator<<(ostream& os, const Groupe& groupe)
{
    os << "\nGroupe " << groupe.nom_ << ".\nCout total: " << groupe.getTotalDepenses() << "$ \nUtilisateurs:    \n\n";
    for (int i = 0; i < groupe.gestionnaireUtilisateurs_->getNombreElements(); i++) {
        os <<"\t- " << *groupe.gestionnaireUtilisateurs_->getElementParIndex(i).first;
    }
    os << endl;

    if (groupe.transferts_.size() != 0) {
        os << "Transferts :" << endl;
        for (int i = 0; i < groupe.transferts_.size(); i++)
            os << "\t" << *(groupe.transferts_[i]);
    }
    else {
        os << "Les comptes ne sont pas equilibres" << endl << endl;
        for (auto it = groupe.gestionnaireUtilisateurs_->getConteneur().begin(); it != groupe.gestionnaireUtilisateurs_->getConteneur().end(); ++it) {
            os << it->first->getNom() << " : " << it->second << endl;
        }
    }

    os << endl;
    return os;
}


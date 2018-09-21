#include "transfert.h"
#include "groupe.h"
#include <string>

using namespace std;

Groupe::Groupe()
{
	nom_ = "unknown";
	totalDepenses_ = 0.0;
	listeUtilisateurs_ = nullptr;
	nombreDepenses_ = 0;
	nombreUtilisateurs_ = 0;
	tailleTabUtilisateurs_ = 5;
	tailleTabDepenses_ = 10;
	listeDepenses_ = nullptr;
	comptes_ = nullptr;
	listeTransferts_ = nullptr;
	nombreTransferts_ = 0;
}

Groupe::Groupe(string& nom, unsigned int tailleTabDepenses, unsigned int tailleTabUtilisateurs)
{
	nom = nom_;
	tailleTabDepenses = tailleTabDepenses_;
	tailleTabUtilisateurs = tailleTabUtilisateurs_;
}

Groupe ::~Groupe()
{
	if (listeUtilisateurs_ != nullptr) {
		delete listeUtilisateurs_;
		listeUtilisateurs_ = nullptr;
	}

	if (listeDepenses_ != nullptr) {
		delete listeDepenses_;
		listeDepenses_ = nullptr;
	}

	if (comptes_ != nullptr) {
		delete comptes_;
		comptes_ = nullptr;
	}

	if (listeTransferts_ != nullptr) {
		delete listeTransferts_;
		listeTransferts_ = nullptr;
	}

}

string Groupe:: getNom() const 
{
	return nom_;
}
unsigned int Groupe :: getNombreDepenses() const
{
	return nombreDepenses_;
}

double Groupe :: getTotal() const
{
	return totalDepenses_ ;
}

void Groupe:: setNom(string& nom)
{
	nom = nom_;
}


void Groupe::ajouterDepense(Depense* uneDepense, Utilisateur* payePar)
{

}
//{
//	if (listeUtilisateurs_ == nullptr)
//	{
//		tailleTabUtilisateurs_ = 5;
//		listeUtilisateurs_ = new Depense*[tailleTabUtilisateurs_];
//	}
//	else if (tailleTabUtilisateurs_ == nombreUtilisateurs_)
//	{
//		tailleTabUtilisateurs_ += 5;
//		Depense** nouvelleListeUtilisateurs = new Depense*[tailleTabUtilisateurs_];
//
//		for (int i = 0; i <= nombreDepenses_; i++) {
//			nouvelleListeUtilisateurs[i] = listeUtilisateurs_[i];
//		}
//		delete[] liste_;
//		listeDepenses_ = nouvelleListeDepenses;
//	}
//	listeDepenses_[nombreDepenses_++] = uneDepense;
//}


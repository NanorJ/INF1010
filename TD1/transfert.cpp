#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

#include "transfert.h"

Transfert::Transfert() {
	montant_ = 0.0;
	donneur_ = nullptr;
	receveur_ = nullptr;
}

Transfert::Transfert(double montant, Utilisateur* de, Utilisateur* pour) {
	montant_ = montant;
	donneur_ = de;
	receveur_ = pour;
}

Utilisateur* Transfert::getDonneur() const {
	return donneur_;
}

Utilisateur* Transfert::getReceveur() const {
	return receveur_;
}

double Transfert::getMontant() const {
	return montant_;
}

void Transfert::setDonneur(Utilisateur* donneur) {
	donneur_ = donneur;
}

void Transfert::setReceveur(Utilisateur* receveur) {
	receveur_ = receveur;
}

void Transfert::setMontant(double montant) {
	montant_ = montant;
}

void Transfert::afficherTransfert() const {
	cout << " Transfert fait par : " << donneur_->getNom() << " pour :" << receveur_->getNom() << " d'un montant de :" << getMontant() << endl;
}#include "utilisateur.h"
#include "depense.h"
#include "transfert.h"
#include <iostream>
#include <string>
//#include <stdio.h>

using namespace std;

Transfert::Transfert()
{
	montant_ = 0.0;
	donneur_ = nullptr;
	receveur_ = nullptr;
}

Transfert::Transfert(double montant, Utilisateur* de, Utilisateur* pour)
{
	montant_ = montant;
	donneur_ = de;
	receveur_ = pour;
}

Utilisateur* Transfert::getDonneur() const
{
	return donneur_;
}

Utilisateur* Transfert::getReceveur() const
{
	return receveur_;
}

double Transfert::getMontant() const
{
	return montant_;
}

void Transfert::setDonneur(Utilisateur* donneur)
{
	donneur_ = donneur;
}

void Transfert::setMontant(double montant)
{
	montant_ = montant;
}

void Transfert::setReceveur(Utilisateur* receveur)
{
	receveur_ = receveur;
}

void Transfert::afficherTransfert() const
{
	cout << "Le montant est: " << montant_ << endl;
	cout << "Le donneur est: ";
	donneur_->getNom();
	cout << endl << "Le receveur est: ";
	receveur_->getNom(); //esque ca va afficher le même nom?
}


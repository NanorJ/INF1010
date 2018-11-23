/********************************************
* Titre: Travail pratique #4 - transfertPaypal.h
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/
#ifndef TRANSFERT_PAYPAL_H
#define TRANSFERT_PAYPAL_H

#pragma once

const double COMMISSION = 0.026;
const double FRAIS = 0.30;

#include "transfert.h"
#include "utilisateurPremium.h"


class TransfertPaypal : public Transfert {
public:
	TransfertPaypal(double montant, Utilisateur* expediteur, Utilisateur* receveur);

	string getId() const;
	void setId(string id);

	virtual double getFraisTransfert() const;

private:
	string id_;
};

#endif

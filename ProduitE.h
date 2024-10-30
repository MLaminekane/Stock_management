//
// Created by mlami on 10/17/2024.
//

#ifndef PRODUITE_H
#define PRODUITE_H

#include <string>

#include "Compteur.h"
#include "Produit.h"


class ProduitE : public Produit {
public:
    ProduitE() : Produit("ProduitE") {
        Compteur::ajouterConstructeur();
    }
    ProduitE(const ProduitE& produitE) : Produit(produitE){
        Compteur::ajouterConstructeurCopie();
    }
    ~ProduitE(){
        Compteur::ajouterDestructeur();
    }
    string getDescription() const override {
        return "Description d'un produit E";
    }
};



#endif //PRODUITE_H

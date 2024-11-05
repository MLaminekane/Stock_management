//
// Created by mlami on 10/17/2024.
//

#include "ProduitA.h"
#include "Compteur.h"

ProduitA::ProduitA() : Produit("ProduitA") {
    Compteur::ajouterConstructeur();
}

ProduitA::ProduitA(const ProduitA &produitA): Produit(produitA) {
    Compteur::ajouterConstructeurCopie();
}

ProduitA::~ProduitA() {
    Compteur::ajouterDestructeur();
}

string ProduitA::getDescription() const {
    return "Description d'un produit A";
}

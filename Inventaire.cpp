//
// Created by mlami on 10/17/2024.
//

#include "Inventaire.h"
#include "Produit.h"


void Inventaire::ajouterProduits(Produit *produit, int idProduit) {
}

Inventaire::Inventaire() {
    Compteur::ajouterConstructeur();
}

Inventaire::Inventaire(const Inventaire &other) {
    for (int i = 0; i < 5; ++i) {
        for (Produit *produit : other.produits[i]) {
            produits[i].push_back(produit->clone());
        }
    }
    Compteur::ajouterConstructeurCopie();
}

Inventaire::~Inventaire() {
    for (int i = 0; i < 5; ++i) {
        for (Produit *produit : produits[i]) {
            delete produit;
        }
    }
    Compteur::ajouterDestructeur();
}

Inventaire * Inventaire::clone() const {
    return new Inventaire(*this);
}

void Inventaire::ajouterProduit(ProduitA *produit) {
    ajouterProduits(produit, 0);
    produits[0].push_back(produit);
}

void Inventaire::ajouterProduit(ProduitB *produit) {
    ajouterProduits(produit, 1);
    produits[1].push_back(produit);
}

void Inventaire::ajouterProduit(ProduitC *produit) {
    ajouterProduits(produit, 2);
    produits[2].push_back(produit);
}

void Inventaire::ajouterProduit(ProduitD *produit) {
    ajouterProduits(produit, 3);
    produits[3].push_back(produit);
}

void Inventaire::ajouterProduit(ProduitE *produit) {
    ajouterProduits(produit, 4);
    produits[4].push_back(produit);
}

Produit * Inventaire::recupererProduit(int idProduit) {
    if (!produits[idProduit].empty()) {
        Produit* produit = produits[idProduit].front();
        produits[idProduit].pop_front();
        return produit;
    }
    return nullptr;
}

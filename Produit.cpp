//
// Created by mlami on 10/17/2024.
//

#include "Produit.h"

int Produit::calculerPoids() const {
    int poids = 0;
    for (Composant *composant : composants) {
        poids += composant->getPoids();
    }
    return poids;
}

int Produit::calculerPrix() const {
    int prix = 0;
    for (Composant *composant : composants) {
        prix += composant->getPrix();
    }
    return prix;
}

void Produit::ajouterComposant(Composant *composant) {
    composants.push_back(composant);
}

Produit::Produit(string nom) : nom(nom) {
    Compteur::ajouterConstructeur();
}

Produit::Produit(const Produit& other) : nom(other.nom) {
    for (const auto& composant : other.composants) {
        composants.push_back(composant->clone());
    }
    Compteur::ajouterConstructeurCopie();
}

Produit::~Produit() {
    for (auto composant : composants) {
        delete composant;
    }
    Compteur::ajouterDestructeur();
}

string Produit::getNom() const {
    return nom;
}

string Produit::getDescription() const {
    return "";
}

int Produit::evaluerQualite() const {
    if (composants.empty()) {
        return 0;
    }
    int totalQualite = 0;
    for (Composant *composant : composants) {
        totalQualite += composant->getQualite();
    }
    return totalQualite / composants.size();
}

Produit * Produit::clone() const {
    return new Produit(*this);
}

ostream & operator<<(const ostream & os, string::pointer str);

ostream operator<<(const ostream & lhs, int rhs);

ostream & operator<<(ostream &os, const Produit &produit) {
    os << "Produit: " << produit.getNom() << "\n";
    os << "Description: " << produit.getDescription() << "\n";
    os << "Poids: " << produit.calculerPoids() << "\n";
    os << "Prix: " << produit.calculerPrix() << "\n";
    os << "Qualite: " << produit.evaluerQualite() << "\n";
    return os;
}

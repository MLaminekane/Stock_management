//
// Created by mlami on 10/17/2024.
//

#include "Composant.h"

using namespace std;
Compteur Composant::compteur;

Composant::Composant(std::string nom, int poids, int qualite, int prix)
    : nom(nom), poids(poids), qualite(qualite), prix(prix) {
    Compteur::ajouterConstructeur();
}

Composant::Composant(std::string nom, int poids)
    : nom(nom), poids(poids), qualite(0), prix(0) {
    Compteur::ajouterConstructeur();
}

Composant::Composant(std::string nom, int poids, int prix)
    : nom(nom), poids(poids), qualite(0), prix(prix) {
    Compteur::ajouterConstructeur();
}

Composant::Composant(const Composant& composant)
    : nom(composant.nom), poids(composant.poids), qualite(composant.qualite), prix(composant.prix) {
    Compteur::ajouterConstructeurCopie();
}

Composant::~Composant() {
    Compteur::ajouterDestructeur();
}

Composant * Composant::clone() const {
    return new Composant(*this);
}

string Composant::getNom() {
    return nom;
}

int Composant::getPoids() {
    return poids >= 0 ? poids : 0;
}

int Composant::getQualite() {
    return (qualite >= 0 && qualite <= 100) ? qualite : (qualite < 0 ? 0 : 100);
}

int Composant::getPrix() {
    return prix >= 0 ? prix : 0;
}
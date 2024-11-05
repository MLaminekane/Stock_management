//
// Created by mlami on 10/17/2024.
//

#include "Compteur.h"
int Compteur::Constructeur = 0;
int Compteur::ConstructeurCopie = 0;
int Compteur::Destructeur = 0;

void Compteur::ajouterConstructeur() {
    Constructeur++;
}

void Compteur::ajouterConstructeurCopie() {
    ConstructeurCopie++;
}

void Compteur::ajouterDestructeur() {
    Destructeur++;
}

int Compteur::getNbConstructeurs() {
    return Constructeur;
}

int Compteur::getNbConstructeursCopie() {
    return ConstructeurCopie;
}

int Compteur::getNbDestructeurs() {
    return Destructeur;
}

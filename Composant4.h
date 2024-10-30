//
// Created by mlami on 10/17/2024.
//

#ifndef COMPOSANT4_H
#define COMPOSANT4_H
#include "Composant.h"
#include "Compteur.h"


class Composant4 : public Composant {
public:
    Composant4(int qualite) : Composant("COMPOSANT #4", 11, qualite, 10) {
        Compteur::ajouterConstructeur();
    }
    Composant4(const Composant4& composant4) : Composant(composant4) {
        Compteur::ajouterConstructeurCopie();
    }
    ~Composant4() {
        Compteur::ajouterDestructeur();
    }
};



#endif //COMPOSANT4_H

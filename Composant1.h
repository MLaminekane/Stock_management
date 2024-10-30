//
// Created by mlami on 10/17/2024.
//

#ifndef COMPOSANT1_H
#define COMPOSANT1_H
#include "Composant.h"
#include "Compteur.h"


class Composant1 : public Composant {
private:
    static Compteur compteur;

public:
    Composant1(int qualite, int prix) : Composant("COMPOSANT #1", 10, qualite, 45) {
        compteur.ajouterConstructeur();
    }
    Composant1(const Composant1& composant1) : Composant(composant1) {
        compteur.ajouterConstructeurCopie();
    }
    ~Composant1() {
        compteur.ajouterDestructeur();
    }
};



#endif //COMPOSANT1_H

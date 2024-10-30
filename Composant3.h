//
// Created by mlami on 10/17/2024.
//

#ifndef COMPOSANT3_H
#define COMPOSANT3_H
#include "Composant.h"
#include "Compteur.h"


class Composant3 : public Composant {
private:
    static Compteur compteur;
public:
    Composant3(int prix) : Composant("COMPOSANT #3", 12, 100, prix) {
        Compteur::ajouterConstructeur();
    }
    Composant3(const Composant3& composant3) : Composant(composant3) {
        Compteur::ajouterConstructeurCopie();
    }
    ~Composant3() {
        Compteur::ajouterDestructeur();
    }
};



#endif //COMPOSANT3_H

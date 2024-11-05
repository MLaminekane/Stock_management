#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <list>
#include "Composant.h"
#include "Composant1.h"
#include "Composant2.h"
#include "Composant3.h"
#include "Composant4.h"
#include "Composant5.h"
#include "Compteur.h"

class Fournisseur {
private:
    int quantiteComposants[5];
    static Compteur compteur;

    void initializer();

public:
    Fournisseur();
    Fournisseur(const Fournisseur& f);
    virtual ~Fournisseur();

    std::list<Composant*> commanderComposant(int idComposant, int quantite);

    Composant1* produireComposant1();
    Composant2* produireComposant2();
    Composant3* produireComposant3();
    Composant4* produireComposant4();
    Composant5* produireComposant5();
};

#endif //FOURNISSEUR_H
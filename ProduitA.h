//
// Created by mlami on 10/17/2024.
//

#ifndef PRODUITA_H
#define PRODUITA_H
#include <string>


#include "Produit.h"


class ProduitA : public Produit {
public:
    ProduitA();
    ProduitA(const ProduitA& produitA);
    ~ProduitA() override;
    string getDescription() const override;
};



#endif //PRODUITA_H

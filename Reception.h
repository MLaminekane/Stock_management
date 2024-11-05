// Reception.h

#ifndef RECEPTION_H
#define RECEPTION_H

#include <list>
#include "Produit.h"
#include "BonCommande.h"
#include "Compteur.h"

using namespace std;

class Reception {
private:
    list<Produit*> produits[5];
    BonCommande* bonCommande;
    static Compteur compteur;
public:
    Reception(BonCommande* bonCommande);
    virtual ~Reception();

    Reception(const Reception& reception) = delete;
    void ajouterProduit(Produit* produit, int id);
    BonCommande* getBonCommande();
    int getQuantiteProduitsRecus(int id) const;
    list<Produit*> getProduits(int idProduits);

    friend ostream& operator<<(ostream& out, const Reception& reception);
};

#endif // RECEPTION_H
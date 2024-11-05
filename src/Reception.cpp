// Reception.cpp

#include "Reception.h"
#include "Compteur.h"



Reception::Reception(BonCommande* bonCommande) : bonCommande(bonCommande) {
    Compteur::ajouterConstructeur();
}

Reception::~Reception() {
    for (int i = 0; i < 5; ++i) {
        for (Produit* produit : produits[i]) {
            delete produit;
        }
    }
    delete bonCommande;
    Compteur::ajouterDestructeur();
}

void Reception::ajouterProduit(Produit* produit, int id) {
    if (id >= 0 && id < 5) {
        produits[id].push_back(produit);
    }
}

BonCommande* Reception::getBonCommande() {
    return bonCommande;
}

int Reception::getQuantiteProduitsRecus(int id) const {
    if (id >= 0 && id < 5) {
        return produits[id].size();
    }
    return 0;
}

std::list<Produit*> Reception::getProduits(int idProduits) {
    if (idProduits >= 0 && idProduits < 5) {
        return produits[idProduits];
    }
    return std::list<Produit*>();
}


std::ostream& operator<<(std::ostream& out, const Reception& reception) {
    out << "-------------------------------------" << std::endl;
    out << "RECEPTION" << std::endl;
    out << "Bon de commande : " << reception.bonCommande->getIdBonCommande() << std::endl;
    for (int i = 0; i < 5; ++i) {
        for (Produit* produit : reception.produits[i]) {
            out << "Produit recu --> PRODUIT " << produit->getNom() << " {"
                << produit->getDescription() << "} --> Poids:" << produit->calculerPoids()
                << "/Prix:" << produit->calculerPrix() << std::endl;
        }
    }
    out << "-------------------------------------" << std::endl;
    for (int i = 0; i < 5; ++i) {
        out << "Quantite recue {" << i << "} --> " << reception.getQuantiteProduitsRecus(i) << std::endl;
    }
    out << "-------------------------------------" << std::endl;
    return out;
}
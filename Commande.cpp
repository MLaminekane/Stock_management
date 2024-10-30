//
// Created by mlami on 10/17/2024.
//

#include "Commande.h"
#include "Compteur.h"

int Commande::validerQuantite(int q) {
    if (q < 0) {
        return 0;
    }else if (q > 10) {
        return 10;
    }else {
        return q;
    }
}

Commande::Commande() : noCommande(0) {
    for(int & qte : quantiteProduits) {
        qte = 0;
    }
}

Commande::Commande(int noCommande, int qteProduits[]) : noCommande(noCommande) {
    for (int i = 0; i < 5; i++) {
        quantiteProduits[i] = validerQuantite(qteProduits[i]);
    }
    Compteur::ajouterConstructeur();
}

Commande::~Commande() {
    Compteur::ajouterDestructeur();
}

Commande::Commande(const Commande& ) {

    Compteur::ajouterConstructeurCopie();
}

int Commande::getQuantiteProduit(int idProduit) {
    if (idProduit >= 0 && idProduit < 5) {
        return quantiteProduits[idProduit];
    }
    return 0;
}

int Commande::getNoCommande() {
    return noCommande;
}

ostream & operator<<(ostream &out, const Commande &commande) {
    if (commande.noCommande == 0) {
        out << "-------------------------------------";
        return out;
    }
    out << "Commande No: " << commande.noCommande << "\n";
    out << "Quantite de ProduitA: " << commande.quantiteProduits[0] << "\n";
    out << "Quantite de ProduitB: " << commande.quantiteProduits[1] << "\n";
    out << "Quantite de ProduitC: " << commande.quantiteProduits[2] << "\n";
    out << "Quantite de ProduitD: " << commande.quantiteProduits[3] << "\n";
    out << "Quantite de ProduitE: " << commande.quantiteProduits[4] << "\n";
    return out;
}

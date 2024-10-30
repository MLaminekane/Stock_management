#include <iostream>
#include <list>

#include "Commande.h"
#include "Produit.h"
#include "Composant.h"
#include "Composant1.h"
#include "Composant2.h"
#include "Composant3.h"
#include "Composant4.h"
#include "Composant5.h"
#include "Inventaire.h"
#include "ProduitA.h"
#include "ProduitB.h"
#include "ProduitC.h"
#include "ProduitD.h"
#include "ProduitE.h"

void testInventaire();

void afficherInformation();

int main()
{
testInventaire();
//commerce();
afficherInformation();
return 0;
}
void testInventaire()
{
Inventaire inventaire;
inventaire.ajouterProduit(new ProduitA());
inventaire.ajouterProduit(new ProduitA());
inventaire.ajouterProduit(new ProduitA());
inventaire.ajouterProduit(new ProduitB());
inventaire.ajouterProduit(new ProduitB());
inventaire.ajouterProduit(new ProduitC());
inventaire.ajouterProduit(new ProduitD());
inventaire.ajouterProduit(new ProduitE());
Inventaire* inventaireCC = new Inventaire(inventaire);
Produit* produits[6];
produits[0] = inventaire.recupererProduit(0); // un produitA
produits[1] = inventaire.recupererProduit(0); // un produitA
produits[2] = inventaire.recupererProduit(1); // un produitB
produits[3] = inventaire.recupererProduit(2); // un produitC
produits[4] = inventaire.recupererProduit(3); // un produitD
produits[5] = inventaire.recupererProduit(4); // un produitE
Produit* produit = inventaire.recupererProduit(0);
ProduitA * produitCopie = new ProduitA(*((ProduitA*)produit));
produit->ajouterComposant(new Composant1(100, 20));
produit->ajouterComposant(new Composant2(90, 50));
produit->ajouterComposant(new Composant5(10, 85, 30));
cout << "ORIGINAL --> " << *produit << endl;
cout << "COPIE --> " << *produitCopie << endl;
delete produit;
delete produitCopie;
for (Produit* produit : produits)
cout << *produit << endl;
for (int x = 0; x < 6; x++)
delete produits[x];
delete inventaireCC;
}
void afficherInformation()
{
    cout << endl << endl;
    cout << endl << "-------------------------------" << endl
    << " NB constructeurs : " <<
    Compteur::getNbConstructeurs() << endl
    << " NB constructeurs copie : " <<
    Compteur::getNbConstructeursCopie() << endl
    << " NB destructeurs : " << Compteur::getNbDestructeurs()
    << endl;
    cin.get();
}
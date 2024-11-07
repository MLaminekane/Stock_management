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
#include "Entrepot.h"
#include "Fournisseur.h"
#include "Inventaire.h"
#include "ProduitA.h"
#include "ProduitB.h"
#include "ProduitC.h"
#include "ProduitD.h"
#include "ProduitE.h"
#include "BonCommande.h"
#include "Client.h"
#include "Entreprise.h"
#include "Reception.h"
#include "RapportAssuranceQualite.h"


void afficherInformation();

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

void commerce();
int main()
{
    commerce();
    afficherInformation();
    return 0;
}
void commerce()
{
    Entreprise entreprise;
    Client client("ROGER", 90);
    std::cout << client << std::endl;
    for (int x = 0; x < 4; x++)
    {
        Commande commande(client.getCommande(x));
        cout << commande << endl;
        BonCommande* bonCommande = entreprise.traiterCommande(commande);
        cout << *bonCommande << endl;
        Reception* reception = entreprise.recupererCommande(bonCommande);
        cout << *reception << endl;
        client.recevoirCommande(reception);
         RapportAssuranceQualite aq;
         entreprise.validerSatisfaction(aq, client);
         cout << aq.genererRapport(client) << endl;
         client.consommerProduits();
    }
}
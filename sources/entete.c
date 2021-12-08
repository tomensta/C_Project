/*
* Authors: Corentin GOETGHEBEUR, Chris ARRIDI
* Ce module contient la structure Entete et les fonctions correspondantes permettant de modéliser un en-tete de compte bancaire.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/date.h"
#include "../headers/transactions.h"
#include "../headers/files_utils.h"

#include "../headers/entete.h"

/* Rappel structure Entete:
* ============================
*    typedef struct Entete{
*        Date date;
*        float solde;
*    }Entete;
*/


Entete creation_entete(Date date, float solde){
    Entete entete = {
        .date = date,
        .solde = solde
    };
    return entete;
}

FILE* creation_fichier(Entete entete, char* nom){
    
    FILE *f = fopen(nom, "w+");   // On place le fichier dans le dossier files/comptes, on l'ouvre avec w+ pour le créer
    fprintf(f, "%i %i %i %f \n", entete.date.jour, entete.date.mois, entete.date.annee, entete.solde);
    return f;
}

void read_entete(FILE *f, Date *d, float *solde){
    int jour, mois, annee;
    float s;
    fscanf(f, "%i %i %i %f \n", &jour, &mois, &annee, &s);
    d->jour = jour;
    d->mois = mois;
    d->annee = annee;
    *solde = s;
}

/*
void mise_a_jour_solde(FILE *f, Date d){

    // Récupération des données depuis le fichier des transactions
    FILE *transactions_file;
    ouvrir(&transactions_file, "Files/liste_transactions");
    
    Transaction t = read_transaction(transactions_file);


    
}
*/
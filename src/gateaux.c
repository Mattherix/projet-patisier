/* Toutes les fonctions lier aux gâteaux */
#include "gateaux.h"

#include <stdlib.h>

Gateau* creer_gateau(Element_str* commande) {
    Gateau* gateau = (Gateau*)malloc(sizeof(Gateau));
    gateau->commande = commande;
    gateau->p_gouts = creer_pile_gouts();

    return gateau;
}

void construire_gateau(Gateau* gateau) {
    // On obtient les couches du gateau ...
    Element_str* l_gouts = commande_list_gouts(gateau->commande);
    
    // ...  et les ajoutes
    while (l_gouts != NULL) {
        empiler(gateau->p_gouts, l_gouts->texte);
        l_gouts = l_gouts->next;
    }
}

void free_gateau(Gateau* gateau) {
    free_pile_gouts(gateau->p_gouts);
    free_element_str_list(gateau->commande);
    free(gateau);
}
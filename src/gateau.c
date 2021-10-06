#include "gateau.h"
#include <stdlib.h>

Gateau* creer_gateau(Element_str* commande) {
    Gateau* gateau = (Gateau*)malloc(sizeof(Gateau));
    gateau->commande = commande;
    gateau->p_gouts = creer_pile_gouts();
    return gateau;
}

void construire_gateau(Gateau* gateau, Element_str* l_gouts) {
    Element_str *commande = gateau->commande;
    Element_str* cmd_precedent;
    while (commande != NULL) {
        empiler(gateau->p_gouts, commande->texte);
        commande = commande->next;
    }
}
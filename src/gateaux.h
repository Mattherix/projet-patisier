#ifndef GATEAUX_H
#define GATEAUX_H

#include "gouts.h"

typedef struct Gateau {
    struct Element_str* commande;
    struct Pile_Gouts* p_gouts;
} Gateau;

Gateau* creer_gateau(Element_str* commande);
void construire_gateau(Gateau* gateau);

#endif

#include "gouts.h"


typedef struct Gateau {
    struct Element_str* commande;
    struct Pile_Gouts* p_gouts;
} Gateau;

Gateau* creer_gateau(Element_str* commande);
void construire_gateau(Gateau* gateau, Element_str* l_gouts);

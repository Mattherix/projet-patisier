#ifndef GOUTS_H
#define GOUTS_H

#include <stdbool.h>
#include "element-str.h"

typedef struct Pile_Gouts {
    Element_str* data;
} Pile_Gouts;

Element_str* create_gout(char gout[50]);
void add_gout(Element_str** l_gouts, Element_str* gout);
Element_str * initialiser_gouts();
Pile_Gouts* creer_pile_gouts();
void empiler(Pile_Gouts* p, char gout[50]);
Element_str* depiler(Pile_Gouts* p);
bool pile_est_vide();
Element_str* commande_list_gouts(Element_str* commande);
void free_pile_gouts(Pile_Gouts* pile_gouts);

#endif

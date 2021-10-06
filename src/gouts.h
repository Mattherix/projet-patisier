#include "element-str.h"

typedef struct Pile_Gouts {
    Element_str* data;
} Pile_Gouts;

Pile_Gouts* creer_pile_gouts();
void empiler(Pile_Gouts* p, char gout[50]);
Element_str* depiler(Pile_Gouts* p);
int pile_est_vide();
void free_pile_gouts();
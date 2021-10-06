#include <stdlib.h>
#include "gouts.h"

Pile_Gouts* creer_pile_gouts() {
    Pile_Gouts* nouv_pile = (Pile_Gouts*)malloc(sizeof(Pile_Gouts));
    nouv_pile->data = NULL;
    return nouv_pile;
}


void empiler(Pile_Gouts* p, char gout[50]) {    
    Element_str* nouv_element = (Element_str*)malloc(sizeof(Element_str));
    strncpy(nouv_element->texte, gout, 50);
    if (strlen(gout) >= 49) {
        nouv_element->texte[49] = '\0';
    }
    
    nouv_element->next = p->data;
    p->data = nouv_element;
}
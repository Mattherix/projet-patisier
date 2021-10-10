/* Toutes les fonctions lier à élément-str */
#include <stdlib.h>
#include <string.h>

#include "element-str.h"

Element_str* creer_element_str(char gout[50]) {
    Element_str* nouv_element = (Element_str*)malloc(sizeof(Element_str));
    strncpy(nouv_element->texte, gout, 50);
    if (strlen(gout) >= 49) {
        nouv_element->texte[49] = '\0';
    }
    return nouv_element;
}

void free_element_str_list(Element_str* ele) {
    if (ele != NULL) {
        free_element_str_list(ele->next);
        free(ele);
    }
}
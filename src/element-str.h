#ifndef ELEMENT_STR_H
#define ELEMENT_STR_H

typedef struct Element_str {
    char texte[50];
    struct Element_str* next;
} Element_str;

Element_str* creer_element_str(char gout[50]);
void free_element_str_list(Element_str* ele);

#endif

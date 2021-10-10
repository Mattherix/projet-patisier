/* Toutes le fonction lier aux gouts */
#include <stdlib.h>
#include <stdbool.h>

#include "gouts.h"

Element_str* create_gout(char gout[50]) {
    if (gout == NULL) {
        gout = "";
    }
    
    Element_str* l_gouts;
    l_gouts = malloc(sizeof(Element_str));
    
    strncpy(l_gouts->texte, gout, 50);
    // strncpy n'ajoute pas de '\0' si la chaine de char est trop longue
    if (strlen(gout) >= 49) {
        l_gouts->texte[49] = '\0';
    }

    l_gouts->next = NULL;
    return l_gouts;
}

void add_gout(Element_str** l_gouts, Element_str* gout) {
    if (*l_gouts == NULL) {
        *l_gouts = gout;
    } else {
        add_gout(&(*l_gouts)->next,gout);
    }
}

// Demander mais inutile pour le reste du programme
Element_str * initialiser_gouts() {
    Element_str* l_gouts = NULL;
    add_gout(&l_gouts,create_gout("Chocolat"));
    add_gout(&l_gouts,create_gout("Vanille"));
    add_gout(&l_gouts,create_gout("Fraise"));
    add_gout(&l_gouts,create_gout("Abricot"));
    add_gout(&l_gouts,create_gout("Pomme"));
    add_gout(&l_gouts,create_gout("Banane"));
    add_gout(&l_gouts,create_gout("Myrtille"));

    return l_gouts;
}

Pile_Gouts* creer_pile_gouts() {
    Pile_Gouts* nouv_pile = (Pile_Gouts*)malloc(sizeof(Pile_Gouts));
    nouv_pile->data = NULL;
    return nouv_pile;
}

void empiler(Pile_Gouts* p, char gout[50]) {    
    Element_str* nouv_element = (Element_str*)malloc(sizeof(Element_str));
    
    strncpy(nouv_element->texte, gout, 50);
    // strncpy n'ajoute pas de '\0' si la chaine de char est trop longue
    if (strlen(gout) >= 49) {
        nouv_element->texte[49] = '\0';
    }
    
    nouv_element->next = p->data;
    p->data = nouv_element;
}

Element_str* depiler(Pile_Gouts* p) {
    Element_str* result;
    result=create_gout("");
    if(pile_est_vide(p)){
        return result ;
    }
    else{
        strncpy(result->texte, p->data->texte, 50);
        // strncpy n'ajoute pas de '\0' si la chaine de char est trop longue
        if (strlen(p->data->texte) >= 49) {
            result->texte[49] = '\0';
        }

        // On free l'élément dépiler
        Element_str* old = p->data;
        p->data=p->data->next;
        free(old);

        return result;
    }
}

bool pile_est_vide(Pile_Gouts* p) {
    if (p->data == NULL) {
        return true;
    } else {
        return false;
    }
}

// Transforme une commande en une liste de gouts
Element_str* commande_list_gouts(Element_str* commande) {
    Element_str* l_gouts = NULL;
    char c;
    int i;
    while (commande != NULL) {
        c = commande->texte[0];
        i = 0;
        // Pour chaque char de la commande on ajoute le gout approprier
        while (c != '\0') {
            switch (c) {
                case 'C':
                case 'c':
                    add_gout(&l_gouts,create_gout("Chocolat"));
                    break;
                case 'V':
                case 'v':
                    add_gout(&l_gouts,create_gout("Vanille"));
                    break;
                case 'F':
                case 'f':
                    add_gout(&l_gouts,create_gout("Fraise"));
                    break;
                case 'A':
                case 'a':
                    add_gout(&l_gouts,create_gout("Abricot"));
                    break;
                case 'P':
                case 'p':
                    add_gout(&l_gouts,create_gout("Pomme"));
                    break;
                case 'B':
                case 'b':
                    add_gout(&l_gouts,create_gout("Banane"));
                    break;
                case 'M':
                case 'm':
                    add_gout(&l_gouts,create_gout("Myrtille"));
                    break;
                default:
                    break;
            }
            
            ++i;
            c = commande->texte[i];
        }
        commande = commande->next;
    }
    return l_gouts;
}

void free_pile_gouts(Pile_Gouts* pile_gouts) {
    free_element_str_list(pile_gouts->data);
    free(pile_gouts);
}
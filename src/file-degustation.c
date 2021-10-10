/* Toutes les fonctions lier à la file de dégustation */
#include <stdlib.h>

#include "file-degustation.h"

Element_gtx* create_element_gtx(Gateau* gateau) {
    Element_gtx* temp = (Element_gtx*)malloc(sizeof(Element_gtx));
    temp->gateau = gateau;
    temp->next = NULL;

    return temp;
}

File_Degustation* create_file_degustation() {
    File_Degustation* f_gateau = (File_Degustation*)malloc(sizeof(File_Degustation));
    f_gateau->commandes = NULL;

    return f_gateau;
}

// Equivalent à enfiler
void livrer(Gateau* gateau, File_Degustation* f_degustation) {
    Element_gtx* nouv_element = create_element_gtx(gateau);
    
    if(f_degustation->commandes == NULL) {
        f_degustation->commandes = nouv_element;
    }
    else {
        Element_gtx* temp = f_degustation->commandes;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nouv_element;
    }
}

void degustation(File_Degustation* f_degustation, int nb_parts) {
    if (f_degustation->commandes != NULL) {
        Element_gtx* old_gateaux = f_degustation->commandes;

        while(nb_parts > 0) {
            // Si le premier gateau de la file n'a plus de couche ...
            if(pile_est_vide(f_degustation->commandes->gateau->p_gouts)) {
                // .. on essaye de passer au prochain gateau
                old_gateaux = f_degustation->commandes;
                f_degustation->commandes = f_degustation->commandes->next;
                free(old_gateaux);

                // On vérifier si il y a encore des gateaux
                if (f_degustation->commandes == NULL ) {
                    printf("plus de gateaux :(\n");
                    nb_parts = 0;
                }
                else {
                    printf("nouveaux gateaux!\n");
                }
            }
            // On mange une part
            if (nb_parts != 0) {
                printf("%s \n", depiler(f_degustation->commandes->gateau->p_gouts)->texte);
                nb_parts--;
            }
        }
    } else {
        puts("Pas de gateau dans la File :(");
    }   
}

void free_element_gtx_list(Element_gtx* ele) {
    if (ele != NULL) {
        free_element_gtx_list(ele->next);
        free_gateau(ele->gateau);
        free(ele);
    }
}
void free_file_degustation(File_Degustation* f_degustation) {
    free_element_gtx_list(f_degustation->commandes);
    free(f_degustation);
}
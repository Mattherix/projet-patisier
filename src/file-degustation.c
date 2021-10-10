#include <stdlib.h>

#include "file-degustation.h"

Element_gtx* create_element_gtx(Gateau* gateau) {
    Element_gtx* temp = (Element_gtx*)malloc(sizeof(Element_gtx));
    temp->gateau=gateau;
    temp->next=NULL;
    return temp;
}

File_Degustation* create_file_degustation() {
    File_Degustation* f_gateau = (File_Degustation*)malloc(sizeof(File_Degustation));
    f_gateau->commandes=NULL;
    return f_gateau;
}

void livrer(Gateau* gateau,File_Degustation* f_degustation) {
    Element_gtx* nouv_element=create_element_gtx(gateau);
    if(f_degustation->commandes==NULL) {
        f_degustation->commandes=nouv_element;
    }
    else {
        Element_gtx* temp=f_degustation->commandes;
        while(temp->next!=NULL) {
            temp=temp->next;
        }
        temp->next=nouv_element;
    }
}

void degustation(File_Degustation* f_degustation, int nb_parts) {
    if (f_degustation->commandes != NULL) {
        Pile_Gouts* temp_gouts=f_degustation->commandes->gateau->p_gouts;
        Element_gtx* temp_gateaux=f_degustation->commandes;
        while(nb_parts>0) {
            if(f_degustation->commandes->gateau->p_gouts->data==NULL) {
                temp_gateaux=f_degustation->commandes;
                f_degustation->commandes=f_degustation->commandes->next;
                free(temp_gateaux);
                if (f_degustation->commandes==NULL ) {
                    printf("plus de gateaux :(\n");
                    nb_parts=0;
                }
                else {
                    printf("nouveaux gateaux!\n");
                }
            }
            if (nb_parts!=0) {
                printf("%s \n", depiler(f_degustation->commandes->gateau->p_gouts)->texte);
            }
            nb_parts--;
        }
    } else {
        puts("Pas de gateau dans la File :(");
    }   
}
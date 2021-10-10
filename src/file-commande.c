#include <stdlib.h>

#include "file-commande.h"
#include "gouts.c"

File_Commandes* creer_file_commande() {
    File_Commandes * nouv_pile = (File_Commandes*)malloc(sizeof(File_Commandes));
    nouv_pile->commandes = NULL;
    return nouv_pile;
}

int est_vide_commande(File_Commandes* p) {
    if(p->commandes==NULL) {
        return 1;
    }
    return 0;
}

void recuperer_commande(char commande[50]) {
    int c = 0;
    int total_gouts = 0;
    do {
        printf("Chocolat: C\nVanille: V\nFraise: F\nAbricot: A\nPomme: P\nBanane: B\nMyrtille: M\nRentrer votre commande:\n");
        scanf("%s", commande);
        while(commande[c] != '\0') {
            switch (commande[c]) {
                case 'C':
                case 'c':
                case 'V':
                case 'v':
                case 'F':
                case 'f':
                case 'A':
                case 'a':
                case 'P':
                case 'p':
                case 'B':
                case 'b':
                case 'M':
                case 'm':
                    total_gouts++;
                    break;
                default:
                    break;
            }
            c++;
        }
        if(commande[0] == '\0') {
            total_gouts++;
        }
    } while(total_gouts == 0);
}

// Equivalent à enfiler
void passer_commande(char commande[50], File_Commandes* f_commandes) {
    // On creer l'élément
    Element_str* nouv_element = (Element_str*)malloc(sizeof(Element_str));
    strncpy(nouv_element->texte, commande, 50);
    nouv_element->next = NULL;

    // On ajoute l'élément
    if(f_commandes->commandes == NULL) {
        f_commandes->commandes = nouv_element;
    } else {
        Element_str* temp = f_commandes->commandes;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nouv_element;
    }
}

//Equivalent à défiler
Element_str* traiter_commande(File_Commandes* f_commandes) {
    if(f_commandes->commandes == NULL) {
        return create_gout('\0');
    } else {
        Element_str* res = create_gout(f_commandes->commandes->texte);
        
        // On free l'ancien element 
        Element_str* old = f_commandes->commandes;
        f_commandes->commandes = f_commandes->commandes->next;
        free(old);

        return res;
    }
}

void free_file_commandes(File_Commandes* f_commandes) {
    free_element_str_list(f_commandes->commandes);
    free(f_commandes);
}

// Seulement pour du débug
void _print_file_commande(File_Commandes* f_commandes) {
    puts("[DEBUG] Print File commandes");
    Element_str* commande = f_commandes->commandes;
    while (commande != NULL) {
        printf("[DEBUG]         %s \n", commande->texte);
        commande = commande->next;
    }
}
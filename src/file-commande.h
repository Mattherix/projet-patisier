#ifndef FILE_COMMANDE_H
#define FILE_COMMANDE_H

#include "element-str.h"

typedef struct File_Commandes {
    Element_str* commandes;
} File_Commandes;

File_Commandes* creer_file_commande();
int est_vide_commande(File_Commandes* p);
void recuperer_commande(char commande[50]);
void passer_commande(char commande[50], File_Commandes* f_commandes);
Element_str* traiter_commande(File_Commandes* f_commandes);
void free_file_commandes(File_Commandes* f_commandes);

// Pour du debug uniquement
void _print_file_commande(File_Commandes* f_commandes);

#endif

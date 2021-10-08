#include "file.h"

File_Commandes* creer_file_commande() {
    File_Commandes * nouv_pile = (File_Commandes*)malloc(sizeof(File_Commandes));
    nouv_pile->commandes = NULL;
    return nouv_pile;
}


int est_vide_commande(File_Commandes* p){
    if(p->commandes==NULL){
        return 1;
    }
    return 0;
}


#include "element-str.h"

typedef struct File_Commandes{
    Element_str* commandes;
} File_Commandes;

File_Commandes* creer_file_commande();
int est_vide_commande(File_Commandes* p);

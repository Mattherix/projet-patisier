#include <stdio.h>
#include <stdlib.h>

#include "element-str.c"
#include "file-commande.c"
#include "gateaux.c"
#include "file-degustation.c"

int main() {
    int i=1;
    int j;
    char commande[50];
    Element_str* gouts=initialiser_gouts();
    File_Commandes* f_commandes=creer_file_commande();
    Gateau* gateau;
    File_Degustation* f_degustation=create_file_degustation();


    while(i!=0){
        printf("Entrer 1 pour passer une commande, 2 pour deguster, 0 pour quitter \n");
        scanf("%d",&i);
        if (i==1) {
            recuperer_commande(commande);
            passer_commande(commande,f_commandes);
            gateau=creer_gateau(traiter_commande(f_commandes));
            construire_gateau(gateau,gouts);
            livrer(gateau,f_degustation);
        }
        if (i==2) {
            printf("Vous deguster;\n");
            degustation(f_degustation,2);
        }
    }

    return 0;
}
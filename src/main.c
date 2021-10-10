#include <stdio.h>
#include <stdlib.h>

#include "element-str.c"
#include "file-commande.c"
#include "gateaux.c"
#include "file-degustation.c"

int main() {
    int choix = 1;
    int nb_parts = 2;
    char commande[50];
    File_Commandes* f_commandes = creer_file_commande();
    Gateau* gateau;
    File_Degustation* f_degustation = create_file_degustation();

    while(choix != 0){
        printf("Entrer 1 pour passer une commande, 2 pour deguster, 0 pour quitter \n");
        scanf("%d", &choix);
        switch (choix) {
            case 0:
                break;
            case 1:
                recuperer_commande(commande);
                passer_commande(commande,f_commandes);
                gateau = creer_gateau(traiter_commande(f_commandes));
                construire_gateau(gateau);
                livrer(gateau,f_degustation);
                break;
            
            case 2:
                do {
                    printf("Combien de parts voulez vous déguster ?\n");
                    scanf("%d", &nb_parts);
                } while (nb_parts <= 0);
                printf("Vous deguster:\n");
                degustation(f_degustation, nb_parts);
                break;

            default:
                puts("Merci d'entrer un choix valide !");
                break;
        }
    }

    return 0;
}
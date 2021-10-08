#include "file-commande.h"

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

void recuperer_commande(char commande[50]){
    int i=0;
    int j=0;
    do{
        i=0;
        j=0;
        printf("Chocolat:C\nVanille:V\nFraise:F\nAbricot:A\nPomme:P\nBanane:B\nMyrtille:M\n\nRentrer votre commande:\n");
        scanf("%s",commande);
        while(commande[i]!='\0'){
            if (!(commande[i]=='C' || commande[i]=='V' || commande[i]=='F'|| commande[i]=='A'|| commande[i]=='P'|| commande[i]=='B'|| commande[i]=='M')){
                j++;
            }
            i++;
        }
        if(commande[0]=='\0'){
            j++;
        }
    }
    while(j!=0);
}

void passer_commande(char commande[50], File_Commandes* f_commandes){
    Element_str* nouv_element = (Element_str*)malloc(sizeof(Element_str));
    strncpy(nouv_element->texte, commande, 50);
    nouv_element->next=NULL;
    if(f_commandes->commandes==NULL){
        f_commandes->commandes = nouv_element;
    }
    else{
        Element_str* temp=f_commandes->commandes;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nouv_element;
    }
}


Element_str* traiter_commande(File_Commandes* f_commandes){
    if(f_commandes->commandes==NULL){
        return create_gout('\0');
    }
    else{
        Element_str* res=create_gout(f_commandes->commandes->texte);

        Element_str* old =f_commandes->commandes;
        f_commandes->commandes=f_commandes->commandes->next;
        free(old);
        return res;
    }

}

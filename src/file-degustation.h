#include "gateau.h"

typedef struct Element_gtx{
    struct Gateau* gateau;
    struct Element_gtx* next;
} Element_gtx;

typedef struct File_Degustation{
    struct Element_gtx* commandes;
} File_Degustation;

Element_gtx* create_element_gtx(Gateau* gateau);
File_Degustation* create_file_degustation();
void livrer(Gateau* gateau,File_Degustation* f_degustation);
void degustation(File_Degustation* f_degustation,int nb_parts);

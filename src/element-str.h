typedef struct Element_str {
    char texte[50];
    struct Element_str* next;
} Element_str;

Element_str* creer_element_str(char gout[50]);

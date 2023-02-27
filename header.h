typedef struct element
{
    int dana;             /* dana (typu int), ktora bedzie przechowywana na szczycie */
    struct element *next; /* wskaznik na strukture, przechowujaca nastepny element */
} Stos;

void push(Stos **wierzch, int *liczba);
int pop(Stos **wierzch);
void inicjuj(Stos **wierzch);
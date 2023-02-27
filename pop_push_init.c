#include <stdio.h>
#include <stdbool.h>
#include "header.h"

void inicjuj(Stos **wierzch)
{
    *wierzch = (Stos *)malloc(sizeof(Stos)); /* lokowanie pamieci dla stosu */
    (*wierzch)->dana = NULL;                 /* Utworzenie pierwszego, pustego elementu */
    (*wierzch)->next = NULL;
}
void push(Stos **wierzch, int *liczba)
{
    if ((*wierzch)->dana == NULL)
    {
        (*wierzch)->dana = liczba; /* przypisanie nowej danej do wierzcholka stosu */
        (*wierzch)->next = NULL;   /* dana next, okreslajaca wartosc "nizej" staje sie NULL */
    }
    else
    {
        Stos *nowy;
        nowy = (Stos *)malloc(sizeof(Stos)); /* tworze nowa, pomocnicza strukture i rezerwuje dla niej pamiec */
        nowy->next = *wierzch;               /* przypisuje do nowej struktury informacje o tym, ze "stary" wierzcholek przypisany do elementu "next" */
        nowy->dana = liczba;                 /* nowa dana jest rowna wprowadzonej liczbie */
        *wierzch = nowy;                     /* wierzcholek przyjmuje wartosc nowej struktury */
    }
}

int pop(Stos **wierzch)
{
    if ((*wierzch) == NULL) /* zjawisko underflow */
    {
        printf("Stos pusty, nie mozna zdjac elementu");
        return 0;
    }
    else
    {
        int temp = (*wierzch)->dana;
        if ((*wierzch)->next == NULL)
        {
            (*wierzch)->dana = NULL;
        }
        else
        {
            Stos *pomoc;
            pomoc = (*wierzch)->next;       /* przypisuje element "nizej" na stosie do zmiennej pomocniczej */
            free(*wierzch);                 /* zwalniam pamiec zawierajaca aktualny wierzcholek */
            *wierzch = pomoc;               /* element zawarty w zmiennej pomocniczej przypisany do nowego szczytu stosu */
        }
        return temp;
    }
}

void empty(Stos *wierzch)
{
    if ((wierzch->dana) == NULL) /* sprawdzenie czy aktualny element na szczycie stosu rowny NULL, tylko wtedy stos pusty */
        printf("Stos pusty");
    else
        printf("Stos nie jest pusty");
}

void print(Stos *wierzch)
{
    printf("aktualna zawartosc:\n");
    Stos *aktualny = wierzch; /* dana pomocnicza wskazujaca na wierzcholek */
    while (aktualny != NULL)  /* while dopoki pomocnicza dana nie jest pusta (wtedy stos pusty) */
    {
        printf("%d\n", aktualny->dana); /* printf aktualnej danej ze szczytu stosu */
        aktualny = aktualny->next;      /* przypisanie do pomocniczej, danej znajdujacej sie "nizej" w stosie */
    }
}
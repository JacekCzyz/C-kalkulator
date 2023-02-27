/*kompilacja poprzez plik makefile (komeda gmake)*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

int main()
{
    Stos *wierzch;
    char *znak = "S"; /*poczatkowy napis*/
    int liczba, liczba1, liczba2, wynik;
    printf("Witaj w kalkulatorze. Aby zakończyć wpisz 'KONIEC'");
    inicjuj(&wierzch); /* inicjacja pierwszego stosu */
    while (1)
    {
        printf("\npodaj znak lub liczbę:\n");
        scanf("%s", &znak); /*wczytanie podanego napisu*/
        if (!strcmp(&znak, "+")) /*sprawdzenie czy plus - dodawanie*/
        {
            liczba1 = pop(&wierzch); /*przypisanie do liczby 1 liczby zdejmowanej ze szczytu stosu*/
            liczba2 = pop(&wierzch); /*przypisanie do liczby 2 liczby zdejmowanej ze szczytu stosu*/
            wynik = liczba2 + liczba1; /*obliczenie  wyniku na podstawie zdjetych liczb*/
            push(&wierzch, wynik); /*push wyniku na szczyt stosu*/
            printf("%d", wynik); /*wyswietlenie wyniku*/
        }
        else if (!strcmp(&znak, "-")) /*sprawdzenie czy minus - odejmowanie*/
        {
            liczba1 = pop(&wierzch);
            liczba2 = pop(&wierzch);
            wynik = liczba2 - liczba1;
            push(&wierzch, wynik);
            printf("%d", wynik);
        }
        else if (!strcmp(&znak, "*")) /*sprawdzenie czy gwiazdka - mnozenie*/
        {
            liczba1 = pop(&wierzch);
            liczba2 = pop(&wierzch);
            wynik = liczba2 * liczba1;
            push(&wierzch, wynik);
            printf("%d", wynik);
        }
        else if (!strcmp(&znak, "/")) /*sprawdzenie czy ukosnik - dzielenie calkowitoliczbowe*/
        {
            liczba1 = pop(&wierzch);
            liczba2 = pop(&wierzch);
            wynik = liczba2 / liczba1;
            push(&wierzch, wynik);
            printf("%d", wynik);
        }
        else if (!strcmp(&znak, "%")) /*sprawdzenie czy procent - dzielenie modulo*/
        {
            liczba1 = pop(&wierzch);
            liczba2 = pop(&wierzch);
            wynik = liczba2 % liczba1;
            push(&wierzch, wynik);
            printf("%d", wynik);
        }
        else if (!strcmp(&znak, "^")) /*sprawdzenie czy ^ - potegowanie */
        {
            liczba1 = pop(&wierzch);
            liczba2 = pop(&wierzch);
            wynik = pow(liczba2, liczba1);
            push(&wierzch, wynik);
            printf("%d", wynik);
        }
        else if (!strcmp(&znak, "KONIEC")) /*sprawdzenie czy KONIEC - zakoncenie dzialania progr*/
            break;
        else /*jesli zaden ze znakow szczegolnych, dodaj na stos*/
        {
            liczba = atof(&znak);
            push(&wierzch, liczba);
        }
    }
    return 0;
}
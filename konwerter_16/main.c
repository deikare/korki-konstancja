#include <stdio.h>

/*
 * konwerter_16.c
 *
 * Created: 06.06.2021 10:58:51
 * Author : bbgol
 */

#include <stdlib.h>
#include <stdint-gcc.h>

// lub tablice przekazujemy jako uint8_t tab []
void convertDecTo16(uint32_t convertedValue, uint32_t base, uint8_t *tab, int length) {
    int iterator = length - 1; // indeks w tablicy ustawiamy na ostatni� pozycj� w tabie

    while (convertedValue != 0 && iterator >= 0) {
        uint8_t r = convertedValue % base; // r = reszta z dzielenia convertedValue przez base
        convertedValue = (convertedValue - r) / base;
        tab[iterator] = r;
        iterator--;
    }
}

int sumRecursive(int tab[], int amountOfElements) { //amountOfElements to ile pierwszych element�w ci�gu mamy sumowa�
    if (amountOfElements == 1)
        return tab[0];
    else return tab[0] + sumRecursive(tab + 1, amountOfElements - 1);
}

void insertInAscendingManner(int tab[], int length, int insertedValue) {
    //1. - ustali� miejsce wstawienia insertedValue
    //2. - przesun�� dalsze o 1
    //3. - wstawi� insertedValue
    int iterator;
    for (iterator = 0; iterator < length; ++iterator) {
        if (tab[iterator] > insertedValue) { //krok 1
            for (int iteratorPushFurther = length - 2; iteratorPushFurther >= iterator; iteratorPushFurther--) // krok 2
                tab[iteratorPushFurther + 1] = tab[iteratorPushFurther];
            break;
        }
    }
    tab[iterator] = insertedValue;
}

void createDynamicArrayWithChars(char * tab, int length){

    // zadanie z dynamicznym tworzeniem tablicy
    tab = (char *) malloc(length * sizeof(char)); //przydzielenie

    for (int i = 0; i <= length; i++)
        tab[i] = 40 + i; //lub 40 + i

    free(tab); //zwolnienie pami�ci    };
}

/*//zadanie z konwersj�
uint32_t convertedValue = 65234;
uint32_t base = 16;
const int length = 8;
uint8_t tab[8]; //przydzielamy programowi length kom�rek w pami�ci na tablic� i przypisujemy adres pierwszej kom�rki do wska�nika tab

//zadanie z sum� rekurencyjn�
int tab2[] = {5, 2, 7, 4, 1, 6};
int amountOfElements = 4;
int result = 0;

//zadanie z wstawianiem z przesuwaniem
int tab3[] = {1, 2, 7, 9, 11, 16, 20, 25};
int length3 = 8;
int insertedValue = 18;

// zadanie z dynamicznym tworzeniem tablicy
char * tab4;
int length4 = 10;*/

// zadanie ze �redni� arytmetyczn� element�w (i-1) oraz (i+1)
float * tab5;
int length5 = 10;

//typ A
void meanValueOfEachElementOfArray_A(float * tab, int length) {
    float tabCopy[length];

    for (int i = 0; i < length; ++i)
        tabCopy[i] = tab[i]; //tworzymy g��bok� kopi�

    for (int i = 1; i < length - 1; ++i)
        tab[i] = (tabCopy[i - 1] + tabCopy[i + 1]) / 2.0f;
}

//typ B
void meanValueOfEachElementOfArray_B(float * tab, int length) {
    for (int i = 1; i < length - 1; ++i)
        tab[i] = (tab[i - 1] + tab[i + 1]) / 2.0f;
}

//zadanie z średnią arytmetyczną dodatnich elementów tablicy
int tab6[] = {1, -2, -7, 0, -11, 16, -20, 25};
int length6 = 8;



int meanValueOfPositiveElementsOfArray(int tab[] ,int length) {
    int sum = 0;
    int amountOfPositiveElements = 0;

    for (int i = 0; i < length; ++i) {
        if (tab[i] > 0) {
            sum += tab[i];
            amountOfPositiveElements++;
        }
    }

    return sum / amountOfPositiveElements;
}

//zadanie z iloczynem skalarnym
int v1[] = {1, 2, 3};
int v2[] = {4, 8, 10}; //iloczyn = 4 + 16 + 30 = 50
int length7 = 3;

int iloczynSkalarny(int v1[], int v2[], int length) {
    int result = 0;

    for (int i = 0; i < length; ++i) {
        result += v1[i] * v2[i];
    }

    return result;
}

int main(void)
{
    //convertDecTo16(convertedValue, base, tab, length);
    //result = sumRecursive(tab2, amountOfElements);

    //insertInAscendingManner(tab3, length3, insertedValue);

    //createDynamicArrayWithChars(tab4, length4);

    /*tab5 = (float *) malloc(length5 * sizeof(float)); //przydzielenie

    for (int i = 0; i < length5; ++i)
        tab5[i] = (float)rand()/(float)(RAND_MAX/15.0f);

    printf("Przed: \n");
    for (int i = 0; i < length5; ++i)
        printf("%f ", tab5[i]);

    meanValueOfEachElementOfArray_A(tab5, length5);

    //meanValueOfEachElementOfArray_B(tab5, length5);

    printf("\nPo: \n");
    for (int i = 0; i < length5; ++i)
        printf("%f ", tab5[i]);

    free(tab5);*/

    //printf("Średnia dodatnich elementów: %d", meanValueOfPositiveElementsOfArray(tab6, length6));
    printf("Iloczyn skalarny: %d", iloczynSkalarny(v1, v2, length7));
    return 0;
}

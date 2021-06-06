/*
 * konwerter_16.c
 *
 * Created: 06.06.2021 10:58:51
 * Author : bbgol
 */ 

#include <avr/io.h>

// lub tablice przekazujemy jako uint8_t tab []
void convertDecTo16(uint32_t convertedValue, uint32_t base, uint8_t *tab, int length) {
    int iterator = length - 1; // indeks w tablicy ustawiamy na ostatni¹ pozycjê w tabie
    
    while (convertedValue != 0 && iterator >= 0) {
        uint8_t r = convertedValue % base; // r = reszta z dzielenia convertedValue przez base
        convertedValue = (convertedValue - r) / base;
        tab[iterator] = r;
        iterator--;
    }
}

int sumRecursive(int tab[], int amountOfElements) { //amountOfElements to ile pierwszych elementów ci¹gu mamy sumowaæ
    if (amountOfElements == 1)
        return tab[0];
    else return tab[0] + sumRecursive(tab + 1, amountOfElements - 1);
}

void insertInAscendingManner(int tab[], int length, int insertedValue) {
    //1. - ustaliæ miejsce wstawienia insertedValue
    //2. - przesun¹æ dalsze o 1
    //3. - wstawiæ insertedValue
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

//zadanie z konwersj¹
uint32_t convertedValue = 65234;
uint32_t base = 16;
const int length = 8;
uint8_t tab[8]; //przydzielamy programowi length komórek w pamiêci na tablicê i przypisujemy adres pierwszej komórki do wskaŸnika tab

//zadanie z sum¹ rekurencyjn¹
int tab2[] = {5, 2, 7, 4, 1, 6};
int amountOfElements = 4;
int result = 0;

//zadanie z wstawianiem z przesuwaniem
int tab3[] = {1, 2, 7, 9, 11, 16, 20, 25};
int length3 = 8;
int insertedValue = 18;


int main(void)
{
    //convertDecTo16(convertedValue, base, tab, length);
    //result = sumRecursive(tab2, amountOfElements);
    
    insertInAscendingManner(tab3, length3, insertedValue);
    
    insertedValue = 0;
    insertInAscendingManner(tab3, length3, insertedValue);
    insertedValue = 17;
    insertInAscendingManner(tab3, length3, insertedValue);
    return 0;
}


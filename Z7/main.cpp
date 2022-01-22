#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

/*
1. Tablicê A[w][k] (w, k - sta³e) wype³niæ liczbami losowymi rzeczywistymi z przedzia³u <-X, X>,
zaœ tablicê B[w][k] - z przedzia³u <D, G>
(X, D, G – sta³e rzeczywiste).
2. Tablicê A wydrukowaæ wierszami z dok³adnoœci¹ 1 miejsca po kropce,
tablicê B – z dok³adnoœci¹ 2 miejsc.
3. W tablicy A odwróciæ kolejnoœæ elementów (czyli zamieniæ pierwszy z ostatnim, drugi z
przedostatnim itd.) w wierszach o ujemnej œredniej elementów,
zaœ w tablicy B zrobiæ to samo w wierszach, w których œrednia elementów jest mniejsza od (D+G)/2.
4. Ponownie wydrukowaæ obie tablice.
5. Wydrukowaæ informacjê, w której tablicy odwrócono wiêcej wierszy (a mo¿e tyle samo).

W programie wykorzystaæ:

a. funkcję, która jakąś tablicê wype³nia liczbami losowymi rzeczywistymi zawartymi miêdzy
dwiema jakimiœ wartoœciami

b. funkcję, która jak¹œ tablicê podanego typu drukuje wierszami z jak¹œ precyzj¹ (liczb¹
miejsc po kropce)

c, funkcję, która dla jakiejœ tablicy podanego typu odwraca kolejnoœæ elementów w tych
wierszach, w których œrednia elementów jest mniejsza od jakiejœ wartoœci i zwraca (przez
return) liczbê wierszy, w których dokonano takich odwróceñ.

UWAGA: slowo jakiś oznacza parametr funkcji.
*/



using namespace std;


const int w = 6;
const int k = 5;
const double X = 77.7;
const double D = 11.1;
const double G = 66.6;



//funkcja wypelniajaca
void fillRandomArray(double Tab[w][k], double min, double max ) {
    srand(time(NULL));
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < k; j++) {
            Tab[i][j] = ((max - min) * ((double)rand() / RAND_MAX)) + min;
        }
    }
}

//funkcja drukujaca z zadana precyzja
void printArray(double Tab[w][k], int precision) {
    for (int i = 0; i < w; i++) {
        for (int j = 0; j <k; j++) {
            cout << fixed << setw(5) << setprecision(precision) << Tab[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl;
};

//funkcja odwracajaca
void invertArray(double Tab[], int size) {
    double TempTab[size];
    for (int i = 0; i < size; i++) {
        TempTab[size - 1 - i] = Tab[i];
    }
    for (int i = 0; i < size; i++) {
        Tab[i] = TempTab[i];
    }
};

//funkcja zliczajaca
int invertArrayRowIfAvgSmaller(double Tab[w][k], int number) {
    int inverted = 0;
    for (int i = 0; i < w; i++) {
        double sum = 0;
        for (int j = 0; j < k; j++) {
            sum += Tab[i][j];
        }
        if (sum/k < number) {
            invertArray(Tab[i], k);
            inverted++;
        }
    }
    return inverted;
};


int main() {

    double A[w][k];
    double B[w][k];

    int invertedA, invertedB;

    fillRandomArray(A, (-X), X);
    fillRandomArray(B, D, G);

    cout << "Tablica A \n";
    printArray(A, 1);

    cout << "Tablica B \n";
    printArray(B, 2);

    cout << endl;

    invertedA = invertArrayRowIfAvgSmaller(A,0);
    invertedB = invertArrayRowIfAvgSmaller(B, ((D+G)/2));

    cout << "Tablica A - odwrocona \n";
    printArray(A, 1);

    cout << "Tablica B - odwrocona \n";
    printArray(B, 2);

    if(invertedA == invertedB) {
        cout << "W obu tablicach odwrocono tyle samo wierszy: " << invertedA << ".\n";
    } else {
        cout
                << "W tablicy "
                << ((invertedA > invertedB) ? 'A' : 'B')
                << " odwrocono wiecej wierszy: "
                << ((invertedA > invertedB) ? invertedA : invertedB) << ".\n";
    }
    return 0;
}

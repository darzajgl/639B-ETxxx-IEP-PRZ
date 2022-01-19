#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

/*
1. Do tablicy towarów A[n][n] (n - sta³a) wylosowaæ rekordy o polach (nazwa towaru - typu char, cena - typu int) w taki sposób, aby:
- nazwy towarów by³y du¿ymi literami na obwodzie i na obu przek¹tnych tablicy, zaœ ma³ymi literami w pozosta³ym obszarze tablicy.
- ceny by³y jedno- lub dwucyfrowe.
2. Tablicê wydrukowaæ wierszami w postaci kolejnych rekordów, np. a10 R 7 w93…
3. Zamieniæ miejscami najtañszy towar lezacy na drugiej przekatnej tablicy z najdro¿szym towarem le¿¹cym w trzech ostatnich wierszach tej tablicy.
4. Ponownie wydrukowaæ wierszami tablicê oraz zapisaæ j¹ wierszami do pliku ceny.txt, w formacie jak w p.2.

 Wskazówka: Najpierw nale¿y zdefiniowaæ strukturê rekordów.
*/


int main() {

//1.
    const int n = 4;

    struct DataBase {
        char name;
        int price;
    };

    DataBase A[n][n];

    srand(time(0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // losowanie zawartosci
            A[i][j].price = (rand() % 98) + 1;
            A[i][j].name = 'a' + rand() % 26;
            //zmiana wielkosci liter na obwodzie i przekatnych
            if (
                i== j || // glowna przekątna
                i + j + 1 == n || // 2ga przekatna
                i == 0 || // gora
                j == 0 || // lewo
                i == n-1 || // dol
                j == n -1   // prawo
            ) {
                A[i][j].name = toupper(A[i][j].name);
            }
        }
    }

//2. drukowanie
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << char (A[i][j].name) <<" "<< A[i][j].price << "\t";
        }
        cout << endl;
    }
    cout << endl;

//3.
    DataBase lowestPrice;
    DataBase highestPrice;
    lowestPrice = A[0][n-1];

    int lowPrice_i = 0;

    int highPrice_i;
    int highPrice_j;

    // najnizsza cena na drugiej przekatnej
    for (int i = 0; i < n; i++) {
        if (A[i][n-1-i].price < lowestPrice.price) {
            lowestPrice = A[i][n-1-i];
            lowPrice_i = i;
        }
    }
    cout << lowestPrice.price << endl;


    // najwieksza cena w ostatnich trzech wierszach
    for (int i = n-3; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i== n-1-3 && j == 0) {
                highestPrice = A[i][j];
                highPrice_i = i;
                highPrice_j = j;
            }
            if (highestPrice.price < A[i][j].price) {
                highestPrice = A[i][j];
                highPrice_i = i;
                highPrice_j = j;
            }
        }
    }
    cout << highestPrice.price << endl;

    // zamiana elementow
    A[lowPrice_i][n-1-lowPrice_i] = highestPrice;
    A[highPrice_i][highPrice_j] = lowestPrice;

//4. drukowanie po zamianie
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << char (A[i][j].name) <<" "<< A[i][j].price << "\t";
        }
        cout << endl;
    }

    return 0;
}

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

/*
a. Tablice A[n][n] (n-stala) wypelnic liczbami losowymi calkowitymi z przedzialu <D,G> (D,G-stale)
b. Wydrukowac tablice z wierszami ustawiona za pomoca stalej W szerokoscia wydruku.
c. W dodatkowym wierszu pod tak wydrukowana tablica wydrukowac:
    - pod kolumna o indeksie 0 - ilosc liczb parzystych w tej kolumnie
    - pod kazda nastepna kolumna - roznice pomiedzy iloscia liczb parzystych w tej kolumnie a iloscia liczb parzystych w kolumnie poprzedniej
d. Znalezc najwiekszy element glownej przekatnej w tablicy A i zapamietac oraz wydrukowac indeks wiersza w ktorym sie on znajduje.
e. Zmienic miejscami znaleziony najwiekszy element z najmniejszym elementem wiersza, w ktorym go znaleziono.
f. Wydrukowac zawartosc tego wiersza po dokonanej zmianie.

*/

using namespace std;

int main() {

srand(time(NULL));

    const int n = 4;
    const int D = -17;
    const int G = 14;
    int A[n][n];
    const int W = 7;

//a.

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j<n; j++) {
            A[i][j]= D + rand()%(G+1-D);
        }
    }

//b.

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << setw(W) << A[i][j];
        }
        cout << endl;
    }
    cout << endl;

//c.

    int curr=0;
    int prev=0;

    for(int j = 0; j < n; j++) {
        for(int i = 0; i < n; i++) {
            if (A[i][j] % 2 == 0) {
                curr++;
            }
        }
        cout << setw(W) << (curr - prev);
        prev = curr;
        curr = 0;
    }
    cout<<endl;

//d.

    int maxDiag = A[0][0];
    int maxDiagIndex = 0;

    for(int i = 0; i < n; i++) {
        if(A[i][i]>maxDiag) {
            maxDiag = A[i][i];
            maxDiagIndex = i;
        }
    }
    cout << " \nNajwiekszy element na przekatnej to " << maxDiag << ", ktory znajduje sie w wierszu nr " << maxDiagIndex << "." <<endl;

//e.

    int minRow = A[maxDiagIndex][0];
    int minColumnIndex = 0;

    for(int j = 1 ; j < n; j++)
        if(A[maxDiagIndex][j] < minRow) {
            minRow = A[maxDiagIndex][j];
            minColumnIndex = j;
        }

    int temp = A[maxDiagIndex][minColumnIndex];
    A[maxDiagIndex][minColumnIndex] = A[maxDiagIndex][maxDiagIndex];
    A[maxDiagIndex][maxDiagIndex] = temp;

//f.

    cout << "\nWiersz o indeksie " <<maxDiagIndex << " z zamienionymi wartosciami:" << endl;
    for (int j= 0; j < n; j++) {
        cout << setw(W) << A[maxDiagIndex][j];
    }


    return 0;
}

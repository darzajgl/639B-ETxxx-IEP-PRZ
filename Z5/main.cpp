#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
/*
1. Z pliku o nazwie podanej przez u¿ytkownika wczytaæ wierszami dane rzeczywiste ( mog¹ byæ ujemne, mog¹ byæ bez kropki) do tablicy A[w][k] (w,k-sta³e).
Jeœli danych w plików bêdzie za ma³o, wolne miejsca w tablicy A powinny byæ wype³nione wartoœci¹ sta³¹ Z.

2. Wydrukowaæ tablicê wierszami ze sta³¹ liczb¹ P miejsc po kropce i sta³¹ serokoœci¹ D kolumn.

3. Dla ka¿dego wiersza tablicy:
    a. wydrukowaæ œredni¹ wszystkich elementów w tym wierszu
    b. wydurukowaæ œredni¹ skrajnych elementów w tym wierszu
    c. przesun¹æ cyklicznie w lewo ten wiersz, jeœli œrednia wszystkich elementów w tym wierszu jest wiêksza od œredniej skrajnych elementów tego wiersza.

4. Ponownie wydrukowaæ tablicê(w formacie jak w p.2).

5. Na koniec ca³¹ tablicê zapisaæ wierszami (w formacie jak 2 p.2) do pliku o nazwie "nowa.txt"

wskazówki:
1. nale¿y sygnalizowaæ brak pliku danymi o podanej nazwie i zakoñczyæ program.
2. najpierw wype³niamy sta³¹ Z ca³¹ tablicê, a potem z pliku wczytujemy wierszami tablicê analogicznie jak z klawiaruty
    -wczyta siê co najwy¿ej tyle danych, ile jest w pliku (nie trzeba sprawdzaæ eof).
3. przesuwanie cykliczne w tablicy jest omówione w lekcji 3.2.

*/



using namespace std;

int main() {

    int i;
    int j;

    const int w = 6;
    const int k = 4;
    double A[w][k];
    const double Z = 5.123456;

    const int P = 3;
    const int D = 10;


    string nazwaPliku;
    ifstream dane; //("dane.txt")
    ofstream wyniki ("nowa.txt");


    cout << "Podaj z jakiego pliku pobrac dane?\n";

    getline(cin, nazwaPliku);
    dane.open(nazwaPliku.c_str());

    if(!dane.good()) {
        cout << "Blad otwarcia pliku. Sprawdz czy plik istnieje" << endl;

        return 1;
    }
    for (i = 0; i < w; i++) {
        for (j = 0; j < k; j++) {
            A[i][j] = Z;
        }
    }
    for (i = 0; i < w; i++) {
        for (j = 0; j < k; j++) {
            dane >> A[i][j];
        }
    }

//2.
    for (i = 0; i<w; i++) {
        for (j=0; j<k; j++) {
            cout << setw(D) << fixed << setprecision(P) << A[i][j];
        }
        cout << endl;
    }
    cout << endl;

//3.a.b

    double avg[w];
    double avgExternal[w];
    double sum[w];
    double sumExternal = 0;

    for(i  = 0; i < w; i++) {
        avg[i] = 0;
        sum[i] = 0;
        avgExternal[i] = 0;
    }

    for(i = 0; i < w; i++) {
        for (j = 0; j < k; j++) {
            sum [i] +=A[i][j];
        }

        avg[i] = sum[i]/k;
        avgExternal[i] = (A[i][0]+A[i][k-1]) /2;

        cout << "Wiersz "<< i <<", Srednia calego wiersza: " << fixed << setprecision(P)<<avg[i]
             << ", srednia skrajnych elementow: " << fixed << setprecision(P) << avgExternal[i] <<endl;
    }
    cout << endl;

//3.c.

    double temp;
    for(i = 0; i < w; i++) {
        if(avg[i] > avgExternal[i]) {
            temp = A [i][0];
            for(j = 0; j < k-1 ; j++) {
                A[i][j] = A[i][j+1];
            }
            A [i][k-1] = temp;
        }
    }

//4.

    for (i = 0; i < w; i++) {
        for (j = 0; j < k; j++) {
            cout << setw(D)  << fixed << setprecision(P) << A[i][j];
        }
        cout << endl;
    }

//5.

    for (i = 0; i < w; i++) {
        for (j = 0; j < k; j++) {
            wyniki << setw(D) << fixed << setprecision(P) << A[i][j];
        }
        wyniki << endl;
    }
    dane.close();
    wyniki.close();

    return 0;
}

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
/*
1. Z pliku o nazwie podanej przez u�ytkownika wczyta� wierszami dane rzeczywiste ( mog� by� ujemne, mog� by� bez kropki) do tablicy A[w][k] (w,k-sta�e).
Je�li danych w plik�w b�dzie za ma�o, wolne miejsca w tablicy A powinny by� wype�nione warto�ci� sta�� Z.

2. Wydrukowa� tablic� wierszami ze sta�� liczb� P miejsc po kropce i sta�� seroko�ci� D kolumn.

3. Dla ka�dego wiersza tablicy:
    a. wydrukowa� �redni� wszystkich element�w w tym wierszu
    b. wydurukowa� �redni� skrajnych element�w w tym wierszu
    c. przesun�� cyklicznie w lewo ten wiersz, je�li �rednia wszystkich element�w w tym wierszu jest wi�ksza od �redniej skrajnych element�w tego wiersza.

4. Ponownie wydrukowa� tablic�(w formacie jak w p.2).

5. Na koniec ca�� tablic� zapisa� wierszami (w formacie jak 2 p.2) do pliku o nazwie "nowa.txt"

wskaz�wki:
1. nale�y sygnalizowa� brak pliku danymi o podanej nazwie i zako�czy� program.
2. najpierw wype�niamy sta�� Z ca�� tablic�, a potem z pliku wczytujemy wierszami tablic� analogicznie jak z klawiaruty
    -wczyta si� co najwy�ej tyle danych, ile jest w pliku (nie trzeba sprawdza� eof).
3. przesuwanie cykliczne w tablicy jest om�wione w lekcji 3.2.

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

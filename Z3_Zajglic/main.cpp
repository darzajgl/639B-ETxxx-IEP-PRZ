#include <iostream>

/*
Napisac program, ktory:
a. Definiuje stala calkowita N o dowolnej wartosci >1 (jesli N<=1, program konczy dzialanie).
b. Wczytuje (petla for) N liczb calkowitych i drukuje dwie najwieksze z nich (bez uzycia tablic).
c. Wczytuje (petla for) N napisow i drukuje dwa ostatnie z nich (bez uzycia tablic)
d. Wczytuje (petla for) N znakow i drukuje co drugi wczytany znak w kolejnosci od ostatniego do pierwszego(tu trzebe zastosowac tablice jednowymiarowa)

Wskazowki
ad b. potrzebne sa dwie zmienne do zapietywania aktualnie dwoch najwiekszych liczb.
ad c potrzebne sa dwie zmienne do zapamietywania aktualnie dwoch ostatnich napisow.
ad c. i d. wczytywanie napisow wykonac operatorem cin, oddzielajac je od siebie spacjami lub Enterami (analogicznie jak liczby), znaki (widoczne) tez wczytujemy operatorem cin, mozna ich od siebie nie oddzielac.
*/

using namespace std;

int main() {

//a.

    int N = 6;

            if (N <= 1) {
                cout << "N jest mniejsze lub rowne 1, niestety musze zakonczyc program. \nZmien wartosc N i uruchom program ponownie.\n"<<endl;
                return 0;
            }

//b.
            int a, bigger, bigest;

            cout << "Podaj "<< N <<" liczb." << endl;


            for (int i = 0; i <= N - 1; i++) {
                cout << "Podaj wartosc liczbowa nr "<<i+1 <<" i wcisnij Enter :";
                cin >> a;


                if (i==0) {
                    bigest = a;

                } else if(i == 1) {

                    if(bigest < a) {
                        bigger = bigest;
                        bigest = a;

                    } else {
                        bigger = a;
                    }

                } else if (bigest < a) {
                    bigger = bigest;
                    bigest = a;

                } else if(bigger < a) {
                    bigger = a;
                }

            };

            cout << "\nNajwieksze z podanych liczb to: "<< bigest <<" oraz " << bigger <<".\n" << endl;

//c.

            string b, last, secondLast;

            cout << "Podaj "<< N <<" napisow." << endl;

            for (int i = 0; i<= N-1; i++) {
                cout << "Wprowadz napis nr " << i+1 << " i wcisnij Enter :";
                cin >> b;
                if(i==N-2) {
                    secondLast = b;
                }
                if(i==N-1) {
                    last = b;
                }
            };
            cout << "\nOstatni z wprowadzonych napisow to \""<< last <<"\" a przedostatni to \"" <<secondLast<<"\".\n" << endl;

//d.

    char arr[N/2];
    char c;

    cout << "Podaj " << N <<" znakow." << endl;

    for (int i = 0; i < N; i ++) {
        cout << "Wprowadz znak nr "<< i+1 <<" i wcisnij Enter :";
        cin >> c;
        if((i + N%2) %2 == 0) {
            arr[i/2] = c;
        }
    }
    cout << endl;
    cout << "Co drugi znak od konca: " << endl;

    for (int i = 0; i < N/2; i++) {
        cout << arr[N/2 - i - 1];

    }

    return 0;
}

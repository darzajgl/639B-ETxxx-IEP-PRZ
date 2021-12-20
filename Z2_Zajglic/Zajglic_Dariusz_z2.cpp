#include <iostream>

using namespace std;
/*
1. wymusza wpisanie liczby ca�kowitej x zawartej w przedziale <A,B>
2. drukuje tak okre�lon� warto�� x
3. wczytuje ci�g liczb ca�kowitych a� do wczytania liczby parzystej lub podzielnej przez x
4. drukuje najwi�ksz� ujemn� liczb� tego ci�gu (nie bior�c pod uwag� liczby ko�cz�cej ci�g)
    - lub informacj�, �e nie by�o liczb ujemnych
*/

int main() {
    //deklaracje
    int A = -30;
    int B = 30;
    int x = A-1;
    int zagadka;
    int najwieksza_ujemna = 0;

    //1.
    while(x < A || x > B) {
        cout << "\Podaj liczbe z przedzialu <"<<A<<","<<B<<">"<<endl;
        cin >> x;
    }

    //2.
    cout << "Swietnie, wprowadziles " << x << "." << endl;

    //ponizsze rozwiazanie nie zadziala w przypadku x = 0

    cout << "\nPora na zagadke. \nZnajdz liczbe, ktora uwolni Cie z petli."<<endl;

    //3.
    do {
        if((zagadka < 0 ) && ((zagadka > najwieksza_ujemna) || (najwieksza_ujemna == 0))) {
            najwieksza_ujemna = zagadka;
        }
        cout << "\nPodaj liczbe: ";
        cin >> zagadka;
        cout << "\nWpisales "<<zagadka<<"."<<endl;

    } while((zagadka%2 != 0) && (zagadka%x != 0));

    //4.
    {
        cout<< "Uwolniles sie z petli!"<<endl;
        if(najwieksza_ujemna == 0) {
            cout << "\nNie podales liczb ujemnych."<<endl;
        } else {
            cout << "\nNajwieksza ujemna podana przez Ciebie liczba to: " << najwieksza_ujemna <<endl;
        }
    }
    return 0;
}

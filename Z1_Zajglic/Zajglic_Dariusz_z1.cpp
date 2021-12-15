#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    //zadanie 1
    // deklaracje
    string imie;

    cout << "Podaj swoje imie: ";
    cin >> imie;
    cout <<"Dobrze Cie widziec " << imie <<"!" <<endl;

    //zadanie 2
    //deklaracje
    int a, b;

    cout << "Podaj dwie liczby przedzielone spacja lub enterem: ";
    cin >>a>>b;
    //spr
    cout << "Podane liczby to: "<<a<<" oraz " <<b <<"."<<endl;

    //zadanie 3
    //deklaracje
    int ile;
    ile = 0;

    if(a<10 && a>-10) {
        ile++;
    }
    if(b<10 && b>-10) {
        ile++;
    }

    cout << "Ilosc podanych liczb jednocyfrowych: " << ile << endl;

    int minimal;
    //zadanie 4
    if(a==b) {
        cout <<"Podane liczby sa sobie rowne, koncze dzialanie programu." <<endl;
        cout <<"Bywaj!"<<endl;
        return 0;
    }

    //zadanie 5
    if(a>b) {
        minimal = b;
    } else {
        minimal = a;
    }
    if (minimal==0) {
        cout << "Mniejsza z liczb jest rowna 0."<<endl;
    } else if(minimal>0) {
        cout<< "Mniejsza z liczb jest dodatnia."<<endl;
    } else if(minimal<0) {
        cout<< "Mniejsza z liczb jest ujemna."<<endl;
    }

    //zadanie 6
    float wynik;

    if(b==0) {
        cout << "Chcialbym przedstawic wynik dzialania ale nie mozna dzielic przez 0!" << endl;
    } else {
        wynik = (float)a/(3*(float)b);
        cout << "Podaje wynik obliczen: " << a << " / 3*" << b << " = "<< wynik<<endl;
    }

    return 0;
}

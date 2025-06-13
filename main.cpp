#include <iostream>

using namespace std;

class Klient {
    int ID_Klienta;
    string Imie;
    string Nazwisko;
    double Saldo_Konta;
    double Oprocentowanie;
};

class KlientVIP : public Klient {
    double dodatkoweOprocentowanie;
}

//Dodawanie nowych klientów - Nowy klient saldo = 0, oprocentowanie = 2%
Klient Add_Client() {
    Klient Temporary;
    cout<<"Dodajesz wlasnie nowego klienta"<<endl;
    cout<<"Podaj Imie: ";
    cin>>Temporary.Imie;
    cout<<"Podaj nazwisko: ";
    cin>>Temporary.Nazwisko;
    Temporary.Saldo_Konta = 0;
    Temporary.Oprocentowanie = 1.02;
    return Temporary;
}
//Zasilenie konta klienta
//Wypłata z konta klienta - do wysokości salda
//Przelew pomiędzy dwoma istniejącymi kontami
//Naliczenie oprocentowania dla konta
//Wyświetlanie listy wszystkich klientów
//Wyszukiwanie klienta po ID
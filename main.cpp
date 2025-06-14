#include <iostream>
#include <vector>

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
};

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
void Top_Up_Account(Klient& X)  {
    int T_Value;
    cout<<"Wplacasz pieniadze na konto"<<endl;
    do {
        cout<<"Podaj kwote wplaty: ";
        cin>>T_Value;
        if (T_Value<=0) cout<<"Kwota musi byc dodatnia. Sprobuj jeszcze raz"<<endl;
    } while (T_Value <= 0);
    X.Saldo_Konta += T_Value;
}

//Wypłata z konta klienta - do wysokości salda
void Withdraw_Cash(Klient& X) {
    int T_Value;
    cout<<"Wyplacasz pieniadze z konta"<<endl;
    do {
    cout<<"Podaj kwote wyplaty: ";
    cin>>T_Value;
    if (T_Value<=0) {
        cout<<"Kwota musi byc dodatnia. Sprobuj jeszcze raz"<<endl;
    } else if (T_Value > X.Saldo_Konta) {
        cout<<"Brak wystarczajacych srodkow. Sprbuj jeszcze raz"<<endl;
    }
    } while (T_Value <= 0 || T_Value > X.Saldo_Konta);
    X.Saldo_Konta -= T_Value;
}

//Przelew pomiędzy dwoma istniejącymi kontami
void Money_Transfer(Klient& X, Klient& Y) {
    int T_Value;
    cout<<"Przelewasz pieniadze na konto klienta o numerze " << Y.ID_Klienta <<endl;
    do {
    cout<<"Podaj kwote przelewu: ";
    cin>>T_Value;
    if (T_Value<=0) {
        cout<<"Kwota musi byc dodatnia. Sprobuj jeszcze raz"<<endl;
    } else if (T_Value > X.Saldo_Konta) {
        cout<<"Brak wystarczajacych srodkow. Sprbuj jeszcze raz"<<endl;
    }
    } while (T_Value <= 0 || T_Value > X.Saldo_Konta);
    X.Saldo_Konta -= T_Value;
    Y.Saldo_Konta += T_Value;
}

//Naliczenie oprocentowania dla konta
void Add_Interest_Money(Klient X) {
    X.Saldo_Konta *= X.Oprocentowanie;
}

//Wyświetlanie listy wszystkich klientów
void List_Of_Client(vector<Klient>& X) {  //Referencja w celu oszczędzania pamięci - większa szybkość bez kopiowania 
    cout<<"Lista klientow"<<endl;
    for (int i = 0; i < X.size(); i++)
    {
        cout << X[i].ID_Klienta << " " << X[i].Imie << " " << X[i].Nazwisko << " " << X[i].Saldo_Konta << " " << X[i].Oprocentowanie << endl;
    }
}

//Wyszukiwanie klienta po ID
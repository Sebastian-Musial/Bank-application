#include <iostream>
#include <vector>

using namespace std;

class Klient {
public:
    int ID_Klienta;
    string Imie;
    string Nazwisko;
    double Saldo_Konta;
    double Oprocentowanie;

    //Konstruktor
    Klient(int id_klienta, string imie, string nazwisko, double saldo_konta, double oprocentowanie) : 
    ID_Klienta(id_klienta), Imie(imie), Nazwisko(nazwisko), Saldo_Konta(saldo_konta), Oprocentowanie(oprocentowanie) {}

    //Konstruktor domyslny
    Klient() {}
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
void Search_Client(vector<Klient>& X) {
    cout<<"Szukasz klienta"<<endl;
    int ID;
    char Choice = 'Y';
    while (Choice == 'Y' || Choice == 'y') {
        
        do {
            cout<<"Podaj ID klienta: ";
            cin>>ID;

            if (ID<0) { 
                cout<<"Numer klienta musi byc dodatni"<<endl;
                cout<<"Czy chcesz sprobowac jeszcze raz? Y/N: ";
                cin>>Choice;
                if (Choice == 'N' || Choice == 'n') return;
                }
        } while (ID < 0);

        bool Found = false;
        int Index;

        for (int i = 0; i < X.size(); i++) {
            if (ID == X[i].ID_Klienta) {
                Found = true;
                Index = i;
                break;
                }
            }

        if (!Found) {
            cout<<"Nie ma klienta o podanym ID"<<endl;
            cout<<"Czy chcesz sprobowac jeszcze raz? Y/N: ";
            cin>>Choice;
            continue;
        }

        //Ponizszy kod wykona sie tylko jak bedzie znaleziony klient (Found == True)
        cout<<"Dane klienta "<< ID <<endl;
        cout<< X[Index].Imie << " " << X[Index].Nazwisko << "\nSaldo konta: " << X[Index].Saldo_Konta << "\nOprocentowanie: " << (X[Index].Oprocentowanie - 1) * 100 << "%" << endl;
    }
}

//Testowy vector klientow
vector<Klient> List_Client = {
    {1234, "Adam", "Nowak", 1000, 1.02},
    {3721, "Anna", "Rak", 10000, 1.10},
    {919, "Patryk", "Konski", 100, 1.02},
    {2222, "Elzbieta", "Krol", 2000, 1.02}
};
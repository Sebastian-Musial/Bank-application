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
Klient Add_Client(int Temp_ID) {
    Klient Temporary;
    cout<<"Dodajesz wlasnie nowego klienta"<<endl;
    cout<<"Podaj Imie: ";
    cin>>Temporary.Imie;
    cout<<"Podaj nazwisko: ";
    cin>>Temporary.Nazwisko;
    Temporary.Saldo_Konta = 0;
    Temporary.Oprocentowanie = 1.02;
    Temporary.ID_Klienta = Temp_ID + 1;
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
    {1, "Adam", "Nowak", 1000, 1.02},
    {2, "Anna", "Rak", 10000, 1.10},
    {3, "Patryk", "Konski", 100, 1.02},
    {4, "Elzbieta", "Krol", 2000, 1.02}
};

 int main() {
    int M_Choice;
    cout<<"Witaj w aplikacji bankowej!"<<endl;

    //Menu
    do {
        cout<<"Menu"<<endl;
        cout<<"1. Dodanie nowego klienta"<<endl;
        cout<<"2. Zasilenie konta"<<endl;
        cout<<"3. Wyplata z konta"<<endl;
        cout<<"4. Przelew pomiedzy kontami"<<endl;
        cout<<"5. Naliczenie oprocentowania"<<endl;
        cout<<"6. Wyswietlenie listy klientow"<<endl;
        cout<<"7. Wyszukanie klienta po ID"<<endl;
        cout<<"8. Autor"<<endl;
        cout<<"9. Wyjscie z programu"<<endl;

        do
        {
            cout<<"Podaj cyfre od 1 do 9.\nTwoj wybor: ";
            cin>> M_Choice;
            if (M_Choice < 1 || M_Choice > 9) cout<<"Wybrales bledna cyfre"<<endl;
        } while (M_Choice < 1 || M_Choice > 9);

        int C_ID = 0, C_ID_2 = 0, M_Index = 0, M_Index_2 = 0;
        bool M_Found;
        M_Found = false;

        switch (M_Choice)
        {
        case 1:

            List_Client.push_back(Add_Client(List_Client.size()));
            break;
        
        case 2:
            cout<<"Dla klienta o jakim ID chcesz dokonac zasilenia konta: ";
            cin>>C_ID;
            for (int i = 0; i < List_Client.size(); i++)
            {
                if(C_ID == List_Client[i].ID_Klienta) {
                M_Found = true;
                M_Index = i;
                break;
                }
            }
            if(M_Found == true)Top_Up_Account(List_Client[M_Index]);
            else cout<<"Bledny numer klienta. Powrot do menu"<<endl;
            break;
        
        case 3:
            cout<<"Dla klienta o jakim ID chcesz dokonac wyplaty: ";
            cin>>C_ID;
            for (int i = 0; i < List_Client.size(); i++)
            {
                if(C_ID == List_Client[i].ID_Klienta) {
                M_Found = true;
                M_Index = i;
                break;
                }
            }
            if(M_Found == true)Withdraw_Cash(List_Client[M_Index]);
            else cout<<"Bledny numer klienta. Powrot do menu"<<endl;
            break;
        
        case 4:
            cout<<"Od klienta o jakim ID chcesz dokonac przelewu: ";
            cin>>C_ID;
            for (int i = 0; i < List_Client.size(); i++)
            {
                if(C_ID == List_Client[i].ID_Klienta) {
                M_Found = true;
                M_Index = i;
                break;
                }
            }

            if(M_Found == false) {
                cout<<"Bledny numer klienta. Powrot do menu"<<endl;
                break;
            }

            M_Found = false;

            cout<<"Do klienta o jakim ID chcesz dokonac przelewu: ";
            cin>>C_ID_2;
            for (int i = 0; i < List_Client.size(); i++)
            {
                if(C_ID_2 == List_Client[i].ID_Klienta) {
                M_Found = true;
                M_Index_2 = i;
                break;
                }
            }

            if(M_Found == true)Money_Transfer(List_Client[M_Index], List_Client[M_Index_2]);
            else {
                cout<<"Bledny numer klienta. Powrot do menu"<<endl;
                break;
            }
            break;

        case 5:
            cout<<"Dla klienta o jakim ID chcesz dokonac naliczenia oprocentowania: ";
            cin>>C_ID;
            for (int i = 0; i < List_Client.size(); i++)
            {
                if(C_ID == List_Client[i].ID_Klienta) {
                M_Found = true;
                M_Index = i;
                break;
                }
            }
            if(M_Found == true)Add_Interest_Money(List_Client[M_Index]);
            else cout<<"Bledny numer klienta. Powrot do menu"<<endl;
            break;
        
        case 6:
            List_Of_Client(List_Client);
            break;

        case 7:
            Search_Client(List_Client);
            break;

        case 8:
            cout<<"Autor: Sebastian Musial"<<endl;
            cout<<"Indeks: 162790"<<endl;
            break;
        }
    } while (M_Choice != 9);
    return 0;
 }
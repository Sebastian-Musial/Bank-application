#include <iostream>
#include <vector>
#include <iomanip>

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
    cout<<"\nDodajesz wlasnie nowego klienta"<<endl;
    cout<<"\nPodaj Imie: ";
    cin>>Temporary.Imie;
    cout<<"Podaj nazwisko: ";
    cin>>Temporary.Nazwisko;
    Temporary.Saldo_Konta = 0;
    Temporary.Oprocentowanie = 1.02;
    Temporary.ID_Klienta = Temp_ID + 1;
    cout<<endl;
    return Temporary;
}

//Zasilenie konta klienta
void Top_Up_Account(Klient& X)  {
    int T_Value;
    cout<<"\nWplacasz pieniadze na konto"<<endl;
    do {
        cout<<"\nPodaj kwote wplaty: ";
        cin>>T_Value;
        if (T_Value<=0) cout<<"\nKwota musi byc dodatnia. Sprobuj jeszcze raz"<<endl;
    } while (T_Value <= 0);
    X.Saldo_Konta += T_Value;
    cout<<"Pieniadze wplacone\n"<<endl;
}

//Wypłata z konta klienta - do wysokości salda
void Withdraw_Cash(Klient& X) {
    int T_Value;
    cout<<"\nWyplacasz pieniadze z konta"<<endl;
    do {
    cout<<"\nPodaj kwote wyplaty: ";
    cin>>T_Value;
    if (T_Value<=0) {
        cout<<"\nKwota musi byc dodatnia. Sprobuj jeszcze raz"<<endl;
    } else if (T_Value > X.Saldo_Konta) {
        cout<<"\nBrak wystarczajacych srodkow. Sprobuj jeszcze raz"<<endl;
    }
    } while (T_Value <= 0 || T_Value > X.Saldo_Konta);
    X.Saldo_Konta -= T_Value;
    cout<<"\nPieniadze wyplacone\n"<<endl;
}

//Przelew pomiędzy dwoma istniejącymi kontami
void Money_Transfer(Klient& X, Klient& Y) {
    int T_Value;
    cout<<"\nPrzelewasz pieniadze na konto klienta o numerze " << Y.ID_Klienta <<endl;
    do {
    cout<<"\nPodaj kwote przelewu: ";
    cin>>T_Value;
    if (T_Value<=0) {
        cout<<"\nKwota musi byc dodatnia. Sprobuj jeszcze raz"<<endl;
    } else if (T_Value > X.Saldo_Konta) {
        cout<<"\nBrak wystarczajacych srodkow. Sprbuj jeszcze raz"<<endl;
    }
    } while (T_Value <= 0 || T_Value > X.Saldo_Konta);
    X.Saldo_Konta -= T_Value;
    Y.Saldo_Konta += T_Value;
    cout<<"\nPieniadze przelane\n"<<endl;
}

//Naliczenie oprocentowania dla konta
void Add_Interest_Money(Klient& X) {
    X.Saldo_Konta *= X.Oprocentowanie;
    cout<<"\nOprocentowanie naliczone\n"<<endl;
}

//Wyświetlanie listy wszystkich klientów
void List_Of_Client(vector<Klient>& X) {  //Referencja w celu oszczędzania pamięci - większa szybkość bez kopiowania 
    cout<<"\nLista klientow\n"<<endl;
    for (int i = 0; i < X.size(); i++)
    {
        cout << X[i].ID_Klienta << " " << left << setw(12) << X[i].Imie << " " << left << setw(12) << X[i].Nazwisko 
        << " Saldo konta: " << setw(20) << X[i].Saldo_Konta << " Oprocentowanie: " << setw(4) << (X[i].Oprocentowanie - 1) * 100 << "%" << endl;
    }
    cout<<endl;
}

//Wyszukiwanie klienta po ID
void Search_Client(vector<Klient>& X) {
    cout<<"\nSzukasz klienta"<<endl;
    int ID;
    char Choice = 'Y';
    while (Choice == 'Y' || Choice == 'y') {
        
        do {
            cout<<"\nPodaj ID klienta: ";
            cin>>ID;

            if (ID<0) { 
                cout<<"\nNumer klienta musi byc dodatni"<<endl;
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
            cout<<"\nNie ma klienta o podanym ID"<<endl;
            cout<<"Czy chcesz sprobowac jeszcze raz? Y/N: ";
            cin>>Choice;
            continue;
        }

        //Ponizszy kod wykona sie tylko jak bedzie znaleziony klient (Found == True)
        cout<<"\nDane klienta o ID: "<< ID <<endl;
        cout<< X[Index].Imie << " " << X[Index].Nazwisko << "\nSaldo konta: " << X[Index].Saldo_Konta << "\nOprocentowanie: " << (X[Index].Oprocentowanie - 1) * 100 << "%\n" << endl;
        Choice = 'N';
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
    cout<<"Witaj w aplikacji bankowej!\n"<<endl;

    //Menu
    do {
        cout<<"Menu\n"<<endl;
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
            cout<<"\nPodaj cyfre od 1 do 9.\nTwoj wybor: ";
            cin>> M_Choice;
            if (M_Choice < 1 || M_Choice > 9) cout<<"\nWybrales bledna cyfre"<<endl;
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
            cout<<"\nDla klienta o jakim ID chcesz dokonac zasilenia konta: ";
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
            else cout<<"\nBledny numer klienta. Powrot do menu\n"<<endl;
            break;
        
        case 3:
            cout<<"\nDla klienta o jakim ID chcesz dokonac wyplaty: ";
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
            else cout<<"\nBledny numer klienta. Powrot do menu\n"<<endl;
            break;
        
        case 4:
            cout<<"\nOd klienta o jakim ID chcesz dokonac przelewu: ";
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
                cout<<"\nBledny numer klienta. Powrot do menu\n"<<endl;
                break;
            }

            M_Found = false;

            cout<<"\nDo klienta o jakim ID chcesz dokonac przelewu: ";
            cin>>C_ID_2;
            for (int i = 0; i < List_Client.size(); i++)
            {
                if(C_ID_2 == List_Client[i].ID_Klienta) {
                M_Found = true;
                M_Index_2 = i;
                break;
                }
            }

            if(M_Found == true && C_ID != C_ID_2)Money_Transfer(List_Client[M_Index], List_Client[M_Index_2]);
            else {
                cout<<"\nBledny numer klienta. Powrot do menu\n"<<endl;
                break;
            }
            break;

        case 5:
            cout<<"\nDla klienta o jakim ID chcesz dokonac naliczenia oprocentowania: ";
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
            else cout<<"\nBledny numer klienta. Powrot do menu\n"<<endl;
            break;
        
        case 6:
            List_Of_Client(List_Client);
            break;

        case 7:
            Search_Client(List_Client);
            break;

        case 8:
            cout<<"\nAutor: Sebastian Musial"<<endl;
            cout<<"Indeks: 162790\n"<<endl;
            break;
        }
    } while (M_Choice != 9);
    return 0;
 }
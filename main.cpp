

class Klient {
    int ID_Klienta
    string Imie
    string Nazwisko
    double Saldo_Konta
    double Oprocentowanie
}

class KlientVIP : public Klient {
    double dodatkoweOprocentowanie
}

//Dodawanie nowych klientów
//Zasilenie konta klienta
//Wypłata z konta klienta - do wysokości salda
//Przelew pomiędzy dwoma istniejącymi kontami
//Naliczenie oprocentowania dla konta
//Wyświetlanie listy wszystkich klientów
//Wyszukiwanie klienta po ID
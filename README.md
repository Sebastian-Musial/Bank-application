# Aplikacja bankowa - Praca studencka
Projekt aplikacji bankowej w języku C++ na przedmiot programowania obiektowego
Autor: Sebastian Musiał
Numer indeksu: 162790
Kierunek: Informatyka

## Aplikacja dzieli klientów bankowych na 2 typy:
- Typ VIP z dodatkowym 10% oprocentowaniem konta
- Typ nie VIP bez dodatkowego oprocentowania konta

Każdy nowo tworzony klient, niezależnie czy jest to klient VIP czy też nie, posiada podstawowe oprocentowanie w wysokości 2%

W kodzie programu klienci nie VIP są klasą "klient" z podanymi poniżej atrybutami:
- ID klienta (int)
- Imie(string)
- Nazwisko (string)
- Saldo konta (double)
- Oprocentowanie (double)
Klasa "klient" jest klasą główną

W kodzie programu klienci VIP są pochodną klasy "klient" o nazwie "KlientVIP" i posiadają dodatkowy atrybut:
- dodatkoweOprocentowanie (double)

## Funkcje aplikacji
- Dodawanie nowych klientów
- Zasilenie konta klienta
- Wypłatę z konta klienta (do wysokości salda)
- Przelew pomiędzy dwoma istniejącymi kontami
- Naliczenie oprocentowania dla konta
- Wyświetlanie listy wszystkich klientów.
- Wyszukiwanie klienta po ID.

## Dane wbudowane w aplikacje
Aplikacja posiada wbudowaną listę klientów w celu łatwiejszego sprawdzenia działania aplikacji:

- Klient {1, "Adam", "Nowak", 1000, 1.02},
- Klient {2, "Anna", "Rak", 10000, 1.10},
- Klient {3, "Patryk", "Konski", 100, 1.02},
- Klient {4, "Elzbieta", "Krol", 2000, 1.02},
- KlientVIP {5, "Izabela", "Wipowska", 20000, 1.02, 0.10},
- KlientVIP {6, "Ryszard", "Bogacz", 25000, 1.02, 0.10}

W przypadku dodania nowych klientów, są oni dostępni do czasu zamknięcia aplikacji. Aplikacja nie zapisuje wprowadzony zmian i przy ponownym uruchomieniu dane się resetują.

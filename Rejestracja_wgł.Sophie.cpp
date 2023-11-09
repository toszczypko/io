#include <iostream>
#include <string>
using namespace std;

int max_id = 0;// temp model bazy danych
struct db {
    int kod;
    int id;
    string imie;
    string nazwisko;
    int nr_albumu;
    int grupa;
};
db* baza[100];
int good_kod = 123;

db* wprowadz_dane() {
    db* konto = new db{};
    cout << "podaj kod:";   cin >> konto->kod;
    cout << "podaj imie:";   cin >> konto->imie;
    cout << "podaj nazwisko:";   cin >> konto->nazwisko;
    cout << "podaj nr.albumu:";   cin >> konto->nr_albumu;
    cout << "podaj grupe:";   cin >> konto->grupa;
    return konto;
}

int weryfikacja(db* konto) { //0 - dane zle  1 - dane dobre

    if (konto->kod != good_kod) {
        cout << "\nbledny kod!\n";
        return 0;
    }
    for (size_t i = 0; i < max_id; i++)
    {
        if (konto->nr_albumu == baza[i]->nr_albumu) {
            cout << "\nnr albumu jest juz zarejestrowany!\n";
            return 0;
        }
    }
    return 1;
}
void zapisz_wbazie(db* x) {
    x->id = max_id;
    baza[max_id] = x;
    max_id++;
}
db* szyfr(db* x) {    //szyfrem jest kod cezara z offsetem 0 (nikt by sie nie spodziewał)
    return x;
}
db* deszyfr(db* x) {
    return x;
}

//funkcja realizowana przez inny przypadek na potrzeby testy zakładamy udane logowanie (1 - udane logowanie 0 - nieudane logowanie)
int logowanie() {
    return 1;
}


int main()
{
    while (true)
    {
        cout << "\nREJESTRACJA KONTA    (kod to 123)\n";
        db* nowe = wprowadz_dane();
        if (weryfikacja(nowe)) {    //udana weryfikacja
            nowe = szyfr(nowe);
            zapisz_wbazie(nowe);
            if (logowanie()) {
                cout << "\n[interface konta]\n";
            }
            else {
                cout << "\nlogowanie nieudane, sprobuj ponownie\n";
            }
        }
        //nieudana weryfikacja
    }
}
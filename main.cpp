/* Oleksii Bieskrovnyi*/
#include <iostream>
#include <string>
using namespace std;

string liczbaNaSlowa(int n) {
    if (n < 0 || n > 10000) {
        return "Liczba poza zakresem!";
    }

    if (n == 0) return "zero";
    if (n == 10000) return "dziesięć tysięcy";

    string jednostki[] = {"", "jeden", "dwa", "trzy", "cztery", "pięć", "sześć", "siedem", "osiem", "dziewięć"};
    string nastki[] = {"dziesięć", "jedenaście", "dwanaście", "trzynaście", "czternaście", "piętnaście", "szesnaście", "siedemnaście", "osiemnaście", "dziewiętnaście"};
    string dziesiatki[] = {"", "dziesięć", "dwadzieścia", "trzydzieści", "czterdzieści", "pięćdziesiąt", "sześćdziesiąt", "siedemdziesiąt", "osiemdziesiąt", "dziewięćdziesiąt"};
    string setki[] = {"", "sto", "dwieście", "trzysta", "czterysta", "pięćset", "sześćset", "siedemset", "osiemset", "dziewięćset"};

    string wynik = "";

    int tys = n / 1000;
    if (tys > 0) {
        if (tys == 1) {
            wynik += "tysiąc ";
        } else if (tys >= 2 && tys <= 4) {
            wynik += jednostki[tys] + " tysiące ";
        } else {
            wynik += jednostki[tys] + " tysięcy ";
        }
    }

    n %= 1000;
    int sto = n / 100;
    if (sto > 0) {
        wynik += setki[sto] + " ";
    }

    n %= 100;
    if (n >= 10 && n <= 19) {
        wynik += nastki[n - 10] + " ";
    } else {
        int dzies = n / 10;
        if (dzies > 0) {
            wynik += dziesiatki[dzies] + " ";
        }

        int jed = n % 10;
        if (jed > 0) {
            wynik += jednostki[jed] + " ";
        }
    }

    return wynik;
}

int main() {
    int n;
    cout << "Podaj liczbe (0 <= n <= 10000): ";
    cin >> n;

    cout << liczbaNaSlowa(n) << endl;

    return 0;
}

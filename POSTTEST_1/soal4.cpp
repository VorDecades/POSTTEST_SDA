#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int angka1 = 10;
    int angka2 = 50;

    cout << "= Sebelum =" << endl;
    cout << "Angka 1 : " << angka1 << endl;
    cout << "Angka 2 : " << angka2 << endl;

    swap(&angka1, &angka2);

    cout << "\n=== Sesudah ===" << endl;
    cout << "Angka 1 : " << angka1 << endl;
    cout << "Angka 2 : " << angka2 << endl;

    return 0;
}
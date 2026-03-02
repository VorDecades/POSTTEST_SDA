#include <iostream>
using namespace std;

void revArray(int* arr, int n) {
    int* a = arr;
    int* b = arr + n - 1;

    while (a < b) {
        int temp = *a;
        *a = *b;
        *b = temp;

        a++;
        b--;
    }
}

void printArrayAlamat(int* arr, int n) {
    int* p = arr;

    while (p < arr + n) {
        cout << "Nilai: " << *p << "\t| Alamat: " << p << endl;
        p++;
    }
    cout << "=================================" << endl;
}

int main() {
    int primes[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;

    cout << "= Array sebelum dibalik =" << endl;
    printArrayAlamat(primes, n);

    revArray(primes, n);

    cout << "\n= Array sesudah dibalik =" << endl;
    printArrayAlamat(primes, n);

    return 0;
}
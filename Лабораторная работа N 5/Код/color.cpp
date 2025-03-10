#include <iostream>
#include <windows.h> // Untuk mengatur warna di konsol

using namespace std;

// Fungsi untuk mengatur warna teks
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Fungsi untuk mencetak array dengan diagonal utama, sekunder, dan segitiga berwarna
void printArray(int** A, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // Mengatur warna untuk elemen diagonal utama
            if (i == j) {
                setColor(10); // Hijau untuk diagonal utama
            } 
            // Mengatur warna untuk elemen diagonal sekunder
            else if (i + j == N - 1) {
                setColor(9); // Biru untuk diagonal sekunder
            } 
            // Mengatur warna untuk elemen segitiga atas
            else if (i < j && i + j < N - 1) {
                setColor(5); // Ungu untuk segitiga atas
            } 
            // Mengatur warna untuk elemen segitiga bawah
            else if (i > j && i + j > N - 1) {
                setColor(5); // Ungu untuk segitiga bawah
            }
            // Mengatur warna untuk elemen segitiga kiri dan kanan
            else if (j < i && j + i < N - 1) {
                setColor(14); // Kuning untuk segitiga kiri
            } 
            else if (j > i && i + j > N - 1) {
                setColor(14); // Kuning untuk segitiga kanan
            }
            else {
                setColor(7); // Putih untuk elemen lainnya
            }
            cout << A[i][j] << " ";
        }
        cout << endl; 
    }
    // Reset warna ke default setelah mencetak
    setColor(7);
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void triugolnik(int** A, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i < j && j < N - i - 1) {  
                // Upper - Under
                swap(A[i][j], A[N - i - 1][j]);
            } else if (j < i && i < N - j - 1) { 
                // Left - Right
                swap(A[i][j], A[i][N - j - 1]);
            }
        }
    }
}

int main() {
    int N;
    
    cout << "Input size of array N (must be odd and between 3 and 99): ";
    cin >> N;

    if (N % 2 == 0 || N < 3 || N > 99) {
        cout << "Size must be an odd number between 3 and 99. Try again." << endl;
        return 1;
    }

    // Alokasi memori untuk array
    int** A = new int*[N];
    for (int i = 0; i < N; ++i) {
        A[i] = new int[N];
    }

    // Mengisi array dari 0 hingga N*N-1
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            A[i][j] = i * N + j;
        }
    }

    cout << "Original Array of A:" << endl;
    printArray(A, N);

    triugolnik(A, N);

    cout << "\nArray after changes:" << endl;
    printArray(A, N);

    // Membebaskan memori yang dialokasikan
    for (int i = 0; i < N; ++i) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}

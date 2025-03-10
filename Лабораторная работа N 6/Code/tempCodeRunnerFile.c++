#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

// Struct to track sorting efficiency
struct Counter {
    int comparisons;
    int swaps;
};

// Global counters for each algorithm
Counter bubble_counter = {0, 0};
Counter selection_counter = {0, 0};
Counter insertion_counter = {0, 0};
Counter shell_counter = {0, 0};
Counter quick_counter = {0, 0};

// Function to generate a random matrix
vector<vector<int>> generate_random_matrix(int M, int N) {
    vector<vector<int>> matrix(M, vector<int>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = rand() % 100;  // Random numbers between 0 and 99
        }
    }
    return matrix;
}

//Fixed Bubble Sort with Early Exit
void bubble_sort(vector<int>& arr) {
    bubble_counter = {0, 0};
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            bubble_counter.comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                bubble_counter.swaps++;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

//Selection Sort
void selection_sort(vector<int>& arr) {
    selection_counter = {0, 0};
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            selection_counter.comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
            selection_counter.swaps++;
        }
    }
}

//Insertion Sort
void insertion_sort(vector<int>& arr) {
    insertion_counter = {0, 0};
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j]) {
            // Count each successful comparison inside the loop.
            insertion_counter.comparisons++;
            arr[j + 1] = arr[j];
            insertion_counter.swaps++;
            j--;
        }
        //Count the final comparison when the while condition fails (if any)
        if (j >= 0)
            insertion_counter.comparisons++;
        arr[j + 1] = key;
    }
}

//Shell Sort
void shell_sort(vector<int>& arr) {
    shell_counter = {0, 0};
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                shell_counter.comparisons++;
                arr[j] = arr[j - gap];
                shell_counter.swaps++;
            }
            if (j >= gap)
                shell_counter.comparisons++;
            arr[j] = temp;
        }
    }
}

//Quick Sort
void quick_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            quick_counter.comparisons++;
            if (arr[j] <= pivot) {
                i++;
                if (i != j) {  //Only count swap if different positions
                    swap(arr[i], arr[j]);
                    quick_counter.swaps++;
                }
            }
        }
        if (i + 1 != high) {
            swap(arr[i + 1], arr[high]);
            quick_counter.swaps++;
        }
        int pi = i + 1;
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
void quick_sort(vector<int>& arr) {
    quick_counter = {0, 0};
    quick_sort(arr, 0, arr.size() - 1);
}

//Chessboard Sort
vector<vector<int>> chessboard_sort(vector<vector<int>> matrix) {
    int M = matrix.size();
    if (M == 0) return matrix;
    int N = matrix[0].size();

    //Sort white squares in each row in ascending order.
    for (int i = 0; i < M; ++i) {
        vector<int> whiteValues;
        vector<int> whiteCols;
        for (int j = 0; j < N; ++j) {
            if ((i + j) % 2 == 0) {  // white square
                whiteValues.push_back(matrix[i][j]);
                whiteCols.push_back(j);
            }
        }
        sort(whiteValues.begin(), whiteValues.end());
        sort(whiteCols.begin(), whiteCols.end());
        for (size_t k = 0; k < whiteValues.size(); ++k) {
            matrix[i][whiteCols[k]] = whiteValues[k];
        }
    }

    //Sort black squares in each column in descending order.
    for (int j = 0; j < N; ++j) {
        vector<int> blackValues;
        vector<int> blackRows;
        for (int i = 0; i < M; ++i) {
            if ((i + j) % 2 != 0) {  //black square
                blackValues.push_back(matrix[i][j]);
                blackRows.push_back(i);
            }
        }
        sort(blackValues.begin(), blackValues.end(), greater<int>());
        sort(blackRows.begin(), blackRows.end());
        for (size_t k = 0; k < blackValues.size(); ++k) {
            matrix[blackRows[k]][j] = blackValues[k];
        }
    }

    return matrix;
}

//Function to print matrix
void print_matrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << setw(4) << num << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    srand(time(0));  // Seed the random number generator

    int M, N;
    cout << "Enter the number of rows M: ";
    cin >> M;
    cout << "Enter the number of columns N: ";
    cin >> N;

    // Check if M or N is zero
    if (M <= 0 || N <= 0) {
        cout << "Error" << endl;
        return 1; // Exit the program with an error code
    }

    // Generate a random matrix
    vector<vector<int>> original = generate_random_matrix(M, N);
    cout << "\nOriginal matrix:\n";
    print_matrix(original);

    // Apply sorting algorithms to each row
    vector<vector<int>> bubble = original;
    for (auto& row : bubble) 
        bubble_sort(row);

    vector<vector<int>> selection = original;
    for (auto& row : selection) 
        selection_sort(row);

    vector<vector<int>> insertion = original;
    for (auto& row : insertion) 
        insertion_sort(row);

    vector<vector<int>> shell = original;
    for (auto& row : shell) 
        shell_sort(row);

    vector<vector<int>> quick = original;
    for (auto& row : quick) 
        quick_sort(row);

    // Print sorted matrices
    cout << "Sorted matrices:\n";
    cout << "Bubble Sort:\n";
    print_matrix(bubble);
    cout << "Selection Sort:\n";
    print_matrix(selection);
    cout << "Insertion Sort:\n";
    print_matrix(insertion);
    cout << "Shell Sort:\n";
    print_matrix(shell);
    cout << "Quick Sort:\n";
    print_matrix(quick);

    // Print efficiency comparison table
    cout << "Efficiency Comparison Table:\n";
    cout << left << setw(15) << "Method" 
         << setw(15) << "Comparisons" 
         << setw(15) << "Swaps" << endl;
    cout << string(45, '-') << endl;
    cout << setw(15) << "Bubble" 
         << setw(15) << bubble_counter.comparisons 
         << setw(15) << bubble_counter.swaps << endl;
    cout << setw(15) << "Selection" 
         << setw(15) << selection_counter.comparisons 
         << setw(15) << selection_counter.swaps << endl;
    cout << setw(15) << "Insertion" 
         << setw(15) << insertion_counter.comparisons 
         << setw(15) << insertion_counter.swaps << endl;
    cout << setw(15) << "Shell" 
         << setw(15) << shell_counter.comparisons 
         << setw(15) << shell_counter.swaps << endl;
    cout << setw(15) << "Quick" 
         << setw(15) << quick_counter.comparisons 
         << setw(15) << quick_counter.swaps << endl;

    // Apply chessboard sort and print result
    vector<vector<int>> chess = chessboard_sort(original);
    cout << "\nMatrix after chessboard sorting:\n";
    print_matrix(chess);

    return 0;
}
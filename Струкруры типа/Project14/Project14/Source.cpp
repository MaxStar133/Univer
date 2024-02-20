#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

void checkArProg(int arr[], int n, ofstream& outFile) {
    if (n >= 3) {
        sort(arr, arr + n);

        int diff = arr[1] - arr[0];
        if (diff == 0) return;

        for (int i = 2; i < n; ++i) {
            if (arr[i] - arr[i - 1] != diff) {
                return;
            }
        }

        outFile << "Arithmetic progression found: ";
        for (int i = 0; i < n; ++i) {
            outFile << arr[i] << " ";
        }
        outFile << endl;
    }
}

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    if (!inFile.is_open()) {
        cout << "Unable to open input file";
        return 1;
    }

    const int N = 20;
    int n;
    inFile >> n;

    if (n < 3 || n > 20) {
        cout << "Error: n should be between 3 and 20";
        return 1;
    }

    int arr[N];

    for (int i = 0; i < n; i++) {
        inFile >> arr[i];
        if (arr[i] <= 0) {
            cout << "Error: numbers should be natural";
            return 1;
        }
    }

    for (int mask = 1; mask < (1 << n); ++mask) {
        int arr2[N];
        int size = 0;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                arr2[size++] = arr[i];
            }
        }

        checkArProg(arr2, size, outFile);
    }

    inFile.close();
    outFile.close();

    ifstream outFile1("output.txt");
    string line;

    if (outFile1.is_open()) {
        while (getline(outFile1, line)) {
            cout << line << endl;
        }
        outFile1.close();
    }
    else {
        cout << "Unable to open file";
    }

    return 0;
}
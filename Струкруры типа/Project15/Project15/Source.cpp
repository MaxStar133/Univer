/*#include <iostream>
using namespace std;

const int N1 = 1000; // Максимальное количество строк
const int N2 = 1000; // Максимальное количество столбцов

int main() {
    int n1, n2;
    cout << "Введите количество строк и столбцов массива: ";
    cin >> n1 >> n2;

    int matrix[N1][N2];

    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            cin >> matrix[i][j];
        }
    }

    int dp[N1][N2];

    // Инициализация первой строки массива dp
    dp[0][0] = matrix[0][0];
    for (int j = 1; j < n2; ++j) {
        dp[0][j] = matrix[0][j] + dp[0][j - 1];
    }

    // Заполнение массива dp
    for (int i = 1; i < n1; ++i) {
        dp[i][0] = matrix[i][0] + dp[i - 1][0];

        for (int j = 1; j < n2; ++j) {
            dp[i][j] = matrix[i][j] + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
        }
    }

    int result = dp[n1 - 1][n2 - 1];
    cout << "Минимальная сумма пути: " << result << endl;

    return 0;
}*/

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

const int MAX_SIZE = 20;

void setBlueTextAttribute() {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
}

int main() {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN |
        FOREGROUND_BLUE);
    setlocale(LC_ALL, "rus");

    ifstream f("input.txt");
    int N1, N2;
    f >> N1 >> N2;

    int Floor[MAX_SIZE][MAX_SIZE], BestFloor[2][MAX_SIZE], BestDir[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < 2; i++) {
        fill(begin(BestFloor[i]), end(BestFloor[i]), 0);
    }

    for (int i = 0; i < N1; i++) {
        fill(begin(BestDir[i]), end(BestDir[i]), 0);
    }

    for (int i = 0; i < N1; i++) {
        for (int j = 0; j < N2; j++) {
            f >> Floor[i][j];
            BestFloor[1][j] = BestFloor[0][j];
            BestFloor[0][j] += Floor[i][j];
        }

        for (int j = 1; j < N2; j++) {
            if (BestFloor[1][j - 1] + Floor[i][j] < BestFloor[0][j]) {
                BestFloor[0][j] = BestFloor[1][j - 1] + Floor[i][j];
                BestDir[i][j] = -2;
            }
        }

        for (int j = 1; j < N2; j++) {
            if (BestFloor[0][j - 1] + Floor[i][j] < BestFloor[0][j]) {
                BestFloor[0][j] = BestFloor[0][j - 1] + Floor[i][j];
                BestDir[i][j] = -1;
            }
        }

        for (int j = N2 - 2; j >= 0; j--) {
            if (BestFloor[1][j + 1] + Floor[i][j] < BestFloor[0][j]) {
                BestFloor[0][j] = BestFloor[1][j + 1] + Floor[i][j];
                BestDir[i][j] = 2;
            }
        }

        for (int j = N2 - 2; j >= 0; j--) {
            if (BestFloor[0][j + 1] + Floor[i][j] < BestFloor[0][j]) {
                BestFloor[0][j] = BestFloor[0][j + 1] + Floor[i][j];
                BestDir[i][j] = 1;
            }
        }
    }
    f.close();

    int j1 = 0;
    for (int j = 1; j < N2; j++) {
        if (BestFloor[0][j] < BestFloor[0][j1]) j1 = j;
    }

    int Dir[MAX_SIZE][MAX_SIZE]{ 0 }, n1 = N1 - 1, n2 = j1;
    for (int i = n1; i >= 0; i--) {
        for (int j = N2 - 1; j >= 0; j--) {
            if (i == n1 && j == n2) {
                if (BestDir[i][j] == 0) {
                    n1--;
                    Dir[i][j] = 1;
                }
                else if (BestDir[i][j] == 1) {
                    n2++;
                    Dir[i][j] = 1;
                    i++;
                }
                else if (BestDir[i][j] == -1) {
                    n2--;
                    Dir[i][j] = 1;
                    i++;
                }
                else if (BestDir[i][j] == 2) {
                    n2++;
                    n1--;
                    Dir[i][j] = 1;
                }
                else if (BestDir[i][j] == -2) {
                    n2--;
                    n1--;
                    Dir[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < N1; i++) {
        for (int j = 0; j < N2; j++) {
            setBlueTextAttribute();
            if (Dir[i][j] == 1) SetConsoleTextAttribute(handle, FOREGROUND_RED);
            cout.width(2);
            cout << Floor[i][j] << " ";
        }
        cout << endl;
    }

    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN |
        FOREGROUND_BLUE);
    cout << "Минимум равен " << BestFloor[0][j1] << endl;

    system("pause");
    return 0;
}
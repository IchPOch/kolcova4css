#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void printResult(vector<double> result) {
    for (double digit : result) {
        cout << digit << " ";
    }
    cout << endl;
}

vector<double> doMagic(double h) {
    double ax = 0;
    double bx = 1;
    double eps = 0.00001;
    int N = int(((bx - ax) / h)) + 1;
    vector<double> result(N);
    vector<double> result2(N);
    for (int i = 0; i < N; i++) {
        result[i] = 4 * pow(i * h, 3) - 9 * pow(i * h, 2) - 4 * i * h;
    }
    while (true) {
        double condition = 0;
        for (int i = 1; i < N - 1; i++) {
            result2[i] = (result[i + 1] + (1 + h) * result[i - 1] + 12 * pow(i, 2) * pow(h, 4) - 24 * pow(i, 1) * pow(h, 3) ) / (h + 2);
            condition += pow(result2[i] - result[i], 2);
            result[i] = result2[i];
        }
        result2[0] = 1;
        result2[N - 1] = 6.7;
        condition += pow(result2[0] - result[0], 2);
        condition += pow(result2[N - 1] - result[N - 1], 2);
        condition *= h;
        condition = sqrt(condition);
        result[0] = result2[0];
        result[N - 1] = result2[N - 1];
        if (condition < eps) {
            break;
        }
    }
    cout << "Результаты для h = " << h << endl;
    return result2;
}

void checkResults(vector<double> result, double h) {
    for (int i = 0; i < 11; i++) {
        cout << " " << result[int((0.1 / h) * i)] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<double> h = { 0.1, 0.01 };
    for (double delta : h) {
        checkResults(doMagic(delta), delta);
    }
    cout << "\nСравним результаты вычислений в точках: x={ 0; 0,1; 0,2; 0,3; 0,4; 0,5; 0,6; 0,7; 0,8; 0,9; 1}" << endl;
    return 0;
}
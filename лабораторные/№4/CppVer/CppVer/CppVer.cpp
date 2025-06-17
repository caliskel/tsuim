#include <iostream>
#include <math.h>
#include <chrono>

using namespace std;

int main() {
    float x;
    int n;

    cout << "Input x: ";
    cin >> x;
    cout << "Input n: ";
    cin >> n;

    auto start = std::chrono::high_resolution_clock::now();

    float sum = 0.0f;
    for (int j = 0; j < 100000; j++) {
        sum = 0.0f;
        for (int k = 0; k <= n; k++) {
            float a_k;
            if (k == 0) {
                a_k = 1.0f / sin(x);  // упрощение для k=0
            }
            else {
                a_k = pow(x, -1.0f / k) / sin(x);
            }
            sum += fabs(a_k);
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    cout << "Sum z = " << sum << endl;
    cout << "Execution Time: " << duration.count() << " seconds" << endl;

    cout << "Press Enter to exit...";
    cin.ignore();
    cin.get();

    return 0;
}
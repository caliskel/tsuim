#include <iostream>
#include <chrono>

using namespace std;

extern "C" float compute_sum(float x, int n);

int main(int argc, char** argv) {
    float x;
    int n;

    cout << "Input x: ";
    cin >> x;
    cout << "Input n: ";
    cin >> n;

    auto start = std::chrono::high_resolution_clock::now();

    float result;
    for (int j = 0; j < 100000; j++) {
        result = compute_sum(x, n);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    cout << "Sum z = " << result << endl;
    cout << "Execution Time: " << duration.count() << " seconds" << endl;

    cout << "Press Enter to exit...";
    cin.ignore();
    cin.get();

    return 0;
}
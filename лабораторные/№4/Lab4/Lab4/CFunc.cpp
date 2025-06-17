#include <iostream>
#include <math.h>

using namespace std;

extern "C" float cfunc(float x, int k) {
    if (k == 0) {
        // ��� k=0 ������� x^(-1/k) �� ����������, ���������� x^(-inf) = 0 ��� x>1, inf ��� 0<x<1
        // �������� �� a_0 = 1/sin(x)
        return 1.0f / sin(x);
    }

    float power = pow(x, -1.0f / k);  // x^(-1/k)
    float a_k = power / sin(x);       // a_k = x^(-1/k) / sin(x)
    return a_k;
}
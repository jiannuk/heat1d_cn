#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "thomas.h"

int main() {
    double L = 1.0;
    double T = 0.5;
    double alpha = 0.01;
    int nx = 50;
    int nt = 100;

    double dx = L / (nx - 1);
    double dt = T / nt;
    double lam = alpha * dt / (dx * dx);

    std::vector<double> x(nx);
    for (int i = 0; i < nx; i++) x[i] = i * dx;

    std::vector<double> u(nx);
    for (int i = 0; i < nx; i++) u[i] = std::sin(M_PI * x[i]);
    u[0] = 0.0;
    u[nx-1] = 0.0;

    int n = nx - 2;
    std::vector<double> a(n, -lam/2);
    std::vector<double> b(n, 1.0 + lam);
    std::vector<double> c(n, -lam/2);
    std::vector<double> d(n);

    for (int t = 0; t < nt; t++) {
        for (int i = 0; i < n; i++) {
            d[i] = lam/2 * u[i] + (1.0 - lam) * u[i+1] + lam/2 * u[i+2];
        }
        std::vector<double> u_inner = Thomas(a, b, c, d);
        for (int i = 0; i < n; i++) {
            u[i+1] = u_inner[i];
        }
    }

    std::ofstream fout("heat1d_cn_result.txt");
    for (int i = 0; i < nx; i++) {
        fout << x[i] << " " << u[i] << "\n";
    }
    fout.close();

    std::cout << "结果已写入 heat1d_cn_result.txt" << std::endl;
    return 0;
}
#include "thomas.h"

std::vector<double> Thomas(
    const std::vector<double>& a,
    const std::vector<double>& b,
    const std::vector<double>& c,
    const std::vector<double>& d)
{
    int n = b.size();
    std::vector<double> cp(n);
    std::vector<double> dp(n);
    std::vector<double> x(n);

    cp[0] = c[0] / b[0];
    dp[0] = d[0] / b[0];

    for (int i = 1; i < n; i++) {
        double m = b[i] - a[i] * cp[i-1];
        cp[i] = c[i] / m;
        dp[i] = (d[i] - a[i] * dp[i-1]) / m;
    }

    x[n-1] = dp[n-1];
    for (int j = n-2; j >= 0; j--) {
        x[j] = dp[j] - cp[j] * x[j+1];
    }

    return x;
}
// file: var_cvar.cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    // Sample daily returns (decimal form; negative = loss)
    std::vector<double> returns = {0.002, -0.015, 0.010, -0.020, -0.005,0.012, -0.003, -0.030, 0.006, -0.025};

    // Sort ascending (worst losses first)
    std::sort(returns.begin(), returns.end());

    double confidence = 0.95;
    int cutoff = static_cast<int>((1.0 - confidence) * returns.size());

    double VaR = -returns[cutoff];  // positive loss
    double sum = 0.0;
    for (int i = 0; i < cutoff; ++i) sum += returns[i];
    double CVaR = -(sum / cutoff);

    std::cout << "95% VaR  = " << VaR * 100 << "%\n";
    std::cout << "95% CVaR = " << CVaR * 100 << "%\n";
    return 0;
}

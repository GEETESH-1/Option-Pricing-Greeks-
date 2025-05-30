// file: vasicek.cpp
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

int main() {
    // Model parameters
    double a     = 0.5;   // speed of mean reversion
    double b     = 0.03;  // long-term mean rate
    double sigma = 0.01;  // volatility
    double r0    = 0.05;  // initial rate

    int   steps = 100;        // number of time steps
    double T    = 1.0;        // total years
    double dt   = T / steps;  // time increment

    // Prepare RNG for standard normal draws
    std::mt19937_64 rng(42);
    std::normal_distribution<double> stdnorm(0.0, 1.0);

    // Simulate one path
    std::vector<double> rates(steps+1);
    rates[0] = r0;
    for (int t = 0; t < steps; ++t) {
        double dW = stdnorm(rng) * std::sqrt(dt);  
        rates[t+1] = rates[t] + a*(b - rates[t])*dt + sigma * dW;
    }

    // Output first few simulated rates
    std::cout << "Simulated Vasicek path:\n";
    for (int i = 0; i <= 5; ++i) {
        std::cout << "  t=" << i << ": " << rates[i] << "\n";
    }
    return 0;
}

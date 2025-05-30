// file: black_scholes.cpp
#include <cmath>
#include <iostream>

// Standard normal CDF via error function
double norm_cdf(double x) {
    return 0.5 * (1.0 + std::erf(x / std::sqrt(2.0)));
}

// Standard normal PDF
double norm_pdf(double x) {
    return (1.0 / std::sqrt(2.0 * M_PI)) * std::exp(-0.5 * x * x);
}

// Black–Scholes call price
double black_scholes_call(double S, double K, double T, double r, double sigma) {
    double d1 = (std::log(S/K) + (r + 0.5*sigma*sigma)*T) / (sigma*std::sqrt(T));
    double d2 = d1 - sigma*std::sqrt(T);
    return S * norm_cdf(d1) - K * std::exp(-r*T) * norm_cdf(d2);
}

// Greeks: Delta and Gamma
void black_scholes_greeks(double S, double K, double T, double r, double sigma,
                          double& delta, double& gamma) {
    double d1 = (std::log(S/K) + (r + 0.5*sigma*sigma)*T) / (sigma*std::sqrt(T));
    delta = norm_cdf(d1);
    gamma = norm_pdf(d1) / (S * sigma * std::sqrt(T));
}

int main() {
    double S = 100.0;     // stock price
    double K = 100.0;     // strike
    double T = 1.0;       // time to expire (years)
    double r = 0.05;      // risk-free rate
    double sigma = 0.20;  // volatility

    double price = black_scholes_call(S, K, T, r, sigma);
    double delta, gamma;
    black_scholes_greeks(S, K, T, r, sigma, delta, gamma);

    std::cout << "Call Price: " << price << "\n";
    std::cout << "Delta:      " << delta << "\n";
    std::cout << "Gamma:      " << gamma << "\n";
    return 0;
}

#include <iostream>
#include <cmath>
#include <iomanip>

struct IntegrationInfo {
    double to;
    double from;
    double dx;
    IntegrationInfo (double to, double from, double dx) : 

    to(to),
    from(from),
    dx(dx)
    {};
};

int main () {
    double sum = 0;
    auto f = [](double x) {
        return (x * x) / std::exp(x);
    };
    auto Integrate = [&](IntegrationInfo info) {
        for (double x = info.from; x < info.to; x += info.dx) {
            sum += f(x) * info.dx;
        }
    };
    auto OverIntegrate = [&](IntegrationInfo info) {
        for (double x = info.from; x < info.to; x += info.dx) {
            sum += f(x + info.dx) * info.dx;
        }
    };

    IntegrationInfo info(1, 0, 0.000001);
    Integrate(info);
    OverIntegrate(info); 
    sum /= 2;
    std::cout << std::setprecision(15) << sum << std::endl;
}
/*
    integral_0^1 x^2/e^x dx = 2 - 5/e
    wolfram_alpha : 0.160602794142788
    nazo_integral : 0.160602794142594
    diff          : -1.94455562763096e-13
*/


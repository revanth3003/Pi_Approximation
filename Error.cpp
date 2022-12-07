#include <iostream>
#include <math.h>

using namespace std;

// function to calculate f(x) for given x
double calcF(double x) {
    return sqrt(1 - x*x);
}

// Returning multiple values using structures
struct PiResults{
     float approx;
     float error;
};

// structure function

PiResults pi_approx(int N){
    
    // initializing the limits
    double a = 0;
    double b = 1;
    
    // partition the interval [a,b]
    double x[N];
    for (int i = 0; i < N; i++) {
        x[i] = a + (b - a) / N * i;
    }
    
    // initializing with 0
    long double approx = 0;
    long double error = 0;
    
    // calculation of given integral
    for (int i=1; i < N; i++) {
        approx += (x[i] - x[i-1]) * ((calcF(x[i]) + calcF(x[i-1])) / 2);
    }

    PiResults result;
    result.approx = approx*4; // multiply by 4 to get Pi
    result.error = abs(approx*4 - M_PI); // Error calculation
    return result;
}

// Main function
int main() {
    // Asking for number of intervals N
    int N;
    cout << "Enter the number of intervals (N): ";
    cin >> N;
    PiResults result = pi_approx(N);
    cout << "Approximated Pi: " << result.approx << endl;
    cout << "Error: " << result.error << endl;
}

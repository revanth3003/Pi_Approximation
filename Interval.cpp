#include <iostream>
#include <math.h>

using namespace std;

// function to calculate f(x) for given x
double calcF(double x) {
    return sqrt(1 - x*x);
}

// Returning multiple values using structures
struct Pi2Results{
    float error;
    int N;
};

// function to calculate error
double pi_approx2(int N){
    
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
    error = abs(approx*4 - M_PI);
    return error;
}

// structure function
Pi2Results getInterval(float Maxerror) {
    int N1 = 0, N2 = 1000000; // initializing with Minimum annd Maximum N
    while (N1+1!=N2){
        int mid = (N1+N2)/2;
        double error = pi_approx2(mid);
        
        if (error > Maxerror){     // checking for side
            N1 = mid;
        }
        if (error < Maxerror) {   // checking for side
            N2 = mid;
        }
    }
    // Returning Results (Error and Number of Intervals)
    Pi2Results result;
    result.error = pi_approx2(N2);
    result.N = N2;
    return result;
}

// Main function
int main() {
    // Asking for maximum acceptable error
    float Maxerror;
    cout << "Enter your maximum acceptable error: ";
    cin >> Maxerror;
    Pi2Results result = getInterval(Maxerror);
    cout << "Error: " << result.error << endl;
    cout << "Number of interval: " << result.N << endl;

}



/*
#include <iostream>
using namespace std;

int main() {

  int first_number, second_number, sum;
    
  cout << "Enter two integers:";
  cin >> first_number >> second_number;

  // sum of two numbers in stored in variable sumOfTwoNumbers
  sum = first_number + second_number;

  // prints sum 
  cout << first_number << " + " <<  second_number << " = " << sum;     

  return 0;
}*/

#include <iostream>
#include <cmath>
#include <limits>

// Define a function pointer type for the function whose root we want to find
typedef double (*Function)(double);

// Bisection method implementation
double bisection(Function f, double a, double b, double tol, int maxIter) {
    if (f(a) * f(b) >= 0) {
        std::cerr << "Function has the same signs at a and b. No root found in this interval.\n";
        return ;
        //std::numeric_limits<double>::quiet_NaN();
    }

    double c = a;
    int iter = 0;

    while ((b - a) / 2 > tol && iter < maxIter) {
        c = (a + b) / 2;
        if (f(c) == 0.0) {
            return c; // Found exact root
        } else if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
        iter++;
    }

    return c; // Return the midpoint as the root approximation
}

// Example function: f(x) = x^2 - 4
double exampleFunction(double x) {
    return x * x - 4;
}

int main() {
    double a, b, tol;
    int maxIter;

    // Input function bounds, tolerance, and maximum iterations
    std::cout << "Enter the lower bound (a): ";
    std::cin >> a;
    std::cout << "Enter the upper bound (b): ";
    std::cin >> b;
    std::cout << "Enter tolerance: ";
    std::cin >> tol;
    std::cout << "Enter maximum iterations: ";
    std::cin >> maxIter;

    // Call the bisection method
    double root = bisection(exampleFunction, a, b, tol, maxIter);

    if (!std::isnan(root)) {
        std::cout << "Root found: " << root << std::endl;
    } else {
        std::cout << "No root found or invalid interval.\n";
    }

    return 0;
}


#include <iostream>
#include <iomanip>
using namespace std;

/*
Function: getCelsius
Purpose: Converts a Fahrenheit temperature to Celsius
Parameters:
- fahrenheit: The temperature in Fahrenheit to convert
Returns: The Celsius equivalent of the given Fahrenheit temperature
Preconditions: None
Postconditions: Returns the Celsius equivalent of the given Fahrenheit temperature
 */
double getCelsius(double fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}


int main() {
    
    //Initialize the range of Fahrenheit temperatures to convert.
    const int minFahrenheit = 0;
    const int maxFahrenheit = 20;
    
    //Create a header for the table.
    cout << "Temperature Conversion Table" << endl;
    cout << "----------------------------" << endl << endl;

    // Write the column labels.
    cout << setw(12) << "Fahrenheit" << setw(12) << "Celsius" << endl;
    cout << setw(12) << "----------" << setw(12) << "-------" << endl;

    //For Fahrenheit temperatures between minFahrenheit and maxFahrenheit, get the Celsius equivalent temperature.
    for (int fahrenheit = minFahrenheit; fahrenheit <= maxFahrenheit; fahrenheit++) {
        double celsius = getCelsius(fahrenheit);

        // Write the Fahrenheit and Celsius temperatures into the table, with the temperature values right aligned and truncated to one decimal place.
        cout << setw(12) << fixed << setprecision(1) << static_cast<double>(fahrenheit)
             << setw(12) << fixed << setprecision(1) << celsius << endl;
    }

    return 0;
}
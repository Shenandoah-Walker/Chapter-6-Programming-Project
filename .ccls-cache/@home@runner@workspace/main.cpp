//Paint Job Estimator Program


#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/* 
Function: getRooms
Purpose: To get the number of rooms to be painted from the user.
Parameters: None
Returns: The number of rooms to be painted.
Preconditions: None
Postconditions: The number of rooms must be at least 1.
*/
int getRooms();

/*
Function: getSqFt
Purpose: To get the square footage of wall space for a room from the user.
Parameters: None
Returns: The square footage of wall space for a room.
Preconditions: None
Postconditions: The square footage must be at least 0.
*/
double getSqFt();

/*
Function: getPricePerGallon
Purpose: To get the price per gallon of paint from the user.
Parameters: None
Returns: The price per gallon of paint.
Preconditions: None
Postconditions: The price per gallon must be at least $10.00.
*/
double getPricePerGallon();

/*
Function: gallonsForRoom
Purpose: To calculate the gallons of paint needed for a room.
Parameters:
-squareFeet: The square footage of wall space for a room.
Returns: The number of gallons needed (rounded up to the next integer).
Preconditions: squareFeet >= 0
Postconditions: None
*/
int gallonsForRoom(double squareFeet);

/*
Function: calculateLaborHours
Purpose: To calculate the labor hours needed for a room.
Parameters:
-squareFeet: The square footage of wall space for a room.
Returns: The number of labor hours needed.
Preconditions: squareFeet >= 0
Postconditions: None
*/
double calculateLaborHours(double squareFeet);

/*
Function: calculateLaborCost
Purpose: To calculate the labor cost based on hours.
Parameters:
-laborHours: The number of labor hours needed.
Returns: The total labor cost.
Preconditions: laborHours >= 0
Postconditions: None
*/
double calculateLaborCost(double laborHours);

/*
Function: displayEstimate
Purpose: To display the complete painting estimate.
Parameters:
-paintCharge: The total cost of paint.
-gallonsNeeded: The total gallons of paint needed.
-laborCharge: The total labor cost.
-laborHours: The total labor hours needed.
-numRooms: The number of rooms to be painted.
Returns: None
Preconditions: All parameters are valid calculated values.
Postconditions: Prints formatted estimate to console.
*/
void displayEstimate(double paintCharge, int gallonsNeeded, double laborCharge, double laborHours, int numRooms);


int main() {
    //Initialize variables
    double paintCharge = 0, laborCharge = 0, laborHours = 0;
    int gallonsNeeded = 0;

    //Create a header for the program
    cout << "Paint Job Estimator\n";
    cout << "--------------------\n\n";

    int numRooms = getRooms();

    //Loop through each room and calculate the necessary values
    for (int i = 1; i <= numRooms; i++) {
        cout << "\nRoom " << i << ":\n";

        double squareFeet = getSqFt();
        int gallons = gallonsForRoom(squareFeet);
        gallonsNeeded += gallons;

        double paintPrice = getPricePerGallon();
        paintCharge += gallons * paintPrice;

        double labor = calculateLaborHours(squareFeet);
        laborHours += labor;
        laborCharge += calculateLaborCost(labor);
    }
    //Display the final estimate
    displayEstimate(paintCharge, gallonsNeeded, laborCharge, laborHours, numRooms);

    return 0;
}

//Function definitions
int getRooms() {
    int rooms;

    do {
        cout << "Enter the number of rooms to be painted: ";
        cin >> rooms;

        if (rooms < 1) {
            cout << "Error: Number of rooms must be at least 1.\n";
        }
    } while (rooms < 1);

    return rooms;
}


double getSqFt() {
    double sqFt;

    do {
        cout << "Enter the square feet of wall space: ";
        cin >> sqFt;

        if (sqFt < 0) {
            cout << "Error: Square footage cannot be negative.\n";
        }
    } while (sqFt < 0);

    return sqFt;
}


double getPricePerGallon() {
    double price;

    do {
        cout << "Enter the price of paint per gallon: $";
        cin >> price;

        if (price < 10.00) {
            cout << "Error: Paint price must be at least $10.00.\n";
        }
    } while (price < 10.00);

    return price;
}


int gallonsForRoom(double squareFeet) {
    const double gallonsPerSqFt = 1.0 / 110.0;
    double gallons = squareFeet * gallonsPerSqFt;
    return static_cast<int>(ceil(gallons));
}


double calculateLaborHours(double squareFeet) {
    const double laborPerSqFt = 8.0 / 110.0;
    return squareFeet * laborPerSqFt;
}


double calculateLaborCost(double laborHours) {
    const double laborChargePerHour = 25.00;
    return laborHours * laborChargePerHour;
}


void displayEstimate(double paintCharge, int gallonsNeeded, double laborCharge, double laborHours, int numRooms) {
    double totalCost = paintCharge + laborCharge;

    //Print the output to the console with proper formatting
    cout << fixed << setprecision(2);
    cout << "\nEstimate for painting " << numRooms << " rooms:\n";
    cout << "Gallons of paint to purchase: " << gallonsNeeded << "\n";
    cout << "Number of hours required to paint rooms: " << laborHours << "\n";
    cout << "Cost of paint: $" << paintCharge << "\n";
    cout << "Cost of labor: $" << laborCharge << "\n";
    cout << "Total cost for job: $" << totalCost << "\n";
}


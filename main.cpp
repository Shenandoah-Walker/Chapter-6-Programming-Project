#include <iostream>
using namespace std;

// Function prototypes
void getLength_Width(double& length, double& width);
double calcPerimeter(double length, double width);
double calcArea(double length, double width);
void displayProperties(double perimeter, double area);

/*
Function: getLength_Width
Purpose: To get the length and width of a rectangle from the user and validate the input (ensure that the length and width are greater than 0).
Parameters:
 -length: a reference to a double variable that will store the length of the rectangle.
 -width: a reference to a double variable that will store the width of the rectangle.
Returns: None
Preconditions: None
Postconditions: The length and width variables will contain positive values entered by the user.
 */
void getLength_Width(double& length, double& width) {
    do {
        cout << "Enter the length of the rectangle: ";
        cin >> length;
        if (length <= 0) {
            cout << "Length must be greater than 0. Please try again." << endl;
        }
    } while (length <= 0);

    do {
        cout << "Enter the width of the rectangle: ";
        cin >> width;
        if (width <= 0) {
            cout << "Width must be greater than 0. Please try again." << endl;
        }
    } while (width <= 0);
}

/*
Function: calcPerimeter
Purpose: To calculate the perimeter of a rectangle given its length and width.
Parameters:
 -length: a double variable that stores the length of the rectangle.
 -width: a double variable that stores the width of the rectangle.
Returns: a double value that represents the perimeter of the rectangle.
Preconditions: The length and width variables must contain positive values.
Postconditions: None
 */

double calcPerimeter(double length, double width) {
    return 2 * length + 2 * width;
}

/*
Function: calcArea
Purpose: To calculate the area of a rectangle given its length and width.
Parameters:
 -length: a double variable that stores the length of the rectangle.
 -width: a double variable that stores the width of the rectangle.
Returns: a double value that represents the area of the rectangle.
Preconditions: The length and width variables must contain positive values.
Postconditions: None
 */

double calcArea(double length, double width) {
    return length * width;
}

/*
Function: displayProperties
Purpose: To display the perimeter and area of a rectangle.
Parameters:
 -perimeter: a double variable that stores the perimeter of the rectangle.
 -area: a double variable that stores the area of the rectangle.
Returns: None
Preconditions: The perimeter and area variables must contain positive values.
Postconditions: None
 */

    void displayProperties(double perimeter, double area) {
    cout << "\nRectangle Properties:" << endl;
    cout << "Perimeter: " << perimeter << endl;
    cout << "Area: " << area << endl << endl;
}


int main() {
    double length, width, perimeter, area;
    char continueChoice;

    cout << "Rectangle Properties Calculator" << endl;
    cout << "===============================" << endl << endl;

    do {
        //Get validated input from user.
        getLength_Width(length, width);

        //Calculate perimeter and area.
        perimeter = calcPerimeter(length, width);
        area = calcArea(length, width);

        //Display the results.
        displayProperties(perimeter, area);

        //Ask if user wants to continue.
        cout << "Do you want to process another rectangle? (y/n): ";
        cin >> continueChoice;
        cout << endl;

    } while (continueChoice == 'y' || continueChoice == 'Y');

    cout << "End of program." << endl;

    return 0;
}

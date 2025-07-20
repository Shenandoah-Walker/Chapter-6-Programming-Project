//Safest Driving Area Program


#include <iostream>
#include <string>
using namespace std;


/*
Function: getRegInfo
Purpose: This function gets the name of the region and the number of accidents.
Parameters:
 - regionName: a reference to a string variable to store the region name.
 - accidents: a reference to an integer variable to store the number of accidents.
Returns: None.
Preconditions: regionName is a valid string, accidents is a non-negative integer.
Postconditions: regionName and accidents are updated with the input values.
 */

void getRegInfo(string& regionName, int& accidents);

/*
Function: isLower
Purpose: This function checks if the first value is less than or equal to the second value.
Parameters:
 - value1: an integer value to compare.
 - value2: an integer value to compare.
Returns: true if value1 is less than or equal to value2, false otherwise.
Preconditions: value1 and value2 are non-negative integers.
Postconditions: returns true if value1 is less than or equal to value2, false otherwise.
 */
bool isLower(int value1, int value2);

/*
Function: showLowest
Purpose: This function displays the safest driving area results.
Parameters:
 - regionName: a string variable containing the name of the safest region.
 - accidents: an integer variable containing the number of accidents in the safest region.
Returns: None.
Preconditions: regionName is a valid string, accidents is a non-negative integer.
Postconditions: displays the safest driving area results.
 */
void showLowest(string regionName, int accidents);

int main() {
    string regionName, lowestRegion;
    int accidents, lowestAccidents;

    cout << "Safest Driving Area Analysis" << endl;
    cout << endl << endl;
    cout << "Enter accident data for 5 regions:" << endl << endl;

    // Ask the user for the accident data for the first region
    cout << "Region 1:" << endl;
    getRegInfo(regionName, accidents);
    lowestRegion = regionName;
    lowestAccidents = accidents;

    // Process the remaining 4 regions.
    for (int i = 2; i <= 5; i++) {
        cout << "\nRegion " << i << ":" << endl;
        getRegInfo(regionName, accidents);

        // Check if this region has fewer accidents.
        if (isLower(accidents, lowestAccidents)) {
            lowestRegion = regionName;
            lowestAccidents = accidents;
        }
    }

    // Display the results.
    cout << "\n" << endl;
    showLowest(lowestRegion, lowestAccidents);

    return 0;
}

void getRegInfo(string& regionName, int& accidents) {
    // Get region name.
    cout << "Enter the region name: ";
    getline(cin, regionName);

    // Get and validate number of accidents.
    do {
        cout << "Enter the number of accidents for " << regionName << ": ";
        cin >> accidents;

        if (accidents < 0) {
            cout << "Error: Number of accidents cannot be negative. Please try again." << endl;
        }
    } while (accidents < 0);

    // Clear the input buffer for next getline call.
    cin.ignore();
}
//Check if the first value is less than or equal to the second value.
bool isLower(int value1, int value2) {
    return value1 <= value2;
}
//Display the safest driving area results.
void showLowest(string regionName, int accidents) {
    cout << "Safest Driving Area Results:" << endl << endl;
    cout << "Region: " << regionName << endl;
    cout << "Number of accidents: " << accidents << endl;
    cout << "\n" << regionName << " is the safest driving area, with " 
         << accidents << " reported accidents." << endl;
}

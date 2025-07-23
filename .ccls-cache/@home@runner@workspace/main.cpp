//Star Search Program

#include <iostream>
#include <iomanip>
using namespace std;

/*
Function: getScore
Purpose: Gets and validates a score from the user
Parameters: None (gets input from user via keyboard)
Returns: A valid score between 0.0 and 10.0 (inclusive)
Preconditions: None
Postconditions: Returns a valid score between 0.0 and 10.0 (inclusive)
*/
double getScore();

/*
Function: isLower
Purpose: This function takes two double values as input, it returns true if the first value is <= the second value, and it returns false for any other case.
Parameters: 
- value1: first value to compare
- value2: second value to compare
Returns: true if value1 <= value2, false otherwise
Preconditions: Both values should be valid double numbers
Postconditions: Returns true if value1 <= value2, false otherwise
*/
bool isLower(double value1, double value2);

/*
Function: isHigher
Purpose: This function takes two double values as input, it returns true if the first value is >= the second value, and it returns false for any other case.
Parameters:
- value1: first value to compare
- value2: second value to compare
Returns: true if value1 >= value2, false otherwise
Preconditions: Both values should be valid double numbers
Postconditions: Returns true if value1 >= value2, false otherwise
*/
bool isHigher(double value1, double value2);

/*
Function: calcAverage
Purpose: This function takes as input the total of all the scores, the minimum score value and the maximum score value. It returns the average of the three middle scores by subtracting out the minimum and maximum scores from the total.
Parameters:
- total: sum of all five scores
- minScore: the lowest score (to be dropped)
- maxScore: the highest score (to be dropped)
Returns: The average of the three remaining scores after dropping the highest and lowest scores
Preconditions: total should be the sum of exactly 5 scores, minScore and maxScore should be valid scores that were part of the total
Postconditions: Returns the average of the three remaining scores after dropping the highest and lowest scores
*/
double calcAverage(double total, double minScore, double maxScore);


int main() {
    cout << "Star Search Talent Competition Score Calculator" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Enter scores from 5 judges (scores may range from 0.0 to 10.0, inclusive):" << endl;

    double total = 0.0;
    double minScore, maxScore;

    //Get first judge's score
    cout << "Judge 1: ";
    double score = getScore();
    total += score;
    minScore = score;
    maxScore = score;

    //Get remaining four judges' scores
    for (int i = 2; i <= 5; i++) {
        cout << "Judge " << i << ": ";
        score = getScore();
        total += score;

        if (isLower(score, minScore)) {
            minScore = score;
        }
        if (isHigher(score, maxScore)) {
            maxScore = score;
        }
    }

    //Calculate and display the average
    double average = calcAverage(total, minScore, maxScore);

    cout << "The contestant's final score is: " << fixed << setprecision(1) << average << endl;

    return 0;
}

//Use getScore to get a valid score from the user
double getScore() {
    double score;

    do {
        cin >> score;
        if (score < 0.0 || score > 10.0) {
            cout << "Invalid score! Please enter a score between 0.0 and 10.0: ";
        }
    } while (score < 0.0 || score > 10.0);

    return score;
}

//Use isLower to check if value1 is <= value2
bool isLower(double value1, double value2) {
    return value1 <= value2;
}

//Use isHigher to check if value1 is >= value2
bool isHigher(double value1, double value2) {
    return value1 >= value2;
}

//Use calcAverage to calculate the average of the three middle scores
double calcAverage(double total, double minScore, double maxScore) {
    double adjustedTotal = total - minScore - maxScore;
    return adjustedTotal / 3.0;

return 0;
}
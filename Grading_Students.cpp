#include <iostream>
#include <vector>
using namespace std;

vector<int> gradingStudents(vector<int> grades) {
    vector<int> finalGrades;
    for (int grade : grades) {
        if (grade < 38) {
            // No rounding for failing grades
            finalGrades.push_back(grade);
        } else {
            int nextMultipleOf5 = ((grade / 5) + 1) * 5;
            if (nextMultipleOf5 - grade < 3) {
                // Round up
                finalGrades.push_back(nextMultipleOf5);
            } else {
                // No rounding needed
                finalGrades.push_back(grade);
            }
        }
    }
    return finalGrades;
}

int main() {
    int n;
    cin >> n;
    vector<int> grades(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> grades[i];
    }

    vector<int> result = gradingStudents(grades);

    for (int grade : result) {
        cout << grade << endl;
    }

    return 0;
}

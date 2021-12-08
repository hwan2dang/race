#include <iostream>
#include "race.hpp"

using namespace std;

int main() {
    Race myRace;
    string inputString = "";
    while(inputString != "done") {
        cout << "Type a race: ";
        cin >> inputString;
        if(!myRace.isValidInput(inputString)) {
            cout << "Input is not valid" << endl;
        } else {
            myRace.run(inputString);
        }
    }

    return 0;
}
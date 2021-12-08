#ifndef race_hpp
#define race_hpp

#include <iostream>
#include <vector>

class Race {
public:
    void run(std::string inputString);
    bool isValidInput(std::string inputString);

private:
    bool containsOnlyUpperCase(std::string inputString);
    bool sameNumberOfTeamMember(std::string inputString);

    std::vector<char> isWinner(std::string inputString);
    std::vector<double> isWinnerScore(std::string inputString);
    std::vector<double> isScore(std::string inputString);
    std::vector<char> isSort(std::string inputString);
    std::vector<char> isUnique(std::vector<char> sort);
    std::vector<char> isInputString(std::string inputString);
    std::vector<double> isInputScore(std::string inputString);

    //member value. properties. attributes
    std::vector<char> uniqueVector;
    std::vector<double> scoreVector;
    std::vector<char> winner;
    std::vector<double> winnerScore;
    std::vector<char> inputScore;
};

#include "race.cpp"
#endif
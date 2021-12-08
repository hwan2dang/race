#include "race.hpp"

void Race::run(std::string inputString) {
    uniqueVector = isUnique(isSort(inputString));
    scoreVector = isScore(inputString);
    winner = isWinner(inputString);
    winnerScore = isWinnerScore(inputString);

    std::cout << "Team Score" << std::endl;
    std::cout << "---- -----" << std::endl;
    for(int i = 0; i < uniqueVector.size(); i++) {
        std::cout << uniqueVector[i] << "      " << scoreVector[i] << std::endl;
    }

    std::cout << "The winning Team is " << winner[0] << " wiht a score of " << winnerScore[0] << std::endl;
}

bool Race::isValidInput(std::string inputString) { //check only capital && sameTeam
    if( containsOnlyUpperCase(inputString)
        && sameNumberOfTeamMember(inputString) ) {
            return true;//check number, check special...
    }
    return false;
}

bool Race::containsOnlyUpperCase(std::string inputString) {
    //Goal: Check if there are only capital
    bool result = true;
    for(int i = 0; i < inputString.size(); i++) {
        if(!(inputString[i] >='A' && inputString[i] <= 'Z')) {
            return false;
        }
    }
    return result;
}

bool Race::sameNumberOfTeamMember(std::string inputString) { //AABBD
    int sumOfinputString = 0;
    int sumOfuniqueString = 0;
    int numberOfStandardChar = 0;
    int result = 0;
    uniqueVector = isUnique(isSort(inputString));

    //inputString 의 총합
    for(int i = 0; i < inputString.length(); i++) { //AABB
        if(inputString[0] == inputString[i]) {
            numberOfStandardChar++;
        }
        sumOfinputString += inputString[i];
    }
    //uniqueString 의 총합
    for(int i = 0; i < uniqueVector.size(); i++) {
        sumOfuniqueString += uniqueVector[i];
    }

    result = sumOfuniqueString * numberOfStandardChar;

    if((sumOfinputString == result)
        && (inputString.size() > 1)
        && isUnique(isSort(inputString)).size() != 1 ) {
        return true;
    }
    return false;
}

std::vector<char> Race::isWinner(std::string inputString) {
    std::vector<char> winner;

    for(int i = 0; i < scoreVector.size(); i++) {
        if(scoreVector[i] < scoreVector[1 - i]) {
            winner.push_back(uniqueVector[i]);
        }
    }
    return winner;
}

std::vector<double> Race::isWinnerScore(std::string inputString) {
    std::vector<double> winnerScore;

    for(int i = 0; i < scoreVector.size(); i++) {
        if(scoreVector[i] < scoreVector[1 - i]) {
            winnerScore.push_back(scoreVector[i]);
        }
    }
    return winnerScore;
}

std::vector<double> Race::isScore(std::string inputString) {
    std::vector<double> inputScore = isInputScore(inputString);
    std::vector<double> score;

    double numberOfStandardChar = 0.0;
    for(int i = 0; i < inputString.size(); i++) {
        if(inputString[0] == inputString[i]) {
            numberOfStandardChar++;
        }
    }

    double sum = 0.0;
    for(int i = 0; i < uniqueVector.size(); i++) {
        for(int j = 0; j < inputString.size(); j++) {
            if(uniqueVector[i] == inputString[j]) {
                sum += inputScore[j];
            }
        }
        score.push_back(sum / numberOfStandardChar);
        sum = 0.0;
    }
    return score;
}

std::vector<char> Race::isUnique(std::vector<char> sort) {
    std::vector<char> unique;

    unique.push_back(sort[0]);
    for(int i = 1; i < sort.size(); i++) {
        if(sort[i - 1] != sort[i]) {
            unique.push_back(sort[i]);
        }
    }
    return unique;
}

// //----------------------------------------------------------
std::vector<char> Race::isSort(std::string inputString) {
    std::vector<char> sort;
    for(int i = 0; i < inputString.size(); i++) {
        sort.push_back(inputString[i]);
    }

    int temp = 0;
    for(int i = 0; i < sort.size(); i++) {
        for(int j = 0; j < sort.size(); j++) {
            if(sort[j] > sort[i]) {
                temp = sort[i];
                sort[i] = sort[j];
                sort[j] = temp;
            }
        }
    }
    return sort;
}

std::vector<char> Race::isInputString(std::string inputString) {
    std::vector<char> inputStrings;
    for(int i = 0; i < inputString.size(); i++) {
        inputStrings.push_back(inputString[i]);
    }
    return inputStrings;
}

std::vector<double> Race::isInputScore(std::string inputString) {
    std::vector<double> inputScore;
    for(int i = 0; i < inputString.size(); i++) {
        inputScore.push_back(i + 1);
    }
    return inputScore;
}

//
// Created by Allen Lam on 5/8/22.
//

#ifndef SFML_TEST_SCORE_H
#define SFML_TEST_SCORE_H
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
class Score {
private:
    std::string answer;
    std::vector<std::string> shareScore;
    bool solve = false;
public:
    void setAnswer(std::string word);
    std::string attemptResult(std::string word);
    bool isSolve() const;
    std::string getAnswer() const;
    void scoreFile(std::string title);
};


#endif //SFML_TEST_SCORE_H
#include "Wordle.h"
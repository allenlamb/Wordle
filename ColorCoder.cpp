//
// Created by Allen Lam on 3/25/22.
//

#include "ColorCoder.h"


std::vector<char> ColorCoder::ops = {'-', '=', '*', '/', '+'};
std::vector<std::string> ColorCoder::keywords = {"double", "float", "int", "char"};

std::vector<sf::Color> ColorCoder::colorCode(std::string word) {
    std::string keywordTemp;
    int colorState = SPACE;
    std::vector<sf::Color> value;
    for (int i=0; i<word.size();++i) {
        if (std::find(ops.begin(),ops.end(),word[i])!=ops.end()) {
            colorState = OPERATOR;
            value.push_back(sf::Color::Green);
            keywordTemp.clear();
        }
        else if (isdigit(word[i]) &&
                (colorState == SPACE || colorState == DIGIT
                || colorState == OPERATOR)) {

            colorState = DIGIT;
            value.push_back(sf::Color::Red);
            keywordTemp.clear();
        }
        else if (word[i] == ' ') {
            if (colorState == KEYWORD) {
                if (std::find(keywords.begin(),keywords.end(),keywordTemp)!=keywords.end()) {
                    for (int j = 1; j < keywordTemp.size()+1; ++j) {
                        value[i-j] = sf::Color::Blue;
                    }
                }
            }
            colorState = SPACE;
            value.push_back(sf::Color::Transparent);
            keywordTemp.clear();
        }
        else {
                value.push_back(sf::Color::White);
                keywordTemp.push_back(word[i]);
                colorState = KEYWORD;
            }
        }
    return value;
}


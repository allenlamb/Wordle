//
// Created by Allen Lam on 3/25/22.
//

#ifndef SFML_TEST_COLORCODER_H
#define SFML_TEST_COLORCODER_H
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <list>
#include <ctype.h>
#include "colorEnum.h"

class ColorCoder {
private:
    static std::vector<char> ops;
    static std::vector<std::string> keywords;
public:
    static std::vector<sf::Color> colorCode(std::string fullType);

};


#endif //SFML_TEST_COLORCODER_H

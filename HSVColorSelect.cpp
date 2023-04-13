#include "HSVColorSelect.h"

HSVColorSelect::HSVColorSelect() {
    points.setPrimitiveType(sf::Points);
    points.resize(255*255);
    initPos = {0,0};
}
HSVColorSelect::HSVColorSelect(sf::Vector2f pos) {
    points.setPrimitiveType(sf::Points);
    points.resize(255*255);
    initPos = pos;
}

void HSVColorSelect::update() {
    for (unsigned int y = 0; y <= 255; ++y) {
        for (unsigned int x = 0; x <= 255; ++x) {
            points[y*256+x].position.x = initPos.x + 255 - x;
            points[y*256+x].position.y = initPos.y + 255 - y;
        }
    }
}

void HSVColorSelect::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(points);
}

float HSVColorSelect::RGBtoHue(sf::Color color) {
    float r = color.r / 255;
    float g = color.g / 255;
    float b = color.b / 255;
    float hue;
    if (r >= g && r>= b) {
        if (g >= b) {
            hue = ((g-b)/(r-b));
        }
        else {
            hue = ((g-b)/(r-g));
        }
    }
    else if (g >= r && g >= b) {
        if (r >= b) {
            hue = 2.0 + (b-r) / (g-b);
        }
        else {
            hue = 2.0+ (b-r) / (g-r);
        }
    }
    else if (b >= r && b >= g) {
        if (r >= g) {
            hue =  4.0 + (r-g) / (b-g);
        }
        else {
            hue = 4.0  +(r-g) / (b-r);
        }
    }
    hue *=60;
    if (hue <0) {
        hue += 360;
    }
    if (hue == 0) {
        hue = 360;
    }
    return hue/360;
}

void HSVColorSelect::initializePixels(double hue) {
    for (int y = 0; y <= 255; ++y) {
        for (int x = 0; x <= 255; ++x) {
            double s = x / 255.;
            double v = y / 255.;
            int cs = hue * 6;
            double f = hue * 6 - cs;
            double p = v * (1 - s);
            double q = v * (1 - s * f);
            double t = v * (1 - s * (1 - f));
            switch (cs) {
                case 0:
                case 1:
                    points[y * 256 + x].color = sf::Color(q * 255, v * 255, p * 255);
                    break;
                case 2:
                    points[y * 256 + x].color = sf::Color(p * 255, v * 255, t * 255);
                    break;
                case 3:
                    points[y * 256 + x].color = sf::Color(p * 255, q * 255, v * 255);
                    break;
                case 4:
                    points[y * 256 + x].color = sf::Color(t * 255, p * 255, v * 255);
                    break;
                case 5:
                    points[y * 256 + x].color = sf::Color(v * 255, p * 255, q * 255);
                    break;
                case 6:
                    points[y * 256 + x].color = sf::Color(v * 255, t * 255, p * 255);
                    break;
            }
        }
    }

}

sf::Color HSVColorSelect::getColor(sf::Vector2<int> pos) {
    sf::Vector2f relPos = {255 - (pos.x-initPos.x),255- (pos.y-initPos.y)};
    return points[relPos.y * 256 + relPos.x].color;
}

void HSVColorSelect::setPosition(sf::Vector2f pos) {
    initPos = pos;
}



//
// Created by Allen Lam on 4/28/22.
//

#include "LogoMaker.h"

LogoMaker::LogoMaker()
: tOpacity("Text Opacity: ",255,{50,750}),
sOpacity("Shadow Opacity: ",220, {50,820}),
bOpacity("Background Opacity: ", 220, {840,820}),
skew("Skew: ", 180, {1380,750}),
fontSize("Font Size: ",325,{775,750}),
textX("Text X-Axis: ", 1300, {50,890}),
textY("Text Y-Axis: ",1300,{50,960}),
shadowX("Shadow X-Axis: ",1300, {50,1030}),
shadowY("Shadow Y-Axis: ",1300, {50,1100}),
font("Font Color", {1000, 10},sf::Color::White),
back("Background Color", {1300,10},sf::Color::Black)
{
    menu.addMenu("File");
    menu.addMenu("Fonts");
    menu.addMenu("Export");
    menu.addMenuItem("File","New Project");
    menu.addMenuItem("File","Open Project");
    menu.addMenuItem("File","Save Project");
    menu.addMenuItem("File","Quit");

    FileNode* fontFile = new FileNode("Fonts", {0,0}, true);
    FileNode* File1 = new FileNode("Boring", {0,0},true);
    FileNode* File2 = new FileNode("Logo", {0,0},true);
    FileNode* File3 = new FileNode("The Best", {0,0},true);
    FileNode* Font1 = new FileNode("OpenSans-Bold", {0,0},false);
    FileNode* Font11 = new FileNode("Arial", {0,0},false);
    FileNode* Font12 = new FileNode("Times-NR", {0,0},false);
    FileNode* Font2 = new FileNode("Comic-Sans", {0,0},false);
    FileNode* Font21 = new FileNode("Papyrus", {0,0},false);
    FileNode* Font3 = new FileNode("SEGA", {0,0},false);
    FileNode* Font4 = new FileNode("Supreme", {0,0},false);
    FileNode* Font5 = new FileNode("Prince", {0,0},false);
    File1->push(Font1);
    File1->push(Font11);
    File1->push(Font12);
    File2->push(Font4);
    File2->push(Font5);
    File2->push(Font3);
    File3->push(Font2);
    File3->push(Font21);
    fontFile->push(File1);
    fontFile->push(File2);
    fontFile->push(File3);
    fontTree.push("",fontFile);
}

void LogoMaker::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(background);
    window.draw(tOpacity);
    window.draw(sOpacity);
    window.draw(bOpacity);
    window.draw(skew);
    window.draw(fontSize);
    window.draw(textX);
    window.draw(textY);
    window.draw(shadowX);
    window.draw(shadowY);
    window.draw(font);
    window.draw(back);
    window.draw(menu);
    window.draw(logo);
}

void LogoMaker::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    tOpacity.backwardEventHandler(window, event);
    sOpacity.backwardEventHandler(window, event);
    bOpacity.backwardEventHandler(window, event);
    skew.addEventHandler(window, event);
    fontSize.addEventHandler(window, event);
    textX.addEventHandler(window, event);
    textY.addEventHandler(window, event);
    shadowX.addEventHandler(window, event);
    shadowY.addEventHandler(window, event);
    font.addEventHandler(window, event);
    back.addEventHandler(window, event);
    logo.addEventHandler(window, event);
    menu.addEventHandler(window, event);
    if (menu.menuClick() == "New Project") {
        newProject();
    }
    if (menu.menuClick() == "Save Project") {
        saveFile();
    }
    if (menu.menuClick() == "Open Project") {
        loadFile();
    }
    if (menu.menuClick() == "Quit") {
        window.close();
    }
    if (menu.menuClick(1)) {
        fontMenuClick();
        logo.setFont(fontTree.getFontName());
    }
    if (menu.menuClick(2)) {
        exportMenuClick(window);
    }
}

void LogoMaker::update() {
    tOpacity.update();
    sOpacity.update();
    bOpacity.update();
    skew.update();
    fontSize.update();
    textX.update();
    textY.update();
    shadowX.update();
    shadowY.update();
    font.update();
    back.update();
    logo.update();
    menu.update();
}


void LogoMaker::applyUpdates() {
    logo.applyUpdates(255-tOpacity.getValue(),255-sOpacity.getValue(),skew.getValue()+1,fontSize.getValue(),
                      textX.getValue()+50,textY.getValue()*0.35+100,shadowX.getValue(),
                      shadowY.getValue(),font.getColor());
    background.update(back.getColor(),255-bOpacity.getValue());
}


Snapshot LogoMaker::getSnapshot() {
    return Snapshot();
}

void LogoMaker::applySnapshot(const Snapshot &snapshot) {

}

void LogoMaker::fontMenuClick() {
    sf::RenderWindow fontWindow(sf::VideoMode(1800, 1200), "Font Menu");
    fontWindow.setFramerateLimit(30);
    while (fontWindow.isOpen()) {

        sf::Event fontEvent;
        while (fontWindow.pollEvent(fontEvent)) {
            if (fontEvent.type == sf::Event::Closed)
                fontWindow.close();
            fontTree.addEventHandler(fontWindow,fontEvent);
        }
        fontTree.update();
        fontWindow.clear();
        fontWindow.draw(fontTree);
        fontWindow.display();
    }
}

void LogoMaker::exportMenuClick(sf::RenderWindow& window) {
    sf::Texture texture;
    texture.create(window.getSize().x,window.getSize().y);
    texture.update(window);
    sf::Image image = texture.copyToImage();
    sf::Image screenShot;
    screenShot.create(1650,495);
    screenShot.copy(image,0,0,sf::IntRect(50,115,1650,495));
    std::string fileName = "Screenshots/screenshot" + std::to_string(rand() % 1000) + ".jpg";
    if (screenShot.saveToFile(fileName)) {
        std::cout << fileName.substr(12,30) << " saved!" << std::endl;
    }

}

void LogoMaker::newProject() {
    LogoMaker *x = new LogoMaker;
    *this = *x;
}

void LogoMaker::saveFile() {
    std::ofstream fout;
    fout.open("saveFile.txt");
    if (fout.is_open()) {
        fout << logo.getString() << std::endl;
        fout << tOpacity.getValue() << std::endl;
        fout << sOpacity.getValue() << std::endl;
        fout << bOpacity.getValue() << std::endl;
        fout << skew.getValue() << std::endl;
        fout << fontSize.getValue() << std::endl;
        fout << textX.getValue() << std::endl;
        fout << textY.getValue() << std::endl;
        fout << shadowX.getValue() << std::endl;
        fout << shadowY.getValue() << std::endl;
        fout << font.getColor().toInteger() << std::endl;
        fout <<background.getColor().toInteger() << std::endl;
        fout << fontTree.getFontName();
    }
    fout.close();
    std::cout << "saveFile overwritten." << std::endl;
}

void LogoMaker::loadFile() {
    std::ifstream fin("saveFile.txt");
    std::string line;
    getline(fin,line);
    logo.setString(line);
    getline(fin, line);
    tOpacity.adjustSlider(std::stoi(line));
    getline(fin, line);
    sOpacity.adjustSlider(std::stoi(line));
    getline(fin, line);
    bOpacity.adjustSlider(std::stoi(line));
    getline(fin, line);
    skew.adjustSlider(std::stoi(line));
    getline(fin, line);
    fontSize.adjustSlider(std::stoi(line));
    getline(fin, line);
    textX.adjustSlider(std::stoi(line));
    getline(fin, line);
    textY.adjustSlider(std::stoi(line));
    getline(fin, line);
    shadowX.adjustSlider(std::stoi(line));
    getline(fin, line);
    shadowY.adjustSlider(std::stoi(line));
    getline(fin, line);
    font.setColor(std::stol(line));
    getline(fin, line);
    back.setColor(std::stol(line));
    getline(fin, line);
    if (line.empty()) {logo.setFont("OpenSans-Bold");}
    else logo.setFont(line);
    std::cout << "saveFile loaded." << std::endl;
    fin.close();

}

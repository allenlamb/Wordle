//
// Created by Allen Lam on 4/27/22.
//

#include "FileNode.h"
std::string FileNode::fontName = "";
FileNode::FileNode() {
}

void FileNode::push(std::string item, bool type) {
    FileNode node(item,{0,0},type);
    FileNode* nodePtr = new FileNode(item,{0,0},type);
    children.push_back(nodePtr);
}

FileNode::FileNode(std::string item, sf::Vector2f pos, bool iconType) {
    data.setText(item);
    data.setPosition(pos);
    data.setIcon(iconType);
}
void FileNode::addEventHandler(sf::RenderWindow& window, sf::Event event) {
    data.adEventHandler(window,event);
    if (data.isClick() && data.isFile()) {
        states.enableState(CHILDTOGGLE);
    }
    if (states.isEnabled(CHILDTOGGLE)) {
        auto iter = children.begin();
        for(;iter!=children.end();++iter) {
            (*iter)->addEventHandler(window,event);
        }
    }
    if (!data.isClick() && states.isEnabled(CHILDTOGGLE)) {
        auto iter = children.begin();
        bool childClick = false;
        for(;iter!=children.end();++iter) {
            if ((*iter)->data.isClick() && !(*iter)->data.isFile()){
                fontName = (*iter)->data.getString();
            }
            else if ((*iter)->data.isClick()) {
                childClick = true;
            }
        }
       if(!childClick) {
            states.disableState(CHILDTOGGLE);
        }
    }
}

void FileNode::update() {
    data.update();
    reposition();
    if (states.isEnabled(CHILDTOGGLE)) {
        auto iter = children.begin();
        for(;iter!=children.end();++iter) {
            (*iter)->update();
        }
    }
}

std::vector<FileNode *>& FileNode::getChildren() {
    return children;
}

void FileNode::reposition() {
    sf::Vector2f increment = {data.getGlobalBounds().left+50,
                              data.getGlobalBounds().top + data.getGlobalBounds().height};
    for(auto iter = children.begin(); iter!=children.end();++iter) {
        (*iter)->data.setPosition(increment);
        if ((*iter)->childToggle()) {
            for (int i = 0; i < (*iter)->children.size(); ++i) {
                increment.y+=data.getGlobalBounds().height;
            }
        }
        increment.y+=data.getGlobalBounds().height;
    }
}
void FileNode::draw(sf::RenderTarget &window, sf::RenderStates state) const {

    window.draw(data);
    if (states.isEnabled(CHILDTOGGLE)) {
        auto iter = children.cbegin();
        for(;iter!=children.cend();++iter) {
            window.draw((*iter)->data);
        }
    }

}

void FileNode::setItemData( const FileItem& item) {
    data = item;
}

FileItem FileNode::getData() const {
    return data;
}

float FileNode::height() {
    float x = data.getGlobalBounds().height;
    if (states.isEnabled(CHILDTOGGLE)) {
        for (int i = 0; i < children.size(); ++i) {
            x += data.getGlobalBounds().height;
        }
    }
    return x;
}

void FileNode::push(FileNode *data) {
    children.push_back(data);

}

bool FileNode::childToggle() const {
    return states.isEnabled(CHILDTOGGLE);
}

void FileNode::incrementHeight() {
    data.setPosition({data.getGlobalBounds().left, data.getGlobalBounds().top + 80});
}

std::string FileNode::getName() {
    return fontName;
}




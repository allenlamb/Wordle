//
// Created by Allen Lam on 4/27/22.
//

#ifndef SFML_TEST_FILENODE_H
#define SFML_TEST_FILENODE_H
#include "GUIComponents.h"
#include "FileItem.h"
#include <map>
class FileNode : public sf::Drawable
        {
private:
    FileItem data;
    std::vector<FileNode*> children;
    States states;
    void setData(FileItem item);
    static std::string fontName;
public:
    FileNode();
    FileNode(std::string item, sf::Vector2f pos, bool iconType);
    void reposition();
    void push(std::string item, bool type);
    void push(FileNode* data);
    void update();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates state) const;
    FileItem getData() const;
    std::vector<FileNode*>& getChildren();
    void setItemData(const FileItem& item);
    float height();
    bool childToggle() const;
    void incrementHeight();
    std::string getName();
};


#endif //SFML_TEST_FILENODE_H

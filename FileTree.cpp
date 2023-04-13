//
// Created by Allen Lam on 4/27/22.
//

#include "FileTree.h"

void FileTree::push(FileNode *&root, std::string parent, FileNode *item) {
    if(root == nullptr) {
        root = item;
    }
}

void FileTree::traverse(FileNode *&root, sf::RenderWindow &window, sf::Event event) {
    if (root == nullptr) return;
    root->addEventHandler(window,event);
    if (root->getChildren().size() == 0) {
        return;
    }
    for (int i = 0; i < root->getChildren().size(); ++i) {
        traverse(root->getChildren()[i],window,event) ;
    }

}

FileTree::FileTree() {

}

void FileTree::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (root == nullptr) return;
    window.draw(*root);
    if (root->getChildren().size() == 0) {
        return;
    }
    for (int i = 0; i < root->getChildren().size(); ++i) {

        window.draw(*root->getChildren()[i]);
    }
}

void FileTree::applySnapshot(const Snapshot &snapshot) {

}

void FileTree::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    traverse(root,window,event);
}

void FileTree::update() {
    update(root);
}

Snapshot FileTree::getSnapshot() {

}

sf::FloatRect FileTree::getGlobalBounds() {

}

void FileTree::push(std::string parent, FileNode *item) {
    push(root,parent,item);
}

void FileTree::preOrder(FileNode *&root) {

}

void FileTree::update(FileNode *&root) {
    if (root == nullptr) return;
    root->update();
    if (root->getChildren().size() == 0) {
        return;
    }
    for (int i = 0; i < root->getChildren().size(); ++i) {
        update(root->getChildren()[i]) ;
    }
}

std::string FileTree::getFontName() {
    return root->getName();
}


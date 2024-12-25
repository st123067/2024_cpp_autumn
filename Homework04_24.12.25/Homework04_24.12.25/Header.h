#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <iostream>
#include <stack>
#include <string>

class TextEditor {
private:
    std::stack<char> leftStack;
    std::stack<char> rightStack;

public:
    TextEditor() {}

    TextEditor(const TextEditor& other) {
        leftStack = other.leftStack;
        rightStack = other.rightStack;
    }

    TextEditor& operator=(const TextEditor& other) {
        if (this != &other) {
            leftStack = other.leftStack;
            rightStack = other.rightStack;
        }
        return *this;
    }

    ~TextEditor() {}

    void addText(const std::string& text);
    int deleteText(int k);
    std::string cursorLeft(int k);
    std::string cursorRight(int k);
    void display();
};

#endif
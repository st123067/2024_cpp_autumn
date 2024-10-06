/* 
=== Структура проекта ===
1) README с описнием задачи, сборки и запуска
2) Makefile для сборки
3) text_editor.h с объявлением класса и его методов
4) text_editor.cpp с определением методов
5) main.cpp в котором проверяется функциональность написанного класса
=========================
Нужно переписать все согласно этой структуре
*/

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

    void addText(const std::string& text) {
        for (char c : text) {
            leftStack.push(c);
        }
    }

    int deleteText(int k) {
        int count = 0;
        while (!leftStack.empty() && k > 0) {
            leftStack.pop();
            count++;
            k--;
        }
        return count;
    }

    std::string cursorLeft(int k) {
        std::string result;
        while (!leftStack.empty() && k > 0) {
            rightStack.push(leftStack.top());
            leftStack.pop();
            k--;
        }
        std::stack<char> temp = leftStack;
        while (!temp.empty()) {
            result = temp.top() + result;
            temp.pop();
        }
        return result;
    }

    std::string cursorRight(int k) {
        std::string result;
        while (!rightStack.empty() && k > 0) {
            leftStack.push(rightStack.top());
            rightStack.pop();
            k--;
        }
        std::stack<char> temp = rightStack;
        while (!temp.empty()) {
            result = result + temp.top();
            temp.pop();
        }
        return result;
    }

    void display() {
        std::stack<char> temp = leftStack;
        std::string leftText;
        while (!temp.empty()) {
            leftText = temp.top() + leftText;
            temp.pop();
        }
        std::cout << leftText << "|";
        temp = rightStack;
        std::string rightText;
        while (!temp.empty()) {
            rightText += temp.top();
            temp.pop();
        }
        std::cout << rightText << std::endl;
    }
};

#endif 

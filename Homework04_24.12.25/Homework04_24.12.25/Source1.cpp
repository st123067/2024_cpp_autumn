#include "Header.h"

void TextEditor::addText(const std::string& text) {
    for (char c : text) {
        leftStack.push(c);
    }
}

int TextEditor::deleteText(int k) {
    int count = 0;
    while (!leftStack.empty() && k > 0) {
        leftStack.pop();
        count++;
        k--;
    }
    return count;
}

std::string TextEditor::cursorLeft(int k) {
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

std::string TextEditor::cursorRight(int k) {
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

void TextEditor::display() {
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
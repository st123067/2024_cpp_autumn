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

int main(int argc, char* argv[]) {
    TextEditor editor;
    std::string command;

    std::cout << "Simple text editor. Enter a command (add, delete, left, right, exit): " << std::endl;

    while (true) {
        std::cout << ">> ";
        std::cin >> command;

        if (command == "add") {
            std::string text;
            std::cout << "Enter text: ";
            std::cin >> text;
            editor.addText(text);
        }
        else if (command == "delete") {
            int k;
            std::cout << "How many characters to delete: ";
            std::cin >> k;
            int deleted = editor.deleteText(k);
            std::cout << "Deleted characters: " << deleted << std::endl;
        }
        else if (command == "left") {
            int k;
            std::cout << "Move cursor left by how many characters: ";
            std::cin >> k;
            std::string leftText = editor.cursorLeft(k);
            std::cout << "Text to the left of the cursor: " << leftText << std::endl;
        }
        else if (command == "right") {
            int k;
            std::cout << "Move cursor right by how many characters: ";
            std::cin >> k;
            std::string rightText = editor.cursorRight(k);
            std::cout << "Text to the right of the cursor: " << rightText << std::endl;
        }
        else if (command == "exit") {
            break;
        }

        editor.display();
    }

    return EXIT_SUCCESS;
}

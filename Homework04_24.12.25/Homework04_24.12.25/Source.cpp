#include "Header.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    TextEditor editor;
    int command = 0;

    std::cout << "Simple text editor. Enter a command:\n"
        << "1: add text\n"
        << "2: delete text\n"
        << "3: move cursor left\n"
        << "4: move cursor right\n"
        << "5: exit\n";

    while (true) {
        std::cout << ">> ";
        std::cin >> command;

        switch (command) {
        case 1: {
            std::string text;
            std::cout << "Enter text: ";
            std::cin >> text;
            editor.addText(text);
            break;
        }
        case 2: {
            int k;
            std::cout << "How many characters to delete: ";
            std::cin >> k;
            int deleted = editor.deleteText(k);
            std::cout << "Deleted characters: " << deleted << std::endl;
            break;
        }
        case 3: {
            int k;
            std::cout << "Move cursor left by how many characters: ";
            std::cin >> k;
            std::string leftText = editor.cursorLeft(k);
            std::cout << "Text to the left of the cursor: " << leftText << std::endl;
            break;
        }
        case 4: {
            int k;
            std::cout << "Move cursor right by how many characters: ";
            std::cin >> k;
            std::string rightText = editor.cursorRight(k);
            std::cout << "Text to the right of the cursor: " << rightText << std::endl;
            break;
        }
        case 5:
            std::cout << "Exiting the program." << std::endl;
            return EXIT_SUCCESS;
        default:
            std::cout << "Invalid command. Please enter a number between 1 and 5." << std::endl;
            break;
        }

        editor.display();  // Display the current state of the editor after each operation
    }

    return EXIT_SUCCESS;
}
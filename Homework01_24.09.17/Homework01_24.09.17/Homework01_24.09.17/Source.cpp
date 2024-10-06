#include "Header.h"

int main(int argc, char* argv[]) {
    TextEditor editor;
    std::string command;

    std::cout << "Simple text editor. Enter a command (add, delete, left, right, exit): " << std::endl;

    while (true) {
        std::cout << ">> ";
        std::cin >> command;

        if (command == "add") {    // Лучше переписать это через switch-case
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

#include "Header.h"
#include <iostream>
#include <string>   
#include <cstdlib>  

#define _CRT_SECURE_NO_WARNINGS

String::String(const char* str) {
    size = strlen(str);
    this->str = new char[size + 1];
    strcpy(this->str, str);
}

String::String(size_t n, char c) : size(n), str(0) {
    this->str = new char[size + 1];
    for (size_t i = 0; i < size; this->str[i] = c, ++i);
    str[size] = '\0';
}

String::~String() {
    delete[] str;
}

String::String(const String& other) : size(other.size) {
    str = new char[size + 1];
    strcpy(str, other.str);
}

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] this->str;
        this->size = other.size;
        this->str = new char[this->size + 1];
        strcpy(this->str, other.str);
    }
    return *this;
}

void String::append(const String& other) {
    size += other.size;
    char* new_str = new char[size + 1];
    strcpy(new_str, str);
    strcat(new_str, other.str);
    delete[] str;
    str = new_str;
}

String::SubstringHelper String::operator[](size_t start) const {
    return SubstringHelper(*this, start);
}

int main(int argc, char* argv[]) {
    std::string input_str;
    std::cout << "Enter string: ";
    std::getline(std::cin, input_str);

    String str(input_str.c_str());

    bool running = true;
    while (running) {
        std::cout << "\nSelect action:\n"
            << "1.Extract substring\n"
            << "2. Exit\n";

        int choice;
        std::cin >> choice;
        std::cin.ignore();  // очистка буфера ввода

        switch (choice) {
        case 1: {
            std::string start_str, end_str;
            size_t start, end;

            std::cout << "Enter starting index: ";
            std::getline(std::cin, start_str);

            std::cout << "Enter ending index: ";
            std::getline(std::cin, end_str);

            try {
                start = std::stoul(start_str);
                end = std::stoul(end_str);

                String substring = str[start][end];
                std::cout << "Substring: " << substring.str << std::endl;
            }
            catch (...) {
                std::cout << "Error: Please enter valid indexes!" << std::endl;
            }
            break;
        }
        case 2:
            std::cout << "End of the program." << std::endl;
            running = false;
            break;
        default:
            std::cout << "Error: Wrong choice!" << std::endl;
            break;
        }
    }

    return EXIT_SUCCESS;
}

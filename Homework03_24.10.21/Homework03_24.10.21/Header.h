#ifndef STRING_H
#define STRING_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstddef> 
#include <cstring> 

struct String {
public:
   
    String(const char* str = "");
    String(size_t n, char c);
    ~String();


    String(const String& other);
    String& operator=(const String& other);


    void append(const String& other);

 
    struct SubstringHelper {
        const String& s;
        size_t start;
        SubstringHelper(const String& s, size_t start) : s(s), start(start) {}

        String operator[](size_t end) const {
            if (end < start) return String("");
            size_t new_size = end - start + 1;
            char* buffer = new char[new_size + 1];
            strncpy(buffer, s.str + start, new_size);
            buffer[new_size] = '\0'; 
            String result(buffer);
            delete[] buffer; 
            return result;
        }
    };

    SubstringHelper operator[](size_t start) const;

    char* str; 

private:
    size_t size; 
};

#endif 

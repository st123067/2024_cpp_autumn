#include "gtest/gtest.h"
#include "Header.h"
#include <iostream>
#include <string>

TEST(TextEditorTests, AddText) {
    TextEditor editor;
    editor.addText("hello");
    EXPECT_EQ(editor.cursorLeft(5), "hello"); 
}

TEST(TextEditorTests, DeleteText) {
    TextEditor editor;
    editor.addText("hello");
    int deleted = editor.deleteText(3);
    EXPECT_EQ(deleted, 3); 
    EXPECT_EQ(editor.cursorLeft(2), "he");  
}

TEST(TextEditorTests, CursorLeft) {
    TextEditor editor;
    editor.addText("abcdef");
    std::string leftText = editor.cursorLeft(3);
    EXPECT_EQ(leftText, "abc"); 
}

TEST(TextEditorTests, CursorRight) {
    TextEditor editor;
    editor.addText("abcdef");
    editor.cursorLeft(6); 
    std::string rightText = editor.cursorRight(4);
    EXPECT_EQ(rightText, "ef"); 
}

TEST(TextEditorTests, ComplexOperations) {
    TextEditor editor;
    editor.addText("hello");
    editor.cursorLeft(2);
    editor.addText("y");
    EXPECT_EQ(editor.cursorLeft(4), "heyl"); 
}
 Simple Text Editor

This project is a simple text editor implemented in C++. The editor can perform the following operations:

- Add text at the cursor position.
- Delete text from the cursor position (simulate the "Backspace" key).
- Move the cursor to the left or right.

 Features

1. TextEditor() 
Initializes the editor with no text.

2. void addText(std::string text) 
Adds text at the current cursor position.

3. int deleteText(int k) 
Deletes `k` characters to the left of the cursor. Returns the number of characters deleted.

4. std::string cursorLeft(int k) 
Moves the cursor `k` characters to the left. Returns the characters to the left of the cursor.

5. std::string cursorRight(int k) 
Moves the cursor `k` characters to the right. Returns the characters to the right of the cursor.

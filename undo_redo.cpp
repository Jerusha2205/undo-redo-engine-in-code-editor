#include <iostream>
#include <stack>
#include <string>
using namespace std;

class UndoRedoEditor {
private:
    stack<string> undoStack;
    stack<string> redoStack;
    string currentText;

public:
    void type(const string& text) {
        undoStack.push(currentText);   // Save current state
        currentText += text;           // Add new text

        // Clear redo stack
        while (!redoStack.empty()) {
            redoStack.pop();
        }
    }

    void undo() {
        if (undoStack.empty()) {
            cout << "Nothing to undo!\n";
            return;
        }

        redoStack.push(currentText);
        currentText = undoStack.top();
        undoStack.pop();
    }

    void redo() {
        if (redoStack.empty()) {
            cout << "Nothing to redo!\n";
            return;
        }

        undoStack.push(currentText);
        currentText = redoStack.top();
        redoStack.pop();
    }

    void display() {
        cout << "Current Text: " << currentText << endl;
    }
};

int main() {
    UndoRedoEditor editor;
    int choice;
    string text;

    do {
        cout << "\n--- Undo/Redo Code Editor ---\n";
        cout << "1. Type Text\n";
        cout << "2. Undo\n";
        cout << "3. Redo\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        cin.ignore(); // IMPORTANT: clear newline from buffer

        switch (choice) {
        case 1:
            cout << "Enter text to add: ";
            getline(cin, text);   // FIX: allows spaces
            editor.type(text);
            break;

        case 2:
            editor.undo();
            break;

        case 3:
            editor.redo();
            break;

        case 4:
            editor.display();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
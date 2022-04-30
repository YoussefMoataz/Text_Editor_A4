#include "TextEditorFunctions.h"

string getFileName(int type) {

    string fileName;

    if (type == 1) {
        cout << "Please enter file name :" << endl;
    } else if (type == 2) {
        cout << "Please enter file name you want to merge :" << endl;
    }

    cin >> fileName;

    return fileName + ".txt";

}

string fileName;

void getChoices() {

//    fileName = getFileName(1);
    fileName = "file1.txt";

    int choice;

    while (true) {
        cout << "Welcome to Our Text Editor ! " << endl;
        cout << "Enter your choice : " << endl;

        cout << "1. Add new text to the end of the file" << endl;
        cout << "2. Display the content of the file" << endl;
        cout << "3. Empty the file" << endl;
        cout << "4. Encrypt the file content" << endl;
        cout << "5. Decrypt the file content" << endl;
        cout << "6. Merge another file" << endl;
        cout << "7. Count the number of words in the file" << endl;
        cout << "8. Count the number of characters in the file" << endl;
        cout << "9. Count the number of lines in the file" << endl;
        cout << "10. Search for a word in the file" << endl;
        cout << "11. Count the number of times a word exists in the file" << endl;
        cout << "12. Turn the file content to upper case" << endl;
        cout << "13. Turn the file content to lower case" << endl;
        cout << "14. Turn file content to 1st caps (1st char of each word is capital)" << endl;
        cout << "15. Save" << endl;
        cout << "16. Exit" << endl;

        cin >> choice;


        if (choice == 1) {
            addText();
        } else if (choice == 2) {
            displayContent();
        } else if (choice == 3) {
            empty();
        } else if (choice == 4) {
            encrypt();
        } else if (choice == 5) {
            Decrypt();
        } else if (choice == 6) {
            Merge();
        } else if (choice == 7) {
            countWords();
        } else if (choice == 8) {
            countCharacters();
        } else if (choice == 9) {
            countLines();
        } else if (choice == 10) {
            searchWord();
        } else if (choice == 11) {
            countWordTime();
        } else if (choice == 12) {
            turnToUpper();
        } else if (choice == 13) {
            turnToLower();
        } else if (choice == 14) {
            turnTo1stCaps();
        } else if (choice == 15) {
            save();
        } else if (choice == 16) {
            cout << "Thanks for using Our Text Editor, GoodBye ! " << endl;
            exit(0);
        } else {
            cout << "Wrong Choice " << endl;
        }
    }

}

void addText() {


}

void displayContent() {


}

void empty() {


}

void encrypt() {


}

void Decrypt() {


}

void Merge() {

    fstream mainFile(fileName.c_str(), ios::app);

    string newFileName;

    fstream newFile(getFileName(2).c_str(), ios::in);

    string str;

    mainFile << '\n';

    while (newFile >> str) {
        mainFile << str << " ";
    }

}

void countWords() {

    fstream read(fileName.c_str(), ios::in);

    string word;
    int counter = 0;

    while (read >> word) {
        counter++;
    }

    cout << "The file has " << counter << " words" << endl;
}

void countCharacters() {

    fstream read(fileName.c_str(), ios::in);

    char character;
    int counter = 0;

    while (read >> character) {
        counter++;
    }

    cout << "The file has " << counter << " characters" << endl;

}

void countLines() {

    fstream read(fileName.c_str(), ios::in);

    string line;
    int counter = 0;

    while (getline(read, line, '\n')) {
        counter++;
    }

    cout << "The file has " << counter << " lines" << endl;

}

void searchWord() {

    fstream read(fileName.c_str(), ios::in);

    string str;
    cout << "Enter a word to search for it" << endl;
    cin >> str;

    str = lower(str);

    regex match("( " + str + " ).*");

    string fileContent = "";

    char word [10000];

    while (read.getline(word, 10000)) {
        fileContent += word;
    }

    fileContent = lower(fileContent);

    if (regex_search(fileContent, match)) {
        cout << "Word was found in the file" << endl;
    }else{
        cout << "Word was not found in the file" << endl;
    }

}

void countWordTime() {

    fstream read(fileName.c_str(), ios::in);

    string fileContent;
    string singleWord;

    read >> singleWord;

    while (!read.eof()) {

        fileContent += singleWord + " ";
        read >> singleWord;

    }

    string requiredWord;
    cout << "Enter ther required word :" << endl;
    cin >> requiredWord;

    int wordindex = fileContent.find(requiredWord);

    int counter = 0;

    while (true) {

        if (wordindex != -1) {

            fileContent = fileContent.substr(wordindex + requiredWord.length() - 1, fileContent.length() - 1);

            wordindex = fileContent.find(requiredWord);

            counter++;
        } else {
            break;
        }

    }

    cout << "The word : \"" + requiredWord + "\"" + " is found : " + to_string(counter) + " times in the file." << endl;

}

void turnToUpper() {

    fstream file(fileName.c_str(), ios::in);

    string fileContent = "";

    char word [10000];

    while (file.getline(word, 10000)) {
        fileContent += word;
        fileContent += "\n";
    }

    file.close();

    fileContent = upper(fileContent);

    fstream fileToWrite(fileName.c_str(), ios::out);

    for (char c: fileContent) {

        fileToWrite.put(c);

    }

    fileToWrite.close();

//    cout << fileContent;


}

void turnToLower() {

    fstream file(fileName.c_str(), ios::in);

    string fileContent = "";

    char word [10000];

    while (file.getline(word, 10000)) {
        fileContent += word;
        fileContent += "\n";
    }

    file.close();

    fileContent = lower(fileContent);

    fstream fileToWrite(fileName.c_str(), ios::out);

    for (char c: fileContent) {

        fileToWrite.put(c);

    }

    fileToWrite.close();

//    cout << fileContent;

}

void turnTo1stCaps() {



}

void save() {


}

string upper(string str) {
    string newStr = "";
    for (int i = 0; i < str.length(); i++) {
        newStr += toupper(str[i]);
    }

    return newStr;
}

string lower(string str) {
    string newStr = "";
    for (int i = 0; i < str.length(); i++) {
        newStr += tolower(str[i]);
    }

    return newStr;
}
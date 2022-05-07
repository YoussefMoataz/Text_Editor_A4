#include "TextEditorFunctions.h"

string getFileName(int type) {

    string fileName;

    if (type == 1) {
        cout << "Please enter file name :" << endl;
    } else if (type == 2) {
        cout << "Please enter file name you want to merge :" << endl;
    } else if (type == 3) {
        cout << "Please enter the new file name :" << endl;
    }

    cin >> fileName;

    return fileName + ".txt";

}

string fileName;

void getChoices() {

    fileName = getFileName(1);
//    fileName = "file1.txt";

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
    fstream file(fileName.c_str(), ios::app);
        string userInput;
        while(getline(cin, userInput)){
        file << userInput << endl;
        }
        file.close();


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

    fstream newFile(getFileName(2).c_str(), ios::in);

    string str;

    mainFile << '\n';

    while (newFile >> str) {
        mainFile << str << " ";
    }

    mainFile.close();
    newFile.close();

}

void countWords() {

    fstream file(fileName.c_str(), ios::in);

    string word;
    int counter = 0;

    while (file >> word) {
        counter++;
    }

    file.close();

    cout << "The file has " << counter << " words" << endl;
}

void countCharacters() {

    fstream file(fileName.c_str(), ios::in);

    char character;
    string word;
    int counterChars = 0;
    int counterWords = 0;

    while (file >> character) {
        counterChars++;
    }

    file.close();

    file.open(fileName.c_str(), ios::in);

    while (file >> word) {
        counterWords++;
    }

    file.close();

    cout << "The file has " << (counterChars + counterWords - 1) << " characters" << endl;

}

void countLines() {

    fstream file(fileName.c_str(), ios::in);

    string line;
    int counter = 0;

    while (getline(file, line, '\n')) {
        counter++;
    }

    file.close();

    cout << "The file has " << counter << " lines" << endl;

}

void searchWord() {

    fstream file(fileName.c_str(), ios::in);

    string str;
    cout << "Enter a word to search for it" << endl;
    cin >> str;

    str = lower(str);

    regex match("( " + str + " ).*");

    string fileContent = "";

    char word[10000];

    while (file.getline(word, 10000)) {
        fileContent += word;
    }

    file.close();

    fileContent = lower(fileContent);

    if (regex_search(fileContent, match)) {
        cout << "Word was found in the file" << endl;
    } else {
        cout << "Word was not found in the file" << endl;
    }

}

void countWordTime() {

    fstream file(fileName.c_str(), ios::in);

    string fileContent;
    string singleWord;

    file >> singleWord;

    while (!file.eof()) {

        fileContent += singleWord + " ";
        file >> singleWord;

    }

    file.close();

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

    char line[10000];

    while (file.getline(line, 10000)) {
        fileContent += line;
        fileContent += "\n";
    }

    file.close();

    fileContent = upper(fileContent);

    fstream fileToWrite(tempFile.c_str(), ios::out);

    for (char c: fileContent) {

        fileToWrite.put(c);

    }

    fileToWrite.close();

}

void turnToLower() {

    fstream file(fileName.c_str(), ios::in);

    string fileContent = "";

    char line[10000];

    while (file.getline(line, 10000)) {
        fileContent += line;
        fileContent += "\n";
    }

    file.close();

    fileContent = lower(fileContent);

    fstream fileToWrite(tempFile.c_str(), ios::out);

    for (char c: fileContent) {

        fileToWrite.put(c);

    }

    fileToWrite.close();

}

void turnTo1stCaps() {

    fstream file(fileName.c_str(), ios::in);

    string fileContent = "";

    char line[10000];

    while (file.getline(line, 10000)) {
        fileContent += line;
        fileContent += "\n";
    }

    file.close();

    fileContent = upperFirst(fileContent);

    fstream fileToWrite(tempFile.c_str(), ios::out);

    for (char c: fileContent) {

        fileToWrite.put(c);

    }

    fileToWrite.close();

}

void save() {

    cout << "Do you want to (1) Save to the same file" << endl;
    cout << "(2) Save to different file" << endl;

    int choice;

    cin >> choice;

    if(choice == 1){

        fstream mainFile(tempFile.c_str(), ios::in);

        fstream newFile(fileName.c_str(), ios::out);

        char str [10000];

        while (mainFile.getline(str, 10000)) {
            newFile << str << "\n";
        }

        mainFile.close();
        newFile.close();

    }else if (choice == 2){

        fstream mainFile(tempFile.c_str(), ios::in);

        fstream newFile(getFileName(3).c_str(), ios::out);

        char str [10000];

        while (mainFile.getline(str, 10000)) {
            newFile << str << "\n";
        }

        mainFile.close();
        newFile.close();

    }

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

string upperFirst(string str) {

    str[0] = toupper(str[0]);

    for (int i = 0; i < str.length(); i++) {

        if (iswspace(str[i])) {
            str[i + 1] = toupper(str[i + 1]);
        } else {
            str[i + 1] = tolower(str[i + 1]);
        }

    }

    return str;
}

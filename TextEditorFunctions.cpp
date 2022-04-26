#include "TextEditorFunctions.h"

void getChoices(){
    
    int choice;

    while(true){
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


        if(choice == 1){
            addText();
        }
        else if(choice == 2){
            displayContent();
        }
        else if(choice == 3){
            empty();
        }
        else if(choice == 4){
            encrypt();
        }
        else if(choice == 5){
            Decrypt();
        }
        else if(choice == 6){
            Merge();
        }
        else if(choice == 7){
            countWords();
        }
        else if(choice == 8){
            countCharacters();
        }
        else if(choice == 9){
            countLines();
        }
        else if(choice == 10){
            searchWord();
        }
        else if(choice == 11){
            countWordTime();
        }
        else if(choice == 12){
            turnToUpper();
        }
        else if(choice == 13){
            turnToLower();
        }
        else if(choice == 14){
            turnTo1stCaps();
        }
        else if(choice == 15){
            save();
        }
        else if(choice == 16){
            cout << "Thanks for using Our Text Editor, GoodBye ! " << endl;
            exit(0);
        }
        else{
            cout << "Wrong Choice " << endl;
        }
    }

}

void addText(){


}
void displayContent(){


}
void empty(){


}
void encrypt(){


}
void Decrypt(){


}
void Merge(){


}
void countWords(){


}
void countCharacters(){


}
void countLines(){


}
void searchWord(){


}
void countWordTime(){


}
void turnToUpper(){


}
void turnToLower(){


}
void turnTo1stCaps(){


}
void save(){


}
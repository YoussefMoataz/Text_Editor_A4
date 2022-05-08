#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

#ifndef TEXT_EDITOR_A4_TEXTEDITORFUNCTIONS_H
#define TEXT_EDITOR_A4_TEXTEDITORFUNCTIONS_H

const string tempFile = "fileTEMPfile.txt";

inline void getChoices();

inline void addText();

inline void displayContent();

inline void empty();

inline void encrypt();

inline void Decrypt();

inline void Merge();

inline void countWords();

inline void countCharacters();

inline void countLines();

inline void searchWord();

inline void countWordTime();

inline void turnToUpper();

inline void turnToLower();

inline void turnTo1stCaps();

inline void save();

inline void exit();

inline string upper(string str);

inline string lower(string str);

inline string upperFirst(string str);

inline string encryption(string text);

inline string decryption(string text);

#endif

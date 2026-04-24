#ifndef WORDLE_H
#define WORDLE_H

#include <iostream>
using namespace std;

class Word {
public:
    Word();
    void setWord(string wordName);
    bool checkAndPrintGuess(string guess);
    int wordLength();

private:
    size_t lenOfWord;
    string targetWord;
    size_t guesses;
};

#endif
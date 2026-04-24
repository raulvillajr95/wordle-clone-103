#include <iostream>
#include <string>
#include <vector>

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
};

Word::Word() {
    lenOfWord = 0;
    targetWord = "";
}

void Word::setWord(string wordName) {
    targetWord = wordName;
    lenOfWord = wordName.size();
}

int Word::wordLength() {
    return lenOfWord;
}

bool Word::checkAndPrintGuess(string guess) {
    int* status = new int[lenOfWord];
    bool* targetUsed = new bool[lenOfWord];
    bool* guessUsed = new bool[lenOfWord];

    for (size_t i = 0; i < lenOfWord; i++) {
        status[i] = 0;
        targetUsed[i] = false;
        guessUsed[i] = false;
    }

    for (size_t i = 0; i < lenOfWord; i++) {
        if (guess[i] == targetWord[i]) {
            status[i] = 2; 
            targetUsed[i] = true;
            guessUsed[i] = true;
        }
    }

    for (size_t i = 0; i < lenOfWord; i++) {
        if (!guessUsed[i]) {
            for (size_t j = 0; j < lenOfWord; j++) {
                if (!targetUsed[j] && guess[i] == targetWord[j]) {
                    status[i] = 1;
                    targetUsed[j] = true;
                    break;
                }
            }
        }
    }

    cout << "Result: ";
    for (size_t i = 0; i < lenOfWord; i++) {
        if (status[i] == 2) {
            cout << "\033[32m" << guess[i] << "\033[0m";
        } else if (status[i] == 1) {
            cout << "\033[33m" << guess[i] << "\033[0m";
        } else {
            cout << "\033[90m" << guess[i] << "\033[0m";
        }
    }
    cout << endl;

    bool isCorrect = (guess == targetWord);

    delete[] status;
    delete[] targetUsed;
    delete[] guessUsed;

    return isCorrect;
}

int main() {
    Word word1;
    word1.setWord("queue");
    
    string guess;
    bool isCorrect = false;

    cout << "Guess the " << word1.wordLength() << " letter word!" << endl;

    while (!isCorrect) {
        cout << "Enter guess: ";
        cin >> guess;

        if (guess.size() != word1.wordLength()) {
            cout << "Write a word with " << word1.wordLength() << " letters." << endl;
            continue; 
        }

        isCorrect = word1.checkAndPrintGuess(guess);

        if (isCorrect) {
            cout << "Correct! You won!" << endl;
        }
    }

    return 0;
}
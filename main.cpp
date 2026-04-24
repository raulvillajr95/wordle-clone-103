#include <iostream>
#include "wordle.h"
using namespace std;

int main() {
    Word word1;
    word1.setWord("queue");
    
    string guess;
    bool isCorrect = false;
    size_t guessNum = 0;
    string contStatus = "";

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
        } else {
          guessNum++;
          if (guessNum >= 6)
          {
            cout << "LOSER!" << endl;
            cout << "Press C to continue or Q to quit: ";
            cin >> contStatus;
            if(contStatus[0] == 'Q')
            {
              cout << "BYE" << endl;
              break;
            } else {
              cout << "New game!" << endl;
              // start a new game somehow
            }
          }
          
        }
    }

    return 0;
}

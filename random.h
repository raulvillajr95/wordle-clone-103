#ifndef RANDOM_H
#define RANDOM_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <random>

using namespace std;

string randomWord() {
    string* words = new string[3414];
    random_device rd;

    mt19937 gen(rd());

    uniform_int_distribution<> distr(0, 3414 - 1);

    int randomIndex = 0;

    // Create and open a text file
    ifstream WordBank("C:/Users/maxwe/Desktop/wordle-cs/wordbank.txt");


    if(WordBank.fail()){
        cout << "Error detected" << endl;
    }
    
    // Read from the file
    string myText;
    int i = 0;
    while(getline(WordBank, myText)){
        words[i] = myText;
        i++;
    }

    randomIndex = distr(gen);

    cout << words[randomIndex] << endl;

    // for(int i = 0; i < 3414; i++){
    //     cout << words[i] << ", ";
    // }

    // Close the file
    WordBank.close();

    return words[randomIndex];
}

#endif
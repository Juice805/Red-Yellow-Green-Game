//
//  main.cpp
//  redyellowgreengame
//
//  Created by Justin Oroz on 9/24/14.
//  Copyright (c) 2014 jmoroz. All rights reserved.
//

#include "main.h"

void redyellowgreen::resetGame() {
    srand((int)time(0));
    
    // puts generated value into array
    answer = rand() % (999+1-100) + 100;
    answerArray[0] = answer / 100; //100's place
    answerArray[1] = (answer % 100) / 10;
    answerArray[2] = answer % 10;
    
    cout << "Number Generated!\n";
    
    void initializeStateArray(); // initialize stateArray to all red
}

bool redyellowgreen::answerCorrect () {
    
    if ((answerArray[0] == guessedNum[0]) && (answerArray[1] == guessedNum[1]) && (answerArray[2] == guessedNum[2])) {
        return true;
    } else {
        
        bool numUsed = false; //records whether the number has been used already (prevents double yellow)
        int colorCount[3]; //counts colors [0]=g [1]=y [2]=r
        initializeStateArray();
        
        //initialize count array
        for (int i = 0; i < 3; i++)
            colorCount[i] = 0;

        for (int i = 0; i < 3; i++) {
            numUsed = false;
            for (int j = 0; j < 3; j++) {
                if ((guessedNum[j] == answerArray[i]) && (numUsed == false) && (stateArray[j] == red)) {
                    // continues on match, and unused answer number, guess number is not yet matched
                    
                    if (answerArray[i] == guessedNum[i]) // check for exact match first
                        stateArray[i] = green;
                    else
                        stateArray[j] = 'y';
                    
                    numUsed = true;
                }
            }
        }
        
        //count
        for (int i = 0; i < 3; i++) {
            if (stateArray[i] == green) {
                colorCount[0] += 1;
            } else if (stateArray[i] == yellow) {
                colorCount[1] += 1;
            } else colorCount[2] += 1;
        }
        
        //print score
        printScore(colorCount[0], colorCount[1], colorCount[2]);
        
        //reset stateArray
        initializeStateArray();
        return false;
    }
}

int main(int argc, const char * argv[]) {
    redyellowgreen game;  // creates the number, fills the array
    char play;
    int best = INT_MAX;
    
    do {
        
        int guess;
        int guessCount = 0;
        
        cout << "Enter a guess (100-999): ";
        cin >> guess;
        cout << endl;
        
        while (game.error(guess)) {
            cout << "\nERROR: Enter a guess (100-999): ";
            cin >> guess;
        }
        
        game.guessNumber(guess); // first guess initializes loop
        guessCount++;
        
        while (!game.answerCorrect()) {
            cout << "Guesses so far: " << guessCount << endl;
            cout << "Next Guess: ";
            cin >> guess;
            
            while (game.error(guess)) {
                cout << "\nERROR: Enter a guess (100-999): ";
                cin >> guess;
                cout << endl;
            }
            
            game.guessNumber(guess);
            guessCount++;
            cout << endl;
        }
        
        cout << "\nCorrect! The answer was " << game.getAnswer() << endl << endl;
        cout << "\tIt took you " << guessCount << " tries. Best: ";
        
        if (guessCount < best) //saves best score
            best = guessCount;
        
        cout << best << endl << endl;
        
        
        cout << "Play again? (y/n): ";
        cin >> play;
        cout << endl;
        
        switch (play) {
            case 'y':
            case 'Y':
                cout << endl << endl;
                game.resetGame();
                break;
            case 'n':
            case 'N':
                game.play = false;
                cout << "Best score: " << best << endl << "\tThanks for playing!\n\n";
                break;
            default:
                cout << "ERROR: Unknown characacter. Exiting...\n";
                game.play = false;
                break;
        }
        
        
    } while (game.play);
    
    return 0;
}

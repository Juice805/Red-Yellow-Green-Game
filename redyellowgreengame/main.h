//
//  main.h
//  redyellowgreengame
//
//  Created by Justin Oroz on 9/24/14.
//  Copyright (c) 2014 jmoroz. All rights reserved.
//

#ifndef redyellowgreengame_main_h
#define redyellowgreengame_main_h


#endif

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// value / 100 gives first number
// Make random number between 100-999
// place number into array
// divide by 100 put into array[1]
// divide remainder by 10 ((number%100)/10)
// remainder put into final array space ((number%100)%10)
// While incorrect (Starts incorrect = true)
// recieve number
// Place into array
// Check for matches


class redyellowgreen {
public:
    redyellowgreen(){
        resetGame();
    }
    
    bool play = true;
    bool answerCorrect();
    
    void resetGame();

    void guessNumber(int guess) {
        guessedNum[0] = guess / 100; //100's place
        guessedNum[1] = (guess % 100) / 10;
        guessedNum[2] = guess % 10;
    }
    
    bool error(int guess){
        if ((guess > 99) && (guess < 1000)) {
            return false;
        } else  return true;
    }
    
    int getAnswer() {
        return answer;
    }
    
    
    
private:
    void initializeStateArray(){ // initialize stateArray to all red
        
        for (int i = 0; i < 3; i++) {
            stateArray[i] = red;
        }
    }
    
    void printScore(int g, int y, int r){
        cout << "Greens: " << g << endl;
        cout << "Yellows: " << y << endl;
        cout << "Reds: " << r << endl;
        cout << endl << endl;
    }
    
    int answer;
    int answerArray[3];
    int guessedNum[3]; // stores the guessed number
    char stateArray[3]; // matched to the guessed number, puts a char depending on guess result (g,y,r)
    
    // colors for readability
    char green = 'g';
    char yellow = 'y';
    char red = 'r';
    
};
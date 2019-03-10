//
//  Player.cpp
//  Pig
//
//

#include "Player.h"

#include <iostream>

namespace cs31
{
    
    Player::Player() : mDie( 6 ), mScore( 0 ), mTotal( 0 )
    {
        
    }
    
    // TODO: roll the die and adjust the score for the current round
    // accordingly
    // when the amount is zero, the Die should be rolled for random play
    // when the amount is not zero, we are trying to cheat for testing
    // purposes.  in that case, this method should force a specific roll
    // amount.
    int Player::roll( int amount )
    {
        int rolledNum;
        if(amount != 0)
            rolledNum = amount; // if a value is entered, "cheat" out that value
        else {
            mDie.roll(); // roll the Player's dice
            rolledNum = mDie.getValue();
        }
        
        mScore += rolledNum; // add value of rolled number to the score
        
        if(rolledNum == 1) { // if a 1 is rolled, score is set to 0 and the turn is ended
            mScore = 0;
        }
        return rolledNum;
    }
    
    // TODO: add the current score into the running total since the turn ended
    //       reset the current score to 0 for the next round of play
    void Player::endTurn()
    {
        mTotal += mScore;
        mScore = 0;
    }
    
    // TODO: return the current total
    int Player::getTotal( ) const
    {
        return mTotal;
    }
    
    // TODO: return the current score
    int  Player::getScore( ) const
    {
        return mScore;
    }
    

}

using namespace std;
#include <vector>
#include <algorithm>
#include "Deck.h"
  //  vector<Card> theDeck;
 //   vector<Card> dealtCards;

    /* Constructs a Deck of 52 cards:
       Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King of each suit.
       Cards should start off in this order with the order of suits being:
       Clubs, Diamonds, Hearts, Spades.
    */
    //theDeck.at(((i)*13)+(x-1))=Card('c',x);
Deck::Deck()
{
    for(unsigned i=0;i<4; i++)
    {
        for(unsigned x=1; x<14; x++)
        {
            if(i==0)
            {
                theDeck.insert(theDeck.begin(),Card('c',x));
            }
            if(i==1)
            {
               theDeck.insert(theDeck.begin(),Card('d',x));
            }
            if(i==2)
            {
                theDeck.insert(theDeck.begin(),Card('h',x));
            }
            if(i==3)
            {
                theDeck.insert(theDeck.begin(),Card('s',x));
            }
            
        }
    }
}

    /* Deals (returns) the top card on the deck. 
       Removes this card from theDeck and places it in the dealtCards.
    */
    Card Deck::dealCard()
    {
       dealtCards.insert(dealtCards.begin(),theDeck.at(theDeck.size()-1));
        theDeck.pop_back();
        return dealtCards.at(0);
    }


    /* Places all cards back into theDeck and shuffles them into random order.
    */
    void Deck::shuffleDeck()
    {
        if(dealtCards.size()==0)
        {
            random_shuffle(theDeck.begin(),theDeck.end());
            return;
        }
        for(unsigned i=0; i<dealtCards.size();i++)
        {
            theDeck.push_back(dealtCards.at(dealtCards.size()-1));
            dealtCards.pop_back();
            i--;
        }
        random_shuffle(theDeck.begin(),theDeck.end());
    }


    /* returns the size of the Deck (how many cards have not yet been dealt).
    */
    unsigned Deck::deckSize() const
    {
        return theDeck.size();
    }
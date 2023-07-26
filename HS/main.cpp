#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
/* Passes in a vector Cards and returns true if any 2 Cards have the same rank.
   Otherwise returns false.
*/
bool hasPair(const vector<Card> &);


/* Passes in a vector of Cards and outputs to the stream each Card
   separated by a comma and a space, 
   with no comma, space, or newline at the end.
*/
ostream & operator<<(ostream &, const vector<Card> &);

bool hasPair(const vector<Card> &hand)
{
    int R=hand.at(0).getRank();
    for(unsigned x=1;x<hand.size();x++)
    {
        for(unsigned i=x;i<hand.size();i++)
        {
            if(R==hand.at(i).getRank())
            {
                return true;
            }
        }
        R=hand.at(x).getRank();
    }
    return false;
}

ostream & operator <<(ostream & out, const vector<Card> & rhs)
{
    for(unsigned i=0;i<rhs.size();i++)
    {
        if(i==rhs.size()-1)
        {
            out<<rhs.at(i);
        }
        else
        {
            out<< rhs.at(i) << ", ";
        }
    }
    return out;
}

int main()
{
    srand(2222);
    
    string ans;
    
    Deck dDeck=Deck();
    
    vector<Card> hand;
    
    unsigned size, sims;
    double count=0.00;
    
    dDeck.shuffleDeck();
    
    cout << "Do you want to output all hands to a file?(Yes/No) ";
    
    cin >> ans;
    cout << endl;
    if(ans=="no" || ans=="No")
    {
        cout << "Enter number of cards per hand: ";
        cin >> size;
        cout << endl;
        cout << "Enter number of deals (simulations): ";
        cin >> sims;
        cout << endl;
        for(unsigned i=0;i<size;i++)
        {
            hand.push_back(dDeck.dealCard());
        }
        for(unsigned i=0;i<sims;i++)
        {
            if(hasPair(hand))
            {
                count++;
            }
            
            dDeck.shuffleDeck();
            
            for(unsigned i=0;i<size;i++)
            {
                hand.at(i)=dDeck.dealCard();
            }
        }
        cout << "Chances of receiving a pair in a hand of " << size << " cards is: " << (count/sims)*100.00 << "%" << endl;
    }
    if(ans=="yes" || ans=="Yes")
    {
        string output;
        cout << "Enter name of output file: ";
        cin >> output;
        cout << endl;
        ofstream fout(output.c_str());
        cout << "Enter number of cards per hand: ";
        cin >> size;
        cout << endl;
        cout << "Enter number of deals (simulations): ";
        cin >> sims;
        cout << endl;
        for(unsigned i=0;i<size;i++)
        {
            hand.push_back(dDeck.dealCard());
            
        }
        for(unsigned i=0;i<sims;i++)
        {
            if(hasPair(hand))
            {
                count++;
                if(i==sims-1)
                {
                    fout << "Found Pair!! " << hand;
                }
                else
                {
                     fout << "Found Pair!! " << hand << endl;
                }
            }
            if(!hasPair(hand))
            {
                if(i==sims-1)
                {
                    fout << "             " << hand;
                }
                else
                {
                    fout << "             " << hand << endl;
                }
            }

            dDeck.shuffleDeck();
            
            for(unsigned i=0;i<size;i++)
            {
                hand.at(i)=dDeck.dealCard();
            }
        }
         cout << "Chances of receiving a pair in a hand of " << size << " cards is: " << (count/sims)*100.00 << "%" << endl;
         fout.close();
    }
    return 0;
}
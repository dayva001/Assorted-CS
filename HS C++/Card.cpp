#include "Card.h"
 //   char suit;
 //   int rank;

    /* Assigns a default value of 2 of Clubs
    */
Card::Card()
:suit('c'), rank(2)
{    }


    /* Assigns the Card the suit and rank provided.
       suits: c = Clubs, d = Diamonds, h = Hearts, s = Spades
       If an invalid suit is provided, sets the suit to Clubs
       ranks: 1 - 13 (1 = Ace, 11 = Jack, 12 = Queen, 13 = King)
       If an invalid rank is provided, sets the rank to 2
       Accepts lower or upper case characters for suit
    */  
Card::Card(char c, int i)
{
    if(i<1|| i>13)
    {
        rank=2;
    }
    else
    {
        rank=i;
    }
    
    if(c=='c' || c=='C'||c=='d'||c=='D'||c=='h'||c=='H'||c=='s'||c=='S')
    {
       if(c=='c'||c=='C')
       {
           suit='c';
       }
       if(c=='d'||c=='D')
       {
           suit='d';
       }
       if(c=='h'||c=='H')
       {
           suit='h';
       }
       if(c=='s'||c=='S')
       {
           suit='s';
       }
    }
    else
    {
        suit='c';
    }
}

    
    /* Returns the Card's suit
    */
char Card::getSuit() const
{
    return suit;
}


    /* Returns the Card's rank as an integer
    */
int Card::getRank() const
{
    return rank;
}

    /* Outputs a Card in the following format: Rank of Suit
       For example, if the rank is 3 and the suit is h: 3 of Hearts
       Or, if the rank is 1 and the suit is d: Ace of Diamonds
       Or, if the rank is 12 and the suit is c: Queen of Clubs
       etc.
    */  
ostream & operator<<(ostream &out, const Card &C)
{
    switch(C.rank)
    {
        case 1:if(C.suit=='c'||C.suit=='C')
                {
                    out << "Ace of Clubs";
                    return out;
                }
                if(C.suit=='d'||C.suit=='D')
                {
                    out << "Ace of Diamonds";
                    return out;
                }
                if(C.suit=='s'||C.suit=='S')
                {
                    out << "Ace of Spades";
                    return out;
                }
                  if(C.suit=='h'||C.suit=='H')
                {
                    out << "Ace of Hearts";
                    return out;
                }
                break;
       case 2:if(C.suit=='c'||C.suit=='C')
                {
                    out << "2 of Clubs";
                    return out;
                }
                if(C.suit=='d'||C.suit=='D')
                {
                    out << "2 of Diamonds";
                    return out;
                }
                if(C.suit=='s'||C.suit=='S')
                {
                    out << "2 of Spades";
                    return out;
                }
                  if(C.suit=='h'||C.suit=='H')
                {
                    out << "2 of Hearts";
                    return out;
                }
                break;
        case 3:if(C.suit=='c'||C.suit=='C')
                {
                    out << "3 of Clubs";
                    return out;
                }
                if(C.suit=='d'||C.suit=='D')
                {
                    out << "3 of Diamonds";
                    return out;
                }
                if(C.suit=='s'||C.suit=='S')
                {
                    out << "3 of Spades";
                    return out;
                }
                  if(C.suit=='h'||C.suit=='H')
                {
                    out << "3 of Hearts";
                    return out;
                }
                break;
        case 4:if(C.suit=='c'||C.suit=='C')
                {
                    out << "4 of Clubs";
                    return out;
                }
                if(C.suit=='d'||C.suit=='D')
                {
                    out << "4 of Diamonds";
                    return out;
                }
                if(C.suit=='s'||C.suit=='S')
                {
                    out << "4 of Spades";
                    return out;
                }
                  if(C.suit=='h'||C.suit=='H')
                {
                    out << "4 of Hearts";
                    return out;
                }
                break;
        case 5:if(C.suit=='c'||C.suit=='C')
                {
                    out << "5 of Clubs";
                    return out;
                }
                if(C.suit=='d'||C.suit=='D')
                {
                    out << "5 of Diamonds";
                    return out;
                }
                if(C.suit=='s'||C.suit=='S')
                {
                    out << "5 of Spades";
                    return out;
                }
                  if(C.suit=='h'||C.suit=='H')
                {
                    out << "5 of Hearts";
                    return out;
                }
                break;
        case 6:if(C.suit=='c'||C.suit=='C')
                {
                    out << "6 of Clubs";
                    return out;
                }
                if(C.suit=='d'||C.suit=='D')
                {
                    out << "6 of Diamonds";
                    return out;
                }
                if(C.suit=='s'||C.suit=='S')
                {
                    out << "6 of Spades";
                    return out;
                }
                  if(C.suit=='h'||C.suit=='H')
                {
                    out << "6 of Hearts";
                    return out;
                }
                break;
        case 7:if(C.suit=='c'||C.suit=='C')
                {
                    out << "7 of Clubs";
                    return out;
                }
                if(C.suit=='d'||C.suit=='D')
                {
                    out << "7 of Diamonds";
                    return out;
                }
                if(C.suit=='s'||C.suit=='S')
                {
                    out << "7 of Spades";
                    return out;
                }
                  if(C.suit=='h'||C.suit=='H')
                {
                    out << "7 of Hearts";
                    return out;
                }
                break;
        case 8:if(C.suit=='c'||C.suit=='C')
                {
                    out << "8 of Clubs";
                    return out;
                }
                if(C.suit=='d'||C.suit=='D')
                {
                    out << "8 of Diamonds";
                    return out;
                }
                if(C.suit=='s'||C.suit=='S')
                {
                    out << "8 of Spades";
                    return out;
                }
                  if(C.suit=='h'||C.suit=='H')
                {
                    out << "8 of Hearts";
                    return out;
                }
                break;
        case 9:if(C.suit=='c'||C.suit=='C')
                {
                    out << "9 of Clubs";
                    return out;
                }
                if(C.suit=='d'||C.suit=='D')
                {
                    out << "9 of Diamonds";
                    return out;
                }
                if(C.suit=='s'||C.suit=='S')
                {
                    out << "9 of Spades";
                    return out;
                }
                  if(C.suit=='h'||C.suit=='H')
                {
                    out << "9 of Hearts";
                    return out;
                }
                break;
        case 10:if(C.suit=='c'||C.suit=='C')
                {
                    out << "10 of Clubs";
                    return out;
                }
                if(C.suit=='d'||C.suit=='D')
                {
                    out << "10 of Diamonds";
                    return out;
                }
                if(C.suit=='s'||C.suit=='S')
                {
                    out << "10 of Spades";
                    return out;
                }
                  if(C.suit=='h'||C.suit=='H')
                {
                    out << "10 of Hearts";
                    return out;
                }
                break;
        case 11:if(C.suit=='c'||C.suit=='C')
                {
                    out << "Jack of Clubs";
                    return out;
                }
                if(C.suit=='d'||C.suit=='D')
                {
                    out << "Jack of Diamonds";
                    return out;
                }
                if(C.suit=='s'||C.suit=='S')
                {
                    out << "Jack of Spades";
                    return out;
                }
                  if(C.suit=='h'||C.suit=='H')
                {
                    out << "Jack of Hearts";
                    return out;
                }
                break;
        case 12:if(C.suit=='c'||C.suit=='C')
                {
                    out << "Queen of Clubs";
                    return out;
                }
                if(C.suit=='d'||C.suit=='D')
                {
                    out << "Queen of Diamonds";
                    return out;
                }
                if(C.suit=='s'||C.suit=='S')
                {
                    out << "Queen of Spades";
                    return out;
                }
                  if(C.suit=='h'||C.suit=='H')
                {
                    out << "Queen of Hearts";
                    return out;
                }
                break;
        case 13:if(C.suit=='c'||C.suit=='C')
                {
                    out << "King of Clubs";
                    return out;
                }
                if(C.suit=='d'||C.suit=='D')
                {
                    out << "King of Diamonds";
                    return out;
                }
                if(C.suit=='s'||C.suit=='S')
                {
                    out << "King of Spades";
                    return out;
                }
                  if(C.suit=='h'||C.suit=='H')
                {
                    out << "King of Hearts";
                    return out;
                }
                break;
        default:
                out<< "2 of Clubs";
                return out;
                break;
    }
    out << "2 of Clubs";
    return out;
}

#include <iostream>
#include <string>
#include <random>
#include "Player.h"
using namespace std;

int coinToss(){
  
  return rand()%2;
}

void battle(Player *P1, Player *P2);
void add(Player *P1);
void trade(Player *P1, Player *P2);
void displayRound(int num);
bool attackDefendSelect();
void calculateDamage(Player *P1, Player *P2, bool isP1Attacking, bool isP2Attacking);

int main()
{

 srand(time(NULL));
 Player A("Daniel");
 Player B("Caleb");
 Player C("Starter Deck");
 Player *P1, *P2;
 int c1, c2 = 0, c3 = 0, pNum;

 cout << "Select a player:" << endl;
 cout << "1) " << A.getName() << endl;
 cout << "2) " << B.getName() << endl;
 cout << "3) Create Custom Player" << endl;
 cout << "4) End Program" << endl;

 cin >> c1;
 while(c1 < 1 || c1 > 4)
 {
  cout << "Please select a valid option (1-4):" << endl;
  cin.clear();
  cin.ignore();
  cin >> c1;
 }

 if(c1 == 1)
  P1 = &A;

 else if(c1 == 2)
  P1 = &B;
 
 else if(c1 == 3)
 {
  string pName;
  cin.ignore(1000, '\n');
  cout << "Enter player name:" << endl;

  getline(cin, pName);
  while(cin.fail())
  {
   cout << "Please enter a valid name:" << endl;
   cin.clear();
   cin.ignore();
   cin >> pName;
  }

  C.setName(pName);
  cout << "Player " << C.getName() << " created." << endl;
  P1 = &C;
 }

 while(c1 != 4 && c2 != 4)
 {
  cout << "Please select a valid option: (1-4):" << endl;
  cout << "1) Add Card" << endl;
  cout << "2) Trade Card With Other Player" << endl;
  cout << "3) Battle Other Player" << endl;
  cout << "4) End Program" << endl;

  cin >> c2;
  while(c2 < 1 || c1 > 4)
  {
   cout << "Please select a valid option (1-4):" << endl;
   cin.clear();
   cin.ignore();
   cin >> c1;
  }

  //Add
  if(c2 == 1)
   add(P1);

  //Trade
  else if(c2 == 2)
  {
   cout << "Which player would you like to trade with?" << endl;

   if(c1 == 1)
   {
    cout << "1) " << B.getName() << endl;
    cout << "2) " << C.getName() << endl;

    cin >> c3;
    while(c3 < 1 || c3 > 2)
    {
     cout << "Please select a valid option (1-2):" << endl;
     cin.clear();
     cin.ignore();
     cin >> c3;
    }

    if(c3 == 1)
     P2 = &B;

    else if(c3 == 2)
     P2 = &C;
   }

   if(c1 == 2)
   {
    cout << "1) " << A.getName() << endl;
    cout << "2) " << C.getName() << endl;

    cin >> c3;
    while(c3 < 1 || c3 > 2)
    {
     cout << "Please select a valid option (1-2):" << endl;
     cin.clear();
     cin.ignore();
     cin >> c3;
    }

    if(c3 == 1)
     P2 = &A;

    else if(c3 == 2)
     P2 = &C;
   }

   if(c1 == 3)
   {
    cout << "1) " << A.getName() << endl;
    cout << "2) " << B.getName() << endl;

    cin >> c3;
    while(c3 < 1 || c3 > 2)
    {
     cout << "Please select a valid option (1-2):" << endl;
     cin.clear();
     cin.ignore();
     cin >> c3;
    }

    if(c3 == 1)
     P2 = &A;

    else if(c3 == 2)
     P2 = &B;
   }
   trade(P1, P2);
  }

  //Battle
  else if(c2 == 3)
  {
   cout << "Which player would you like to battle?" << endl;

   if(c1 == 1)
   {
    cout << "1) " << B.getName() << endl;
    cout << "2) " << C.getName() << endl;

    cin >> c3;
    while(c3 < 1 || c3 > 2)
    {
     cout << "Please select a valid option (1-2):" << endl;
     cin.clear();
     cin.ignore();
     cin >> c3;
    }

    if(c3 == 1)
     P2 = &B;

    else if(c3 == 2)
     P2 = &C;
   }

   if(c1 == 2)
   {
    cout << "1) " << A.getName() << endl;
    cout << "2) " << C.getName() << endl;

    cin >> c3;
    while(c3 < 1 || c3 > 2)
    {
     cout << "Please select a valid option (1-2):" << endl;
     cin.clear();
     cin.ignore();
     cin >> c3;
    }

    if(c3 == 1)
     P2 = &A;

    else if(c3 == 2)
     P2 = &C;
   }

   if(c1 == 3)
   {
    cout << "1) " << A.getName() << endl;
    cout << "2) " << B.getName() << endl;

    cin >> c3;
    while(c3 < 1 || c3 > 2)
    {
     cout << "Please select a valid option (1-2):" << endl;
     cin.clear();
     cin.ignore();
     cin >> c3;
    }

    if(c3 == 1)
     P2 = &A;

    else if(c3 == 2)
     P2 = &B;
   }
   battle(P1, P2);
  }
 }
 return 0;
}

/*-----------------------*/
/*     FUNCTION LIST     */
/*-----------------------*/

/*-----------------------*/
/*         ADD           */
/*-----------------------*/

void add(Player *P1)
{
 int select, addATK, addDEF;
 string addName;

 P1->deckList();
 cout << "Which card would you like to replace?" << endl;
 cin >> select;

 while(select < 1 || select > 50)
 {
  cout << "Please enter a valid number for one of the cards listed (1-50):" << endl;
  cin.clear();
  cin.ignore();
  cin >> select;
 }

 cin.ignore(1000, '\n');
 cout << "What is the name of the card you would like to replace it with?" << endl;
 getline(cin, addName);

 while(cin.fail())
 {
  cout << "Please enter a valid name:" << endl;
  cin.clear();
  cin.ignore();
  cin >> addName;
 }

 cout << "What is the ATK value of the card you would like to add?" << endl;
 cin >> addATK;

 while(addATK < 0)
 {
  cout << "Please enter a valid ATK value (>= 0):" << endl;
  cin.clear();
  cin.ignore();
  cin >> addATK;
 }

 cout << "What is the DEF value of the card you would like to add?" << endl;
 cin >> addDEF;

 while(addDEF < 0)
 {
  cout << "Please enter a valid DEF value (>= 0):" << endl;
  cin.clear();
  cin.ignore();
  cin >> addDEF;
 }

 P1->setDeckCard(select - 1, addName, addATK, addDEF);
 cout << "Card replaced." << endl << endl;
}

/*-----------------------*/
/*         TRADE         */
/*-----------------------*/

void trade(Player *P1, Player *P2)
{
 int select1, select2, select3;

 P1->deckList();
 cout << "Which card would you like to offer for trade?" << endl;
 cin >> select1;

 while(select1 < 1 || select1 > 50)
 {
  cout << "Please enter a valid number for one of the cards listed (1-50):" << endl;
  cin.clear();
  cin.ignore();
  cin >> select1;
 }

 cout << P2->getName() << ", " << P1->getName() << " has offered you the opportunity to trade for their " << P1->getDeckName(select1 - 1) << " (" << P1->getDeckATK(select1 -1) << " ATK, " << P1->getDeckDEF(select1 -1) << " DEF), do you accept the trade request?" << endl << "1) yes" << endl << "2) no" << endl;
 cin >> select2;

 while(select2 < 1 || select2 > 2)
 {
  cout << "Please enter 1 for yes or 2 for no:" << endl;
  cin.clear();
  cin.ignore();
  cin >> select2;
 }

 if(select2 == 1)
 {
  P2->deckList();
  cout << "Which card would you like to offer for trade?" << endl;
  cin >> select3;

  while(select1 < 1 || select1 > 50)
  {
   cout << "Please enter a valid number for one of the cards listed (1-50):" << endl;
   cin.clear();
   cin.ignore();
   cin >> select3;
  }

  cout << P1->getName() << ", " << P2->getName() << " has offered to trade you their " << P2->getDeckName(select3 - 1) << " (" << P2->getDeckATK(select3 -1) << " ATK, " << P2->getDeckDEF(select3 -1) << " DEF) for your " << P1->getDeckName(select1 - 1) << " (" << P1->getDeckATK(select1 -1) << " ATK, " << P1->getDeckDEF(select1 -1) << " DEF). Do you accept?" << endl << "1) yes" << endl << "2) no" << endl;

  cin >> select2;
  while(select2 < 1 || select2 > 2)
  {
   cout << "Please enter 1 for yes or 2 for no:" << endl;
   cin.clear();
   cin.ignore();
   cin >> select2;
  }

  if(select2 == 1)
  {
   card swap;
   swap.name = P1->getDeckName(select1 -1);
   swap.ATK = P1->getDeckATK(select1 - 1);
   swap.DEF = P1->getDeckDEF(select1 - 1);

   P1->setDeckCard(select1 - 1, P2->getDeckName(select3 - 1), P2->getDeckATK(select3 - 1), P2->getDeckDEF(select3 - 1));

   P2->setDeckCard(select3 - 1, swap.name, swap.ATK, swap.DEF);

   cout << "Trade Complete." << endl;
  }
 }
}

/*-----------------------*/
/*     DISPLAY ROUND     */
/*-----------------------*/

void displayRound(int roundCount)
{
 cout << "Round " << roundCount << endl;
 roundCount++;
}

/*------------------------*/
/*  ATTACK DEFEND SELECT  */
/*------------------------*/

bool attackDefendSelect()
{
 int attackDefend;
 cout << "Would you like to attack or defend this round?" << endl;
 cout << "1) Attack" << endl << "2) Defend" << endl;
 cin >> attackDefend;

 while(attackDefend < 1 || attackDefend > 2)
 {
  cout << "Invalid action number. Please input the number of one of the actions listed." << endl;
  cin.clear();
  cin.ignore();
  cin >> attackDefend;
 }

 if(attackDefend == 1)
 {
  cout << "You are attacking this round." << endl;
  return true;
 }
 else
 {
  cout << "You are defending this round." << endl;
  return false;
 }
}

/*-----------------------*/
/*    CALCULATE DAMAGE   */
/*-----------------------*/

void calculateDamage(Player *P1, Player *P2, bool isP1Attacking, bool isP2Attacking)
{
 card P1card, P2card;
 if(isP1Attacking == true && isP2Attacking == true)
 {
  P1->Attack.dequeue(P1card);
  //P1->dequeueATK(P1card);//dequeue loads P1Card with the values of the card at the front of the queue, then deletes the front card in the queue
  cout << P1->getName() << " is attacking with " << P1card.name << " (" << P1card.ATK << " ATK)" << endl;
  P2->Attack.dequeue(P2card);
  //P2->dequeueATK(P2card);
  cout << P2->getName() << " is attacking with " << P2card.name << " (" << P2card.ATK << " ATK)" << endl;

  if(P1card.ATK > P2card.ATK)
  {
   P2->setLP(P1card.ATK - P2card.ATK);
   cout << P2->getName() << " took " << P1card.ATK - P2card.ATK << " damage." << endl;
  }

  else if(P1card.ATK < P2card.ATK)
  {
   P1->setLP(P2card.ATK - P1card.ATK);
   cout << P1->getName() << " took " << P2card.ATK - P1card.ATK << " damage." << endl;
  }

  else if(P1card.ATK == P2card.ATK)
  {
   cout << "Neither player took damage." << endl;
  }
 }

 else if(isP1Attacking == true && isP2Attacking == false)
 {
  P1->Attack.dequeue(P1card);
  //P1->dequeueATK(P1card);
  cout << P1->getName() << " is attacking with " << P1card.name << " (" << P1card.ATK << " ATK)" << endl;
  P2->Defense.dequeue(P2card);
  //P2->dequeueDEF(P2card);
  cout << P2->getName() << " is defending with " << P2card.name << " (" << P2card.DEF << " DEF)" << endl;

  if(P1card.ATK > P2card.DEF)
  {
   P2->setLP(P1card.ATK - P2card.DEF);
   cout << P2->getName() << " took " << P1card.ATK - P2card.DEF << " damage." << endl;
  }

  else if(P1card.ATK <= P2card.DEF)
  {
   cout << P2->getName() << " blocked " << P1->getName() << "'s attack." << endl;
  }
 }

 else if(isP1Attacking == false && isP2Attacking == true)
 {
  P1->Defense.dequeue(P1card);
  //P1->dequeueDEF(P1card);
  cout << P1->getName() << " is defending with " << P1card.name << " (" << P1card.DEF << " DEF)" << endl;
  P2->Attack.dequeue(P2card);
  //P2->dequeueATK(P2card);
  cout << P2->getName() << " is attacking with " << P2card.name << " (" << P2card.ATK << " ATK)" << endl;

  if(P2card.ATK > P1card.DEF)
  {
   P1->setLP(P1card.ATK - P2card.DEF);
   cout << P1->getName() << " took " << P2card.ATK - P1card.DEF << " damage." << endl;
  }

  else if(P1card.ATK <= P2card.DEF)
  {
   cout << P1->getName() << " blocked " << P2->getName() << "'s attack." << endl;
  }
 }

 else if(isP1Attacking == false && isP2Attacking == false)
 {
  P1->Defense.dequeue(P1card);
  //P1->dequeueDEF(P1card);
  cout << P1->getName() << " is defending with " << P1card.name << " (" << P1card.DEF << " DEF)" << endl;
  P2->Defense.dequeue(P2card);
  //P2->dequeueDEF(P2card);
  cout << P2->getName() << " is defending with " << P2card.name << " (" << P2card.DEF << " DEF)" << endl;

  cout << "Nothing happened." << endl;
 }
}





void battle(Player *P1, Player *P2)
{
 int p1cardNum, p2cardNum;
 card p1cardatk,p1carddef,p2cardatk,p2carddef,p1card,p2card;
 bool isP1Attacking, isP2Attacking;
 //displays initial lifepoints
 P1->displayLP();
 P2->displayLP();

 P1->draw(); //the draw() function should perform a linear search of the hand[5] using name (empty hand slots should be filled with Name: Empty, ATK: 0, DEF: 0, the constructor for player should initialize the hand completely filled with Empty), and every time it finds a slot containing Empty it should pop the deck and input the card information into that slot, then notify the player what they drew.  If the deck isEmpty(), the draw function should let the player know that they could not draw.
 P2->draw();

 Player *first, *second; //pointers will be used b/c it makes it easier to deal with the randomized start order

 int coin = coinToss(); //coinToss() uses RNG to randomly generate a 1 or 0

 if(coin == 0)
 {
  first = P1;
  second = P2;
  cout << first->getName() << " won the coin toss. They will go first." << endl;
 }
 else
 {
  first = P2;
  second = P1;
  cout << first->getName() << " won the coin toss. They will go first." << endl;
 }

 int roundCount = 1; //this keeps track of what round it is
 displayRound(roundCount);

 cout << first->getName() << "'s turn:" << endl;
 first->displayHand(); /*displayHand() should list all cards in the player's hand, including ATK & DEF values numbered from 1 to 5 for easier choice input when playing cards
example:
1) Dark Magician: 2500 ATK, 2000 DEF
2) Curse of Dragon: 2000 ATK, 1500 DEF
3) Mystical Elf: 800 ATK, 2000 DEF
4) Empty: 0 ATK, 0 DEF
5) Silver Fang: 1200 ATK, 800 DEF
*/
 first->playATK();
 first->playDEF();


 isP1Attacking= attackDefendSelect();
 //if(isP1Attacking==true){
  //first->dequeueATK(p1cardatk);
  //p1card=p1cardatk;
  //}
 //else{
  //first->dequeueDEF(p1carddef);
  //p1card=p1carddef;
  //}
 //cout<< p1cardNum<<endl;
 cout << second->getName() << "'s turn:" << endl;
 second->displayHand();

 second->playATK();
 second->playDEF();

 
 

 isP2Attacking=attackDefendSelect();
 //if(isP2Attacking==true){
  //second->dequeueATK(p2cardatk);
  //p2card=p2cardatk;
//}
 //else{
  //second->dequeueDEF(p2carddef);
  //p2card=p2carddef;
//}

 calculateDamage(first, second, isP1Attacking, isP2Attacking);

 while(first->getLP() > 0 && second->getLP() > 0) //isHandEmpty() should return true or false depending on whether a player's hand is completely filled with Empty
 {
  displayRound(roundCount);
  first->displayLP();
  second->displayLP();

  first->draw();
  second->draw();

  cout << first->getName() << "'s turn:" << endl;
  first->displayHand();

  first->playATK();
  first->playDEF();

  isP1Attacking= attackDefendSelect();
  /*if(isP1Attacking==true){
   first->dequeueATK(p1cardatk);
   p1card=p1cardatk;
   }
  else{
   first->dequeueDEF(p1carddef);
   p1card=p1carddef;
   }
 */

  cout << second->getName() << "'s turn:" << endl;
  second->displayHand();
  second->playATK();
  second->playDEF();
  isP2Attacking=attackDefendSelect();
  /*if(isP2Attacking==true){
   second->dequeueATK(p2cardatk);
   p2card=p2cardatk;
   }
  else{
   second->dequeueDEF(p2carddef);
   p2card=p2carddef;
   }
*/


  calculateDamage(first, second, isP1Attacking, isP2Attacking);

  if(first->getLP() <= 0 || first->isHandEmpty() == true)
   cout << first->getName() << " has been defeated. " << second->getName() << " is victorious." << endl;
  else if(second->getLP() <= 0 || second->isHandEmpty() == true)
   cout << second->getName() << " has been defeated. " << first->getName() << " is victorious." << endl;
 }
}


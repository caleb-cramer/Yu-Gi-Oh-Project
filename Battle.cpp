#include <iostream>
#include <string>
#include "Player.h"
using namespace std;


void displayRound(int num)
{
 cout << "Round " << num << endl;
 num++;
}


void attackDefendSelect(int &isAttacking)
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
  isAttacking = true;
  cout << "You are attacking this round." << endl;
 }
 else
 {
  isAttacking = false;
  cout << "You are defending this round." << endl;
 }
}


void calculateDamage(Player P1, Player P2, bool isP1Attacking, bool isP2Attacking)
{
 card P1card, P2card;

 if(isP1Attacking == true && isP2Attacking == true)
 {
  P1.ATK.dequeue(P1card); //dequeue loads P1Card with the values of the card at the front of the queue, then deletes the front card in the queue
  cout << P1.getName() << " is attacking with " << P1card.name << " (" << P1card.ATK << " ATK)" << endl;

  P2.ATK.dequeue(P2card);
  cout << P2.getName() << " is attacking with " << P2card.name << " (" << P2card.ATK << " ATK)" << endl;

  if(P1card.ATK > P2card.ATK)
  {
   P2.LP -= (P1card.ATK - P2card.ATK);
   cout << P2.name << " took " << P1card.ATK - P2card.ATK << " damage." << endl;
  }

  else if(P1card.ATK < P2card.ATK)
  {
   P1.LP -= (P2card.ATK - P1card.ATK);
   cout << P1.name << " took " << P2card.ATK - P1card.ATK << " damage." << endl;
  }

  else if(P1card.ATK == P2card.ATK)
  {
   cout << "Neither player took damage." << endl;
  }
 }

 else if(isP1Attacking = true && isP2Attacking = false)
 {
  P1.ATK.dequeue(P1card);
  cout << P1.getName() << " is attacking with " << P1card.name << " (" << P1card.ATK << " ATK)" << endl;

  P2.DEF.dequeue(P2card);
  cout << P2.getName() << " is defending with " << P2card.name << " (" << P2card.DEF << " DEF)" << endl;

  if(P1card.ATK > P2card.DEF)
  {
   P2.LP -= (P1card.ATK - P2card.DEF);
   cout << P2.name << " took " << P1card.ATK - P2card.DEF << " damage." << endl;
  }

  else if(P1card.ATK <= P2card.DEF)
  {
   cout << P2.name << " blocked " << P1.name << "'s attack." << endl;
  }
 }

 else if(isP1Attacking = false && isP2Attacking = true)
 {
  P1.DEF.dequeue(P1card);
  cout << P1.getName() << " is defending with " << P1card.name << " (" << P1card.DEF << " DEF)" << endl;

  P2.ATK.dequeue(P2card);
  cout << P2.getName() << " is attacking with " << P2card.name << " (" << P2card.ATK << " ATK)" << endl;

  if(P2card.ATK > P1card.DEF)
  {
   P2.LP -= (P1card.ATK - P2card.DEF);
   cout << P1.name << " took " << P2card.ATK - P1card.DEF << " damage." << endl;
  }

  else if(P1card.ATK <= P2card.DEF)
  {
   cout << P1.name << " blocked " << P2.name << "'s attack." << endl;
  }
 }

 else if(isP1Attacking = false && isP2Attacking = false)
 {
  P1.DEF.dequeue(P1card);
  cout << P1.getName() << " is defending with " << P1card.name << " (" << P1card.DEF << " DEF)" << endl;

  P2.DEF.dequeue(P2card);
  cout << P2.getName() << " is defending with " << P2card.name << " (" << P2card.DEF << " DEF)" << endl;

  cout << "Nothing happened." << endl;
 }
}



void battle(Player A, Player B)
{
 A.displayLP(A);
 B.displayLP(B);

 A.draw(); //the draw() function should perform a linear search of the hand[5] using name (empty hand slots should be filled with Name: Empty, ATK: 0, DEF: 0, the constructor for player should initialize the hand completely filled with Empty), and every time it finds a slot containing Empty it should pop the deck and input the card information into that slot, then notify the player what they drew.  If the deck isEmpty(), the draw function should let the player know that they could not draw.
 B.draw();

 Player *P1, *P2; //pointers will be used b/c it makes it easier to deal with the randomized start order

 int coin = coinToss(); //coinToss() uses RNG to randomly generate a 1 or 0
 if(coin == 0)
 {
  P1 = &A;
  P2 = &B;
  cout << P1->getName() << " won the coin toss. They will go first." << endl;
 }
 else
 {
  P1 = &B;
  P2 = &A;
  cout << P1->getName() << " won the coin toss. They will go first." << endl;
 }

 int roundCount = 1; //this keeps track of what round it is
 displayRound(roundCount);

 cout << P1->getName() << "'s turn:" << endl;
 P1->displayHand(); /*displayHand() should list all cards in the player's hand, including ATK & DEF values numbered from 1 to 5 for easier choice input when playing cards
example:
1) Dark Magician: 2500 ATK, 2000 DEF
2) Curse of Dragon: 2000 ATK, 1500 DEF
3) Mystical Elf: 800 ATK, 2000 DEF
4) Empty: 0 ATK, 0 DEF
5) Silver Fang: 1200 ATK, 800 DEF
*/

 playATK(*P1);
 playDEF(*P1);

 bool isP1Attacking, isP2Attacking;
 attackDefendSelect(isP1Attacking);

 cout << P2->getName() << "'s turn:" << endl;
 P1->displayHand();

 playATK(*P2)
 playDEF(*P2)

 attackDefendSelect(isP2Attacking);

 calculateDamage(*P1, *P2, isP1Attacking, isP2Attacking)

 while(P1->getLP() > 0 || P2->getLP() > 0 || P1->isHandEmpty() == false || P2->isHandEmpty() == false) //isHandEmpty() should return true or false depending on whether a player's hand is completely filled with Empty
 {
  displayRound(roundCount);
  A.displayLP(*P1);
  B.displayLP(*P2);

  P1->draw();
  P2->draw();

  cout << P1->getName() << "'s turn:" << endl;
  P1->displayHand();

  playATK(*P1);
  playDEF(*P1);

  attackDefendSelect(isP1Attacking);

  cout << P2->getName() << "'s turn:" << endl;
  P1->displayHand();

  playATK(*P2)
  playDEF(*P2)

  attackDefendSelect(isP2Attacking);

  calculateDamage(*P1, *P2, isP1Attacking, isP2Attacking)

  if(P1->getLP() <= 0 || P1->isHandEmpty() == true)
   cout << P1->getName << " has been defeated. " << P2->getName << " is victorious." << endl;
  else if(P2->getLP() <= 0 || P2->isHandEmpty() == true)
   cout << P2->getName << " has been defeated. " << P1->getName << " is victorious." << endl;
 }
}

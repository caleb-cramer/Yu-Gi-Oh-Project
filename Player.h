#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <random>
#include <string>
using namespace std;

struct card
{
 string name;
 int ATK;
 int DEF;
};


class DynCardQueue
{
private:
 struct QueueNode
 {
  card value;
  QueueNode *next;
 };

 QueueNode *front;
 QueueNode *rear;
 int numItems;

public:
 DynCardQueue()
 {
  front = nullptr;
  rear = nullptr;
  numItems = 0;
 }

 ~DynCardQueue()
 {
  clear();
 }

 void enqueue(card ADcard)
 {
  QueueNode *newNode = nullptr;

  newNode = new QueueNode;
  newNode->value.name = ADcard.name;
  newNode->value.ATK = ADcard.ATK;
  newNode->value.DEF = ADcard.DEF;
  newNode->next = nullptr;

  if(isEmpty())
  {
   front = newNode;
   rear = newNode;
  }

  else
  {
   rear->next = newNode;
   rear = newNode;
  }

  numItems++;
 }

 void dequeue(card &ADcard)
 {
  QueueNode *temp = nullptr;

  if(isEmpty())
   cout << "The queue is empty.\n";

  else
  {
   ADcard.name = front->value.name;
   ADcard.ATK = front->value.ATK;
   ADcard.DEF = front->value.DEF;

   temp = front;
   front = front->next;
   delete temp;

   numItems--;
  }
 }

 bool isEmpty() const
 {
  bool status;

  if(numItems > 0)
   status = false;
  else
   status = true;
  return status;
 }

 void clear()
 {
  card value;

  while(!isEmpty())
   dequeue(value);
 }
};

class Player
{
private:
 string name;
 int LifePoints = 8000;
 card hand[5] = {{"Empty", 0, 0}, {"Empty", 0, 0}, {"Empty", 0, 0}, {"Empty", 0, 0}, {"Empty", 0, 0}};



public:

  DynCardQueue Defense;
  DynCardQueue Attack;

 card deck[50] = {{"Hitotsu-Me Giant", 1200, 1000}, {"Dark Magician", 2500, 2100}, {"Gaia the Fierce Knight", 2300, 2100}, {"Mammoth Graveyard", 1200, 800}, {"Silver Fang", 1200, 800}, 
 {"Curtain of the Dark Ones", 600, 500}, {"Tomozaurus", 500, 400}, {"Dark Gray", 800, 900}, {"Nemuriko", 800, 700}, {"Fiend's Hand", 600, 600}, {"Curse of Dragon", 2000, 1500}, 
 {"Mystical Elf", 800, 2000}, {"One-Eyed Shield Dragon", 700, 1300}, {"Ansatsu", 1700, 1200}, {"Beaver Warrior", 1200, 1500}, 
 {"Darkworld Thorns", 1200, 900}, {"Giant Soldier of Stone", 1300, 2000}, {"Lesser Dragon", 1200, 1000}, {"Misairuzame", 1400, 1600}, {"Red Eyes B. Dragon", 2400, 2000}, {"Rogue Doll", 1600, 1000}, {"Sand Stone", 1300, 1600}, {"Succubus Knight", 1650, 1300}, {"The Wandering Doomed", 800, 600}, 
 {"Witty Phantom", 1400, 1300}, {"Cyber Soldier of Darkworld", 1400, 1200}, {"Great White", 1600, 800}, {"Hercules Beetle", 1500, 2000}, 
 {"Mystic Clown", 1500, 1000}, {"Temple of Skulls", 900, 1300}, {"Tiger Axe", 1300, 1100}, {"Ancient Elf", 1450, 1200}, {"Armored Lizard", 1500, 1200}, {"D. Human", 1300, 1100}, {"Dark Assailant", 1200, 1200}, {"Flame Viper", 400, 450}, {"Harpie Lady", 1300, 1400}, {"Summoned Skull", 2500, 1200}, {"Winged Dragon, Guardian of the Fortress #1", 1400, 1200}, {"Killer Needle", 1200, 1000}, {"Baby Dragon", 1200, 700}, 
 {"Cyber Commando", 750, 700}, {"Kuriboh", 300, 200}, {"Blue-Eyes White Dragon", 3000, 2500}, {"Labyrinth Wall", 0, 3000}, {"Skull Servant", 300, 200}, {"Celtic Guardian", 1400, 1200}, {"Feral Imp", 1300, 1400}, {"Jerry Beans Man", 1750, 0}, {"Sonic Maid", 1200, 900}};
 
 Player(string pName)
 {
  name = pName;
 }

// should check to see if any spots in hand are empty and then draw cards from thier mainDeck queue.
 void draw(){
  for(int i=0;i<5;i++){
    if(hand[i].name=="Empty" && hand[i].ATK==0 && hand[i].DEF==0){
      hand[i] = deck[rand()%50+1];
    }
  }
 }

 string getName()
 {
  return name;
 }

 void setName(string playerName){
  name=playerName;
 }

 int getLP()
 {
  return LifePoints;
 }

 void setLP(int num)
 {
  LifePoints -= num;
 }

 void displayLP()
 {
  cout << name << " LP: " << LifePoints << endl;
 }

 void displayHand() //part of the Player class
 {
  cout << name << "'s hand:" << endl;
  for(int i = 0; i < 5; i++)
   cout << i + 1 << ") " << hand[i].name << ": " << hand[i].ATK << " ATK, " << hand[i].DEF << " DEF" << endl;
  cout << endl;
 }

 void deckList() //part of the Player class
 {
  cout << name << "'s deck:" << endl;
  for(int i = 0; i < 50; i++)
   cout << i + 1 << ") " << deck[i].name << ": " << deck[i].ATK << " ATK, " << deck[i].DEF << " DEF" << endl;
  cout << endl;
 }

 string getDeckName(int pos) //part of the Player class
 {
  return deck[pos].name;
 }

 int getDeckATK(int pos) //part of the Player class
 {
  return deck[pos].ATK;
 }

 int getDeckDEF(int pos) //part of the Player class
 {
  return deck[pos].DEF;
 }

 void setDeckCard(int pos, string addName, int addATK, int addDEF) //part of the Player class
 {
  deck[pos].name = addName;
  deck[pos].ATK = addATK;
  deck[pos].DEF = addDEF;
 }

 string getCardName(int pos)
 {
  return hand[pos].name;
 }

 int getCardATK(int pos)
 {
  return hand[pos].ATK;
 }

 int getCardDEF(int pos)
 {
  return hand[pos].DEF;
 }

 void setCard(int pos, string cardName, int cardATK, int cardDEF)
 {
  hand[pos].name = cardName;
  hand[pos].ATK = cardATK;
  hand[pos].DEF = cardDEF;
 }

 void enqueueATK(card ADcard)
 {
  Attack.enqueue(ADcard);
 }

 void dequeueATK(card ADcard)
 {
  Attack.dequeue(ADcard);
  //cout << ADcard.name << endl;
 }

 void enqueueDEF(card ADcard)
 {
  Defense.enqueue(ADcard);
 }

 void dequeueDEF(card ADcard)
 {
  Defense.dequeue(ADcard);
  //cout << ADcard.name << endl;
 }

 void playATK()
 {
  int cardNum; //this is used to keep track of which card in their hand the player wants to play
  cout << "Select a card to play in Attack Mode: ";
  cin >> cardNum;
  while (cardNum < 1 || cardNum > 5 || getCardName(cardNum - 1) == "Empty") //getCardName(int num) returns Hand.name[num] (the name of the card corresponding to that position in the hand array)
  {
   cout << "Invalid card. Please input the number of one of the cards listed in your hand. (Empty does not count as a card)" << endl;
   cin.clear();
   cin.ignore();
   cin >> cardNum;
  }
  cout << "You played " << getCardName(cardNum - 1) << " in Attack Mode."<<endl;
  Attack.enqueue(hand[cardNum - 1]); //enqueue(int num) creates and appends new queue node with Hand.name[num], Hand.ATK[num], Hand.DEF[num]
  setCard(cardNum - 1, "Empty" , 0, 0); //setCard(int num, string cardName, int Attack, int Defense) sets Hand.name[num] = cardName, Hand.ATK[num] = Attack, Hand.DEF[num] = Defense
 }


 void playDEF()
 {
  int cardNum;
  cout << "Select a card to play in Defense Mode: ";
  cin >> cardNum;
  while (cardNum < 1 || cardNum > 5 || getCardName(cardNum - 1) == "Empty")
  {
   cout << "Invalid card. Please input the number of one of the cards listed in your hand. (Empty does not count as a card)" << endl;
   cin.clear();
   cin.ignore();
   cin >> cardNum;
  }
  cout << "You played " << getCardName(cardNum - 1) << " in Defense Mode."<<endl;
  Defense.enqueue(hand[cardNum - 1]);
  setCard(cardNum - 1, "Empty" , 0, 0);
 }

 bool isHandEmpty(){
  int i=0;
  do
   {
    i++;     
   } while (hand[i].name=="Empty"&&i<5);
  if (i==4)
  {
    return true;
  }
  else
    return false;
}

};

#endif

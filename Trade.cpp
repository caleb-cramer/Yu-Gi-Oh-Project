void deckList(); //part of the Player class
{
 for(int i = 0; i < 50; i++)
  cout << i + 1 << ") " << Deck[i].name << " " << Deck[i].ATK << " ATK, " << Deck[i].DEF << " DEF" << endl;
}

string getDeckName(int pos); //part of the Player class
{
 return Deck[pos].name;
}

int getDeckATK(int pos); //part of the Player class
{
 return Deck[pos].ATK;
}

int getDeckDEF(int pos); //part of the Player class
{
 return Deck[pos].DEF;
}

void setDeckCard(int pos, string setName, int setATK, int setDEF); //part of the Player class
{
 Deck[pos].name = setName;
 Deck[pos].ATK = setATK;
 Deck[pos].DEF = setDEF;
}

void trade(Player *P1, *P2);
{
 int select1, select2, select3;

 cout << "Which card would you like to offer for trade?" << endl;
 P1->deckList();
 cin >> select1;

 while(select1 < 1 || select1 > 50)
 {
  cout << "Please enter a valid number for one of the cards listed (1-50):" << endl;
  cin.clear();
  cin.ignore();
  cin >> select1;
 }

 cout << P2->getName() << ", " << P1->getName() << " has offered you the opportunity to trade for" << getDeckName(select1) << ", do you accept the trade request?" << endl << "1) yes" << endl << "2) no" << endl;
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
  cout << "Which card would you like to offer for trade?" << endl;
  P2->deckList();
  cin >> select3;

  while(select1 < 1 || select1 > 50)
  {
   cout << "Please enter a valid number for one of the cards listed (1-50):" <<< endl;
   cin.clear();
   cin.ignore();
   cin >> select3;
  }

  cout << P1->getName << ", " << P2->getName << " has offered to trade you their " << P2->getDeckName(select3 - 1) << " for your " << P1->getDeckName(select1 - 1) << ". Do you accept?" << endl << "1) yes" << endl << "2) no" << endl;

  cin << select2;
  while(select2 < 1 || select2 > 2)
  {
   cout << "Please enter 1 for yes or 2 for no:" << endl;
   cin.clear();
   cin.ignore();
   cin >> select2;
  }

  if(select2 == 1)
  {
   Card swap;
   swap.name = P1->getDeckName(select1 -1);
   swap.ATK = P1->getDeckATK(select1 - 1);
   swap.DEF = P1->getDeckDEF(select1 - 1);

   P1->setDeckCard(select1 - 1, P2->getDeckName(select3 - 1), P2-> getDeckATK(select3 - 1), P2->getDeckDEF(select3 - 1);

   P2->setDeckCard(select3 - 1, swap.name, swap.ATK, swap.DEF);

   cout << "Card replaced." << endl;
  }
 }
}

void add(Player *P1)
{
 int select, addATK, addDEF;
 string addName;

 cout << "Which card would you like to replace?" << endl;
 P1->deckList;
 cin >> select;

 while(select < 1 || select > 50)
 {
  cout << "Please enter a valid number for one of the cards listed (1-50):" << endl;
  cin.clear();
  cin.ignore();
  cin >> select;
 }

 cout << "What is the name of the card you would like to replace it with?" << endl;
 cin >> addName;

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

 setDeckCard(select - 1, addName, addATK, addDEF);
 cout << "Card replaced." << endl;
}

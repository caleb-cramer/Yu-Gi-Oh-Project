#include <iostream>
#include <string>
using namespace std;

struct card
{
 string name;
 int ATK;
 int DEF;
};

int main()
{
 card starterDeck[50] = {{"Hitotsu-Me Giant", 1200, 1000}, {"Dark Magician", 2500, 2100}, {"Gaia the Fierce Knight", 2300, 2100}, {"Mammoth Graveyard", 1200, 800}, {"Silver Fang", 1200, 800}, {"Curtain of the Dark Ones", 600, 500}, {"Tomozaurus", 500, 400}, {"Dark Gray", 800, 900}, {"Nemuriko", 800, 700}, {"Fiend's Hand", 600, 600}, {"Curse of Dragon", 2000, 1500}, {"Mystical Elf", 800, 2000}, {"One-Eyed Shield Dragon", 700, 1300}, {"Ansatsu", 1700, 1200}, {"Beaver Warrior", 1200, 1500}, {"Darkworld Thorns", 1200, 900}, {"Giant Soldier of Stone", 1300, 2000}, {"Lesser Dragon", 1200, 1000}, {"Misairuzame", 1400, 1600}, {"Red Eyes B. Dragon", 2400, 2000}, {"Rogue Doll", 1600, 1000}, {"Sand Stone", 1300, 1600}, {"Succubus Knight", 1650, 1300}, {"The Wandering Doomed", 800, 600}, {"Witty Phantom", 1400, 1300}, {"Cyber Soldier of Darkworld", 1400, 1200}, {"Great White", 1600, 800}, {"Hercules Beetle", 1500, 2000}, {"Mystic Clown", 1500, 1000}, {"Temple of Skulls", 900, 1300}, {"Tiger Axe", 1300, 1100}, {"Ancient Elf", 1450, 1200}, {"Armored Lizard", 1500, 1200}, {"D. Human", 1300, 1100}, {"Dark Assailant", 1200, 1200}, {"Flame Viper", 400, 450}, {"Harpie Lady", 1300, 1400}, {"Summoned Skull", 2500, 1200}, {"Winged Dragon, Guardian of the Fortress #1", 1400, 1200}, {"Killer Needle", 1200, 1000}, {"Baby Dragon", 1200, 700}, {"Cyber Commando", 750, 700}, {"Kuriboh", 300, 200}, {"Blue-Eyes White Dragon", 3000, 2500}, {"Labyrinth Wall", 0, 3000}, {"Skull Servant", 300, 200}, {"Celtic Guardian", 1400, 1200}, {"Feral Imp", 1300, 1400}, {"Jerry Beans Man", 1750, 0}, {"Sonic Maid", 1200, 900}};

 for(int i = 0; i < 50; i++)
  cout << starterDeck[i].name << ": " << starterDeck[i].ATK << " ATK, " << starterDeck[i].DEF << " DEF" << endl;
 
 return 0;
}

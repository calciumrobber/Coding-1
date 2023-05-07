#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// I'm not gonna lie, I decided to just have fun with this. It should have all of the required elements
// but I changed some of the values
// I have the normal one too if you want it.

int main() {
  srand(time(0));
  string input;
  int kill = 0;
  int die = 0;
  
  // welcome
  cout << "Welcome Adventurer! What is your name?\n";
  string playerName;
  cin >> playerName;
  cout << "Welcome " << playerName << "! This is a game of chance. If your opponent's attack is higher than your block, then you take damage. Kill your opponent to win.\n\n";
  // Class Selection
  cout << "First, choose a class:\n Barbarian    Wizard    Info\n";
  string playerClass;
  cin >> playerClass;
  if(playerClass == "Info"){
    cout << "Barbarians have more health and a stronger attack, however a much weaker defense.\nWizards have stronger defense but less health and a weaker attack. However, wizards have a 10% chance of using a regeration potion.\n";
    cout << "Pick a class:";
    cin >> playerClass;
    }

  do{
    // reset stats and defining
    int turns = 0;
    
    int monHealth = 15;
    int monAttack = 0;
    int monBlock = 0;

    int pHealth = 10;
    int cAttack = 5;
    int pAttack = 0;
    int cBlock = 6;
    int pBlock = 0;
    
    if(playerClass == "Barbarian"){
      pHealth = 14;
      cAttack = 7;
      cBlock = 2;
    }
  //start game
    do{
      turns += 1;
      cout << "\nTurn " << turns << "\n";
  //monster's turn
      monAttack = rand() % 5 + 1;
      cout << "The orc attacks for " << monAttack << " points.\n";
      pBlock = rand() % cBlock + 1;
      cout << "You block " << pBlock << " points.\n";
      //Sucessful Block
      if(pBlock >= monAttack){
        cout << "You successfully blocked! Your health is still at " << pHealth << ".\n\n";
      }
      // Failed Block, Damage Dealt, Potion Chance
      else{
        pHealth = pHealth - monAttack;
        cout << "The attack hits. Your health is " << pHealth << ".\n\n";
        int potion = rand() % 10 + 1;
        if(playerClass == "Wizard" && potion == 10){
          pHealth = monAttack / 2 + pHealth;
          cout << "You used a potion of regeneration to gain " << monAttack / 2 << " health points back.\n\n";
        }
      }
      //Player Health check after monster attack
      if(pHealth <= 0){
        break;
      }
  //player's turn
      pAttack = rand() % cAttack + 1;
      cout << "You attack for " << pAttack << " points.\n";
      monBlock = rand() % 4 + 1;
      cout << "The orc blocked for " << monBlock << " points.\n";
      //Failed Attack
      if(monBlock >= pAttack){
        cout << "You missed! The orc's health is still at " << monHealth << ".\n\n";
      }
      // Successful Attack
      else{
        monHealth = monHealth - pAttack;
        cout << "Your attack hits. The orc's health is " << monHealth << ".\n\n";
      }
    } while (pHealth > 0 && monHealth > 0); // keeps looping until the player or monster is dead, not turn based (sorry)

  //End Results
    if(pHealth > 0 && monHealth <= 0){
      cout << "You slayed the orc!\n";
      kill ++;
    }
    else if(pHealth <= 0 && monHealth > 0){
      cout << "You were slain.\n";
      die ++;
    }

    cout << "\n\nPlay Again? Y/N\n";
    cin >> input;
    
 }while(input != "n" && input != "N");

  //Ending Statistics
  cout << "Well done " << playerName << "! Here are your final stats as a " << playerClass << ":\n";
  cout << "You killed the orc " << kill << " times.\n";
  cout << "You died " << die << " times.\n";
}
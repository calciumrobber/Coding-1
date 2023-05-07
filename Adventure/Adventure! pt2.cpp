#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int health = 30;
int totalTreasure = 0;

void story(){
  cout << "Sigh... you know the drill by now... welcome to this dungeon crawl... don't die and you can keep your gold, I guess.\n";
}

bool askYN(string question = "Would you like to continue adventuring? (y/n)\n"){
  while(true){
    cout << question;
    char input;
    cin >> input;

    if(input == 'y'){
      return true;
    }
    else if(input == 'n'){
      return false;
    }
  }
}

int rollDice(int sides = 6){
  return rand() % sides + 1;
}

void ending(){
  cout << "Well done... you died, idiot.\n";
  totalTreasure = 0;
  cout << "You've got " << totalTreasure << " coins. ur broke lol.\n";
}

void adventure(){
  int attack = rollDice();
  int block = rollDice();
  int treasure = rollDice();
  if(block >= attack){
    cout << "You successfully blocked!\n";
    totalTreasure = totalTreasure + treasure;
  }
  else if(block < attack){
    cout << "You failed to block!\n";
    health = health - attack;
  }
  cout << "You now have " << health << " hit points left.\n";
  cout << "You have " << totalTreasure << " coins.\n";
}


int main() {
  srand(time(0));
  story();
  while(askYN()){
    adventure();
    if(health <= 0){
      ending();
      break;
    }
    
  }
  if(health > 0){
    cout << "You escaped with " << health << " hit points left and " << totalTreasure << " coins in your pocket.\n";
  }
}
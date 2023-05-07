#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

string diseases[] = {"Dysentery", "Smallpox", "Measles", "Mumps", "Influenza", "Cholera", "Scurvy", "Mountain Fever", "Diptheria", "Tuberculosis"};
int randRoll;


class settler {
public:
string name;
int food;
int distance;
int totalDistance;
bool disease;
bool alive;
int weeks;
string diseaseCaught;



settler() {
  name = "John Doe";
  food = 0;
  distance = 0;
  disease = false;
  alive = true;
  weeks = 0;
}

settler(string givenName, int givenFood) {
  name = givenName;
  food = givenFood;
  distance = 0;
  disease = false;
  alive = true;
  weeks = 0;
}

void status() {
  cout << name << " has traveled " << distance << " miles. " << 2170 - totalDistance << " left.\n";
  cout << "They have " << food << " pounds of food left.\n\n";
}

void randomEvent() {
  randRoll = rand() % 8;
  if(randRoll == 0) {
    diseaseCaught = diseases[rand() % 10];
    cout << "\033[91m" << name << " has contracted " << diseaseCaught << ".\n\n" << "\033[0m";
    disease = true;
  }
  else if(randRoll == 1) {
    cout << name << " watches 2 strangers approach from down the road. The man looks to be carrying a large bag over his shoulder and the woman has a large basket in her hands. ";
    cout << "The woman steps forward first. \n\n     'My husband and I live about a quarter mile through these woods here. You are heading West on the Trail, right?' she said. \n";
    cout << "She steps forward, extending the basket. \n     'We know how hard the journey is so we like to help any travellers we see come through here. Please take it, I insist.'\n";
    cout << name << " has gained 80 pounds of food.\n\n";
    food = food + 80;
  }
  else if(randRoll == 2) {
    cout << name << " sees a group of 3 men approaching from down the road. All 3 look rather scrappy, one seems to be limping slightly.\n";
    cout << "One man steps forward first. He insults " << name << " and their family. A heated debate starts.\n" << name << " doesn't notice the limping man slip behind them until the click of a cocked gun sound behind their head.\n";
    cout << "They can only watch as the 3 men take as much food as they can carry.\n";
    cout << name << " lost 120 pounds of food.\n\n";
    food = food - 120;
  }
  else if(randRoll == 3) {
    cout << "Dark, heavy, grey stormclouds roll off the horizon. Lightning cracks through the torrential downpour, spooking the oxen and the horses.\n";
    cout << name << " manages to control the livestock, but is unable to travel as fast as usual.\n\n";
    totalDistance = totalDistance - 40;
    distance = distance - 40;
  }
  else if(randRoll == 4) {
    cout << name << " is ambushed by a grey wolf. Leaping out of the brush, it bites down on their arm, ripping it to shreds.\n";
    cout << "They scramble for their gun, pointing it at the wolf's head.\n";
    cout << "BANG!\n";
    cout << name << " has to travel slower than usual for a few days, nursing their wound. But, after harvesting the wolf and curing as much as possible, they now have an extra 40 pounds of food.\n\n";
    food = food + 40;
    totalDistance = totalDistance - 80;
    distance = distance - 80;
  }
  else if(randRoll == 5) {
    cout << "A low creak is all the warning that " << name << " got before one of the wheels on the wagon split apart with a loud crack.\n";
    cout << "The wagon wobbled precariously as it slowed to a halt. " << name << " spends the rest of the day repairing and replacing the wheel.\n";
    cout << "They lost a full day's worth of travel.\n\n";
    totalDistance = totalDistance - 20;
    distance = distance - 20;
  }
  else if(randRoll == 6) {
    cout << name << " spends an hour tracking some of the elk they had heard calling earlier. Eventually they find them.\n";
    cout << "With a successful rifle shot to the neck, the elk collapses. \nThe successful hunt ends up yielding 220 pounds of fresh meat.\n\n";
    food = food + 220;
  }
  else if(randRoll == 7) {
    cout << name << " wanders through the trees, eyes flicking across the ground, searching. After a few moments, they find it!\n";
    cout << "They proudly pile a large stack of edible mushrooms and herbs into their basket. By the end, they had amassed 30 pounds of foregables\n\n";
    food = food + 40;
  }
}


}; // end of class

settler settlers[5];



void startNextWeek() {
  cout << "\n\nAnother week passes...\n\n";
  for(int i = 0; i < 5; i++) {
    if(settlers[i].alive == false) {
      continue;
    }
    randRoll = rand() % 2;
    if(settlers[i].disease == true && randRoll == 1) {
      cout << "\033[31m" << settlers[i].name << " has succumbed to " << settlers[i].diseaseCaught << " and died.\n\n" << "\033[0m";
      settlers[i].alive = false;
    }
    settlers[i].weeks++;
    settlers[i].food -= rand() % 60 + 90;
    settlers[i].distance = rand() % 100 + 50; 
    settlers[i].totalDistance = settlers[i].totalDistance + settlers[i].distance;

    //random event roll
    randRoll = rand() % 10;
    if(randRoll == 5) {
      settlers[i].randomEvent();
    }

    // death check
    if(settlers[i].food <= 0) {
      cout << "\033[31m" << settlers[i].name << " has run out of food and starved to death.\n";
      cout << "\033[91m" << "They traveled " << settlers[i].totalDistance << " miles and survived " << settlers[i].weeks << " weeks.\n\n" << "\033[0m";
      settlers[i].alive = false;
    }
    if(settlers[i].totalDistance >= 2170 && settlers[i].alive == true) {
      cout << settlers[i].name << " has arrived in Oregon City, Oregon. They completed their journey with " << settlers[i].food << " pounds of food left.\n";
      cout << "Welcome to your dream home in the West.\n\n";
      settlers[i].alive = false;
    }
    if(settlers[i].alive == true){
      settlers[i].status();
    }
    
  }
  
}


bool askYN(string question = "Continue...? (y/n)\n") {
  while(true) {
    cout << question;
    char input;
    cin >> input;

    if(input == 'y') {
      return true;
    }
    else if(input == 'n') {
      return false;
    }
  }
}




int main() {
  srand(time(0));
 

  cout << "Welcome to the Oregon Trail!\n\n\n";

  string settlerNames[] = {"Abigail", "Benjamin", "Mary", "Charlotte", "Edward", "John", "Thomas", "William", "James", "Elizabeth", "Alice", "Arthur", "Emma", "Charles", "Margaret"};
  for(int i = 0; i < 5; i++) {
    settlers[i] = settler(settlerNames[rand() % 15], rand() % 300 + 1600);
    cout << settlers[i].name << " brought " << settlers[i].food << " pounds of food.\n";
  }
  cout << "\nThey are all ready to embark on their journey!\n\n";
  while(askYN()) {
    startNextWeek();
  }    
  
}
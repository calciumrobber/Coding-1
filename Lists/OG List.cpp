#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  srand(time(0));

  // for(int counter = 0; counter < 10; counter += 1){
  //   cout << rand() % 10 + 1 << "\n";
  // }

  // int seedCounter = 10;
  // while(seedCounter > 0){
  //   seedCounter --;
  //   cout << "I walked 3 feet left.\n";
  //   cout << "Seed planted.\n";
  //   cout << seedCounter << " left.\n";
  // }

  // for(int seedCount = 10; seedCount >= 0; seedCount--){
  //   cout << seedCount << " left.\n";
  //   cout << "I walked 4 feet left.\n";
  //   cout << "Seed planted.\n";
  // }

  // cout << "\n\n\n";

  // while(true){
  //   cout << "Press Q to quit.\n";
  //   char input;
  //   cin >> input;
  //   if(input == 'q'){
  //     break;
  //   }
  // }

  string favGames[100];

  int index = 0;
  string input;
  
  
  while(true){
    cout << "\nWhat would you like to do?\n";
    cout << "Type 'quit' to quit.\n";
    cout << "Type 'add' to add a game.\n";
    cout << "Type 'bulkadd' to add multiple entries at the same time.\n";
    cout << "Type 'show' to show the list of games.\n";
    cout << "Type 'edit' to edit the last entry.\n";
    cout << "Type 'find' to edit a specific entry.\n";

    
    cin >> input;

    if(input == "quit"){
      cout << "\nThanks for playing!\n";
      break;
    }
    if(input == "add"){
      cout << "\nType the name of the game you want:\n";
      cin >> input;
      favGames[index++] = input; // make index point to the nest spot
      // index++; instead of [index++]
    }
    
    if(input == "show"){
      cout << "\nHere are your favorite games:\n";
      for(int i = 0; i < index; i++){
        cout << i + 1 << ". " << favGames[i] << "\n";
      }
    }

    if(input == "edit"){
      cout << "Please re-enter last game\n";
      cin >> input;
      favGames[index - 1] = input;
    }

    if(input == "find"){
      cout << "What game would you like to edit?\n";
      cin >> input;
      for(int i = 0; i < index; i++){
        if(favGames[i] == input){
          cout << "Found it!\n";
          cout << "What would you like to change this to?\n";
          cin >> input;
          favGames[i] = input;
        }
      }
      
    }
    if(input == "bulkadd"){
      cout << "\nType the name of the game you want:\n";
      while(input != "quit"){
        cin >> input;
        if(input == "quit"){
          break;
        }
        favGames[index++] = input; 
      }
    }
    
    
  }
     
}

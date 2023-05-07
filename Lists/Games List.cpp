#include <iostream>
#include <fstream>
using namespace std;

string favGames[100];
int index = 0;

void load() {
  string line;
  ifstream gamesList("list.txt");

  if(gamesList.is_open()) {
    while(getline(gamesList, line)) {
      favGames[index++] = line;
    }
  }
  else {
    cout << "File could not be loaded.\n";
  }
  
}

void save() {
  ofstream gamesList;
  gamesList.open("list.txt");
  for (int i = 0; i < index; i++) {
    gamesList << favGames[i] << "\n";
  }
  gamesList.close();
}

void add() {
  cout << "What would you like to add?\n";
  cout << "Type 'quit' to exit add mode.\n";
  while(true) {
    string input;
    cin >> input;
    if(input == "quit") {
      break;
    }
    favGames[index++] = input;    
  }
  save();
}

void clear() {
  index = 0;
  save();
}

void show() {
  if(index == 0) {
      cout << "\nSorry, looks like you don't have anything added to your list. Please try again.\n";
      return;
  }
  cout << "Here is your list of games!\n";
  for(int i = 0; i < index; i++) {    
    cout << i + 1 << ". " << favGames[i] << "\n";
  }
}

void remove() {
  string input;
  cout << "What game would you like to remove?\n";
  cin >> input;
  for(int i = 0; i < index; i++) {
    if(favGames[i] == input) {
      cout << "Found it!\n";
      cout << "Are you sure you want to remove it? This action cannot be undone. (y/n)\n";
      cin >> input;
      if(input == "y") {
        while(i < index) {
          favGames[i] = favGames[i + 1];
          i++;
        }
        index--;
      }
      else if(input == "n") {
        break;
      }
    }
  }
  save();
}

void edit() {
  string input;
  cout << "What game would you like to edit?\n";
  cin >> input;
  for(int i = 0; i < index; i++) {
    if(favGames[i] == input) {
      cout << "Found it!\n";
      cout << "What would you like to change it to?\n";
      cin >> input;
      favGames[i] = input;
    }
  }
  save();
}

int main() {
  load();
  while(true){
    cout << "\nWhat would you like to do?\n";
    cout << "Type 'add' to add games to your list.\n";
    cout << "Type 'edit' to search and edit a specific game.\n";
    cout << "Type 'clear' to clear the entire list.\n";
    cout << "Type 'show' to show entire games list.\n";
    cout << "Type 'remove' to delete a game from your list.\n";
    cout << "Type 'quit' to quit.\n";

    
    string input;
    cin >> input;
    if(input == "add") {
      add();
    }
    if(input == "edit") {
      edit();
    }
    if(input == "clear") {
      clear();
    }
    if(input == "show") {
      show();
    }
    if(input == "remove") {
      remove();
    }
    if(input == "quit") {
      break;
    }
  }
  
  
}  //end of main
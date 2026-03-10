#include <cstring>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <sstream>

void echo(std::string);
void type(std::string);

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  while(true){
  
  std::cout << "$ ";

  std::string userInput;

  // get the user input
  std::getline(std::cin, userInput);

  // exiting the shell
  if (userInput == "exit"){
    break;
  } 
  
  // "echo" implementation
  if (userInput.substr(0,5) == "echo "){
    echo(userInput);
  }

  // "type" implementation
  else if (userInput.substr(0,4) == "type"){
    type(userInput);
  } else {
    std::cout << userInput << ": command not found\n";
    }

  }
}

// echo implementation
void echo(std::string userInput){
  std::cout << userInput.substr(5) << '\n';
}

// type implementation
void type(std::string userInput){
  std::unordered_set<std::string> keywords = {"echo", "exit", "type"};
  std::stringstream ss(userInput);
  std::string word;
  std::vector<std::string> usrInptWordsList;

  while (ss >> word){
    usrInptWordsList.push_back(word);
  }

  if (keywords.count(usrInptWordsList[1])) {
    std::cout << usrInptWordsList[1] << " is a shell builtin\n";
  } else {
    std::cout << usrInptWordsList[1] << ": not found\n";
  }


}
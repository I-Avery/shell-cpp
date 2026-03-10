#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>



int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  while(true){
  
  std::cout << "$ ";

  std::string userInput;
  std::string word;
  std::vector<std::string> usrInVec;
  // get the user input
  std::getline(std::cin, userInput);
  std::stringstream ss(userInput);

  // make the userInput string a vector
  while(ss >> word){
    usrInVec.push_back(word);
  }
  // std::cout << usrInVec[1];

  // exiting the shell
  if (userInput == "exit"){
    break;
  } 
  
  // "echo" implementation
  if (userInput.substr(0,5) == "echo "){
    std::cout << userInput.substr(5) << '\n';
  } 

  // "type" implementation
  if (userInput.substr(0,4) == "type"){
    if (usrInVec[1] == "echo" || usrInVec[1] == "exit") {
    std::cout << usrInVec[1] << " is a shell builtin\n";
    }
  } else {
    std::cout << userInput << ": command not found\n";
    }

  }
}
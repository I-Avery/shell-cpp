#include <iostream>
#include <string>
#include <sstream>


int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  while(true){
  
  std::cout << "$ ";

  std::string userInput;

  std::getline(std::cin, userInput);

  std::string word;
  std::stringstream ss(userInput);

  // exiting the shell
  if (userInput == "exit"){
    break;
  } 
  

  // "echo" implementation
  if (userInput.substr(0,4) == "echo "){
    std::cout << userInput.substr(5) << '\n';
  } else {
    std::cout << userInput << ": command not found\n";
    }
  }
}
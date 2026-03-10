#include <iostream>
#include <string>
#include <sstream>
#include <vector>


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
  int count = 0;
  ss >> word;
  if (word == "echo") {
    while(ss >> word) {
      if (count != 0){
        std::cout << ' ' << word;
        } else {
          std::cout << word;
          count++;
        }

    }
    count = 0;
    std::cout << '\n';
  } else {
    std::cout << userInput << ": command not found\n";
    }
    
    if (true){
          std::cout << '\n' << "$ ";
          break;
    }
  

  }
  

}
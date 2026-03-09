#include <iostream>
#include <string>


int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  while(true){
  
  std::cout << "$ ";

  std::string userInput;

  std::cin >> userInput;

  // exiting the shell
  if (userInput == "exit"){
    break;
  } else if (userInput.substr(0,5) == "echo") {
    std::cout << userInput.substr(5) << "\n";
  } 

  else {
    std::cout << userInput << ": command not found\n";
  }

  
}
}

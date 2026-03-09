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

  if (userInput == "exit")
  {
    break;
  } else {
    std::cout << userInput << ": command not found\n";
  }

  
}
}

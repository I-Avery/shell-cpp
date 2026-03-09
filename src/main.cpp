#include <iostream>
#include <string>


int main() {
  while(true){
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  // TODO: Uncomment the code below to pass the first stage
  std::cout << "$ ";

  std::string userInput;

  std::cin >> userInput;

  std::cout << userInput << ": command not found";
}
}

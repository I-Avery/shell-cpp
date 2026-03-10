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

  std::string firstWord;
  std::stringstream ss(userInput);
  ss >> firstWord;

  // exiting the shell
  if (userInput == "exit"){
    break;
  } 
  // implementing "echo"
  if (firstWord == "echo") {
  int count = 0;

    // loop each word from the getline(userInput) into firstWord
    while(ss >> firstWord) {
      if (firstWord != "echo" && count == 0) {
        std::cout << firstWord;
        count++;
      } else {
        std::cout << ' ' << firstWord;
    }
  } 
} else {
    std::cout << userInput << ": command not found\n";
  }

  

}
}
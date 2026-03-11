#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <sstream>

namespace fs = std::filesystem;

void echo(std::string);
void type(std::string);
bool checkDirectories(std::string);
std::vector<std::string> getPathDirs(std::string);

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
  
  // "echo" call
  if (userInput.substr(0,5) == "echo "){
    echo(userInput);
  }

  // "type" call
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
  // list of builtins
  std::unordered_set<std::string> keywords = {"echo", "exit", "type"};
  std::stringstream ss(userInput);
  std::string word;
  std::vector<std::string> usrInptWordsList;
  // make the input string a vector to simplify word indexing
  while (ss >> word){
    usrInptWordsList.push_back(word);
  }

  if (keywords.count(usrInptWordsList[1])) {
    std::cout << usrInptWordsList[1] << " is a shell builtin\n";
  } else if (checkDirectories(usrInptWordsList[1])){ 
    // do nothing because checkDirectories will either
    // prduce output and return true, or return false triggering "command not found"

  } else {
    std::cout << usrInptWordsList[1] << ": not found\n";
  }


}
// directory crawler
bool checkDirectories(std::string keywordToCheck){
  // get the PATH string and break it up into its component directories.
  std::vector<std::string> dirs;
  std::string dir;
  // this is a char pointer to the address of the first letter of the path
  char* envPointer = std::getenv("PATH");
  if (!envPointer){
    return false;
  }

  std::stringstream ss(envPointer);
  // build an array of individual paths as seperated by ':'
  while (std::getline(ss, dir, ':')) {
    dirs.push_back(dir);
  }

  for (const std::string& dir : dirs) {
    fs::path fullPath = fs::path(dir) / keywordToCheck;

    if (fs::exists(fullPath)) {
      auto filePerms = fs::status(fullPath).permissions();

      if ((filePerms & fs::perms::owner_exec) != fs::perms::none){
        std::cout << fullPath.string() << '\n';
        return true;
      }

    }
  } 
  // if we check all possible paths and still no return true then return false?
  return false;

}

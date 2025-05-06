#include <iostream>
#include <string>
#include "kvstore.h"

int main() {
  KVStore kv;
  std::string command;

  std::cout << "Simple KVStore CLI\nCommands: put <key> <value>, get <key>, remove <key>, exit\n";

  while (true) {
    std::cout << "> ";
    std::getline(std::cin, command);
    std::istringstream iss(command);
    std::string cmd, key, value;
    iss >> cmd;

    if (cmd == "put") {
      iss >> key >> value;
      kv.put(key, value);
      std::cout << "Stored.\n";
    } else if (cmd == "get") {
      iss >> key;
      try {
        std::cout << kv.get(key) << "\n";
      } catch (const std::out_of_range&) {
        std::cout << "Key not found.\n";
      }
    } else if (cmd == "remove") {
      iss >> key;
      kv.remove(key);
      std::cout << "Removed (if existed).\n";
    } else if (cmd == "exit") {
      break;
    } else {
      std::cout << "Unknown command.\n";
    }
  }

  return 0;
}

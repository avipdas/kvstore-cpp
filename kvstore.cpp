#include "kvstore.h"
#include <stdexcept>

void KVStore::put(const std::string& key, const std::string& value) {
  store[key] = value;
}

std::string KVStore::get(const std::string& key) const {
  auto it = store.find(key);
  if (it == store.end()) {
    throw std::out_of_range("Key not found: " + key);
  }
  return it->second;
}

void KVStore::remove(const std::string& key) {
  store.erase(key);
}

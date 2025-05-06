#include <gtest/gtest.h>
#include "../kvstore.h"

TEST(KVStoreTest, InsertAndRetrieve) {
  KVStore kv;
  kv.put("apple", "red");
  EXPECT_EQ(kv.get("apple"), "red");
}

TEST(KVStoreTest, OverwriteValue) {
  KVStore kv;
  kv.put("apple", "green");
  kv.put("apple", "red");
  EXPECT_EQ(kv.get("apple"), "red");
}

TEST(KVStoreTest, MissingKeyThrows) {
  KVStore kv;
  EXPECT_THROW(kv.get("banana"), std::out_of_range);
}

TEST(KVStoreTest, RemoveKey) {
  KVStore kv;
  kv.put("key", "value");
  kv.remove("key");
  EXPECT_THROW(kv.get("key"), std::out_of_range);
}

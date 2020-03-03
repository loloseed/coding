#include <string>

#include "skiplist-inl.h"
#include "third_party/gtest/include/gtest/gtest.h"

using util::skiplist::Skiplist;
TEST(Skiplist, TEST_INTERFACE) {
  Skiplist<int, int> skiplist;
  EXPECT_EQ(0, skiplist.size());
  EXPECT_EQ(true, skiplist.empty());
}

TEST(Skiplist, ITERATOR) {
  Skiplist<int, int> skiplist;
  Skiplist<int, int>::iterator it = skiplist.begin();
  EXPECT_TRUE(it == skiplist.begin());
  EXPECT_TRUE(it == skiplist.end());
  EXPECT_FALSE(it != skiplist.begin());
  EXPECT_FALSE(it != skiplist.end());
}

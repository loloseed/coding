#ifndef UTIL_SKIPLIST_H_
#define UTIL_SKIPLIST_H_

#include <cstring>
#include <functional>
#include <iterator>
#include <utility>

namespace util {
/**
 * 类似于map的有序集合类型，每个集合元素是key-value对，使用skiplist结构实现。
 */
template <typename KeyType, typename ValueType, typename Comparator = std::less<KeyType> >
class Skiplist {
 public:
  /**
   * 构造函数
   * Usage: Skiplist<string, int> skiplist;
   * 描述：使用默认的std::less<KeyType>排序函数构造空的Skiplist对象；
   * Usage: Skiplist<string, int> skiplist(MyCompareFunction);
   * 描述：使用指定的MyCompareFunction排序函数构造空的Skiplist对象；
   */
  Skiplist(Comparator comp = Comparator());

  // 析构函数
  ~Skiplist();

  /**
   * 拷贝与复制构造函数
   * Usage: Skiplist skiplist(other);
   *        skiplist = other2;
   * 描述：深拷贝skiplist对象；
   */
  Skiplist(const Skiplist& other);
  Skiplist& operator= (const Skiplist& other);

  /**
   * Skiplist可变迭代器类型iterator，常量迭代器类型const_iterator；
   * Usage: Skiplist<string, int>::iterator it = skiplist.begin();
   *        it++;
   *        it--;
   *        it = it + n;
   *        *it;
   *        it->;
   *        it != skiplist.end();
   *        it1 != it2;
   */
  class iterator;
  class const_iterator;

  /**
   * 插入操作
   * Usage: std::pair<Skiplist::iterator, bool> ret = skiplist.insert(key, value);
   * @params[in] key, 插入的key值;
   * @params[in] value, 插入的value值;
   * @ret, 插入成功返回插入的位置iterator并bool为1，插入失败iterator为已存在的key位置并bool为0；
   */
  std::pair<iterator, bool> insert(const KeyType& key, const ValueType& value);

  /**
   * 查找操作
   * Usage: Skiplist::iterator it = skiplist.find(key);
   * @params[in] key, 查找的key值;
   * @ret, 查找成功返回key所在的iterator的位置，查找失败返回end();
   */
  iterator find(const KeyType& key);
  const_iterator find(const KeyType& key) const;

  /**
   * 删除操作
   * Usage: bool ret = skiplist.erase(key);
   * @params[in] key, 删除的key值;
   * @ret, 删除成功返回true，失败返回false;
   */
  bool erase(const KeyType& key);

  /**
   * 下标操作
   * Usage: ValueType value = skiplist[key];
   * @params[in] key, 查找的key值;
   * @ret, 返回key对应的value引用，如果key不存在，插入key，value为缺少值；
   */
  ValueType& operator[] (const KeyType& key);

  /**
   * at操作
   * Usage: try {
   *          ValueType value = skiplist.at(key);
   *        }catch(Exception& ex) {
   *        }
   * @param[in] key, 查找对应的key;
   * @ret, 返回key对应的value的引用，如果key不存在，抛出std::out_of_range异常；
   */
  ValueType& at(const KeyType& key);
  ValueType& at(const KeyType& key) const;

  /**
   * 迭代器头尾
   * Usage: Skiplist<string, int>::iterator it = skiplist.begin();
   *        while (it != skiplist.end()) {
   *          // DO SOMETHING
   *          it++;
   *        }
   */
  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;

  /**
   * Usage: size_t num = skiplist.size();
   * @ret, 返回skiplist元素个数;
   */
  size_t size() const;

  /**
   * Usage: bool ret = skiplist.empty();
   * @ret, skiplist是否为空，为空返回true，不为空返回false;
   */
  bool empty() const;

  /**
   * 交换两个skiplist
   * Usage: skiplist1.swap(skiplist2);
   */
  void swap(Skiplist& other);

 private:

  // 每一个skiplist元素用Node表示
  struct Node {
    // 每一个skiplist元素是一对key-value
    std::pair<KeyType, ValueType> value_;
    const size_t level_;  // Node的层高

    // 不同层指向的下一个Node。当前只分配了一层next指针，不同层的指针运行时分配；
    struct Node* next_[1];

    // 构造值为key-value的Node,Node层高为level
    Node(const KeyType& key, const ValueType& value, size_t level);

    // 分配size + (size*num_next_pointers-1)的空间给Node
    void* operator new(size_t size, int num_next_pointers);
    void operator delete(void* memory);
  };

  static const size_t kMaxLevel = 32;  // skiplist最高层高

  // 比较函数
  Comparator comp_;

  // skiplist每层链表的头结点
  Node* header_[kMaxLevel];

  // 保存skiplist中元素的个数
  size_t size_;

  // 当前最高高度
  size_t highest_level_;

  // 迭代器使用Node结构，申明成Skiplsit的友元类
  friend class iterator;
  friend class const_iterator;

  // 生成Node结点的层高
  size_t GenerateRandomLevel();
};
// TODO(hll): Skiplist比较函数

/***** 实现 *****/
template <typename KeyType, typename ValueType, typename Comparator>
Skiplist<KeyType, ValueType, Comparator>::Skiplist(Comparator comp) :
  comp_(comp) {
  std::memset(header_, 0, sizeof(header_));
  size_ = 0;
  highest_level_ = 0;
}

template <typename KeyType, typename ValueType, typename Comparator>
Skiplist<KeyType, ValueType, Comparator>::~Skiplist() {
  // TODO
}

template <typename KeyType, typename ValueType, typename Comparator>
Skiplist<KeyType, ValueType, Comparator>::Skiplist(const Skiplist& other) {
}

template <typename KeyType, typename ValueType, typename Comparator>
Skiplist<KeyType, ValueType, Comparator>&
Skiplist<KeyType, ValueType, Comparator>::operator= (const Skiplist& other) {
  return *this;
}

template <typename KeyType, typename ValueType, typename Comparator>
std::pair<typename Skiplist<KeyType, ValueType, Comparator>::iterator, bool>
Skiplist<KeyType, ValueType, Comparator>::insert(const KeyType& key, const ValueType& value) {
}

template <typename KeyType, typename ValueType, typename Comparator>
typename Skiplist<KeyType, ValueType, Comparator>::iterator
Skiplist<KeyType, ValueType, Comparator>::find(const KeyType& key) {
}

template <typename KeyType, typename ValueType, typename Comparator>
typename Skiplist<KeyType, ValueType, Comparator>::const_iterator
Skiplist<KeyType, ValueType, Comparator>::find(const KeyType& key) const {
}

template <typename KeyType, typename ValueType, typename Comparator>
bool Skiplist<KeyType, ValueType, Comparator>::erase(const KeyType& key) {
}

template <typename KeyType, typename ValueType, typename Comparator>
ValueType& Skiplist<KeyType, ValueType, Comparator>::operator[] (const KeyType& key) {
}

template <typename KeyType, typename ValueType, typename Comparator>
ValueType& Skiplist<KeyType, ValueType, Comparator>::at(const KeyType& key) {
}

template <typename KeyType, typename ValueType, typename Comparator>
size_t Skiplist<KeyType, ValueType, Comparator>::size() const {
  return size_;
}

template <typename KeyType, typename ValueType, typename Comparator>
bool Skiplist<KeyType, ValueType, Comparator>::empty() const {
  return size_ == 0;
}

template <typename KeyType, typename ValueType, typename Comparator>
void Skiplist<KeyType, ValueType, Comparator>::swap(Skiplist& other) {
}

template <typename KeyType, typename ValueType, typename Comparator>
size_t Skiplist<KeyType, ValueType, Comparator>::GenerateRandomLevel() {
}

// Node implementation
template <typename KeyType, typename ValueType, typename Comparator>
Skiplist<KeyType, ValueType, Comparator>::Node::Node(
    const KeyType& key, const ValueType& value, size_t level) {
}

template <typename KeyType, typename ValueType, typename Comparator>
void* Skiplist<KeyType, ValueType, Comparator>::Node::operator new(
    size_t size, int num_next_pointers) {
}
template <typename KeyType, typename ValueType, typename Comparator>
void Skiplist<KeyType, ValueType, Comparator>::Node::operator delete(
    void* memory) {
  ::operator delete(memory);
}

// iterator implementation
template <typename KeyType, typename ValueType, typename Comparator>
class Skiplist<KeyType, ValueType, Comparator>::iterator:
  public std::iterator<std::bidirectional_iterator_tag,
                       std::pair<KeyType, ValueType> > {
 public:
  iterator() {}
  ~iterator() {}
};

template <typename KeyType, typename ValueType, typename Comparator>
class Skiplist<KeyType, ValueType, Comparator>::const_iterator:
  public std::iterator<std::bidirectional_iterator_tag,
                       std::pair<KeyType, ValueType> > {
 public:
  const_iterator() {}
  ~const_iterator() {}
};
}  // namespace util
#endif  // UTIL_SKIPLIST_H_

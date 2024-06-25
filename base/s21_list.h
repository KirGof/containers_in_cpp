#ifndef LIST_H
#define LIST_H

#include "header.h"
#include <cstdio>

namespace s21 {

template <typename value_type> class iter_for_list;

template <typename T> class list {
public:
  // *List Member type*
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  // using iterator = T *;
  using iterator = iter_for_list<value_type>;
  using const_iterator = const T *;
  using size_type = std::size_t;

  friend class iter_for_list<value_type>;

private:
  // public:
  // *List struct*
  struct Node {
    Node *next_ = nullptr;
    Node *prev_ = nullptr;
    value_type val_ = 0;
    Node(const value_type &value) : val_(value){};
  };
  Node *top_;
  Node *bot_;
  size_type size_;

public:
  // *List Functions*
  list();            // default constructor, creates empty list  |
  list(size_type n); // parameterized constructor, creates the list of size n
  list(std::initializer_list<value_type> const
           &items); // initializer list constructor, creates list initizialized
                    // using std::initializer_list<T>    |
  list(const list &l);         // copy constructor  |
  list(list &&l);              // move constructor  |
  ~list();                     // destructor  |
  list<T> operator=(list &&l); // assignment operator overload for moving object

  // *List Element access*
  const_reference front() const noexcept; //  access the first element |
  const_reference back() const noexcept;  // access the last element
  reference front() noexcept;             //  access the first element |
  reference back() noexcept;              // access the last element

  // *List Iterators*
  const_iterator
  begin() const noexcept; // returns an iterator to the beginning            |
  const_iterator end() const noexcept; // returns an iterator to the end
  iterator begin() noexcept;           // returns an iterator to the beginning |
  iterator end() noexcept;             // returns an iterator to the end

  // *List Capacity*
  bool empty() const noexcept; // checks whether the container is empty |
  size_type size(); // returns the number of elements                  |
  size_type max_size()
      const noexcept; // returns the maximum possible number of elements |

  // *List Modifiers*
  void clear(); // clears the contents                             |
  iterator insert(
      iterator pos,
      const_reference value); // inserts element into concrete pos and returns
                              // the iterator that points to the new element |
  void erase(iterator pos);   // erases element at pos |
  void push_back(const_reference value);  // adds an element to the end |
  void push_front(const_reference value); // adds an element to the head |
  void pop_back();                        // removes the last element        |
  void pop_front();                       // removes the first element        |
  void swap(list &other);                 // swaps the contents |
  void merge(list &other);                //  merges two sorted lists |
  void
  splice(const_iterator pos,
         list &other); // transfers elements from list other starting from pos |
  void reverse();      // reverses the order of the elements              |
  void unique();       // removes consecutive duplicate elements               |
  void sort();         // sorts the elements                |
};

template <typename value_type> class iter_for_list {

  using from_list = list<value_type>;
  friend class list<value_type>;

private:
  typename from_list::Node *current_node_ = nullptr;

public:
  iter_for_list();
  iter_for_list(typename from_list::Node *node) : current_node_(node){};

  typename from_list::reference operator*() const {
    if (current_node_ == nullptr) {
      throw std::invalid_argument(
          "Class iter_for_list, method operator*: current_node == nullptr");
    }
    return current_node_->val_;
  }

  iter_for_list &operator++() noexcept {
    if (current_node_ != nullptr) {
      current_node_ = current_node_->next_;
    }
    return *this;
  }

  iter_for_list &operator++(int) noexcept {
    if (current_node_ != nullptr) {
      current_node_ = current_node_->next_;
    }
    return *this;
  }

  iter_for_list &operator--() noexcept {
    if (current_node_ == nullptr) {
    } else {
      current_node_ = current_node_->prev_;
    }
    return *this;
  }

  iter_for_list &operator--(int) noexcept {

    if (current_node_ == nullptr) {
    } else {
      current_node_ = current_node_->prev_;
    }
    return *this;
  }

  bool operator!=(const iter_for_list &other) const noexcept {
    return current_node_ != other.current_node_;
  }

  bool operator==(const iter_for_list &other) const noexcept {
    return current_node_ == other.current_node_;
  }
};

} // namespace s21

#include "./tpp/s21_list.cpp"

#endif // ! LIST_H

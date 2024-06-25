#ifndef LIST_H
#define LIST_H

#include "header.h"

namespace s21 {

template <typename T> class List_iter;

template <typename T> class list {
public:
  // *List Member type*
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = List_iter<value_type>;
  using const_iterator = const T *;
  using size_type = std::size_t;

private:
  friend class List_iter<value_type>;
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

template <typename T> class List_iter {
  friend class list<T>;

private:
  typename list<T>::Node *current_node_ = nullptr;

public:
  List_iter();
  List_iter(typename list<T>::Node *node);
  typename list<T>::reference operator*() const;
  typename list<T>::iterator &operator++() noexcept;
  typename list<T>::iterator &operator--() noexcept;
  bool operator!=(const List_iter &other) const noexcept;
  bool operator==(const List_iter &other) const noexcept;
};

} // namespace s21

#include "./tpp/s21_iter_for_list.cpp"
#include "./tpp/s21_list.cpp"

#endif // ! LIST_H

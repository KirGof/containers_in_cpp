#include "../s21_list.h"

namespace s21 {

template <typename T>
list<T>::list() : size_(0), top_(nullptr), bot_(nullptr) {}

template <typename T>
list<T>::list(size_type n) : size_(0), top_(nullptr), bot_(nullptr) {
  if (n > 0) {
    for (size_type i = 0; i < n; i++) {
      push_front(value_type());
    }
  } else {
    throw std::invalid_argument("Size list less zero");
  }
}

template <typename T>
list<T>::list(std::initializer_list<value_type> const &items)
    : size_(0), top_(nullptr), bot_(nullptr) {
  for (auto i = items.begin(); i != items.end(); i++) {
    push_back(*i);
  }
}

template <typename T>
list<T>::list(const list &l) : size_(0), top_(nullptr), bot_(nullptr) {
  Node *buff = l.top_;
  while (buff != nullptr) {
    push_back(buff->val_);
    buff = buff->next_;
  }
}

template <typename T> list<T>::list(list &&l) {
  top_ = l.top_;
  bot_ = l.bot_;
  size_ = l.size_;
  l.top_ = nullptr;
  l.bot_ = nullptr;
  l.size_ = 0;
}

template <typename T> list<T>::~list() {
  while (size_ > 0) {
    pop_front();
    printf("DESTROY!!!\n");
  }
}

template <typename T> void list<T>::push_front(const_reference value) {
  Node *new_node = new Node(value);
  if (size_ == 0) {
    top_ = new_node;
    bot_ = new_node;
  } else {
    top_->prev_ = new_node;
    new_node->next_ = top_;
    top_ = new_node;
  }
  size_++;
}

template <typename T> void list<T>::push_back(const_reference value) {
  Node *new_node = new Node(value);
  if (size_ == 0) {
    top_ = new_node;
    bot_ = new_node;
  } else {
    bot_->next_ = new_node;
    new_node->prev_ = bot_;
    bot_ = new_node;
  }
  new_node = nullptr;
  size_++;
}

template <typename T> void list<T>::pop_front() {
  if (size_ == 1) {
    delete top_;
    top_ = bot_ = nullptr;
    size_--;
  } else {
    Node *buff = top_->next_;
    top_->next_ = nullptr;
    delete top_;
    top_ = buff;
    size_--;
  }
}

template <typename T> void list<T>::pop_back() {
  if (size_ == 1) {
    delete top_;
    top_ = bot_ = nullptr;
    size_--;
  } else {
    Node *buff = bot_->prev_;
    bot_->prev_ = nullptr;
    delete bot_;
    bot_ = buff;
    size_--;
  }
}

template <typename T> list<T> list<T>::operator=(list &&l) {
  if (this != l) {
    swap(l);
  }
}

template <typename T> void list<T>::swap(list &other) {
  if (this != other) {
    this->clear();
    std::swap(top_, other.top_);
    std::swap(bot_, other.bot);
    std::swap(size_, other.size_);
  }
}

template <typename T> void list<T>::clear() {
  while (size_ > 0) {
    pop_front();
  }
}

template <typename T> bool list<T>::empty() const noexcept {
  return this->size_ == 0;
}

template <typename T> typename list<T>::reference list<T>::front() noexcept {
  return this->top_->val_;
}

template <typename T> typename list<T>::reference list<T>::back() noexcept {
  return this->bot_->val_;
}

template <typename T>
typename list<T>::const_reference list<T>::front() const noexcept {
  return this->top_->val_;
}

template <typename T>
typename list<T>::const_reference list<T>::back() const noexcept {
  return this->bot_->val_;
}

template <typename T> typename list<T>::iterator list<T>::begin() noexcept {
  return iterator(top_);
}

template <typename T> typename list<T>::iterator list<T>::end() noexcept {
  return iterator(bot_->next_);
}

template <typename T>
typename list<T>::const_iterator list<T>::begin() const noexcept {
  return const_iterator(this->bot_);
}

template <typename T>
typename list<T>::const_iterator list<T>::end() const noexcept {
  return const_iterator(this->top_->next_);
}

template <typename T> typename list<T>::size_type list<T>::size() {
  return this->size_;
}

template <typename T>
typename list<T>::size_type list<T>::max_size() const noexcept {
  return (std::numeric_limits<size_type>::max() - sizeof(Node *) * 2) /
         sizeof(Node);
}

template <typename T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference value) {
  Node *new_node = new Node(value);
  if (pos.current_node_ == nullptr) {
    if (bot_ == nullptr) {
      top_ = new_node;
      bot_ = new_node;
    } else {
      new_node->prev_ = bot_;
      bot_->next_ = new_node;
      bot_ = new_node;
    }
  } else {
    new_node->prev_ = pos.current_node_->prev_;
    new_node->next_ = pos.current_node_;
    if (pos.current_node_->prev_ != nullptr) {
      pos.current_node_->prev_->next_ = new_node;
    } else {
      top_ = new_node;
    }
    pos.current_node_->prev_ = new_node;
  }
  ++size_;
  return iterator(new_node);
}

template <typename T> void list<T>::erase(iterator pos) {
  if (pos.current_node_ == nullptr) {
    throw std::invalid_argument("Method erase: erase nullptr");
  }
  Node *buff = pos.current_node_;
  if (buff == top_) {
    pop_front();

  } else {
    buff->prev_->next_ = buff->next_;
  }

  if (buff == bot_) {
    pop_back();
  } else {
    buff->next_->prev_ = buff->prev_;
  }
  delete buff;
}

} // namespace s21

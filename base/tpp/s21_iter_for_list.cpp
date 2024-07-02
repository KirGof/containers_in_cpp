#include "../s21_list.h"
#include <cstdio>

namespace s21 {

template <typename T>
List_iter<T>::List_iter(typename list<T>::Node *node) : current_node_(node) {}

template <typename T>
typename list<T>::reference List_iter<T>::operator*() const {
  if (current_node_ == nullptr) {
    throw std::invalid_argument(
        "Class List_iter, method operator*: current_node == nullptr");
  }
  return current_node_->val_;
}

template <typename T>
typename list<T>::iterator &List_iter<T>::operator++() noexcept {
  if (current_node_ != nullptr) {
    current_node_ = current_node_->next_;
  }
  return *this;
}

template <typename T>
typename list<T>::iterator List_iter<T>::operator+(const int x) noexcept {
  typename list<T>::iterator buff(current_node_);
  for (int i = 0; i < x; i++) {
    ++buff;
  }
  return buff;
}

template <typename T>
typename list<T>::iterator &List_iter<T>::operator--() noexcept {
  if (current_node_ != nullptr) {
    current_node_ = current_node_->prev_;
  }
  return *this;
}

template <typename T>
bool List_iter<T>::operator!=(const List_iter &other) const noexcept {
  return current_node_ != other.current_node_;
}

template <typename T>
bool List_iter<T>::operator==(const List_iter &other) const noexcept {
  return current_node_ == other.current_node_;
}

template <typename T>
bool List_iter<T>::operator>(const List_iter &other) const noexcept {
  return current_node_->val_ > other.current_node_->val_;
}

template <typename T>
void List_iter<T>::swap(typename list<T>::iterator &other) {
  std::swap(this->current_node_->val_, other.current_node_->val_);
}

} // namespace s21

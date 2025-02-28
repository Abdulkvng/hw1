#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"


ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
/*You need to examine the code provided in
 ulliststr.h and ulliststr.cpp and add the 
 implementations for push_back, push_front, 
 pop_back, pop_front, back, front and getValAtLoc in ulliststr.cpp.*/


std::string const & ULListStr::back() const {
    if (tail_ != nullptr && tail_->last > 0) {
        return tail_->val[tail_->last - 1];}
    throw std::out_of_range("The list is empty");
}


//getvalatlock  retry #4
std::string* ULListStr::getValAtLoc(size_t loc) const {
    if (loc >= size_) {
        return nullptr; }
  Item* curr = head_;
  while (curr) {
   size_t numElements = curr->last - curr->first;
    if (loc < numElements) {
       return &curr->val[curr->first + loc];}
        loc -= numElements;
        curr = curr->next; }
    return nullptr;}

std::string const & ULListStr::front() const {
    if (empty()) {
    throw std::runtime_error("List is empty");}
    return head_->val[head_->first];
}

void ULListStr::push_back(const std::string& val) {
    if (!tail_ || tail_->last == ARRSIZE) {
        Item* newItem = new Item();
        if (!tail_) {
            head_ = tail_ = newItem;} 
            else { tail_->next = newItem;
            newItem->prev = tail_;
            tail_ = newItem;} }
    tail_->val[tail_->last++] = val;
    ++size_;}

void ULListStr::push_front(const std::string& val) {
    if (head_ && head_->first > 0) {
        head_->val[--head_->first] = val; } 
        else {
        // Otherwis make a brand new node and thenn insert the value
  Item* newItem = new Item();
   newItem->last = ARRSIZE; 
  newItem->first = ARRSIZE - 1; 
  newItem->val[newItem->first] = val; 
        if (!head_) {
            head_ = tail_ = newItem;} 
  else {newItem->next = head_;
            head_->prev = newItem;
            head_ = newItem; }} 
            ++size_;
            
            }

  ///pop back
void ULListStr::pop_back() {
    if (empty()) return; 
    if (--tail_->last == tail_->first) {
        //  remove , if tail node empty
        Item* temp = tail_;
        tail_ = tail_->prev;
        if (tail_) {
      tail_->next = nullptr; } 
      else { head_ = nullptr;  }
        delete temp;
    }  --size_; }




void ULListStr::pop_front() {
    if (empty()) return; 
    if (++head_->first == head_->last) {
   Item* temp = head_;
head_ = head_->next;
if (head_) {    head_->prev = nullptr;
        } else {
       tail_ = nullptr;  }
        delete temp;}
    --size_;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

//
// CP2 Flinders University
//

#ifndef ROLODEX_H
#define ROLODEX_H

#include <string>

// rolodex card structre
struct RolodexItem {
 std::string value_;
 RolodexItem* next_;
 RolodexItem* prev_;

 RolodexItem(const std::string& value = "")
     : value_(value), next_(nullptr), prev_(nullptr) {}
};


class Rolodex {
public:
 RolodexItem* current_;
 /**
 * Creates a new empty Rolodex. Constructor and Destructor
 */

 explicit Rolodex();
 ~Rolodex();

 /**
  * Returns true if the Rolodex is positioned before the first card.
  */
 bool isBeforeFirst() const;

 /**
  * Returns true if the Rolodex is positioned after the last card.
  */
 bool isAfterLast() const;

 /**
  * Rotates the Rolodex one card forwards.
  */
 void rotateForward();

 /**
   * Rotates the Rolodex one card backwards.
   */
 void rotateBackward();

 /**
  * Returns the value of the current card.
  */
 const std::string& currentValue() const;

 /**
  * Inserts a new card after the current card and positions the Rolodex
  * at the newly inserted card.
  *
  */

 void insertAfterCurrent(const std::string& value);

 /**
  * Inserts a new card before the current card and positions the Rolodex
  * at the newly inserted card.
  *
  */
 void insertBeforeCurrent(const std::string& value);


 //check if card with specific value exists
 bool contains(const std::string& value) const;


 //delete card
 void deleteCurrent();

 //Check if current card == value
 bool currentMatches(const std::string& value) const;


 size_t size() const {
  size_t count = 0;
  RolodexItem* temp = sentinel_->next_;
  while (temp != sentinel_) {
   count++;
   temp = temp->next_;
  }
  return count;
 }


private:
 RolodexItem* sentinel_;


};


#endif // ROLODEX_H
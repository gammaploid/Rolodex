//
// CP2 Flinders University
//

#include "Rolodex.h"

extern int forwardCount;
extern int backwardCount;


Rolodex::Rolodex() {
     sentinel_ = new RolodexItem("");
    sentinel_-> next_ = sentinel_;
    sentinel_->prev_ = sentinel_;
    current_ = sentinel_;
}

//Deconstructor
Rolodex::~Rolodex() {
    current_ = sentinel_-> next_;
    while (current_ != sentinel_) {
        RolodexItem* temp = current_;
        current_ =  current_-> next_;
        delete  temp;    // clear
    }
    delete sentinel_;
}


/**
 * Returns true if the Rolodex is positioned before the first card.
 */
bool Rolodex::isBeforeFirst() const { return current_ == sentinel_; }

/**
 * Returns true if the Rolodex is positioned after the last card.
 */
bool Rolodex::isAfterLast() const { return current_ == sentinel_; }


/**
 * Rotates the Rolodex one card forwards.
 */
void Rolodex::rotateForward() { current_ = current_ -> next_; }

/**
 * Rotates the Rolodex one card backwards.
 */
void Rolodex::rotateBackward() { current_ = current_ -> prev_; }



/**
 * Returns the value of the current card.
 */
const std::string& Rolodex::currentValue() const { return current_->value_; }



/**
 * Inserts a new card after the current card and positions the Rolodex
 * at the newly inserted card.
 *
 */
void Rolodex::insertAfterCurrent(const std::string& value) {
    RolodexItem* newItems =  new RolodexItem(value);

    newItems-> next_ = current_-> next_;
    newItems-> prev_ = current_;
    current_-> next_->prev_ = newItems;
    current_-> next_ = newItems;

    current_ = newItems;
}

/**
 * Inserts a new card before the current card and positions the Rolodex
 * at the newly inserted card.
 *
 */
void Rolodex::insertBeforeCurrent(const std::string& value) {
    RolodexItem* newItems = new RolodexItem(value);

    newItems-> next_ = current_;
    newItems->prev_ = current_-> prev_;
    current_->prev_->next_ = newItems;
    current_->prev_ = newItems;

    current_ = newItems;
}

//check if rolodex has card with specific value
bool Rolodex::contains(const std::string& value) const
{
    RolodexItem* temp = sentinel_-> next_;
    int count = 0;
    while (temp != sentinel_) {
        if (temp->value_ == value) {
            forwardCount += count + 1;  // Count rotations to find the word
            backwardCount += count + 1;  // Count rotations to get back
            return true;
        }
        count++;
        temp = temp->next_;
    }
    forwardCount += count;  // Count rotations for full search
    backwardCount += count;  // Count rotations to get back
    return false;
}



//delete the current card (skip if already at sentinel)
void Rolodex::deleteCurrent() {
    if (current_ == sentinel_) return;

    RolodexItem* toDelete = current_;
    toDelete->prev_->next_ = toDelete-> next_;
    toDelete->next_ -> prev_ = toDelete-> prev_;

    current_ = (toDelete-> next_ != sentinel_) ? toDelete -> next_ : toDelete -> prev_;

    delete toDelete;
}

//bool check if current card value == given value
bool Rolodex::currentMatches (const std::string& value ) const
{
    return current_ != sentinel_ && current_->value_ == value;
}

#include "MagicalContainer.hpp"
#include <stdexcept>

using namespace ariel;

MagicalContainer::PrimeIterator::PrimeIterator()
    : container(nullptr), it() {}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container)
    : container(&container), it(container.Prime_elem.begin()) {}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other)
    : container(other.container), it(other.it) {}

MagicalContainer::PrimeIterator::~PrimeIterator() {}

// this func can throw exception
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) 
{
    // if not the same containers throw exeption
    if (this->container != other.container)
    {
        throw runtime_error("containers must be the same");
    }
    // only if different from this
    if (this != &other)
    {
        this->it = other.it;
    }
    return *this;
}

// this func can throw exception
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
    // if not the same containers throw exeption
    if (this->container != other.container)
    {
        throw runtime_error("containers must be the same");
    }
    // if it on the same place in the container
    if (this->it == other.it)
    {
        return true;
    }
    return false;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const 
{
    // if it is not equal
    return !(*this == other);
}

// this func can throw exception
bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const 
{
    // if not the same container throw exeption
    if (this->container != other.container)
    {
        throw runtime_error("containers must be the same");
    }
    // check about place and not the value
    if (this->it > other.it)
    {
        return true;
    }
    return false;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const 
{
    // if (this!=other) and not(this>other) then -> this < other
    return (this->operator!=(other)) && !(this->operator>(other));
}

bool MagicalContainer::PrimeIterator::operator>=(const PrimeIterator& other) const 
{
    // if not(this<other) then -> this >= other
    return !(*this < other);
}

bool MagicalContainer::PrimeIterator::operator<=(const PrimeIterator& other) const 
{
    // if not(this>other) then -> this <= other
    return !(*this > other);
}

int MagicalContainer::PrimeIterator::operator*() const 
{
    // the value
    return **it;
}

// this func can throw exception
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() 
{
    // already at the end of the container
    if (it == this->container->Prime_elem.end())
    {
        throw runtime_error("already at the end of the container");
    }
    // move to the next element
    ++it;
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() 
{
  // create new PrimeIterator - in the constructor start at begin
    PrimeIterator iter(*container);
    return iter;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() 
{
    PrimeIterator iter(*container);
    // move the it to the end
    int size = this->container->Prime_elem.size();
    iter.it = this->container->Prime_elem.begin() + size;
    return iter;
}
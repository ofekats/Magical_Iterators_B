#include "MagicalContainer.hpp"
#include <stdexcept>

using namespace ariel;

MagicalContainer::AscendingIterator::AscendingIterator()
    : container(nullptr), it()
{
}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
    : container(&container), it(container.elements.begin())
{
}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other)
    : container(other.container), it(other.it) {}

MagicalContainer::AscendingIterator::~AscendingIterator() {}

// this func can throw exception
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
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
bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
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

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
    // if it is not equal
    return !(*this == other);
}

// this func can throw exception
bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
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

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
{
    // if (this!=other) and not(this>other) then -> this < other
    return (this->operator!=(other)) && !(this->operator>(other));
}

bool MagicalContainer::AscendingIterator::operator>=(const AscendingIterator &other) const
{
    // if not(this<other) then -> this >= other
    return !(*this < other);
}

bool MagicalContainer::AscendingIterator::operator<=(const AscendingIterator &other) const
{
    // if not(this>other) then -> this <= other
    return !(*this > other);
}

int MagicalContainer::AscendingIterator::operator*() const
{
    // the value
    return *it;
}

// this func can throw exception
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    // already at the end of the container
    if (it == this->container->elements.end())
    {
        throw runtime_error("already at the end of the container");
    }
    // move to the next element
    ++it;
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    // create new AscendingIterator - in the constructor start at begin
    AscendingIterator iter(*container);
    return iter;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    AscendingIterator iter(*container);
    // move the it to the end
    int size = (*this->container).size();
    iter.it = this->container->elements.begin() + size;
    return iter;
}
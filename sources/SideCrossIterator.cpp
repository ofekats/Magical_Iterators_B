#include "MagicalContainer.hpp"
#include <stdexcept>

using namespace ariel;

MagicalContainer::SideCrossIterator::SideCrossIterator()
    : container(nullptr), decider(0) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container)
    : container(&container), Start(container.elements.begin()), End(--(container.elements.end())), decider(0)
{
    // if the container is empty
    if (this->container->elements.size() == 0)
    {
        this->Start = container.elements.end();
        this->End = container.elements.end();
    }
}

MagicalContainer::SideCrossIterator::SideCrossIterator(SideCrossIterator &other)
    : container(other.container), Start(other.Start), End(other.End), decider(0) {}

MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

// this func can throw exception
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
    // if not the same containers throw exeption
    if (this->container != other.container)
    {
        throw runtime_error("containers must be the same");
    }
    // only if different from this
    if (this != &other)
    {
        this->Start = other.Start;
        this->End = other.End;
        this->decider = other.decider;
    }
    return *this;
}

// this func can throw exception
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    // if not the same containers throw exeption
    if (this->container != other.container)
    {
        throw runtime_error("containers must be the same");
    }
    // if it on the same place in the container
    if (this->decider == other.decider)
    {
        // if the start ant the end on the same place
        if (this->Start == other.Start && this->End == other.End)
        {
            return true;
        }
    }
    return false;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    // if it is not equal
    return !(*this == other);
}

// this func can throw exception
bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
{
    // if not the same container throw exeption
    if (this->container != other.container)
    {
        throw runtime_error("containers must be the same");
    }
    // check about place and not the value
    if (this->Start > other.Start || this->End < other.End)
    {
        return true;
    }
    return false;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
{
    // if (this!=other) and not(this>other) then -> this < other
    return (this->operator!=(other)) && !(this->operator>(other));
}

bool MagicalContainer::SideCrossIterator::operator>=(const SideCrossIterator &other) const
{
    // if not(this<other) then -> this >= other
    return !(*this < other);
}

bool MagicalContainer::SideCrossIterator::operator<=(const SideCrossIterator &other) const
{
    // if not(this>other) then -> this <= other
    return !(*this > other);
}

int MagicalContainer::SideCrossIterator::operator*() const
{
    // depend on the decider
    switch (this->decider)
    {
    case 0:
        return *Start;
        break;
    case 1:
        return *End;
        break;
    case 2:
        return 0;
        break;
    default:
        return 0;
        break;
    }
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
{
    // is the size even or odd
    size_t size = this->container->elements.size();
    int even = 0;
    if (size % 2 == 0)
    {
        even = 1;
    }
    int done = 0;
    // depend on the decider
    switch (this->decider)
    {
    case 0:
        // if the size is odd
        if (!even)
        {
            if (this->Start == this->End)
            {
                // change to no more
                this->decider = 2;
                this->Start = this->container->elements.end();
                this->End = this->container->elements.end();
                done = 1;
            }
        }
        if (!done)
        {
            // move the start forward
            ++Start;
            // change to end next
            this->decider = 1;
        }

        break;
    case 1:
        // if the size is even
        if (even)
        {
            if (this->Start == this->End)
            {
                // change to no more
                this->decider = 2;
                this->Start = this->container->elements.end();
                this->End = this->container->elements.end();
                done = 1;
            }
        }
        if (!done)
        {
            // return the end one down
            --End;
            // change to start next
            this->decider = 0;
        }
        break;
    case 2:
        // already at the end of the container
        throw runtime_error("already at the end of the container");
        break;
    default:
        break;
    }
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
{
    // create new SideCrossIterator - in the constructor start at begin
    SideCrossIterator iter(*container);
    return iter;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{
    SideCrossIterator iter(*container);
    // move the it to the end
    iter.Start = this->container->elements.end();
    iter.End = this->container->elements.end();
    iter.decider = 2;
    return iter;
}
#include "MagicalContainer.hpp"

using namespace ariel;

MagicalContainer::SideCrossIterator::SideCrossIterator()
    : container(nullptr){}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container)
    : container(&container) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other)
    : container(other.container) {}

MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
    if (this != &other) {
        container = other.container;
    }
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
    return (container == other.container);
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    return !(*this == other);
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
    return (container == other.container) ;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
    return (container == other.container) ;
}

bool MagicalContainer::SideCrossIterator::operator>=(const SideCrossIterator& other) const {
    return !(*this < other);
}

bool MagicalContainer::SideCrossIterator::operator<=(const SideCrossIterator& other) const {
    return !(*this > other);
}

int MagicalContainer::SideCrossIterator::operator*() const {
    
    return 1;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
    return SideCrossIterator(*container);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
    SideCrossIterator iter(*container);
    return iter;
}
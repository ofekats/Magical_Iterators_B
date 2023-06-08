#include "MagicalContainer.hpp"

using namespace ariel;


MagicalContainer::AscendingIterator::AscendingIterator()
    : container(nullptr), position(0) {}

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& container)
    : container(&container), position(0) {}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other)
    : container(other.container), position(other.position) {}

MagicalContainer::AscendingIterator::~AscendingIterator() {}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
    if (this != &other) {
        container = other.container;
        position = other.position;
    }
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
    return (container == other.container) && (position == other.position);
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
    return !(*this == other);
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
    return (container == other.container) && (position > other.position);
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
    return (container == other.container) && (position < other.position);
}

bool MagicalContainer::AscendingIterator::operator>=(const AscendingIterator& other) const {
    return !(*this < other);
}

bool MagicalContainer::AscendingIterator::operator<=(const AscendingIterator& other) const {
    return !(*this > other);
}

int MagicalContainer::AscendingIterator::operator*() const {
    return container->elements[position];
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    ++position;
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
    return AscendingIterator(*container);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
    AscendingIterator iter(*container);
    iter.position = container->elements.size();
    return iter;
}
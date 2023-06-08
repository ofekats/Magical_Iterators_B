#include "MagicalContainer.hpp"

using namespace ariel;

MagicalContainer::SideCrossIterator::SideCrossIterator()
    : container(nullptr), position(0), reverse(false) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& container)
    : container(&container), position(0), reverse(false) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other)
    : container(other.container), position(other.position), reverse(other.reverse) {}

MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
    if (this != &other) {
        container = other.container;
        position = other.position;
        reverse = other.reverse;
    }
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
    return (container == other.container) && (position == other.position) && (reverse == other.reverse);
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    return !(*this == other);
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
    return (container == other.container) && (position > other.position) && (reverse == other.reverse);
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
    return (container == other.container) && (position < other.position) && (reverse == other.reverse);
}

bool MagicalContainer::SideCrossIterator::operator>=(const SideCrossIterator& other) const {
    return !(*this < other);
}

bool MagicalContainer::SideCrossIterator::operator<=(const SideCrossIterator& other) const {
    return !(*this > other);
}

int MagicalContainer::SideCrossIterator::operator*() const {
    if (reverse) {
        return container->elements[container->elements.size() - 1 - position];
    } else {
        return container->elements[position];
    }
}

typename MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    if (reverse) {
        --position;
    } else {
        ++position;
    }
    return *this;
}

typename MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
    return SideCrossIterator(*container);
}

typename MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
    SideCrossIterator iter(*container);
    iter.position = container->elements.size();
    return iter;
}
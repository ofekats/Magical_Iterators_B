#include "MagicalContainer.hpp"

using namespace ariel;

MagicalContainer::PrimeIterator::PrimeIterator()
    : container(nullptr), position(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& container)
    : container(&container), position(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other)
    : container(other.container), position(other.position) {}

MagicalContainer::PrimeIterator::~PrimeIterator() {}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
    if (this != &other) {
        container = other.container;
        position = other.position;
    }
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
    return (container == other.container) && (position == other.position);
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
    return !(*this == other);
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
    return (container == other.container) && (position > other.position);
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
    return (container == other.container) && (position < other.position);
}

bool MagicalContainer::PrimeIterator::operator>=(const PrimeIterator& other) const {
    return !(*this < other);
}

bool MagicalContainer::PrimeIterator::operator<=(const PrimeIterator& other) const {
    return !(*this > other);
}

int MagicalContainer::PrimeIterator::operator*() const {
    return container->elements[position];
}

typename MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    ++position;
    return *this;
}

typename MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
    return PrimeIterator(*container);
}

typename MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    PrimeIterator iter(*container);
    iter.position = container->elements.size();
    return iter;
}
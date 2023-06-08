#pragma once

#include <vector>

using namespace std;

namespace ariel {

class MagicalContainer {
private:
    vector<int> elements;
    vector<int *> Prime_elem;

public:
    MagicalContainer();
    ~MagicalContainer();
    void addElement(int element);
    void removeElement(int element);
    int size() const;

    class AscendingIterator {
    private:
        const MagicalContainer* container;
        size_t position;

    public:
        AscendingIterator();
        AscendingIterator(const MagicalContainer& container);
        AscendingIterator(const AscendingIterator& other);
        ~AscendingIterator();
        AscendingIterator& operator=(const AscendingIterator& other);
        bool operator==(const AscendingIterator& other) const;
        bool operator!=(const AscendingIterator& other) const;
        bool operator>(const AscendingIterator& other) const;
        bool operator<(const AscendingIterator& other) const;
        bool operator>=(const AscendingIterator& other) const;
        bool operator<=(const AscendingIterator& other) const;
        int operator*() const;
        AscendingIterator& operator++();

        AscendingIterator begin();
        AscendingIterator end();
    };

    class SideCrossIterator {
    private:
        const MagicalContainer* container;
        size_t position;
        bool reverse;

    public:
        SideCrossIterator();
        SideCrossIterator(const MagicalContainer& container);
        SideCrossIterator(const SideCrossIterator& other);
        ~SideCrossIterator();
        SideCrossIterator& operator=(const SideCrossIterator& other);
        bool operator==(const SideCrossIterator& other) const;
        bool operator!=(const SideCrossIterator& other) const;
        bool operator>(const SideCrossIterator& other) const;
        bool operator<(const SideCrossIterator& other) const;
        bool operator>=(const SideCrossIterator& other) const;
        bool operator<=(const SideCrossIterator& other) const;
        int operator*() const;
        SideCrossIterator& operator++();

        SideCrossIterator begin();
        SideCrossIterator end();
    };

    class PrimeIterator {
    private:
        const MagicalContainer* container;
        size_t position;

        static bool isPrime(int number);
        static int getNextPrime(int number);

    public:
        PrimeIterator();
        PrimeIterator(const MagicalContainer& container);
        PrimeIterator(const PrimeIterator& other);
        ~PrimeIterator();
        PrimeIterator& operator=(const PrimeIterator& other);
        bool operator==(const PrimeIterator& other) const;
        bool operator!=(const PrimeIterator& other) const;
        bool operator>(const PrimeIterator& other) const;
        bool operator<(const PrimeIterator& other) const;
        bool operator>=(const PrimeIterator& other) const;
        bool operator<=(const PrimeIterator& other) const;
        int operator*() const;
        PrimeIterator& operator++();

        PrimeIterator begin();
        PrimeIterator end();
    };
};

}

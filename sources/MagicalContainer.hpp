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
    static bool isPrime(int number);
    void addElement(int element);
    void add_sorted(int element);
    void removeElement(int element);
    int size() const;

    class AscendingIterator {
    private:
        MagicalContainer* container;
        vector<int>::iterator it;

    public:
        AscendingIterator();
        AscendingIterator(MagicalContainer& container);
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
        MagicalContainer* container;
        vector<int>::iterator it;

    public:
        SideCrossIterator();
        SideCrossIterator(MagicalContainer& container);
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
        MagicalContainer* container;
        vector<int *>::iterator it;

    public:
        PrimeIterator();
        PrimeIterator(MagicalContainer& container);
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

#include "MagicalContainer.hpp"
#include <algorithm>
#include <stdexcept>

using namespace ariel;

MagicalContainer::MagicalContainer() {}

MagicalContainer::~MagicalContainer() {}

void MagicalContainer::add_sorted(int element)
{
    //no elements in vector yet
    if(this->elements.size() == 0)
    {
        this->elements.emplace_back(element);
    }
    else //need to insert the new element in the right place
    {
        size_t place = 0;
        size_t i;
        for(i = 0; i < this->elements.size(); ++i)
        {
            if(element < this->elements[i])
            {
                place =i;
                break;
            }
        }
        vector<int>::iterator it = this->elements.begin() + int(i);
        this->elements.insert(it, element);
    }
}

void MagicalContainer::addElement(int element) 
{
    //checks if the element already in the container
    vector<int>::iterator it = find(this->elements.begin(), this->elements.end(), element);
    //if the element not in - insert it, but if it is in - do nothing
    if(it == this->elements.end()){
        add_sorted(element);
    }
}

//this func can throw exception
void MagicalContainer::removeElement(int element) 
{
    //if the elem not in the container
    int have_elem = 0;
    for (vector<int>::iterator it = this->elements.begin(); it != this->elements.end(); ++it) 
    {
        //delete the element
        if (*it == element) {
            elements.erase(it);
            //found the element
            have_elem = 1;
            break;
        }
    }
    //if the elem not in the container throw
    if(!have_elem)
    {
        throw runtime_error("elem not in the container"); 
    }
}

int MagicalContainer::size() const 
{
    return elements.size();
}

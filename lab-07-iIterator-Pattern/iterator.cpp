
#include "iterator.h"

void PreorderIterator::first() {
    
    Iterator* iter = self_ptr->create_iterator();
    if(iter!= NULL)
    {
        iter->first();
        while(iterators.empty())
        {
            iterators.pop();
        }
        iterators.push(iter);
    }
}
void PreorderIterator::next() {
    Iterator* iter = iterators.top()->current()->create_iterator();
    
    iter->first();
    iterators.push(iter);
    
    while(!iterators.empty() && iterators.top()->is_done())
    {
        iterators.pop();
        if(iterators.empty())
        {
            break;
        }
        iterators.top()->next();
    }
}

bool PreorderIterator::is_done() {
    return iterators.empty();
}

Base* PreorderIterator::current() {
    return iterators.top()->current();
}

void OperatorIterator::first() {
    current_ptr = self_ptr->get_left();
}

void OperatorIterator::next() {
    if (current_ptr == self_ptr->get_left()) {
        current_ptr = self_ptr->get_right();
    }
    else {
        current_ptr = NULL;
    }
}

bool OperatorIterator::is_done() {
    if (current_ptr == NULL){
        return true;
    }
    return false;
}

Base* OperatorIterator::current() {
    return current_ptr;
}

void UnaryIterator::first() {
    current_ptr = self_ptr->get_left();
}

void UnaryIterator::next() {
    current_ptr = NULL;
}

bool UnaryIterator::is_done() {
    if (current_ptr == NULL){
        return true;
    }
    return false;
}

Base* UnaryIterator::current() {
    return current_ptr;
}

void NullIterator::first() {
    return;
}

void NullIterator::next() {
    return;
}

bool NullIterator::is_done() {
    return true;
}

Base* NullIterator::current() {
    return NULL;
}




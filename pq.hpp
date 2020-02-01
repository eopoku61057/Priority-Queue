#pragma once

#include <cstddef>  // Include to use NULL, otherwise use nullptr
#include <iostream>
#include "node.hpp"

template<class T>
class PQ{
private:
    Node<T> *head;          // the pointer to the front of the list
    Node<T> *tail;          // the pointer to the back of the list
    int count;

public:
    // desc: Inializes a new, empty queue
	PQ();

    // desc:    Adds new data to the queue
    // param:   data The data to add to the list
    // param:   priority The priority assigned to this node
    // returns: void
	void enqueue(T &data, int priority);

    // desc:    Removes the front element form the queue
    // returns: void
	void dequeue(void);   

    // desc:    Removes the value found at the front of the queue
    // returns: The data found at the front of the queue
    T get_front(void); 

    // desc:    Checks if the queue is empty or not
    // returns: true is the queue is empty, false if not
    bool isEmpty(void);

    // desc:    Clears the queue
    // returns: void
    void clear(void);

    // desc:    Returns the number of elements in the queue
    // returns: The number of elements in the queue
    int get_count(void);
};

template<class T>
PQ<T>::PQ()
{
	head = NULL;
    tail = NULL;
    count = 0;
}

template<class T>
void PQ<T>::enqueue(T &data, int priority)
{
    // create new node with priority
    Node<T> *new_node = new Node<T>(data, priority);

    // check to see if head is null, point head and tail to the new node
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
        new_node->set_priority(priority);
    }
    else 
    {
        tail->set_next(new_node);
        tail = new_node;  
        new_node->set_priority(priority);     
    }
    return;

}

template<class T>
void PQ<T>::dequeue(void)
{
    // create a pointer
    Node<T> *itunes;

    // check to see if the head is null, meaning data is empty
    if (head == NULL)
    {
        return;
    }
    else
    {
        itunes = head;
        head = head->get_next();

        // check to see if head is null then set tail to null
        if (head == NULL)
        {
            tail = NULL;
        }

        delete(itunes);
    }
    
    return;
}

template<class T>
T  PQ<T>::get_front()
{
    // create a pointer
    Node<T> *newPointer;

    // check to see if the list is empty then return
    if (head == NULL)
    {
        return 0;
    }
    else
    {
       return head->get_data();
    }
    
}

template<class T>
bool PQ<T>::isEmpty()
{
    // check to see if queue is empty, return true if it is empty else false
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class T>
void PQ<T>::clear(void)
{
    // create two new pointer
    Node<T> *newPointer;
    Node<T> *toDelete;

    // check to see if data is empty
    if (head == NULL)
    {
        return;
    }
    else
    {
        // set newpointer to head
        newPointer = head;

        // loop whiles new pointer is not NULL, then traverse and delete
         while (newPointer != NULL)
        {
            // check to see if newpointer is the first or last element in the queue
            if (newPointer == head)
            {
                newPointer = head;
                head = head->get_next();

                //check to see if head is Null then set tail to null
                if (head == NULL)
                {
                    tail = NULL;
                } 
                toDelete = newPointer;
                newPointer = newPointer->get_next();
                delete(toDelete)       
            }          
        }
        
    }  
    
}


template<class T>
int PQ<T>::get_count(void)
{
    Node<T> *itr = head;
    Node<T> *count;

    while (itr != NULL)
    {
        count = itr->get_data();
        itr = itr->get_next();
        
        if (count > 0)
        {
            return count;
        }
        else
        {
            return 0;
        }
        
    }
}


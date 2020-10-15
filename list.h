#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include "listExceptions.h"

template <class T>
class Node
{
    public:
    T data;
    Node* next;
   
};

template <class T>
class list
{
    private:
    Node<T> *dummyHead,*tail;
    int size;

    public:
    explicit list();
    ~list();
    list(list& other);
    int getSize() const;
    void addToEnd(const T& new_data);
    void addToStart(const T& new_data);
    void deleteEnd();
    void deleteStart();
    void addNode(unsigned int position,const T& new_data);
    void deleteNode(unsigned int position);
    T getData(unsigned int position);
    int find(const T& val);
    template<class U>
    friend std::ostream& operator<<(std::ostream &os, const list<U>& list); 
};

template<class T>
list<T>::list()
{ 
    try
    {
        dummyHead=new Node<T>();
        tail=nullptr;
        dummyHead->next=tail;
        size=0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

template<class T>
list<T>::list(list& other)
{
    this->dummyHead=new Node<T>();
    (this->dummyHead)->next=nullptr;
    this->size=other.getSize();
    Node<T> *temp=other.dummyHead;
    while ( temp->next!=nullptr)
    {
        this->addToEnd(temp->data);
        temp=temp->next;
    }
}

template<class T>
list<T>::~list()
{
    Node<T>* temp;
    size=size+2;
    while(!size)
    {
        temp=dummyHead->next;
        delete dummyHead;
        dummyHead=temp;
        size--;
    }
}

template<class T>
void list<T>::addToEnd(const T& new_data)
{
    try
    {
        Node<T>* new_node=new Node<T>();
        new_node->data=new_data;
        if (size==0)
        {
            tail=new_node;
            dummyHead->next=new_node;
            new_node->next=nullptr;
        }
        else
        {       
            tail->next=new_node;
            tail=new_node;
        }
        size++;
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
          
}

template<class T>
T list<T>::getData(unsigned int position)
{
    Node<T> *tmp=this->dummyHead;
    for(int i=0;i<position;i++)
    {
        tmp=tmp->next;
    }
    return tmp->data;
}

template<class T>
void list<T>::addToStart(const T& new_data)
{
    if (size==0)
    {
        addToEnd(new_data);
        return;
    }

     try
    {
        Node<T>* new_node=new Node<T>();
        new_node->data=new_data;
        new_node->next=dummyHead->next;
        dummyHead->next=new_node;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    size++;
}

template<class T>
void list<T>::deleteStart()
{
    if (size==0)
    {
        throw EmptyList();
    }
     Node<T> *temp;
    temp=dummyHead->next;
    dummyHead->next=temp->next;
    delete temp;
    size--;
}

template<class T>
void list<T>::deleteEnd()
{
    if (size==0)
    {
        throw EmptyList();
    }
     Node<T>* curr;
     Node<T>* prev;
    while(curr->next!=nullptr)
    {
        prev=curr;
        curr=curr->next;
    }
    tail=prev;
    delete curr;
    size--;
}

template<class T>
int list<T>::getSize() const
{
    return size;
}

template<class T>
std::ostream& operator<<(std::ostream &os, const list<T>& list) 
{
    Node<T>* temp=(list.dummyHead)->next;
    while (temp!=nullptr)
    {
        os<<temp->data;
        os<<",";
        temp=temp->next;
    }
    return os;
}

template<class T>
void list<T>::deleteNode(unsigned int position)
{
    if (size==0)
    {
        throw EmptyList();
    }

    if ((position==0) || (position>size))
    {
        throw OutOfRange();
    }
    else if (position==1)
    {
        deleteStart();
    }
    else if (position==size)
    {
        deleteEnd();
    }
    else
    {
         Node<T>* curr=dummyHead->next;
         Node<T>* prev;
        for (int i=0; i<position-1;i++)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        delete curr;
        size--;
    } 
}

template<class T>
int list<T>::find(const T& val)
{
    Node<T> *temp=(this->dummyHead)->next;
    int position=0;
    while(temp->next!=nullptr)
    {
        position++;
        if (temp->data==val)
        {
            return position;
        } 
        temp=temp->next;
    }
    return -1;
}

template<class T>
void list<T>::addNode(unsigned int position,const T& new_data)
{
    if ((position<1)||(position>size))
    {
        throw OutOfRange();
    }

    try
    {
        Node<T> *new_node= new Node<T>();
        Node<T> *previous=dummyHead->next;
        for (int i=0;i<position-1;i++)
        {
            previous=previous->next;
        }
        new_node->data=new_data;
        new_node->next=previous->next;
        previous->next=new_node;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    size++;
}

#endif
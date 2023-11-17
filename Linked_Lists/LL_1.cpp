#include <iostream>
using namespace std;

class DoublyList
{
    class Node
    {
    public:
        Node *next;
        void *data; // void pointer is a pointer which can point to any data type
        Node *prev;

        Node()
        {
            this->next = NULL;
            data = NULL;
            this->prev = NULL;
        }

        Node(void *data)
        {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
    };

    Node *head;
    Node *tail;
    int listSize;

public:
    DoublyList()
    {
        //when a non_paramterized constructor is called all node pointers are set to NULL;
        this->head = NULL;
        this->tail = NULL;
        listSize = 0;
    }
    DoublyList(void* data)
    {
        //when any datatype address to pass to DoublyList, It create an node which is on line 42 and head points to it; 
        this->head = new Node(data);
        //as we have head and a node ,now tail of node should points to head
        this->tail = head;
        listSize = 1;
    }

};

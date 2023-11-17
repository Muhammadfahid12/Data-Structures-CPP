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
        // when a non_paramterized constructor is called all node pointers are set to NULL;
        this->head = NULL;
        this->tail = NULL;
        listSize = 0;
    }
    DoublyList(void *data)
    {
        // when any datatype address to pass to DoublyList, It create an node which is on line 42 and head points to it;
        this->head = new Node(data);
        // as we have head and a node ,now tail of node should points to head
        this->tail = head;
        listSize = 1;
    }

    // to check the size of linkedlist;

    int size()
    {
        return listSize;
    }

    // reading data in at a given indexLinked List
    void *read(int index = -1)
    {
        Node *Slider = NULL;

        if (index >= 0)
        {
            Slider = head;

            for (int i = 0; i < index - 1; i++) // we use i < index -1 bcz 0 is first index and we use previous node pointer to point to next node or node_data,so we only need previous node to point to desired node
            {
                Slider = Slider->next;
            }
            return Slider->data;
        }

        else
        {
            Slider = tail;

            for (int i = -1; i < index; i++)
            {
                Slider = Slider->prev;
            }
            return Slider->data;
        }
    }

    //insertion in Linked_list

};

int main()
{
    int x = 45;

    int y = 44;

    int z = 46;

    DoublyList newList(&x);

    // cout << "size: "<<newList.size();
    int *ptr = (int *)newList.read(); // to assign a data_type to void function we use this type casting
    cout <<*ptr; // dereferncing pointer to get stored value
}

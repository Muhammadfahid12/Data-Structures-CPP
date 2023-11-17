#include <iostream>
#include <string>

using namespace std;

class DoublyList {

    private:

        class Node {

            public:

                Node* prev;
                void* data;
                Node* next;

                Node() {
                    this->prev = NULL;
                    this->data = NULL;
                    this->next = NULL;
                }

                Node(void* data) {
                    this->prev = NULL;
                    this->data = data;
                    this->next = NULL;
                }
        };

        Node* head;
        Node* tail;
        int listSize = 0;

    public:

        DoublyList() {
            this->head = NULL;
            this->tail = NULL;
            this->listSize = 0;
        }

        DoublyList(void* data) {
            this->head = new Node(data);//new returns pointer 
            this->tail = this->head;
            this->listSize = 1;
        }

        int size()  {
            return this->listSize;
        }

        void* read(int index = -1) {

            Node* slider = NULL;

            if (index >= 0)
            {
                slider = head;

                for (int i = 0; i < index - 1; i++)
                {
                    slider = slider->next;
                }
                return slider->data;
            }
            else
            {
                slider = tail;

                for (int i = -1; i < index; i--)
                {
                    slider = slider->prev;
                }
                return slider->data;
            }
        }

        void insert(void* data, int index = -1) {
            
            if (index == 0)
            {
                Node* oldHead = this->head;

                this->head->next = oldHead;

                oldHead->prev = this->head;

                oldHead->data = data;
                
                this->listSize += 1;
            }
            else if (index == -1)
            {
                
            }
            
            

        }

        void remove(int index = -1) {

            Node* slider = NULL;

            if (index == 0)
            {
                Node* oldHead = this->head;

                this->head = oldHead->next;

                this->head->prev = NULL;

                delete oldHead;

                this->listSize -= 1;
            }
            

            else if (index == -1 || index == (this->listSize -1))
            {
                Node* oldTail = this->tail;

                this->tail = oldTail->prev;
                this->tail->next = NULL;

                delete oldTail;

                this->listSize -= 1;
            }

            else
            {
                if (index >= 0)
                {
                    slider = head;

                    for (int i = 0; i < index - 1; i++)
                    {
                        slider = slider->next;
                    }
                    slider->prev->next = slider->next;
                    slider->next->prev = slider->prev;

                    delete slider;

                    this->listSize -= 1;
                }
                else
                {
                    slider = tail;

                    for (int i = -1; i < index; i--)
                    {
                        slider = slider->prev;
                    }
                    slider->prev->next = slider->next;
                    slider->next->prev = slider->prev;

                    delete slider;

                    this->listSize -= 1;
                }
            }
        }
};




int main() {

    int y = 5;

    int x = 10;
    
    int z = 15;
    
    DoublyList myList(&y);

    myList.insert(&x, 0);

    myList.insert(&z, 0);

    for (int  i = 0; i <= myList.size(); i++)
    {
        cout << "Int " << *((int*)myList.read(i)) << endl;
    }
    

    cout << "Size: " << myList.size() << endl;

    return 0;
}
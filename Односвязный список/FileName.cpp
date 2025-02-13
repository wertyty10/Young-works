#include <iostream>

using namespace std;

template<typename T>
class List
{
public:
    List()
    {
        size = 0;
        Head = nullptr;
    }

    ~List();

    int GetSize() { return size; }

    void push_back(T Data);

    void clear();

    void push_into(T Data, const int into);
  
    void delete_into(const int into);

    T& operator[](const int index);

private:
    template<typename T>
    class Node
    {
    public:

        Node(T Data = T(), Node* pNext = nullptr)
        {
            this->Data = Data;
            this->pNext = pNext;
        }

        Node* pNext;
        T Data;
    };

    Node<T>* Head;
    int size;
};

template<typename T>
List<T>::~List()
{
    clear();
}

template<typename T>
void List<T>::clear()
{
    while (size)
    {
        delete_into(0);
    }

}

template<typename T>
void List<T>::push_back(T Data)
{
    if (Head == nullptr)
    {
        Head = new Node<T>(Data);
        size++;
    }
    else
    {
        Node<T>* current = this->Head;

        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(Data);
        size++;
    }
}

template<typename T>
void List<T>::push_into(T Data, const int into)
{
    if (into < 0)
    {
        cout << "\nИндекс меньше количества узлов в списке!" << endl;;
    }
    else 
    {
        if (into > size)
        {
            cout << "\nИндекс больше количества узлов в списке!" << endl;;
        }
        else
        {
            if (into != size)
            {
                if (into == 0)
                {
                    Head = new Node<T>(Data, Head);
                }
                else
                {
                    Node<T>* previous = this->Head;

                    for (int i = 0; i < into - 1; i++)
                    {
                        previous = previous->pNext;
                    }

                    previous->pNext = new Node<T>(Data, previous->pNext);
                }
            }
            else
            {
                push_back(Data);
            }

            size++;
        }
    }
}



template<typename T>
void List<T>::delete_into(const int into)
{
    if (into < 0)
    {
        cout << "\nИндекс меньше количества узлов в списке!" << endl;;
    }
    else
    {
        if (into >= size)
        {
            cout << "\nИндекс больше количества узлов в списке!" << endl;;
        }
        else
        {
            if (into != size)
            {
                if (into == 0)
                {
                    Node<T>* temp = this->Head;

                    Head = Head->pNext;                   
                    delete temp;                       
                }
                else
                {
                    Node<T>* current1 = this->Head;
                    Node<T>* current2 = this->Head;
                    Node<T>* temp = this->Head;

                    for (int i = 0; i < into - 1; i++)
                    {
                        current1 = current1->pNext;
                    }  

                    for (int i = 0; i < into + 1; i++)
                    {
                        current2 = current2->pNext;
                    }

                    temp = current1->pNext;
                    
                    delete temp;
                    
                    current1->pNext = current2;
                }
            }
            size--;
        }
    }
}

template<typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0;

    Node<T>* current = this->Head;
    while (true)
    { 
        if (counter == index)
        {
            return current->Data;
        }
        
        current = current->pNext;
        counter++;
    }
        
}

int main()
{

    setlocale(LC_ALL, "rus");

    List<int> st1;

    st1.push_back(3763);
    st1.push_back(2);
    st1.push_back(258);
    st1.push_back(57);
    st1.push_back(479);



    for (int i = 0; i < st1.GetSize(); i++)
    {
        cout << st1[i] << " ";
    }  

    st1.push_into(78, 3);

    cout << endl;

    for (int i = 0; i < st1.GetSize(); i++)
    {
        cout << st1[i] << " ";
    }
    cout <<endl<< st1.GetSize() << endl;
    return 0;
}
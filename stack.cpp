/*
The purpose of this program is to implement a stack
and queue then test to see if they are identical and have
matching group symbols.
*/

#include <iostream>

using namespace std;


//--------Stack-----------


template <class T>
class Stack
{
    private:
        struct node
        {
            T data;
            int index;
            node *next;
        };
        node *head;

        int stackSize;
        int sizeHold;
    public:
        Stack()
        {
            head = NULL;
            stackSize = 0;
            sizeHold = 0;
        }
        ~Stack();

        void push(T);
        void pop();
        T top();
        T index(int);
        bool isEmpty() const;
        int Size()
        {
            return sizeHold;
        }
};

template <class T>
Stack<T>::~Stack()
{
    node *nodePtr, *next;

    nodePtr = head;

    while(nodePtr != NULL)
    {
        next = nodePtr->next;
        delete nodePtr;
        nodePtr = next;
    }
    head = NULL;
}

template <class T>
void Stack<T>::push(T value)
{
    node *newNode;
    node *nodePtr;

    newNode = new node;
    newNode->data = value;

    if(isEmpty())
    {
        head = newNode;
        newNode->next = NULL;
        newNode->index = 0;
    }
    else
    {
        newNode->next = head;
        newNode->index = 0;
        head = newNode;

        int counter = 1;
        nodePtr = head->next;

        while(nodePtr->next != NULL)
        {
            nodePtr->index = counter;
            nodePtr = nodePtr->next;
            counter++;
        }
    }

    stackSize++;
    sizeHold++;
}

template <class T>
void Stack<T>::pop()
{
    node *newHead;
    node *nodePtr;

    if(isEmpty())
    {
        return;
    }

    else
    {
        if(stackSize == 1)
        {
            delete head;
            head = NULL;
        }
        else
        {
            newHead = head->next;
            delete head;
            head = newHead;

            nodePtr = newHead;
            while(nodePtr->next != NULL)
            {
                int spot = nodePtr->index;
                nodePtr->index = (spot - 1);
                nodePtr = nodePtr->next;
            }
        }

    }
    stackSize--;
}

template <class T>
T Stack<T>::top()
{
    return head->data;
}

template <class T>
T Stack<T>::index(int num)
{
    if(num > stackSize || num < 0)
    {
        cout << "Index doesn't exist....returning 999: ";
        return 999;
    }

    node *nodePtr;

    nodePtr = head;

    while(nodePtr->next != NULL && nodePtr->index != num)
    {
        nodePtr = nodePtr->next;
    }

    return nodePtr->data;
}

template <class T>
bool Stack<T>::isEmpty() const
{
    bool status;

    if(!head)
        status = true;
    else
        status = false;

    return status;
}



// -------Queue--------



template <class T>
class Queue
{
    private:
        struct node
        {
            T data;
            int index;
            node *next;
        };
        node *head;
        node *first;
        node *last;

        int queueSize;
        int sizeHold;
    public:
        Queue()
        {
            head = NULL;
            first = NULL;
            last = NULL;
            queueSize = 0;
            sizeHold = 0;
        }
        ~Queue();

        void enqueue(T);
        void dequeue();
        T First();
        T Last();
        T index(int);
        bool isEmpty() const;
        int Size()
        {
            return sizeHold;
        }
};

template <class T>
Queue<T>::~Queue()
{
    node *nodePtr, *next;

    nodePtr = head;

    while(nodePtr != NULL)
    {
        next = nodePtr->next;
        delete nodePtr;
        nodePtr = next;
    }
    head = NULL;
}

template <class T>
void Queue<T>::enqueue(T value)
{
    node *newNode;
    node *nodePtr;
    node *finder;

    newNode = new node;
    newNode->data = value;
    newNode->next = NULL;

    if(isEmpty())
    {
        head = newNode;
        //newNode->next = NULL;
        newNode->index = 0;
        //first = newNode;
        //last = newNode;
    }
    else
    {
        finder = head;
        while(finder->next != NULL)
            finder = finder->next;

        finder->next = newNode;
        last = newNode;

        int counter = 1;
        nodePtr = head->next;
        while(nodePtr->next != NULL)
        {
            nodePtr->index = counter;
            nodePtr = nodePtr->next;
            counter++;
        }
    }

    queueSize++;
    sizeHold++;
}

template <class T>
void Queue<T>::dequeue()
{
    node *newHead;
    node *nodePtr;

    if(isEmpty())
    {
        return;
    }
    else
    {
        if(queueSize == 1)
        {
            delete head;
            head = NULL;
        }
        else
        {
            newHead = head->next;
            delete head;
            head = newHead;
            first = newHead;

            nodePtr = newHead;
            while(nodePtr->next != NULL)
            {
                int spot = nodePtr->index;
                nodePtr->index = (spot - 1);
                nodePtr = nodePtr->next;
            }
        }
    }
    queueSize--;
}

template <class T>
T Queue<T>::First()
{
    return head->data;
}

template <class T>
T Queue<T>::Last()
{
    return last->data;
}

template <class T>
T Queue<T>::index(int num)
{
    if(num > (queueSize-1) || num < 0)
    {
        cout << "Index doesn't exist....";
    }

    node *nodePtr;

    nodePtr = head;

    while(nodePtr->next != NULL && nodePtr->index != num)
        nodePtr = nodePtr->next;


    return nodePtr->data;
}

template <class T>
bool Queue<T>::isEmpty() const
{
    bool status;

    if(!head)
        status = true;
    else
        status = false;

    return status;
}



int main()
{
    bool again = true;
    bool noStackSemi = true; // Check for Stack semicolon
    bool noQueueSemi = true; // Check for Queue semicolon
    bool sameLength = true;  // Check if Stack and Queue are same length
    bool SameValues = true;  // Check if Stack and Queue have the same values
    bool matchSymbol = false;// Check if Stack has matching group symbols
    int input;               // input (1 or 9)
    char sValue,             // Stack value to push
         qValue;             // Queue value to push

    cout << "*** Welcome to My stack / Queue Program ***\n\n"
            "The function of this program is to :\n"
            "      1-   Validate that a stack and a\n"
            "           queue are identical.\n"
            "           Stacks / queues are same if\n"
            "           they have the same number of elements, symbols,\n"
            "           and their elements and symbols at the\n"
            "           corresponding positions are the same.\n\n"

            "      2-   The program also outputs whether the elements\n"
            "           do have the same matching group symbols.\n\n\n";
    while(again)
    {
        Stack<char> tempCharStack;  // Temporary stack (will be reversed)
        Stack<char> realCharStack;  // Real stack to be used (reversed temp stack)

        Queue<char> charQ;

        try
        {
            cout << "Select from the following menu\n"
                    "1.   Enter Stack / Queue Values.\n"
                    "9.   Terminate the Program.    ";
            cin >> input;

            if(cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                throw input;
            }
            else if(input > 1 && input < 9)
                throw input;
            else if(input < 1 || input > 9)
                throw input;

            switch(input)
            {
            case 1:
                cout << "\nEnter Stack Values terminated by ;    ";
                while(noStackSemi)
                {
                    cin >> sValue;
                    if(sValue == ';')   // If semicolon is entered, loop will end
                        noStackSemi = false;
                    else
                        tempCharStack.push(sValue);
                }
                for(int i = 0; i < tempCharStack.Size(); i++)
                    realCharStack.push(tempCharStack.index(i)); // Reversing stack

                cout << "Enter Queue Values terminated by ;    ";
                while(noQueueSemi)
                {
                    cin >> qValue;

                    if(qValue == ';')   // If semicolon is entered, loop will end
                        noQueueSemi = false;
                    else
                        charQ.enqueue(qValue);
                }

                if(realCharStack.Size() != charQ.Size()) // Check to see if they're the same
                    sameLength = false;                  // length
                else
                {
                    for(int i = 0; i < charQ.Size(); i++)
                    {
                        if(realCharStack.index(i) != charQ.index(i))
                        {
                            SameValues = false;          // checking to see if they have the
                            break;                       // same values
                        }
                    }
                }
                if(!sameLength || !SameValues)
                    cout << "\nStack and Queue are not identical\n";
                else
                    cout << "\nStack and Queue are identical\n";

                for(int i = 0; i < realCharStack.Size(); i++)
                {
                    char check = realCharStack.index(i);
                    switch(check) // If check == (,{,[, or <, switch
                    {             // will execute
                    case '(':
                        for(int j = i + 1; j < realCharStack.Size(); j++)
                        {
                            if(realCharStack.index(j) == ')') // checking stack for
                            {                                 // matching symbol
                                matchSymbol = true;
                                break;
                            }
                        }
                        break;
                    case '{':
                        for(int j = i + 1; j < realCharStack.Size(); j++)
                        {
                            if(realCharStack.index(j) == '}') // checking stack for
                            {                                 // matching symbol
                                matchSymbol = true;
                                break;
                            }
                        }
                        break;
                    case '[':
                        for(int j = i + 1; j < realCharStack.Size(); j++)
                        {
                            if(realCharStack.index(j) == ']') // checking stack for
                            {                                 // matching symbol
                                matchSymbol = true;
                                break;
                            }
                        }
                        break;
                    case '<':
                        for(int j = i + 1; j < realCharStack.Size(); j++)
                        {
                            if(realCharStack.index(j) == '>') // checking stack for
                            {                                 // matching symbol
                                matchSymbol = true;
                                break;
                            }
                        }
                        break;
                    }
                }
                if(matchSymbol == true)
                    cout << "\nFirst Expression does have matching grouping symbols\n\n\n";
                else
                    cout << "\nFirst Expression does not have matching grouping symbols\n\n\n";

                break;
            case 9:
                again = false;
                break;
            }

            noStackSemi = true; // Bool variables must be reset
            noQueueSemi = true;
            sameLength = true;
            SameValues = true;
            matchSymbol = false;
        }catch(...)
        {
            cout << "\nInvalid Option\n\n";
        }
    }

    cout << "\n\n*** Program is terminated. Written by Brandon Alfred ***\n";

    return 0;
}


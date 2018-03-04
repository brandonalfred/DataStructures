/*
The purpose of this program is to show different methods
of using a linked list.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class linkedList
{
    private:
        struct node
        {
            int data;
            node *next;
        };
        node *head;

    public:
       linkedList()
       {
           head = NULL;
           listSize = 0;
       }
       int listSize;

       void appendNode(int);
       void appendNodeFront(int);
       void insertNode(int,int);
       void removeNode(int);
       void removeNodePos(int);
       void searchList(int);
       void fillList();
       void displayList();
       void sortList();
       void splitList();
       void removeDups();
       void rotateList();
       void printReverse();
       void printReverseRecursive(node *n);
       void clearList();
       bool isPresent(node*,int);
       void getUnion(node*,node*);
       void getIntersect(node*,node*);
};

int main()
{
    cout << "Welcome to Brandon's Linked List Manipulation Program." << endl;
    cout << endl;



    char answer = 'y';
    bool again = true;
    bool noFail = true;

    while(again)
    {
        try
        {
            if(noFail)
            {
                linkedList obj;

                obj.fillList();
                obj.sortList();
                obj.displayList();

                cout << "\nMain list after inserting new number -100 at the beginning:\n";
                obj.appendNodeFront(-100);
                obj.displayList();

                cout << "\nMain list after inserting new number 15 at the third location:\n";
                obj.insertNode(15,3);
                obj.displayList();

                cout << "\nMain list after appending new number 1000:\n";
                obj.appendNode(1000);
                obj.displayList();

                cout << "\nMain list after removing number 5:\n";
                obj.removeNode(5);
                obj.displayList();

                cout << "\nMain list after removing second element:\n";
                obj.removeNodePos(2);
                obj.displayList();

                cout << "\nMain list after rotating the list one position to the right:\n";
                obj.rotateList();
                obj.displayList();

                cout << endl;
                obj.searchList(17);
                cout << endl;
                obj.displayList();

                cout << "\nDisplaying the main list backward:\n";
                obj.printReverse();

                obj.splitList();

                cout << "\nMain list after deleting duplicate numbers:\n";
                obj.removeDups();
                obj.displayList();

                cout << "\nDelete the entire main list.\n\n";
                obj.clearList();

                obj.searchList(35);
            }

            cout << "\nWould you like to re-run the program again?"
                 << "\nEnter Y or N   --->   ";
            cin >> answer;
            cout << endl;

            if(!cin.fail())
                noFail = true;
            else if(answer == 'y' || answer == 'Y' || answer == 'n' || answer== 'N')
                noFail = true;


            if(cin.fail())
                throw answer;
            else if(answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N')
                throw answer;


            if(answer == 'n' || answer == 'N')
            {
                cout << "\nThis LL program is implemented by Brandon Alfred"
                     << "\nMarch - 2017\n";
                again = false;

            }
        }catch(...)
        {
            cout << "\nError *** Invalid selection " << answer
                 << " - Must enter y|Y or n|N\n";
            noFail = false;
        }
    }

    return 0;
}

void linkedList::appendNode(int num)
{
    node *newNode;
    node *nodePtr;

    newNode = new node;
    newNode->data = num;
    newNode->next = NULL;

    if(!head)
        head = newNode;
    else
    {
        nodePtr = head;

        while(nodePtr->next)
            nodePtr = nodePtr->next;

        nodePtr->next = newNode;
    }

    listSize++;
}

void linkedList::appendNodeFront(int num)
{
    node *newNode;
    node *nodePtr;

    newNode = new node;
    newNode->data = num;

    nodePtr = head;
    head = newNode;

    newNode->next = nodePtr;
    listSize++;
}

void linkedList::insertNode(int num, int pos)
{
    node *prev;
    node *curr;
    node *newNode = new node;

    newNode->data = num;

    int tempPos = 1;

    curr = head;

    while(curr->next != NULL && tempPos != pos)
    {
        prev = curr;
        curr = curr->next;
        tempPos++;
    }

    prev->next = newNode;
    newNode->next = curr;
    listSize++;
}

void linkedList::removeNode(int num)
{
    node *nodePtr;
    node *prev;

    //cout << head << endl;
    if(!head)
    {
        cout <<  "List is empty" << endl;
        return;
    }


    if(head->data == num)
    {
        nodePtr = head->next;
        delete head;
        listSize--;
        head = nodePtr;
    }
    else
    {

        nodePtr = head;

        int attempts = 0;

        while(nodePtr != NULL && nodePtr->data != num)
        {
            prev = nodePtr;
            nodePtr = nodePtr->next;
            attempts++;
        }

        if(attempts == listSize)
        {
            cout << "Item not found...\n";
            return;
        }
        else if(nodePtr)
        {
            prev->next = nodePtr->next;
            delete nodePtr;
            listSize--;
        }
    }
}

void linkedList::removeNodePos(int pos)
{
    node *temp;
    node *ahead;
    node *curr;
    node *ptr = head;

    if(!head)
    {
        cout <<  "List is empty" << endl;
        return;
    }

    curr = head;
    ahead = head;

    if(pos == 0)
    {
        head = ptr->next;
        delete ptr;
        listSize--;
        return;
    }


    for(int i = 0; curr != NULL && i < pos-1; i++)
        curr = curr->next;

    for(int i = 0; curr != NULL && i < pos+1; i++)
        ahead = ahead->next;

    if(curr == NULL || curr->next == NULL)
    {
        cout << "Not found..." << endl;
        return;
    }


    temp = curr;
    delete curr->next;

    temp->next = ahead;
    listSize--;
}

void linkedList::fillList()
{
    cout << "A sorted main list of 19 random integer numbers that are between 10 and 20 are"
            "\nas follows:" << endl;

    srand(time(0));

    for(int i = 0; i < 19; i++)
    {
        int num = (rand()%11) + 10;
        appendNode(num);
    }
}

void linkedList::displayList()
{
    if(!head)
    {
        cout << "\nList is empty\n";
        return;
    }

    node *nodePtr;

    nodePtr = head;

    while(nodePtr)
    {
        cout << nodePtr->data << " ";
        nodePtr = nodePtr->next;
    }
    cout << endl;
}

void linkedList::searchList(int num)
{
    cout << "Searching the main list for item number " << num << ": ";

    if(!head)
    {
        cout << "List is empty\n";
        return;
    }

    node *nodePtr = head;
    int pos = 0;

    while(nodePtr != NULL && nodePtr->data != num)
    {
        nodePtr = nodePtr->next;
        pos++;
    }

    if(nodePtr != NULL)
    {
        cout << "Item found at location " << pos << endl;
    }
    else
    {
        cout << "Item not found\n";
    }
}

void linkedList::sortList()
{
    for (node *index = head; index->next != NULL; index = index->next)
    {
        for (node *selection = index->next; selection != NULL; selection = selection->next)
        {
            if (index->data >= selection->data)
            {
                swap(index->data, selection->data);
            }
        }
    }
}

void linkedList::splitList()
{
    node *og = head;
    int counter = 0;

    linkedList small;
    linkedList big;

    for(; og != NULL; og = og->next)
    {
        int x = og->data;
        if(counter < 10)
            small.appendNode(x);
        else
            big.appendNode(x);
        counter++;
    }

    cout << "\n\nSplitting the main list into 2 sub lists (sub_List_1 and sub_List_2).\n";
    cout << "\nSub_List_1:\n";
    small.displayList();

    cout << "\nSub_List_2:\n";
    big.displayList();

    getUnion(small.head,big.head);
    getIntersect(small.head,big.head);
}

void linkedList::removeDups()
{
    if(!head)
        return;

    node *curr = head;
    node *aux;

    while(curr->next != NULL)
    {
        if(curr->data == curr->next->data)
        {
            aux = curr->next->next;
            delete curr->next;
            listSize--;
            curr->next = aux;
        }
        else
        {
            curr = curr->next;
        }
    }
}

void linkedList::rotateList()
{
    if(!head)
    {
        cout <<  "List is empty" << endl;
        return;
    }

    if(listSize == 1)
    {
        cout << "not enough nodes\n";
        return;
    }

    node *endOf;
    node *prev;

    endOf = head;

    while(endOf->next != NULL)
    {

        prev = endOf;
        endOf = endOf->next;

    }

    endOf->next = head;
    head = endOf;

    prev->next = NULL;
}

void linkedList::printReverse()
{
    printReverseRecursive(head);
}

void linkedList::printReverseRecursive(node *n)
{
    if(n)
    {
        printReverseRecursive(n->next);
        cout << n->data << " ";
    }
}

void linkedList::clearList()
{
    node *first = head;
    //node *temp;

    while(first)
    {
        node *ptr = first->next;
        delete first;
        first = NULL;
        first = ptr;
        listSize--;
    }
    head = NULL;
}

bool linkedList::isPresent(node *head9, int num)
{
    node *temp = head9;

    while(temp != NULL)
    {
        if(temp->data == num)
            return true;
        temp = temp->next;
    }
    return false;
}

void linkedList::getUnion(node *head1, node *head2)
{
    linkedList result;
    node *t1 = head1;
    node *t2 = head2;

    while(t1 != NULL)
    {
        result.appendNode(t1->data);
        t1 = t1->next;
    }

    while(t2 != NULL)
    {
        if(!isPresent(result.head,t2->data))
            result.appendNode(t2->data);
        t2 = t2->next;
    }

    cout << "\nUnion of the sub lists:\n";
    result.displayList();
}

void linkedList::getIntersect(node *head1, node *head2)
{
    linkedList result;
    node *t1 = head1;

    while(t1 != NULL)
    {
        if(isPresent(head2,t1->data))
            result.appendNode(t1->data);
        t1 = t1->next;
    }

    cout << "\nIntersection of the sub lists:\n";
    result.displayList();
}

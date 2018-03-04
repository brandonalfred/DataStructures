#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class hashTable
{
    private:
        static const int SIZE = 30;
        int arr[SIZE];
        int hashCount;
        int probeCount;
    public:
        hashTable();
        void display();
        void searchNum(int);
        bool isTaken(int);
        void deleteNum(int);
        int Hash(int);
        void insertNum(int);
        int getHashCount();
        int getProbeCount();
};

int main()
{
    int input;
    int numSearch;
    int numDelete;
    int numHash;
    bool again = true;

    hashTable a;

    cout << "Brandon Alfred\n\n"

            "The function of this program is to\n"
            "create a hash table of numbers\n"
            "between 100 and 500 inclusive.\n\n"
            "Generated array:\n";
            a.display();

    while(again)
    {
        try
        {
            cout << "\nSelect from the following menu\n"
                    "1.   Display the hash table.\n"
                    "2.   Search for a number.\n"
                    "3.   Insert a new number.\n"
                    "4.   Delete a number.\n"
                    "9.   Terminate the Program.     ";
            cin >> input;

            if(cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                throw input;
            }
            else if(input < 1)
                throw input;
            else if(input > 4 && input < 9)
                throw input;
            else if(input > 9)
                throw input;

            switch(input)
            {
            case 1:
                a.display();
                break;
            case 2:
                cout << "\nEnter the number you want to find: ";
                cin >> numSearch;
                a.searchNum(numSearch);
                break;
            case 3:
                cout << "\nEnter the number you want to hash: ";
                cin >> numHash;
                a.insertNum(numHash);
                break;
            case 4:
                cout << "\nEnter the number you want to delete: ";
                cin >> numDelete;
                a.deleteNum(numDelete);
                break;
            case 9:
                again = false;
                break;
            }

        }catch(...)
        {
            cout << "\n*** Invalid Option ***\n\n";
        }
    }

    cout << "\nHashes done: " << a.getHashCount();
    cout << "\nProbes done: " << a.getProbeCount();

    cout << "\n\nDeveloped by Brandon Alfred & Eric Ross\n"
            "April 2017\n";

    return 0;
}

hashTable::hashTable()
{
    hashCount = 0;
    probeCount = 0;

    for(int i = 0; i < SIZE; i++)
        arr[i] = -1;

    srand(time(0));

    for(int i = 0; i < 15; i++)
    {
        int num = (rand()%401) + 100;
        if(isTaken(Hash(num)))
        {
            int spot = Hash(num);
            while(isTaken(spot))
            {
                if(spot == 29)
                    spot = 0;

                spot++;
                probeCount++;
            }
            hashCount++;
            arr[spot] = num;
        }
        else
        {
            arr[Hash(num)] = num;
            hashCount++;
        }

    }
}

void hashTable::display()
{
    cout << endl;
    for(int i = 0; i < SIZE; i++)
    {
        if(i == 15)
            cout << endl;
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void hashTable::searchNum(int num)
{
    cout << "\nSearching for " << num << ".....\n";

    bool found = false;

    for(int i = 0; i < SIZE; i++)
    {
        if(arr[i] == num)
        {
            found = true;
            break;
        }
    }

    if(found == true)
        cout << num << " is in the hash table\n";
    else
        cout << num << " is NOT in the hash table\n";
}

bool hashTable::isTaken(int pos)
{
    return arr[pos] != -1;
}

void hashTable::deleteNum(int num)
{
    cout << "\nDeleting " << num << ".....\n";

    bool found = false;

    for(int i = 0; i < SIZE; i++)
    {
        if(arr[i] == num)
        {
            found = true;
            arr[i] = -1;
        }
    }

    if(found == true)
        cout << num << " was deleted\n";
    else
        cout << num << " is NOT in the hash table\n";
}

int hashTable::Hash(int num)
{
    //hashCount++;
    return num % SIZE;
}

void hashTable::insertNum(int num)
{
    int spot = Hash(num);
    while(isTaken(spot))
    {
        if(spot == 29)
            spot = 0;

        spot++;
        probeCount++;
    }
    arr[spot] = num;
    hashCount++;
}

int hashTable::getHashCount()
{
    return hashCount;
}

int hashTable::getProbeCount()
{
    return probeCount;
}

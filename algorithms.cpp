/*
The purpose of this program is to create an array
then modify it using various recursive functions.
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

void sqrTable(int);
int power(int,int);
int sumOfSquares(int);
int maxMember(int*, int, int);
void bubbleSort(int*, int);
bool isMemberLin(int*, int, int);
bool isMemberBin(int*, int, int);
void isItPrime(int*, int);
bool isPrime(int);

int main()
{
    int SIZE;
    char input;

    bool again = true;

    cout << "Thinking Recursively\n\n"

            "The function of this program is to\n"
            "use recursion to  :-\n\n"

            "      1. Display squares of integers in ascending\n"
            "         order from 1 to the last element in the array\n"
            "      2. Raise the first number to a power 2\n"
            "      3. Return the sums of squares of the numbers\n"
            "         from 0 to the fifth element in the array\n"
            "      4. Search the array for the array's min and max values\n"
            "      5. Sort the array in ascending order\n"
            "      6. Search the array for the first value in the array\n"
            "      7. Search the array for the number 600\n"
            "      8. Determine if a number is prime (processes all array values)\n\n";
    while(again)
    {
        try
        {
            cout << "Select from the following menu\n"
                    "A.   Enter Array Size that is > 4.\n"
                    "X.   Terminate the Program.     ";
            cin >> input;

            if(cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                throw input;
            }
            else if(input != 'A' && input != 'a' && input != 'X' && input != 'x')
                throw input;

            switch(input)
            {
            case 'A':
            case 'a':
                {
                    bool isNotRightSize = true;
                    while(isNotRightSize)
                    {
                        try
                        {
                            cout << "\nEnter Array Size: ";
                            cin >> SIZE;

                            if(cin.fail())
                            {
                                char caught = SIZE;
                                cin.clear();
                                cin.ignore(1000, '\n');
                                throw caught;
                            }
                            else if(SIZE <= 4)
                                throw SIZE;
                            else
                                isNotRightSize = false;
                        }
                        catch(char x)
                        {
                            cout << "\n*** Invalid Array Size Value ***\n"
                                    "Enter an integer not a char: ";
                            cin >> SIZE;
                            while(SIZE <= 4 || cin.fail())
                            {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                cout << "\n*** Invalid Array Size Value ***\n"
                                        "Enter Array Size That is > 4: ";
                                cin >> SIZE;
                            }
                            cout << endl;
                            isNotRightSize = false;
                        }
                        catch(int x)
                        {
                            cout << "\n*** Invalid Array Size Value ***\n"
                                    "Enter Array Size That is > 4: ";
                            cin >> SIZE;
                            while(cin.fail() || SIZE <= 4)
                            {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                cout << "\n*** Invalid Array Size Value ***\n"
                                        "Enter an integer not a char: ";
                                cin >> SIZE;
                            }
                            cout << endl;
                            isNotRightSize = false;
                        }
                    }

                    srand(time(0));
                    int arr[SIZE];

                    for(int i = 0; i < SIZE; i++)
                    {
                        int num = (rand()%476) + 25;
                        arr[i] = num;
                    }

                    cout << "\nThe generated array is: ";
                    for(int i = 0; i < SIZE; i++)
                        cout << arr[i] << "  ";

                    int last = arr[SIZE-1];
                    int first = arr[0];
                    int fourth = arr[3];
                    int secondToLast = arr[SIZE-2];

                    cout << "\n\nTable of square values 1 - " << last;
                    sqrTable(last);

                    cout << "\nPower Function:\n";
                    cout << first << " raised to the 2nd power is: " << power(first, 2);
                    cout << endl;

                    cout << "\nSum of squares between 0 and " << secondToLast << " is: "
                         << sumOfSquares(secondToLast);

                    cout << "\n\nMin number of ( ";
                    for(int i = 0; i < SIZE; i++)
                    {
                        cout << arr[i];
                        if(i != SIZE - 1)
                            cout << " , ";
                    }
                    cout << " )\n"
                            "is : " << maxMember(arr,SIZE,0);

                    cout << "\n\nMax number of ( ";
                    for(int i = 0; i < SIZE; i++)
                    {
                        cout << arr[i];
                        if(i != SIZE - 1)
                            cout << " , ";
                    }
                    cout << " )\n"
                            "is : " << maxMember(arr,SIZE,1);

                    cout << "\n\nSorted array\n";
                    bubbleSort(arr, SIZE);
                    for(int i = 0; i < SIZE; i++)
                        cout << arr[i] << "  ";

                    fourth = arr[3];

                    cout << "\n\nMember Functions:\n"
                            "Does the array: ";

                    for(int i = 0; i < SIZE; i++)
                        cout << arr[i] << "  ";
                    cout << "have the number\n"
                         << fourth << "? ";
                    if(isMemberLin(arr, SIZE, fourth) == true)
                        cout << "YES\n";
                    else
                        cout << "NO\n";

                    cout << "Does the array: ";
                    for(int i = 0; i < SIZE; i++)
                        cout << arr[i] << "  ";
                    cout << "have the number\n"
                         << 600 << "? ";
                    if(isMemberBin(arr, SIZE, 600) == true)
                        cout << "YES\n";
                    else
                        cout << "NO\n";

                    isItPrime(arr,SIZE);

                    cout << endl << endl;

                    break;
                }
            case 'X':
            case 'x':
                {
                    again = false;
                    break;
                }
            }
        }catch(...)
        {
            cout << "\n*** Invalid Option ***\n\n";
        }
    }

    cout << "\n\nBrandon Alfred - Tweak Development Director\n"
            "April 2017\n";

    return 0;
}

void sqrTable(int n)
{
    if(n > 0)
    {
        sqrTable(n-1);
        cout << n << "\t" << (n*n) << endl;
    }
    else
        cout << "\n\nN\tN Squared\n";
}

int power(int x, int y)
{
    if(y == 0)
        return 1;
    else if(y == 1)
        return x;
    else
        return (x * power(x, y - 1));
}

int sumOfSquares(int n)
{
    if(n == 1)
        return 1;
    else
        return (n * n) + sumOfSquares(n - 1);
}

int maxMember(int* arr, int length, int n)
{
    if(n == 1)
    {
        if(length == 1)
            return arr[0];

        return maxMember(arr, length - 1, n) > arr[length - 1] ?
               maxMember(arr, length - 1, n) : arr[length - 1];
    }
    else
    {
        if(length == 1)
            return arr[0];

        return maxMember(arr, length - 1, n) < arr[length - 1] ?
               maxMember(arr, length - 1, n) : arr[length - 1];
    }
}

void bubbleSort(int *arr, int n)
{
    if (n == 1)
        return;

    for (int i = 0; i < (n-1); i++)
        if (arr[i] < arr[i+1])
            swap(arr[i], arr[i+1]);

    bubbleSort(arr, n-1);
}

bool isMemberLin(int *arr, int length, int num)
{
    if(length < 0)
        return false;
    if(arr[length] == num)
        return true;

    isMemberLin(arr, length - 1, num);
}

bool isMemberBin(int *arr, int length, int num)
{
    return length == 0 ? false
         : arr[length / 2] == num ? true
         : arr[length / 2] < num ? isMemberBin(arr, length / 2, num)
         : isMemberBin(arr + (length / 2 + 1), length - (length / 2 + 1), num);
}

void isItPrime(int *arr, int length)
{

    if(length >= 0)
    {
        isItPrime(arr, length - 1);

        if((length - 1) == -1)
            return;

        if(isPrime(arr[length-1]))
            cout << "\nThe number " << arr[length-1] << " is Prime";
        else
            cout << "\nThe number " << arr[length-1] << " is Not Prime";
    }
    else
        cout << "\nIs it prime:";
}

bool isPrime(int N) // Bool function to check if a number is prime or not
{
    for(int i = 2; i < N ; i++)
        if (N % i == 0)
            return false;

    return true;
}

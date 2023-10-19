#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char const *argv[])
{
    srand((unsigned int) time(NULL));
    int number = rand() % 100 + 1;
    int guess = 0;
    do
    {
        cout<< "Enter the guess(1-100): ";
        cin>> guess;

        if (guess>number)
        {
            cout<< "Guess is lower! Try again" << endl;
        }
        else if (guess<number)
        {
            cout<< "Guess is high! Try again"<< endl;
        }
        else
        {
            cout<<"You Won!"<< endl;
        }
        
    } while (guess != number);
    
    return 0;
}

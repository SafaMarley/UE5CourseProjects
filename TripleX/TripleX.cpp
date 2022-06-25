#include <iostream>
#include <ctime>

void PrintIntroduction()
{
    std::cout << "\nYou forgot the pin code of your phone...\n";
    std::cout << "You need to enter the correct codes to continue.\n";
    std::cout << std::endl;
}

bool PlayGame(int Level, int MaxLevel)
{

    const int CodeX = rand() % (Level + 1) + Level;
    const int CodeY = rand() % (Level + 1) + Level;
    const int CodeZ = rand() % (Level + 1) + Level;

    const int CodeSum = CodeX + CodeY + CodeZ;
    const int CodeProduct = CodeX * CodeY * CodeZ;

    std::cout << MaxLevel - Level << " more codes to go.\n";
    std::cout << "- There are 3 numbers in the code." << std::endl;
    std::cout << "- The codes are add-up to: " << CodeSum << std::endl;
    std::cout << "- The product of the codes are: " << CodeProduct << std::endl;

    int GuessX;
    int GuessY;
    int GuessZ;
    std::cin >> GuessX >> GuessY >> GuessZ;

    int GuessSum = GuessX + GuessY + GuessZ;
    int GuessProduct = GuessX * GuessY * GuessZ;

    if (CodeSum == GuessSum && CodeProduct == GuessProduct)
    {
        std::cout << "Your guess is true, moving on to next pin code.\n";
        return true;
    }
    else
    {
        std::cout << "Your guess is false, try again.\n";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    int Level = 1;
    const int MaxLevel = 6;
    PrintIntroduction();
    bool Completed;
    while (Level < MaxLevel)
    {
        Completed = PlayGame(Level, MaxLevel);
        std::cin.clear();
        std::cin.ignore();
        if (Completed)
        {
            Level++;
        }
    }
    std::cout << "Congrats! You unlocked your phone.";
    return 0;
}

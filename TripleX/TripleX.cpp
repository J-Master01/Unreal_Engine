#include <iostream>

void PrintIntroduction(int Difficulty)
{
        // Print welcome messages to terminal
    std::cout << "\nYou are a jealous and insecure person and you suspect your partner has been being unfaithful!\n";
    std::cout << "You need to break into their security rated " << Difficulty << " phone and look for evidence!\n";
    std::cout << "You need to find the correct combination before your partner wakes up!\n\n" ;
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    //Declare 3 number code
    int CodeA = rand()%10;
    int CodeB = rand()%10;
    int CodeC = rand()%10;

    int CodeSum = CodeA+CodeB+CodeC;
    int CodeProduct = CodeA*CodeB*CodeC;

    // Print sum & product to terminal
    std::cout << "There are 3 numbers in the code.\n\n";
    std::cout << "The numbers add up to " << CodeSum;
    std::cout << "\nThe numbers multiply to give " << CodeProduct << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    
    int GuessSum = GuessA+GuessB+GuessC;
    int GuessProduct = GuessA*GuessB*GuessC;


    // Check if the play guess is correct
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou were right! That bitch was cheating!! Advance to the next level.\n";
        return true;
    }
    else
    {
        std::cout << "\nUh-oh! She woke up and left your jealous ass. Luckily you get to try again.\n";
        return false;
    }
}


int main()
{
    int LevelDifficulty = 1;
    const int MaxDifficulty =5;

    while (LevelDifficulty <= MaxDifficulty) // Loop until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {

            ++LevelDifficulty;
        }
        
    }
    
    std::cout << "Congratulations! You have won the game!";
    return 0;
}

#include <iostream>
#include <ctime>

class Game {
    int randomNumber = getRandomNumber();
    int attempts = 1;
public:
    int getRandomNumber() {
        srand( time(0) );
        return 1 + rand() % 1000;
    }

    int listen() {
        int input;
        std::cin >> input;
        return input;
    }

    void count() {
        attempts++;
    }

    void endGame() {
        std::cout << "You win!" << std::endl;
        std::cout << "Attempts: " << attempts << std::endl;
        std::cout << "Good luck!" << std::endl;
    }

    int definition(int input, const int randomNumber) {
        //std::cout << randomNumber << std::endl;
        if (input == randomNumber) {
            endGame();
            return 0;
        } else if (input < randomNumber) {
            std::cout << "more" << std::endl;
            count();
            definition(listen(), randomNumber);
        } else {
            std::cout << "less" << std::endl;
            count();
            definition(listen(), randomNumber);
        }
    }

    std::string start() {
        std::cout << "Write any number (from 0 to 1000)" << std::endl;
        definition(listen(), randomNumber);
    }
};

int main() {
    Game game;
    game.start();
}
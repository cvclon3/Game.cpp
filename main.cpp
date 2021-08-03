#include <iostream>
#include <ctime>

int getRandomNumber() {
    srand( time(0) );
    return 1 + rand() % 1000;
}

int listen() {
    int input;
    std::cin >> input;
    return input;
}

int definition(int input, const int randomNumber) {
    //std::cout << randomNumber << std::endl;
    if (input == randomNumber) {
        std::cout << "You win!" << std::endl;
        return 0;
    } else if (input < randomNumber) {
        std::cout << "more" << std::endl;
        definition(listen(), randomNumber);
    } else {
        std::cout << "less" << std::endl;
        definition(listen(), randomNumber);
    }
}

int main() {
    definition(listen(), getRandomNumber());
}

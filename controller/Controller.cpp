#include "Controller.hpp"

Controller::Controller(unsigned size, unsigned humans, unsigned vampires) :
    field(size, size, humans, vampires), round(0){
    field.initialise();
}

void Controller::run() {
    bool isEnding = false;
    std::string input;

    while(!isEnding){
        display();
        getline(std::cin, input);

        // Enter input
        if (input.length() == 0) {
            input = "n";
        };

        switch (input[0]) {
            case 'q':
                isEnding = true;
                break;
            case 's':
                runFullSimulation();
                break;
            case 'n':
                nextFrame();
                break;
            default:
                break;
        }
        input = std::string();
    }
}

void Controller::display() {
    field.display();
    std::cout << "[" << round << "] q)uit s)tatistics n)ext : ";
    if(stats != 0.0){
        std::cout << "Success rate : " << stats * 100 << "%" << std::endl;
    }
    std::cout << std::endl;

    // debug
    std::cout << "humans : " << field.getHumansLeft() << "  vampires : " << field.getVampiresLeft() << std::endl;
}

void Controller::nextFrame() {
    round = field.nextTurn();
}

void Controller::runFullSimulation() {
    unsigned success = 0;
    for(unsigned i = 0; i < SIMULATIONS_AMOUNT; ++i){
        field.initialise();

        while(field.getVampiresLeft()){
            field.nextTurn();
        }

        if(field.getHumansLeft()){
            success++;
        }
    }
    stats = (double)success / SIMULATIONS_AMOUNT;
}


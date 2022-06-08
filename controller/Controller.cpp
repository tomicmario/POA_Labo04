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
            input = NEXT;
        };

        switch (input[0]) {
            case QUIT:
                isEnding = true;
                break;
            case STATS:
                runFullSimulation();
                break;
            case NEXT:
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
    if(stats != 0.0){
        std::cout  << "Success rate : " << stats * 100 << "%" << std::endl;
    }
    std::cout << "[" << round << "] q)uit s)tatistics n)ext : ";
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
    round = field.nextTurn();
    stats = (double)success / SIMULATIONS_AMOUNT;
}


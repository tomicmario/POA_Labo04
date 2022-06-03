#include "Controller.hpp"

Controller::Controller(unsigned size, unsigned humans, unsigned vampires) :
    SIZE(size), HUMANS(humans), VAMPIRES(vampires), field(size, size), round(0){
    field.fill();
}

void Controller::run() {
    bool isEnding = false;
    std::string input;
    while(!isEnding){
        display();
        getline(std::cin, input);

        if (input.length() == 0) continue;

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
    std::cout << "[" << round << "] q)uit s)tatistics n)ext : " << std::endl;
}

void Controller::nextFrame() {

}

void Controller::runFullSimulation() {

}


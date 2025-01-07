#include "Food.h"

int Food::counter = 0;

Food::Food() {
    counter++;
}

void Food::removeFood() {
    if (counter > 0) {
        counter--;
    }
    else {
        cout << "Nema vise porcija hrane!" << endl;
    }
}

int Food::getCounter() {
    return counter;
}

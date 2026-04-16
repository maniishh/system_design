#include<iostream>
#include<string>
using namespace std;

class sportsCar {
private:
//characteristics of sports car
string brand;
string model;
bool isEngineOn;
int currentSpeed;
int currentGear;
string tyre;

public:
sportsCar(string b, string m) {
    brand = b;
    model = m;
    isEngineOn = false;
    currentSpeed = 0;
    currentGear = 0;
}
//getters and setters for encapsulation
int getCurrentSpeed() {
    return this->currentSpeed;
}
string getTyre() {
    return this->tyre;
}
void setTyre(string t) {
    // You can add validation here if needed
    this->tyre = t;
}

//behaviour of sports car
void startEngine() {
    isEngineOn = true;
    cout << "Engine started." << endl;
}

void shiftGear(int gear) {
    if (isEngineOn) {
        currentGear = gear;
        cout << "Shifted to gear " << currentGear << "." << endl;
    } else {
        cout << "Cannot shift gears. Engine is off." << endl;
    }
}
void accelerate() {
    if (isEngineOn) {
        currentSpeed += 20; // Accelerate by 20 km/h
        cout << "Accelerated to " << currentSpeed << " km/h." << endl;
    } else {
        cout << "Cannot accelerate. Engine is off." << endl;
    }

}
void brake() {
    if (isEngineOn) {
        currentSpeed -= 20; // Decelerate by 20 km/h
        if (currentSpeed < 0) currentSpeed = 0; // Speed cannot be negative
        cout << "Decelerated to " << currentSpeed << " km/h." << endl;
    } else {
        cout << "Cannot brake. Engine is off." << endl;
    }
}
    void stopEngine() {
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
        cout << "Engine stopped." << endl;
    }

    ~sportsCar(){}
};

int main() {
    sportsCar myCar("Ferrari", "488 Spider");

    myCar.startEngine();
    myCar.shiftGear(1);
    myCar.accelerate();
    myCar.shiftGear(2);
    myCar.accelerate();
    myCar.brake();
    myCar.stopEngine();
   
    cout << "Current speed: " << myCar.getCurrentSpeed() << " km/h" << endl;
    
delete &myCar;

    return 0;
}

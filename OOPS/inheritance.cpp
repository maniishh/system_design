#include<iostream>
#include<string>
using namespace std;


class Car{
  protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

 public:
    Car(string b, string m) {
        brand = b;
        model = m;
        isEngineOn = false;
        currentSpeed = 0;
    }

    void startEngine() {
        isEngineOn = true;
        cout << "Engine started." << endl;
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
            cout << "Decelerated to " << currentSpeed << " km/h." << endl;
        } else {
            cout << "Cannot brake. Engine is off." << endl;
        }
    }

};

class mannualCar : public Car {
    private:
        int currentGear;
    
     public:
        mannualCar(string b, string m) : Car(b, m) {
            currentGear = 0;//specific to mannual car
        }
    
        void shiftGear(int gear) {
            if (isEngineOn) {
                currentGear = gear;
                cout << "Shifted to gear " << currentGear << "." << endl;
            } else {
                cout << "Cannot shift gears. Engine is off." << endl;
            }
        }
};

class ElectricCar : public Car {
    private:
        int batteryLevel;
    
     public:
        ElectricCar(string b, string m) : Car(b, m) {
            batteryLevel = 100; // specific to electric car
        }
    
        void chargeBattery() {
            batteryLevel = 100;
            cout << "Battery fully charged." << endl;
        }
};


int main() {
    mannualCar myMannualCar("Toyota", "Corolla");
    ElectricCar myElectricCar("Tesla", "Model 3");

    cout << "Mannual Car:" << endl;
    myMannualCar.startEngine();
    myMannualCar.accelerate();
    myMannualCar.shiftGear(1);//specific to mannual car
    myMannualCar.brake();

    cout << "\nElectric Car:" << endl;
    myElectricCar.startEngine();
    myElectricCar.accelerate();
    myElectricCar.chargeBattery();//specific to electric car
    myElectricCar.brake();

    return 0;
}

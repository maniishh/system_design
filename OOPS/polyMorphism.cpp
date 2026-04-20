#include<bits/stdc++.h>
using namespace std;

class Car
{
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

public:
    Car(string b, string m)
    {
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
    }

    // Common methods for all Cars
    void startEngine()
    {
        isEngineOn = true;
        cout << brand << " " << model << " : Engine started" << endl;
    }

    void stopEngine()
    {
        isEngineOn = false;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine turned off" << endl;
    }

    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual ~Car() {}
};

class manualCar : public Car
{
private:
    int currentGear;

public:
    manualCar(string b, string m) : Car(b, m)
    {
        currentGear = 0;
    }

    void shiftGear(int gear)
    {
        currentGear = gear;
        cout << brand << " " << model << " : Shifted the gear to " << currentGear << endl;
    }

    // overrirding accelearte - Dynamice Polymorphisms
    void accelerate(){
        if (!isEngineOn)
        {
            cout << brand << " " << model << " : Cannot accelerate as Engine is Off" << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h " << endl;
    }

    // overriding brake - Dynamice Polymorhism
    void brake(){
        currentSpeed -= 20;
        if(currentSpeed<0)currentSpeed = 0;
        cout<<brand<<" "<<model<<" : Braking! the new speed is "<<currentSpeed<<" kmph"<<endl;
    }
};

class electricCar : public Car
{
private:
    int batteryLevel;

public:
    electricCar(string b, string m) : Car(b, m)
    {
        batteryLevel = 100;
    }

    void chargeBattery()
    {
        batteryLevel = 100;
        cout << brand << " " << model << " : Battery is fully charged now" << endl;
    }

    // overriding accelerate - Dynamic Polymorhism
    void accelerate(){
        if(! isEngineOn){
            cout << brand << " " << model << " : Cannot accelerate as Engine is Off" << endl;
            return;
        }
        if(batteryLevel<=0){
            cout << brand << " " << model << " : Batter is dead! cannot accelerate" << endl;
            return;
        }
        batteryLevel-=10;
        currentSpeed+=15;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h " <<"Battery at : "<<batteryLevel<<" % "<< endl;
    }

    // overriding brake - Dynamice Polymorhism
    void brake()
    {
        currentSpeed -= 15;
        if (currentSpeed < 0)
            currentSpeed = 0;
        cout << brand << " " << model << " : Braking! the new speed is " << currentSpeed << " kmph" << endl;
    }
};

int main() {
    
    return 0;
}
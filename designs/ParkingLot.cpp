#include<bits/stdc++.h>
using namespace std;
enum class VehicleType{
    BIKE,
    CAR,
    TRUCK
};
class Vehicle{
    protected:
    string licensePlate;
    VehicleType type;
    public:
    Vehicle(string licensePlate, VehicleType type){
        this->licensePlate=licensePlate;
        this->type=type;
    }
    VehicleType getType(){
        return type;
    }
    string getLicensePlate(){
        return licensePlate;
    }
    virtual ~Vehicle(){}

};
class Car:public Vehicle{
    public:
    Car(string licensePlate):Vehicle(licensePlate,VehicleType::CAR){

    }
};
class Bike : public Vehicle {
public:

    Bike(string licensePlate)
        : Vehicle(licensePlate, VehicleType::BIKE) {}
};
class Truck : public Vehicle {
public:

    Truck(string licensePlate)
        : Vehicle(licensePlate, VehicleType::TRUCK) {}
};
//spot
enum class SpotType {
    BIKE,
    CAR,
    TRUCK
};
//parking Spot
class ParkingSpot {

private:

    int id;
    SpotType type;
    Vehicle* vehicle;

public:

    ParkingSpot(int id, SpotType type) {
        this->id = id;
        this->type = type;
        this->vehicle = nullptr;
    }

    bool isFree() {
        return vehicle == nullptr;
    }

    bool canFit(Vehicle* vehicle) {
        return type == static_cast<SpotType>(vehicle->getType());
    }

    void parkVehicle(Vehicle* vehicle) {
        this->vehicle = vehicle;
    }

    void removeVehicle() {
        this->vehicle = nullptr;
    }

    int getId() {
        return id;
    }
};
//parking floor
class ParkingFloor {

private:

    int floorNumber;

    vector<ParkingSpot*> spots;

public:

    ParkingFloor(int floorNumber) {
        this->floorNumber = floorNumber;
    }

    void addSpot(ParkingSpot* spot) {
        spots.push_back(spot);
    }

    ParkingSpot* findAvailableSpot(Vehicle* vehicle) {

        for (ParkingSpot* spot : spots) {

            if (spot->isFree() &&
                spot->canFit(vehicle)) {

                return spot;
            }
        }

        return nullptr;
    }
};
//ticket
class Ticket {

private:

    int ticketId;
    Vehicle* vehicle;
    ParkingSpot* spot;

public:

    Ticket(int ticketId,
           Vehicle* vehicle,
           ParkingSpot* spot) {

        this->ticketId = ticketId;
        this->vehicle = vehicle;
        this->spot = spot;
    }

    ParkingSpot* getSpot() {
        return spot;
    }
};
//parking lot
class ParkingLot {

private:

    vector<ParkingFloor*> floors;

public:

    void addFloor(ParkingFloor* floor) {
        floors.push_back(floor);
    }

    ParkingSpot* findSpot(Vehicle* vehicle) {

        for (ParkingFloor* floor : floors) {

            ParkingSpot* spot =
                floor->findAvailableSpot(vehicle);

            if (spot != nullptr) {
                return spot;
            }
        }

        return nullptr;
    }
};
//pricing strategy
class PricingStrategy {

public:

    virtual double calculateFee(
        Vehicle* vehicle,
        int hours) = 0;

    virtual ~PricingStrategy() {}
};

class NormalPricing : public PricingStrategy {

public:

    double calculateFee(
        Vehicle* vehicle,
        int hours) override {

        if (vehicle->getType() == VehicleType::BIKE)
            return hours * 20;

        if (vehicle->getType() == VehicleType::CAR)
            return hours * 40;

        if (vehicle->getType() == VehicleType::TRUCK)
            return hours * 80;

        return 0;
    }
};
class VehicleFactory {

public:

    static Vehicle* createVehicle(
        string type,
        string licensePlate) {

        if (type == "CAR")
            return new Car(licensePlate);

        if (type == "BIKE")
            return new Bike(licensePlate);

        if (type == "TRUCK")
            return new Truck(licensePlate);

        return nullptr;
    }
};
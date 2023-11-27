class Plant
{
private:
    int totalStatus;
    int waterStatus;
    int soilStatus;

public:
    Plant() : totalStatus(0), waterStatus(100), soilStatus(100){};

    void water() { this->waterStatus = 100; }
    void feed() { this->soilStatus = 100; }
};

class PlantSlot
{
private:
    Plant *plant;
    bool isEmpty() {}

public:
    PlantSlot(){};

    void pushPlant(Plant *p) { this->plant = p; }

    void pullPlant();
};
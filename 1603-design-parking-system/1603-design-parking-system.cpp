const int BIG = 1;
const int MEDIUM = 2;
const int SMALL = 3;

class ParkingSystem {
public:
    int bigSlots, mediumSlots, smallSlots;

    ParkingSystem(int big, int medium, int small) {
        this->bigSlots = big;
        this->mediumSlots = medium;
        this->smallSlots = small;
    }
    
    bool updateSlot(int& slot) {
        if (slot > 0) {
            slot--;
            return true;
        }
        return false;
    }
    
    bool addCar(int carType) {
        if (carType == BIG) {
            return updateSlot(this->bigSlots);
        } else if (carType == MEDIUM) {
            return updateSlot(this->mediumSlots);
        } else {
            return updateSlot(this->smallSlots);
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
//
// Created by PC on 2025/10/16.
//

class Vehicle {
public:
    explicit Vehicle(int color): color_(color) {}

    int get_color() const {
        return color_;
    }
private:
    int color_;
};

class Car : public Vehicle {
public:
    explicit Car(int i) : Vehicle(i) {}
};
class Boat : public Vehicle {
public:
    explicit Boat(int i) : Vehicle(i) {}
};

class AmphibiousCar : virtual public Car, Boat {
public:
    explicit AmphibiousCar(int c1, int c2) : Car(c1), Boat(c2) {}
};

int main() {
    AmphibiousCar c(1, 2);
    //error: request for member 'get_color' is ambiguous
    // std::cout << c.get_color() << std::endl;
}

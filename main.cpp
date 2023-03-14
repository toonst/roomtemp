#include <cstdio>
#include <iostream>
#include "Room.hpp"

int main()
{
    float min, max;
    std::cout << "Hello there! I am a Room. What is the minimum temperature you want me to be?" << std::endl;
    std::cin >> min;
    std::cout << "Howdy! What is the maximum temperature?" << std::endl;
    std::cin >> max;

    Room room(min, max);

    while (true) {
        float temp = room.getCurrentTemp();
        std::cout << "\r" << "Current temp: " << temp << std::flush;
        if (temp < min) {
            room.startHeating();
        } else if (temp > max) {
            room.startCooling();
        } else {
            room.stopHeating();
            room.stopCooling();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 0;
}

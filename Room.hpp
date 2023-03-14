
#ifndef ROOM_HPP
#define ROOM_HPP

#include <chrono>
#include <thread>

class Room {
    public:
        Room(float minTemp, float maxTemp);

        ~Room();

        void setMinTemp(float minTemp);
        void setMaxTemp(float maxTemp);

        float getMinTemp() const;
        float getMaxTemp() const;
        float getCurrentTemp() const;

        void startHeating();
        void stopHeating();

        void startCooling();
        void stopCooling();

        void updateTemperature();

    private:
        float minTemp_;
        float maxTemp_;
        float currentTemp_;
        bool heating_;
        bool cooling_;
        std::thread thread_;
};

#endif /* ROOM_HPP */

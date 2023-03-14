#include <algorithm>
#include "Room.hpp"

Room::Room(float minTemp, float maxTemp)
            : minTemp_(minTemp), maxTemp_(maxTemp),
              currentTemp_((minTemp + maxTemp) / 2.0f),
              heating_(false), cooling_(false),
              thread_(&Room::updateTemperature, this)
{
    // No need to do anything here
}

Room::~Room()
{
    // Join the thread to ensure it is properly cleaned up
    if (thread_.joinable()) {
        thread_.join();
    }
}
void Room::setMinTemp(float minTemp) { minTemp_ = minTemp; }
void Room::setMaxTemp(float maxTemp) { maxTemp_ = maxTemp; }

float Room::getMinTemp() const { return minTemp_; }
float Room::getMaxTemp() const { return maxTemp_; }
float Room::getCurrentTemp() const { return currentTemp_; }

void Room::startHeating() { heating_ = true; }
void Room::stopHeating() { heating_ = false; }

void Room::startCooling() { cooling_ = true; }
void Room::stopCooling() { cooling_ = false; }

void Room::updateTemperature()
{
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // This models the effect of heating, cooling and natural heat dissipation
        // on the current temperature of the room
        if (heating_) {
            currentTemp_ += 1.0f;
        } else if (cooling_) {
            currentTemp_ -= 1.0f;
        } else {
            currentTemp_ -= 0.25f;
        }
    }
}

#include <algorithm>

class TemperatureControlSystem {
    public:
        TemperatureControlSystem(float minTemp, float maxTemp)
            : minTemp_(minTemp), maxTemp_(maxTemp), currentTemp_(0.0), heating_(false), cooling_(false) {}

        void setMinTemp(float minTemp) { minTemp_ = minTemp; }
        void setMaxTemp(float maxTemp) { maxTemp_ = maxTemp; }

        float getMinTemp() const { return minTemp_; }
        float getMaxTemp() const { return maxTemp_; }
        float getCurrentTemp() const { return currentTemp_; }

        void startHeating() { heating_ = true; }
        void stopHeating() { heating_ = false; }

        void startCooling() { cooling_ = true; }
        void stopCooling() { cooling_ = false; }

        void updateTemperature(float deltaTime) {
            if (heating_) {
                currentTemp_ += deltaTime;
            } else if (cooling_) {
                currentTemp_ -= deltaTime;
            }
            currentTemp_ = std::clamp(currentTemp_, minTemp_, maxTemp_);
        }

    private:
        float minTemp_;
        float maxTemp_;
        float currentTemp_;
        bool heating_;
        bool cooling_;
};


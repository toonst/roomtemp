#pragma once

#include <algorithm>

class TemperatureControlSystem {
    public:
        TemperatureControlSystem(float minTemp, float maxTemp);

        void setMinTemp(float minTemp);
        void setMaxTemp(float maxTemp);

        float getMinTemp() const;
        float getMaxTemp() const;
        float getCurrentTemp() const;

        void startHeating();
        void stopHeating();

        void startCooling();
        void stopCooling();

        void updateTemperature(float deltaTime);

    private:
        float minTemp_;
        float maxTemp_;
        float currentTemp_;
        bool heating_;
        bool cooling_;
};

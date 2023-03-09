#include <cstdio>
#include <iostream>

#include "TemperatureControlSystem.hpp"


int main()
{
    char name[100];printf("please input your name:");
    scanf("%s",name);
    printf("hello,%s\n",name);

    TemperatureControlSystem system(68.0, 72.0);
    std::cout << "Current temperature: " << system.getCurrentTemp() << std::endl;
    system.startHeating();
    system.updateTemperature(0.5);
    std::cout << "Current temperature: " << system.getCurrentTemp() << std::endl;
    system.stopHeating();
    system.startCooling();
    system.updateTemperature(0.5);
    return 0;
}

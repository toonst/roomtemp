#include <gtest/gtest.h>
#include "../Room.hpp"

TEST(RoomTest, GettersAndSetters) {
    Room room(18.0f, 24.0f);
    EXPECT_FLOAT_EQ(room.getMinTemp(), 18.0f);
    EXPECT_FLOAT_EQ(room.getMaxTemp(), 24.0f);

    room.setMinTemp(16.0f);
    room.setMaxTemp(26.0f);

    EXPECT_FLOAT_EQ(room.getMinTemp(), 16.0f);
    EXPECT_FLOAT_EQ(room.getMaxTemp(), 26.0f);
}

TEST(RoomTest, TemperatureUpdate) {
    Room room(20.0f, 22.0f);
    room.startHeating();

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    float currentTemp = room.getCurrentTemp();

    EXPECT_GT(currentTemp, 20.0f);

    room.stopHeating();

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    float newTemp = room.getCurrentTemp();

    EXPECT_FLOAT_EQ(currentTemp, newTemp);
}

TEST(RoomTest, ThreadCleanup) {
    {
        Room room(18.0f, 24.0f);
    } // The room object goes out of scope here, so the thread should have joined

    // The test should pass if the program reaches this point without crashing
}


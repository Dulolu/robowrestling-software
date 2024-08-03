#ifndef ROBOT_H
#define ROBOT_H

#include <Sensors/Sensor.h>
#include "Robots/RobotState.h"
#include <vector>
#include <memory>

class Robot {
    protected:
    std::vector<Sensor*> _sensors;
    RobotState _state;

    public:
    Robot() {}

    virtual void UpdateState() = 0;

    bool UpdateSensors() {
        for (Sensor* sensor : _sensors) {
            sensor -> Poll();
        }

        UpdateState();
        return true;
    }


    const RobotState& GetCurrentState() {
        return _state;
    }



};


#endif

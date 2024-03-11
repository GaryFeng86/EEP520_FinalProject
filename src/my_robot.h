#ifndef __MY_ROBOT_AGENT__H
#define __MY_ROBOT_AGENT__H 

#include "enviro.h"

using namespace enviro;

class MyRobotController : public Process, public AgentInterface {

    public:
    MyRobotController() : Process(), AgentInterface() {}

    void init() {
    
    };
    
    void start() {};
    void update() {
        move_toward(350,-200);
        double front_sensor = sensor_value(0);
        //double right_sensor = sensor_value(1);
    
        if (front_sensor < 50) {
            apply_force(0, 50); 
        } 
        //if(right_sensor < 50){
        //    apply_force(0,80);
        //}
        }
        
    void stop() {}

};

class MyRobot : public Agent {
    public:
    MyRobot(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    MyRobotController c;
};

DECLARE_INTERFACE(MyRobot)

#endif
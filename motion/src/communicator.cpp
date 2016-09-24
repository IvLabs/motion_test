#include "ros/ros.h"
#include "motion/angles.h"
#include "herkulex.cpp"

/////////////////

int motor_id[10]={4, 2, 10, 5, 7, 12, 8, 1, 11, 6};
for (int i=0;i<10;i++)
HerkulexClass::torqueON(motor_id[i]);

/////////////////

void chatterCallback(const motion::angles::ConstPtr& ang_msg) //ang_msg object
{
  //ROS_INFO("I heard: [%s]", msg->data.c_str());
  for (int num=0; num<10; num++)
   {
     motor[num] = ang_msg.angle_to_motor[num];
   }
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "communicator");
  ros::NodeHandle n;
 
  ros::Subscriber sub_ang = n.subscribe("parse_to_motor", 1000, chatterCallback);
  
  ros::Rate loop_rate(50);
  while (ros::ok())
  {
    ros::spinOnce(); //check for incoming messages
    motion::angles10 ang_msg;
    
    for (int i=0; i<10; i++)
     {
       HerkulexClass::moveOne(motor_id[i], motor[num], 22, 1);
       
     }
    loop_rate.sleep();
    
  }
  return 0;
}


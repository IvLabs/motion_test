#include "ros/ros.h"
#include "motion/angles_in.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "angle_parser"); //name_of_node: angle_parser
  ros::NodeHandle n;
  ros::Publisher pub_ang = n.advertise<motion::angles_in>("parse_to_motor", 10); //msgs angle_to_motor[i] is published on topic angle_to_motor; quesize: 10
  ros::Rate loop_rate(500);
  int motor[10] = {0,1,2,3,4,5,6,7,8,9};
  
  while (ros::ok())
  {
    
    motion::angles_in ang_msg;

    for (int i=0; i<10; i++)
     {
       ang_msg.angle_to_motor_in[i] = motor[i];
     }
    pub_ang.publish(ang_msg);
    
    for (int i=0; i<10; i++)
     {
       ROS_INFO("%f",ang_msg.angle_to_motor_in[i]);
     }
    ros::spinOnce();

    loop_rate.sleep();
   
  }
  return 0;
}

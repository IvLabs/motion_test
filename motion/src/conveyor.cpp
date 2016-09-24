#include "ros/ros.h"
#include "motion/angles_out.h"
#include "Herkulex.h"
#include "Herkulex.cpp"

int motor[10];
void chatterCallback(const motion::angles_out::ConstPtr& msg) //ang_msg object
{
  for (int num=0; num<10; num++)
   {
     motor[num] = msg->angle_to_motor_out[num];
     //ROS_INFO("%d",motor[num]);
   }
}
int k=0;
/////////////////


int main(int argc, char **argv)
{
 HerkulexClass hc;
 int motor_id[10]={4, 2, 10, 5, 7, 12, 8, 1, 11, 6};
 
 for (int i=0;i<10;i++)
 hc.moveOne(motor_id[i], motor[i], 1000, 1);
 sleep(2);

 for (int i=0;i<10;i++)
    hc.torqueON(motor_id[i]);
 

 ros::init(argc, argv, "communicator");
 ros::NodeHandle i;

 ros::Subscriber sub_ang = i.subscribe("angle_to_motor", 10, chatterCallback);
 

 ros::Rate loop_rate(33);
 while (ros::ok())
 {
    ros::spinOnce(); //check for incoming messages
   
  if(motor[1]>100)
   {
    
     if(k==0)
     {
     double secs =ros::Time::now().toSec();
     ROS_INFO("%f",secs); k++;
     }
     ros::Rate r(1428); 
     for (int i=0; i<10; i++)
     {
       hc.moveOne(motor_id[i], motor[i], 50, 1); //motor_id, motor_angles, goal_time(from 0 to 2856ms), led_color(1=green)
       
       r.sleep();
       //ROS_INFO("sleep for 0.0007ms");  
     }
       
   }
  //else
    //ROS_INFO("waiting for parser");    
    
  loop_rate.sleep();
 }
 
 return 0;
}


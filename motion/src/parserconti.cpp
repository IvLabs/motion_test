//date:12/9/16
//written by-sakshi
//receives data from csv file and published on a node with custom msg int64[10]
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "readCSV.cpp"
#include "motion/angles_in.h"
#include "motion/angles_out.h"

int main(int argc, char **argv)
{
   readCSV file;//object of class readCSV
   std::vector<std::string> data;// vector,int to store returned vector by storeCSV2array
   int row=1500;//rows that we want to read from csv file
   int col=10;//col that we want to read from csv file
   std::cout <<"start";
   data=file.storeCSV2array("/home/surabhi/.ros/angle2.csv",row,col);//by default,the path is taken from .ros
   std::cout <<"data"<< data[1];

   ros::init(argc, argv, "angle_parser");//node name=angle_parser
   ros::NodeHandle n;
   ros::Publisher pub_ang = n.advertise<motion::angles_out>("angle_to_motor", 10);//topic name=angle_to_mo

   std::cout << data[1];
   motion::angles_in arr;
   motion::angles_out arr1;
   int no_of_cycles=1;
   int k=0;
   float zero_offsets[10] = {
-5.35,
4.43,
10.55,
11.46,
7.79,
2.90,
5.65,
-9.93,
-7.79,
-30.42
};
ros::Time begin = ros::Time::now();
   while (ros::ok())
   {
  // if (k<no_of_cycles)
    // {
      for(int i=0;i<row;i++)
        { 
          ros::Rate loop_rate(500);
          std::vector<float> vect;
          std::stringstream ss(data.at(i));
          float m;
         // ROS_INFO("ROW=%d",i);
          while (ss >> m)
            {
             vect.push_back(m);
             if (ss.peek() == ',')
                ss.ignore();
             }

             for (int h=0; h< vect.size();h++)
               {
                // std::cout<<vect.at(h) << std::endl;
                arr.angle_to_motor_in[h]=vect.at(h) ; 
               } 
             for (int h=0; h< vect.size();h++)
               {
                arr.angle_to_motor_in[h]=vect.at(h) ; 
                // std::cout<<vect.at(h) << std::endl;
                float a = (arr.angle_to_motor_in[h]+150+zero_offsets[h]);
                //ROS_INFO("%f",a);
                //ROS_INFO("HI");
                arr1.angle_to_motor_out[h]=round(21+(a/300)*981);
                // ROS_INFO("HERE");
                ROS_INFO("%d",arr1.angle_to_motor_out[h]);
                //ROS_INFO("BYE");
               }
        
             pub_ang.publish(arr1);
             // ROS_INFO("PUBLISHED");
             //float j=arr.angle_to_motor_in[0];//for verifying
             //ROS_INFO("%f",j);
             loop_rate.sleep();
           }





for(int i=row-1;i>0;i--)
        { 
          ros::Rate loop_rate(500);
          std::vector<float> vect;
          std::stringstream ss(data.at(i));
          float m;
         // ROS_INFO("ROW=%d",i);
          while (ss >> m)
            {
             vect.push_back(m);
             if (ss.peek() == ',')
                ss.ignore();
             }

             for (int h=0; h< vect.size();h++)
               {
                // std::cout<<vect.at(h) << std::endl;
                arr.angle_to_motor_in[h]=vect.at(h) ; 
               } 
             for (int h=0; h< vect.size();h++)
               {
                arr.angle_to_motor_in[h]=vect.at(h) ; 
                // std::cout<<vect.at(h) << std::endl;
                float a = (arr.angle_to_motor_in[h]+150+zero_offsets[h]);
                //ROS_INFO("%f",a);
                //ROS_INFO("HI");
                arr1.angle_to_motor_out[h]=round(21+(a/300)*981);
                // ROS_INFO("HERE");
                ROS_INFO("%d",arr1.angle_to_motor_out[1]);
                //ROS_INFO("BYE");
               }
        
             pub_ang.publish(arr1);
             // ROS_INFO("PUBLISHED");
             //float j=arr.angle_to_motor_in[0];//for verifying
             //ROS_INFO("%f",j);
             loop_rate.sleep();
           }











            ros::spinOnce();
           // k++;
            double secs_current =ros::Time::now().toSec();
            ROS_INFO("%f",secs_current);  
    // }    
       }
return 0;
}

#include "ros/ros.h"
#include "geometry_msgs/Twist.h" 
#include "turtlesim/Pose.h"
#include <sstream>
ros::Publisher velocity_publisher;
ros::Subscriber pose_subscriber;
turtlesim::Pose turtlesim_pose;




const double x_min = 0.0;
const double y_min = 0.0;
const double x_max = 11.0;
const double y_max = 11.0;
const double PI = 3.14159265359;
 
//method to move robot straight
void move(double speed, double distance,bool isForward);
void rotate (double angular_speed, double angle, bool clockwise);
double degree2radians(double angle_in_degrees);
double getDistance(double x1,double y1,double x2,double y2)
double setDesiredorientation (double desired_angle_radians );
void poseCallBack(const turtlesim::Pose::ConstPtr & pose_message);

int main(int argc, char **argv)
{
	// initiate new ros node named talker 
	ros::init(argc,argv,"robot_cleaner");
	ros::NodeHandle n;
	double speed, angular_speed;
	double distance,angle;
	bool isForward, clockwise;

	velocity_publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10); 
	ros::Rate loop_rate(10);
	float arr theta//
	float arrdist//


	ROS_INFO("\n\n\n*******START TESTING*****\n");
	/*cout<<"enter speed";
	cin>>speed;
	cout<<"Enter Distance : ";
	cin>>distance;
	cout<<"forward? : ";
	cin>>isForward;*/
	/*for(int i=0;i<80;++i)
	{
		dis=getDistance(vec[i].first,vec[i].second,vec[i-1].first,vec[i-1].second);
		speed=distance*5;//
		move(speed,distance,isForward);
		rotate(degrees2radians(angular_speed),degrees2radians(angle), clockwise);


	}*/
	turtlesim::Pose goal_pose;
	goal_pose.x=1;
	goal_pose.y=1;
	goal_pose.theta=0;

	geometry_msgs::Twist vel_msg;
	ros::Rate loop_rate(1000);
	ros::ServiceClient clientspawn = n.serviceClient<turtlesim::Spawn>("spawn");
    turtlesim::Spawn::Request reqspawn;
    turtlesim::Spawn::Response resspawn;
    reqspawn.x = 0;
    reqspawn.y = 0;
    reqspawn.theta = 0;
    reqspawn.name = "turtle1";

	do
	{
		cout<<getDistance(turtlesim_pose.x,turtlesim_pose.y,goal_pose.x,goal_pose.y)<<endl;
		vel_msg.linear.x=1.5*getDistance(turtlesim_pose.x,turtlesim_pose.y,goal_pose.x,goal_pose.y);
		vel_msg.linear.y=0;
		vel_msg.linear.z=0;

		vel_msg.angular.x=0;
		vel_msg.angular.y=0;
		vel_msg.angular.z=4*(atan(goal_pose.y-turtlesim_pose.y,goal_pose.x-turtlesim_pose.x));
		velocity_publisher.publish(vel_msg);

		loop_rate.sleep();
		ros::spinOnce;
	}while((getDistance(turtlesim_pose.x,turtlesim_pose.y,goal_pose.x,goal_pose.y))>distance_tolerance);
	cout<<"end move goal"<<"\n";
	vel_msg.linear.x=0;
	vel_msg.angular.z=0;
	velocity_publisher.publish(vel_msg);




	/*speed=distance*5;//
	move(speed,distance,isForward);*/

	/*cout<<"Enter angular velocity in deg/sec : ";
	cin>>angular_speed;
	cout<<"Enter desired angle : ";
	cin>>angle;
	cout<<"clockwise? :";
	cin>>clockwise;*/
	
	loop_rate.sleep();

	ros::spin();
	return 0;



}




void move(double speed,double distance,bool isForward)
{

	// distance=speed*time
	geometry_msgs::Twist vel_msg;
	if (isForward)
		vel_msg.linear.x =abs(speed);
	else
		vel_msg.linear.x =-abs(speed);
	vel_msg.linear.y =0;
	vel_msg.linear.z =0;

	vel_msg.angular.x =0;
	vel_msg.angular.y =0;
	vel_msg.angular.z =0;

	double t0 = ros::Time::now().toSec();
	double current_distance = 0.0;
	ros::Rate loop_rate(100);
	do
	{
		velocity_publisher.publish(vel_msg);
		double t1 = ros::Time::now().toSec();
		current_distance = speed*(t1-t0);
		ros::spinOnce();
		loop_rate.sleep();
	}while(current_distane<distance);
	vel_msg.linear.x =0;
	velocity_publisher.publish(vel_msg);
}
void rotate (double angular_speed, double angle, bool clockwise);
{
	geometry_msgs::Twist vel_msg;

	vel_msg.linear.x =0;
	vel_msg.linear.y =0;
	vel_msg.linear.z =0;
	//
	vel_msg.angular.x =0;
	vel_msg.angular.y =0;

	if(clockwise)
		vel_msg.angular.z =-abs(angular_speed);
	else 
		vel_msg.angular.z =abs(angular_speed);
	double current_angle = 0.0;
	double t0 = ros::Time::now().toSec();
	ros::Rate loop_rate(10);
	do
	{
		velocity_publisher.publish(vel_msg);
		current_angle = angular_speed*(t1-t0);

	}while(current_angle<relative_angle);
	vel_msg.angular.z =0;
	velocity_publisher.publish(vel_msg);

}
double degree2radians(double angle_in_degrees)
{
	return angle_in_degrees*PI /180.0;
}
double setDesiredorientation (double desired_angle_radians )
{
	double relative_angle_radians = desired_angle_radians- turtlesim_pose
}
double setDesiredOrientation(double desired_angle_radians){
    double relative_angle_radians =desired_angle_radians -turtlesim_pose.theta;
    bool clockwise = ((relative_angle_radians<0)?true:false);
    rotate(abs(relative_angle_radians)/4,abs(relative_angle_radians),clockwise);
}

double poseCallback(const turtlesim::Pose::ConstPtr & pose_message){
    turtlesim_pose.x=pose_message->x;
    turtlesim_pose.y=pose_message->y;
    turtlesim_pose.theta=pose_message->theta;
}

double getDistance(double x1,double y1,double x2,double y2){
    return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}



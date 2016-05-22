#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Vector3.h>

using namespace std;

/* Robot wheel pins */

int m11 = 3;
int m12 = 2;

int m21 = 5;
int m22 = 4;




ros::NodeHandle nh;

void turnLeft()
{
    nh.loginfo("Turn left");
    // turn left
    analogWrite(m21, 150); 
    analogWrite(m22, 1);
    analogWrite(m11, 0);
    analogWrite(m12, 0);
    delay(3000); 
    goForward();
}

void turnRight()
{
  nh.loginfo("Turn right");
    // turn right
    analogWrite(m21, 0);
    analogWrite(m22, 0);
    analogWrite(m11, 150); 
    analogWrite(m12, 1);
    delay(3000); 
    goForward();
}

void goForward()
{
  nh.loginfo("Go forward");
    // go forward
    analogWrite(m11, 150); 
    analogWrite(m12, 1);
    analogWrite(m21, 150);
    analogWrite(m22, 1);
    
    //delay(15000);
}

void stop()
{
    nh.loginfo("Stop");
    analogWrite(m11, 0);
    digitalWrite(m12, 0);
    analogWrite(m21, 0);
    digitalWrite(m22, 0);
}


void messageCb(const geometry_msgs::Twist& message) 
{
  geometry_msgs::Vector3 linear = message.linear;
  float forward_vel = float(linear.x);
  
  if(forward_vel == 0) { stop(); return; }
  
  geometry_msgs::Vector3 angular = message.angular;
  float ang_vel = float(angular.z);
  
  if(ang_vel > 0) { turnLeft(); }
  else if(ang_vel < 0) { turnRight(); }
  else { goForward(); }
}


ros::Subscriber<geometry_msgs::Twist> sub("/cmd_vel", &messageCb);

void setup()
{
  nh.initNode();
  nh.subscribe(sub);
  pinMode(m12, OUTPUT);
  pinMode(m22, OUTPUT);
  Serial.begin(57600);
}

void loop()
{
  nh.spinOnce();
  delay(100);
}



#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>

ros::NodeHandle  nh;

void callback_func(const geometry_msgs::Twist& cmdVel)
{
  if (cmdVel.linear.x > 0)
  {
    //hello[13] = "forward";
    Serial.print("forward");
    digitalWrite(6, 1);
    digitalWrite(7, 0);
    digitalWrite(8, 1);
    digitalWrite(9, 0);
    return 0;

  }
  if (cmdVel.linear.x < 0)
  {
    Serial.print("backward");
    digitalWrite(6, 0);
    digitalWrite(7, 1);
    digitalWrite(8, 0);
    digitalWrite(9, 1);
    return 0;
  }
  if (cmdVel.angular.z > 0)
  {
    digitalWrite(6, 1);
    digitalWrite(7, 0);
    digitalWrite(8, 0);
    digitalWrite(9, 1);
    return 0;
  }
  if (cmdVel.angular.z < 0)
  {
    digitalWrite(6, 0);
    digitalWrite(7, 1);
    digitalWrite(8, 1);
    digitalWrite(9, 0);
    return 0;
  }
  else
  {
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 0);
  }
}


ros::Subscriber<geometry_msgs::Twist> sub("turtle1/cmd_vel", &callback_func );

std_msgs::String str_msg;
//ros::Publisher chatter("chatter", &str_msg);

void setup()
{
  Serial.begin(115200);
  nh.getHardware()->setBaud(115200);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
  //  nh.advertise(chatter);
}

void loop()
{
  str_msg.data = hello;
  //  chatter.publish( &str_msg );
  nh.spinOnce();
  delay(500);
}

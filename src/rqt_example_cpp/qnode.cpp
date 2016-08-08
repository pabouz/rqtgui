
#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <std_msgs/Int32.h>
#include <sstream>
#include "rqt_example_cpp/qnode.h"

namespace rqt_example_cpp {


QNode::QNode()
 {
  setObjectName("QNode");
}

QNode::~QNode() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
  wait();
}

bool QNode::init(const std::string &master_url, const std::string &host_url) {

  std::map<std::string,std::string> remappings;
    remappings["__master"] = master_url;
    remappings["__hostname"] = host_url;

 ros::init(remappings,"MyPlugin");

 if ( ! ros::master::check() ) {
    return false;
  }
  ros::start(); // explicitly needed since our nodehandle is going out of scope.
  ros::NodeHandle n;
  // Add your ros communications here.
   up_button.data=0;
  up_publisher =n.advertise<std_msgs::Int32>("up",1);
  start();
  return true;
}



void QNode::run() {
  ros::Rate loop_rate(1);
  while ( ros::ok() ) {
   up_publisher.publish(up_button);
    ros::spinOnce();
    loop_rate.sleep();

  }
  std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
  Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

}

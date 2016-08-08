
#ifndef myplugin_QNODE_H_
#define myplugin_QNODE_H_

#include <ros/ros.h>
#include <string>
#include <QThread>
#include <std_msgs/Int32.h>

namespace rqt_example_cpp {

class QNode : public QThread{
  Q_OBJECT
 public:
   QNode();
   virtual ~QNode();
   bool init(const std::string &master_url, const std::string &host_url);
   void run();
 std_msgs::Int32 up_button;
Q_SIGNALS:
    void rosShutdown();

    private:

    ros::Publisher up_publisher;

};

}

#endif /* myplugin_QNODE_HPP_ */

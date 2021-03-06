#include "rqt_example_cpp/my_plugin.h"
#include <pluginlib/class_list_macros.h>
#include <QStringList>
#include <QMessageBox>

namespace rqt_example_cpp {

MyPlugin::MyPlugin()
  : rqt_gui_cpp::Plugin()
  , widget_(0), qnode()
{
  // Constructor is called first before initPlugin function, needless to say.

  // give QObjects reasonable names
  setObjectName("MyPlugin");
}



void MyPlugin::initPlugin(qt_gui_cpp::PluginContext& context)
{
  // access standalone command line arguments
  QStringList argv = context.argv();
  // create QWidget
  widget_ = new QWidget();
  // extend the widget with all attributes and children from UI file
  ui_.setupUi(widget_);
  // add widget to the user interface
  context.addWidget(widget_);
  QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));
  QObject::connect(ui_.pushButton_up, SIGNAL(clicked()), this, SLOT(up_button_click()));
  if ( !qnode.init("http;//localhost:11311/","localhost" )) {
        showNoMasterMessage();
      }


}

void MyPlugin::shutdownPlugin()
{
  // TODO unregister all publishers here
}

void MyPlugin::saveSettings(qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const
{
  // TODO save intrinsic configuration, usually using:
  // instance_settings.setValue(k, v)
}

void MyPlugin::restoreSettings(const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings)
{


  // TODO restore intrinsic configuration, usually using:
  // v = instance_settings.value(k)
}

/*bool hasConfiguration() const
{
  return true;
}#include <ros/network.h>

void triggerConfiguration()
{
  // Usually used to open a dialog to offer the user a set of configuration
}*/



void MyPlugin::up_button_click()
{
if(qnode.up_button.data==0)
{qnode.up_button.data=1;}
else
{qnode.up_button.data=0;}

}

void MyPlugin::showNoMasterMessage() {
  QMessageBox msgBox;
  msgBox.setText("Couldn't find the ros master.");
  msgBox.exec();
   // close();
}


} // namespace
PLUGINLIB_DECLARE_CLASS(rqt_example_cpp, MyPlugin, rqt_example_cpp::MyPlugin, rqt_gui_cpp::Plugin)

#ifndef rqt_example_cpp_my_plugin_H
#define rqt_example_cpp_my_plugin_H

#include <rqt_gui_cpp/plugin.h>
#include <rqt_example_cpp/ui_my_plugin.h>
#include <QWidget>
#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include "rqt_example_cpp/qnode.h"

namespace rqt_example_cpp {



class MyPlugin
  : public rqt_gui_cpp::Plugin
{
  Q_OBJECT
public:
  MyPlugin();
  virtual void initPlugin(qt_gui_cpp::PluginContext& context);
  virtual void shutdownPlugin();
  virtual void saveSettings(qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const;
  virtual void restoreSettings(const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings);
  void showNoMasterMessage();
  // Comment in to signal that the plugin has a way to configure it
  // bool hasConfiguration() const;
  // void triggerConfiguration();
private:
  Ui::MyPluginWidget ui_;
  QWidget* widget_;
  QNode qnode;


  public Q_SLOTS:
  void up_button_click();

};
}  // namespace rqt_example_cpp
#endif  // rqt_example_cpp_my_plugin_H

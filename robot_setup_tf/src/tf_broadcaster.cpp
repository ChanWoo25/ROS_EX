#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "robot_tf_publisher");
  ros::NodeHandle nh;
  ros::Rate r(100);

  tf::TransformBroadcaster broadcaster;

  while(nh.ok())
  {
    // Send The stamped data structure includes ...
    // Input(transform format)
    // Timestamp
    // (parent) frame_id
    // child_frame_id // So, we transform frame [base_laser->base_link]
    broadcaster.sendTransform(
      tf::StampedTransform(
        tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.1, 0.0, 0.2)),
        ros::Time::now(), "base_link", "base_laser"
      )
    );

    r.sleep();
  }

  return 0;
}

#include <ros/ros.h>
#include <sensor_msgs/PointCloud.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "point_cloud_publisher");
  ros::NodeHandle nh;
  ros::Publisher cloud_pub = nh.advertise<sensor_msgs::PointCloud>("cloud", 50);

  unsigned num_points = 100;
  int count = 0;
  ros::Rate r(1.0);
  while(nh.ok())
  {
    sensor_msgs::PointCloud cloud;
    cloud.header.stamp = ros::Time::now();
    cloud.header.frame_id = "point_cloud_frame";

    cloud.points.resize(num_points);

    // Only one channel by each point
    cloud.channels.resize(1);
    cloud.channels[0].name = "intensity";
    cloud.channels[0].values.resize(num_points);

    for(unsigned i = 0; i< num_points; ++i)
    {
      cloud.points[i].x = 1 + count;
      cloud.points[i].y = 2 + count;
      cloud.points[i].z = 3 + count;
      cloud.channels[0].values[i] = 100 + count;
    }

    cloud_pub.publish(cloud);
    ++count;
    r.sleep();
  }
}

#include<ros/ros.h>
#include "boost/date_time/posix_time/posix_time.hpp"
#include<cv_bridge/cv_bridge.h>
#include<image_transport/image_transport.h>
#include<ros/console.h>
#include<opencv2/highgui/highgui.hpp>
#include<string>
#include <typeinfo>
void imagecb(const sensor_msgs::ImageConstPtr& msg)
{
    //std::stringstream ss;
    //ss << "testcv";
    boost::posix_time::ptime Ptime = ros::Time::now().toBoost(); //posix string time "conversion of UNIX to POSIX type"
    std::string curt = boost::posix_time:: to_iso_extended_string(Ptime);

    std::string filename="/home/nano/ros_package/image/" + curt+".jpeg";
    // VideoWriter video("outcpp.avi",CV_FOURCC('M','J','P','G'),10, Size(frame_width,frame_height));
    cv::imwrite(filename,cv_bridge::toCvShare(msg, "bgr8")->image);
    cv::waitKey(1);
}
int main(int argc,char** argv)
{
    ros::init(argc,argv,"ireceiver");
    ros::NodeHandle nh;
    image_transport::ImageTransport it(nh);
    image_transport::Subscriber sub = it.subscribe("camera/stream_drop/",1,imagecb);
    ros::spin();
}

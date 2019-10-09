#include<ros/ros.h>
#include<ros/console.h>
// #include <std_msgs/Header> 
#include<image_transport/image_transport.h>
#include<cv_bridge/cv_bridge.h>
#include <opencv2/highgui/highgui.hpp>
uint64 count=0;
int main(int argc, char ** argv)
{
    ros::init(argc,argv,"image_streamer");
    ros::NodeHandle nh,h;
    image_transport::ImageTransport it(nh);
    image_transport::Publisher pub=it.advertise("camera/stream",1);
    ros::Publisher header_pub = h.advertise<std_msgs::Header>("camera/status",1);
    //////////////////////////////////////////////////////////////
    cv::Mat frame;
    cv::VideoCapture cap(0);
    if(!cap.isOpened())
    {
    	ROS_INFO("camera not plugged in");
    }
    sensor_msgs::ImagePtr msg;
    // std_msgs::Header
    std_msgs::Header head;
    ros::Rate loop_rate(5);

    while(nh.ok())
    {
        cap>>frame;
        msg=cv_bridge::CvImage(std_msgs::Header(),"bgr8",frame).toImageMsg();
        // ROS_INFO_STREAM(std_msgs::Header());
        pub.publish(msg);
        // header_pub.publish(std_msgs::Header());
        head.stamp = ros::Time::now();
        head.seq = count;
        count++;
        header_pub.publish(head);
        cv::waitKey(1);
    }
    ros::spinOnce();
    loop_rate.sleep();

}

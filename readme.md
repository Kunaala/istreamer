This is a ros wrapper for streaming images from camera used as USB camera.
functionality:
    for streaming images from onboard camera by rosnode running on onboard computer
use case:
    presently used for krishnapatnam port
    can be used for all projects involving USB camera
instructions for use:
1.  clone the project into a directory
2.  use catkin_make(This requires ros installation and setting the ros environment: contact developer for these steps)
3.  >source devel/setup.bash
4.  >rosrun istreamer istream  { This will run ros executable to capture images from cam: published as /camera/stream}
5.  open an other terminal and after entering the directory repeat 3.
6.  >rosrun istreamer ireceive {will subscribe to /camera/stream and renders it as images}
or
    >rosrun istreamer irecieve _image_transport:=theora for using theora codec
7.  for dropping frames or for fps throttling use topic_tools package(inbuilt) in ros before 6.

further developments:

1.  device address independent camera streaming
2.  launch file for ease of operation


Version 2:
Headers added to rostopic /camera/status
Launch file added for the img_streamer which will do FPS throttle at 1/4 of the orignal and save images to /home/nano/ros_package/image/

# rover_viz
A collection of packages to read from the sensor board and display the data

To connect remotely to the Jetson via its own WiFi hotspot:

`sudo echo 2 > /sys/module/bcmdhd/parameters/op_mode`

Be sure your client machine has the network Rover-WiFi set as a private network. You will then need to set up Virtualbox to be in bridged mode. You can do this by going to the settings and adding a bridged network adapter.

Once this is done, you should be able to just connect your main OS to the Rover-WiFi network, then go into Linux on your VM and ping back and forth.

To get everything working with ROS, copy the following lines into your .bashrc file (keeping in mind that you have to source this file after making changes if you want them to update in your current terminal).

```
export ROS_MASTER_URI=http://10.42.0.1:11311
export ROS_IP=10.42.0.154
```
Note that you may need to adjust IP address as necessary. You can get your own IP address (ROS_IP) by running `ifconfig`

#!/usr/bin/env python

import rospy
from std_msgs.msg import String
from smbus2 import SMBusWrapper

I2C_DEV = 1 #device file number
I2C_ADDRESS = 0x0A
REGISTER = 0 
MESSAGE_SIZE = 5 #currently teensy just transmits "hello" repeatedly
MESSAGE_NAME = 'teensymessage' #name of field published to the node
NODE_NAME = 'teensytalker' #name of the ros node


def teensyTalker():
    with SMBusWrapper(I2C_DEV) as bus:
        pub = rospy.Publisher(MESSAGE_NAME, String, queue_size=10)
        rospy.init_node(NODE_NAME)
        rate = rospy.Rate(10)
        startTime = rospy.get_time()
        while not rospy.is_shutdown():
            inData = bus.read_i2c_block_data(I2C_ADDRESS, REGISTER, MESSAGE_SIZE)
            message = ''.join([chr(x) for x in inData])
            message += "_" + str(round(rospy.get_time() - startTime, 2))
            rospy.loginfo(message)
            pub.publish(message)
            rate.sleep()
        
if __name__ == '__main__':
    try:
        teensyTalker()
    except rospy.ROSInterruptException:
        pass

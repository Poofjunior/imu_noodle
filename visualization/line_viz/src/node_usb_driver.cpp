#include "node_usb_driver.h"
// http://www.dreamincode.net/forums/topic/148707-introduction-to-using-libusb-10/
NodeUsbDriver::NodeUsbDriver()
{
    libusb_device **devs; //pointer to pointer of device, used to retrieve a list of devices
    libusb_context *ctx_ = NULL; //a libusb session
    ssize_t cnt; // number of devices in list
    // Initialize the library for the session we just declared
    if(libusb_init(&ctx_) < 0) {
        std::cout << "Init Error "<< std::endl; //there was an error
    }
    libusb_set_debug(ctx_, 3); //set verbosity level to 3, as suggested in the documentation

    cnt = libusb_get_device_list(ctx_, &devs); //get the list of devices
    if(cnt < 0) {
        std::cout<<"Get Device Error"<<std::endl; //there was an error
    }
    std::cout << cnt <<" Devices in list."<<std::endl;

    devHandle_ = libusb_open_device_with_vid_pid(ctx_, TEENSY_VID, TEENSY_PID);
    if(devHandle_ == NULL)
        std::cout<<"Cannot open device"<<std::endl;
    else
        std::cout<<"Device Opened"<<std::endl;
    libusb_free_device_list(devs, 1); //free the list, unref the devices in it

    // find out if kernel driver is attached.
    if(libusb_kernel_driver_active(devHandle_, 0) == 1)
    {
        std::cout<<"Kernel Driver Active"<<std::endl;
        if(libusb_detach_kernel_driver(devHandle_, 0) == 0)
            std::cout<<"Kernel Driver Detached!"<<std::endl;
    }
    //Claim the Teensy's first (and only) interface`.
    if(libusb_claim_interface(devHandle_, 0) < 0)
    {
        std::cout<<"Cannot Claim Interface"<<std::endl;
    }
    std::cout<<"Claimed Interface"<<std::endl;
}

NodeUsbDriver::~NodeUsbDriver()
{
    // Release the claimed interface.
    if(libusb_release_interface(devHandle_, 0))
    {
        std::cout<<"Cannot Release Interface"<<std::endl;
    }
    std::cout<<"Released Interface"<<std::endl;
    //close the device we opened
    libusb_close(devHandle_);
    //needs to be called.
    libusb_exit(ctx_);
}

void NodeUsbDriver::updateNodes()
{
    size_t NUM_BYTES = 64;
    int numBytesTransferred;
    int errorCode;

    // details for endpoints and VID/PID gathered from lsusb -v
    errorCode = libusb_bulk_transfer(devHandle_, (3 | LIBUSB_ENDPOINT_IN),
                                     receivedBytes_, NUM_BYTES, &numBytesTransferred, .050);
    if (errorCode != 0)
    {
        std::cout <<  "Error receving data!" << std::endl;
        return;
    }
    // Stuff raw quaternion data into classes.
    for (size_t qIndex = 0; qIndex < NUM_NODES; ++qIndex)
    {
        // Dump byte contents into a float.
        // Note: assumes packets were organized on the usb side for a little-endian target.
        std::memcpy((void*) &orientations_[qIndex].w_,
                    (void*) &receivedBytes_[qIndex * sizeof(quaternionData) + 0], 4);
        std::memcpy((void*) &orientations_[qIndex].x_,
                    (void*) &receivedBytes_[qIndex * sizeof(quaternionData) + 4], 4);
        std::memcpy((void*) &orientations_[qIndex].y_,
                    (void*) &receivedBytes_[qIndex * sizeof(quaternionData) + 8], 4);
        std::memcpy((void*) &orientations_[qIndex].z_,
                    (void*) &receivedBytes_[qIndex * sizeof(quaternionData) + 12], 4);
        std::cout << std::hex << orientations_[qIndex].w_ << std::endl;
        std::cout << orientations_[qIndex].x_ << std::endl;
        std::cout << orientations_[qIndex].y_ << std::endl;
        std::cout << orientations_[qIndex].z_ << std::endl;
        std::cout << std::dec << std::endl;
    }
}


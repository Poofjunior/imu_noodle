# Arduino Make file. Refer to https://github.com/sudar/Arduino-Makefile
#The mobile embedded interface poses as a generic

GIT_HASH = "\"$(shell git rev-parse HEAD)\""
GIT_BRANCH = "\"$(shell git branch | sed -n -e 's/^\* \(.*\)/\1/p')\""
UPLOAD_DATE = "\"$(shell date)\""

CXXFLAGS_STD = -std=gnu++11 -DGIT_HASH=$(GIT_HASH) -DGIT_BRANCH=$(GIT_BRANCH) \
               -DUPLOAD_DATE=$(UPLOAD_DATE)

USB_TYPE = USB_SERIAL

# WARNING: Trailing whitespace will cause options to be read incorrectly.
BOARD_TAG    = teensy31

# Additional user-defined libraries may be added to this list
ARDUINO_LIBS += bno055 \
                i2c_wrapper \
                i2c_t3

# Default user-defined libraries directory
USER_LIB_PATH += ../lib

# Teensy explicitly requires Arduino 1.0.x as of Nov 2014
# ARDUINO_DIR should be defined in your Makefile. Otherwise, you may
# define it here.

# teensy3, teensy31, and teensy32 explicitly require their own Makefile.
include $(ARDMK_DIR)/Teensy.mk


#include <zephyr/drivers/gnss.h>
#include <zephyr/device.h>
#include <zephyr/sys/printk.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#include "gnss_l76k.h"

static const struct device *gnss_dev = DEVICE_DT_GET(DT_ALIAS(gnss));

int init_gnss(void){

     if(device_is_ready_dt(&gnss_dev)){
        return 0;
    }
   




return 1;
}
/**
 * Copyright (c) 2021 Nicolai Electronics
 *
 * SPDX-License-Identifier: MIT
 */

#include <sdkconfig.h>
#include <driver/i2c.h>
#include "include/managed_i2c.h"

esp_err_t start_i2c(int bus, int pin_sda, int pin_scl, int clk_speed, bool pullup_sda, bool pullup_scl) {
    i2c_config_t i2c_config = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = pin_sda,
        .scl_io_num = pin_scl,
        .master.clk_speed = clk_speed,
        .sda_pullup_en = pullup_sda ? GPIO_PULLUP_ENABLE : GPIO_PULLUP_DISABLE,
        .scl_pullup_en = pullup_scl ? GPIO_PULLUP_ENABLE : GPIO_PULLUP_DISABLE,
    };
    
    esp_err_t res = i2c_param_config(bus, &i2c_config);
    if (res != ESP_OK) return res;
    return i2c_driver_install(bus, i2c_config.mode, 0, 0, 0);
}

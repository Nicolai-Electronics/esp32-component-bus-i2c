#pragma once

#include <esp_err.h>

extern esp_err_t start_i2c(int bus, int pin_sda, int pin_scl, int clk_speed, bool pullup_sda, bool pullup_scl);

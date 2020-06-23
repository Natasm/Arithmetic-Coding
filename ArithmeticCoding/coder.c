#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "ArithmeticConfig.h"
#include "coder.h"
#include "File.h"

#define _num_state_bits 31

void shift(Configuration* config) {
    bool bit = config->_low >> (_num_state_bits);

    writeBit(config->fs, bit);

    // Write out the saved underflow bits
    for (int i = 0; i < config->_num_underflow; i++) writeBit(config->fs, bit ^ 1);

    config->_num_underflow = 0;
}

int write(ArithmeticConfig ac, char symbol, int sizeBuffer, Configuration* config){
    unsigned long int low = config->_low;
    unsigned long int high = config->_high;

    if(low >> 0 >= high >> 0 || ((low & config->_state_mask) != low) || ((high & config->_state_mask) != high)) return -1;

    unsigned long int range = high - low + 1;

    if (!(config->_minimum_range >> 0 <= range >> 0 && range >> 0 <= config->_full_range >> 0)) return -1;

    double symbolLow = getLowLimitsConfig(getLimitsConfig(ac, symbol));
    double symbolHigh = getHighLimitsConfig(getLimitsConfig(ac, symbol));

    if(config->_maximum_total >> 0 <= sizeBuffer >> 0) return -1;

    unsigned long int newLow = low + floor(range * symbolLow);
    unsigned long int newHigh = low + floor(range * symbolHigh) - 1;

    config->_low = newLow;
    config->_high = newHigh;

     while(((config->_low ^ config->_high) & (config->_half_range)) == 0){
        shift(config);
        config->_low = (config->_low << 1) & (config->_state_mask);
        config->_high = ((config->_high << 1) & config->_state_mask) | 1;
    }

    while((config->_low & (~ config->_high) & (config->_quarter_range)) != 0){
        config->_num_underflow = config->_num_underflow + 1;
        config->_low = (config->_low << 1) ^ (config->_half_range);
        config->_high = ((config->_high ^ (config->_half_range)) << 1) | config->_half_range | 1;
    }
    return 1;
}

Configuration getConfig(char* inputOrOutputPath, char* mode){
   Configuration config;

   //Size max of unsigned long int (_full_range)
   config._full_range = 1 << _num_state_bits << 0;
   config._half_range = config._full_range >> 1;
   config._quarter_range = config._half_range >> 1;

   config._minimum_range = config._quarter_range + 2;
   config._maximum_total = config._minimum_range;

   config._state_mask = config._full_range - 1;

   config._low = 0;
   config._high = config._state_mask;

   config._num_underflow = 0;

   config.fs = create_or_open_file(inputOrOutputPath, mode);

   return config;
}

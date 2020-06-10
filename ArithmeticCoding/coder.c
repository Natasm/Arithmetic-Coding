#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "coder.h"

#define _num_state_bits 31

int update(LinkedList ll, char symbol, int sizeBuffer, Configuration* config){
    unsigned long int low = config->_low;
    unsigned long int high = config->_high;

    if(low >> 0 >= high >> 0 || ((low & config->_state_mask) != low) || ((high & config->_state_mask) != high)) return -1;

    unsigned long int range = high - low + 1;

    if (!(config->_minimum_range >> 0 <= range >> 0 && range >> 0 <= config->_full_range >> 0)) return -1;


    //double symbolLow =
}

Configuration getConfig(){
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

   return config;
}




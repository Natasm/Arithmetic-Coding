#ifndef CODER_H_INCLUDED
#define CODER_H_INCLUDED
#include "File.h"

typedef struct configuration{
   unsigned long int _full_range;
   unsigned long int _half_range;
   unsigned long int _quarter_range;

   unsigned long int _minimum_range;
   unsigned long int _maximum_total;

   unsigned long int _state_mask;

   unsigned long int _low;
   unsigned long int _high;

   unsigned long int _num_underflow;

   FileStream fs;

} Configuration;

Configuration getConfig(char* inputOrOutputPath, char* mode);

int write(LimitsConfig* lc, char symbol, int sizeBuffer, Configuration* config);

#endif // CODER_H_INCLUDED

#ifndef CODER_H_INCLUDED
#define CODER_H_INCLUDED

typedef struct configuration{
   unsigned long int _full_range;
   unsigned long int _half_range;
   unsigned long int _quarter_range;

   unsigned long int _minimum_range;
   unsigned long int _maximum_total;

   unsigned long int _state_mask ;

   unsigned long int _low;
   unsigned long int _high;

} Configuration;

Configuration getConfig();

#endif // CODER_H_INCLUDED

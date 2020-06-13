#ifndef CODER_H_INCLUDED
#define CODER_H_INCLUDED

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

   char* output;

} Configuration;

Configuration getConfig();

int write(LinkedList ll, char symbol, int sizeBuffer, Configuration* config);

#endif // CODER_H_INCLUDED

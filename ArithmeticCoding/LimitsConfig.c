#include "LimitsConfig.h"

#include <stdlib.h>

struct limits_config
{
   double _low;
   double _high;
};

double getLowLimitsConfig(LimitsConfig lc) { return lc->_low; }

double getHighLimitsConfig(LimitsConfig lc){ return lc->_high; }

LimitsConfig newLimitsConfig(double low, double high)
{
    LimitsConfig new = (LimitsConfig) malloc(sizeof(struct limits_config));
    new->_low = low;
    new->_high = high;
    return new;
}

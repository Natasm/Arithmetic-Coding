#ifndef LIMITSCONFIG_H_INCLUDED
#define LIMITSCONFIG_H_INCLUDED

typedef struct limits_config* LimitsConfig;

LimitsConfig newLimitsConfig(double low, double high);

double getLowLimitsConfig(LimitsConfig lc);

double getHighLimitsConfig(LimitsConfig lc);

#endif // LIMITSCONFIG_H_INCLUDED

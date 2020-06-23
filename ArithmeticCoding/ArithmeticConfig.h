#ifndef ARITHMETICCONFIG_H_INCLUDED
#define ARITHMETICCONFIG_H_INCLUDED
#include "Node.h"
#include "LimitsConfig.h"

typedef struct arithmeticonfig* ArithmeticConfig;

ArithmeticConfig newArithmeticConfig();

int getSizeNodesValid(ArithmeticConfig ac);

void insertNode(ArithmeticConfig ac, char ch);

Node getNode(ArithmeticConfig ac, int i);

void insertLimitConfig(ArithmeticConfig ac, int i, double low, double high);

LimitsConfig getLimitsConfig(ArithmeticConfig ac, int i);

#endif // ARITHMETICCONFIG_H_INCLUDED

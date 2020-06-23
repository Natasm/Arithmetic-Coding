#include <stdlib.h>
#include "ArithmeticConfig.h"
#include "Node.h"
#include "LimitsConfig.h"

#define SIZE_ALPHABETIC 256

struct arithmeticonfig{
    Node nodes[SIZE_ALPHABETIC];
    LimitsConfig limits_config[SIZE_ALPHABETIC];
};

ArithmeticConfig newArithmeticConfig(){
    ArithmeticConfig ac = (ArithmeticConfig) malloc(sizeof(struct arithmeticonfig));
    for(int i = 0; i < SIZE_ALPHABETIC; i++){
        ac->nodes[i] = NULL;
        ac->limits_config[i] = NULL;
    }
    return ac;
}

int getSizeNodesValid(ArithmeticConfig ac){
    int soma = 0;
    for(int i = 0; i < SIZE_ALPHABETIC; i++) if(ac->nodes[i] != NULL) soma++;
    return soma;
}

void insertNode(ArithmeticConfig ac, char ch){
    if(ac->nodes[ch] == NULL) ac->nodes[ch] = newNode(ch, 1);
    else ac->nodes[ch] = addContentNode(ac->nodes[ch], 1);
}

Node getNode(ArithmeticConfig ac, int i){
    return ac->nodes[i];
}

void insertLimitConfig(ArithmeticConfig ac, int i, double low, double high){
    if(ac->limits_config[i] == NULL) ac->limits_config[i] = newLimitsConfig(low, high);
}

LimitsConfig getLimitsConfig(ArithmeticConfig ac, int i){
    return ac->limits_config[i];
}


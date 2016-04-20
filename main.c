#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "net.h"

int main(){
  double inputs[] = {0.20, 0.45, 0.56, 0.312};
  Brain* brain = Brain_new(3,4,2,4);
  Brain_feedForward(brain, inputs);
  Brain_print(brain);

  return 0;
}

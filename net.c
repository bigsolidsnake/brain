#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "net.h"

Brain* Brain_new(int inputs, int outputs, int hLayers, int nPerH){

  Brain* brain = malloc(sizeof(Brain));

  brain->neurons = malloc(sizeof(NeuronListList));
  brain->neurons->head = NULL;
  brain->neurons->tail = NULL;
  NeuronList* last_col = NULL;

  for (int i = 0; i < hLayers + 2; i++){
    int num_neurons;
    if (i == 0){
      num_neurons = inputs;
    }
    else if (i == hLayers + 1){
      num_neurons = outputs;
    }
    else {
      num_neurons = nPerH;
    }
    NeuronList* col = malloc(sizeof(NeuronList));
    col->head = NULL;
    col->tail = NULL;
    col->next = NULL;

    if(!brain->neurons->head){
      brain->neurons->head = col;
    }
    brain->neurons->tail = col;

    Neuron* last_neuron = NULL;

    for (int j = 0; j < num_neurons; j++){
      Neuron* neuron = malloc(sizeof(neuron));
      neuron->charge = 0;
      neuron->next = NULL;
      neuron->axons = NULL;
      if(last_neuron){
        last_neuron->next = neuron;
      }
      last_neuron = neuron;
      if(!col->head){
        col->head = neuron;
      }
      col->tail = neuron;
      if(i>0){
        int last_neurons = (i == 1) ? inputs:nPerH;
        neuron->axons = malloc(sizeof(double)*last_neurons);
        for (int k = 0; k < last_neurons; k++) {
          neuron->axons[k] = ((double)(rand() % 1000 - 500))/ 500.0;
        }
      }
    }

    if (last_col){
      last_col->next = col;

    }
    last_col = col;
  }

  return brain;

}

void Brain_print(Brain* brain){
  for (NeuronList* i = brain->neurons->head; i; i = i->next){

    for (Neuron* j = i->head; j; j = j->next){
      printf("%f ", j->charge);
    }
    printf("\n");
  }
}

void Brain_feedForward(Brain* brain, double* input){
  for (Neuron* i = brain->neurons->head->head; i; i = i->next){
    printf("%p\n", i);
    i->charge = *input++;
  }
}

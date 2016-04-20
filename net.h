#ifndef NET_H
#define NET_H

typedef struct Neuron Neuron;
typedef struct NeuronList NeuronList;
typedef struct Brain Brain;
typedef struct NeuronListList NeuronListList;

struct Neuron{

  double charge;
  double* axons;
  Neuron* next;

};

struct NeuronList{
  Neuron* head;
  Neuron* tail;
  NeuronList* next;
};

struct NeuronListList{
  NeuronList* head;
  NeuronList* tail;
  NeuronList* next;
};

struct Brain {
  NeuronListList* neurons;
};

void Brain_print(Brain*);

void Brain_feedForward(Brain*, double*);

Brain* Brain_new(int, int, int, int);

#endif

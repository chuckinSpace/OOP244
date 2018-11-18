#ifndef NAMESPACE_GRAPH_H
#define NAMESPACE_GRAPH_H
#define MAX_NO_OF_SAMPLES 20
namespace sict {
// Fills the samples array with the statistic samples
void getSamples(int samples[], int noOfSamples);
int findMax(int samples[], int noOfSamples);
// Prints a scaled bar relevant to the maximum value in samples array
void printBar(int val, int max);
// Prints a graph comparing the sample values visually 
// Prints a graph comparing the sample values visually 
void printGraph(int samples[], int noOfSamples);
}
#endif

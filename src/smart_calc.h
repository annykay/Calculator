#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

double GetN(char **src, int *err);
double GetP(char **src, int *err, double x);
double GetT(char **src, int *err, double x);
double GetE(char **src, int *err, double x);
double GetG(char **src, int *err, double x);
double GetR(char **src, int *err, double x);
double GetSign(char **src, int *err);
double calculate(char *src, int *err, double x);

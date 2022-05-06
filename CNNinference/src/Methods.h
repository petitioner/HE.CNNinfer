#include "Tools.h"
#include "Scheme.h"
#include "VolleyRevolverEncoding.h"
#include <assert.h>


int CNNinference(double** testdata, double* testlabel, long factorDim, long sampleDim, double **CNNdate, long cnnWeightsLen, long *cnnWeightsDims);

int HE_SquareMatrixMult(long dim=64);


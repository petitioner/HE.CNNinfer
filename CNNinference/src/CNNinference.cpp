#include <NTL/BasicThreadPool.h>
#include <thread>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>

#include "Methods.h"
#include "Tools.h"

#include "SerializationUtils.h"  // error: ‘SerializationUtils’ has not been declared

#include <cstdio>

using namespace std;
using namespace NTL;


int main(int argc, char **argv) {

	// Get the number of hardware threads available on the current system
	unsigned int numThreads = thread::hardware_concurrency();
	if (numThreads == 0) {
		cerr << "Unable to get the number of hardware threads." << endl;
		return EXIT_FAILURE;
	}

	// Print the number of hardware threads
	cout << "Number of hardware threads available: " << numThreads << endl;

	// Set the number of threads in NTL to the number of hardware threads
	SetNumThreads(numThreads + 2);

	


	//string trainfile = "../data/FASHION-MNISTtrain(28x28).csv";
	//string testfile  = "../data/FASHION-MNISTt10k(28x28).csv";
    //string CNNweightsfile  = "../data/CNNweightsFASHIONMNIST.csv";

	string trainfile = "../data/MNISTtrain(28x28).csv";
	string testfile  = "../data/MNISTt10k(28x28).csv";
	//string testfile  = "../data/MNISTt10k(28x28)first32imagesfortest.csv";
	//string testfile  = "../data/MNISTt10k(28x28)first68imagesfortest.csv";
	string CNNweightsfile  = "../data/CNNweightsMNIST.csv";
	


	long trainSampleDim = 0, testSampleDim = 0, trainfactorDim = 0,	testfactorDim = 0;
	double **traindataset, **testdataset;
	double *traindatalabel, *testdatalabel;

	//double **zData = Tools::dataFromFile(trainfile, trainfactorDim, trainSampleDim, traindataset, traindatalabel);
	double **zDate = Tools::dataFromFile(testfile, testfactorDim, testSampleDim, testdataset, testdatalabel);

	for (int n = 0; n < 5; n++) {
		cout<< endl << testdatalabel[n] << endl;

		for (int i=0; i < 28; ++i) {
			for ( int j=0; j < 28; ++j)
				if(testdataset[n][i*28+j] < 1e-2) cout << "     ";
            	else printf("%5d", int(testdataset[n][i*28+j]) ) ;
    		cout << endl;
		}
	}

	//Tools::normalizeZData(traindataset, trainfactorDim, trainSampleDim);
	Tools::normalizeZData(testdataset, testfactorDim, testSampleDim);

	for (int n = 0; n < 5; n++) {
		cout<< endl << testdatalabel[n] << endl;

		for (int i=0; i < 28; ++i) {
			for ( int j=0; j < 28; ++j)
				if(testdataset[n][i*28+j] < 1e-2) cout << "     ";
		    	else printf("%5.2f", testdataset[n][i*28+j] ) ;
    		cout << endl;
		}
	}

	long cnnWeightsLen = 0;
	long *cnnWeightsDims;

    double **CNNdate = Tools::dataFromCNNweightsFile(CNNweightsfile, cnnWeightsLen, cnnWeightsDims);
    cout << endl << cnnWeightsLen << endl;
    for (int i=0; i< cnnWeightsLen; i++) {
    	cout << cnnWeightsDims[i] << "  ";
    	for (int j=0; j < (cnnWeightsDims[i]<12?cnnWeightsDims[i]:12); j++)
    			cout << CNNdate[i][j] << "  ";
    	cout << endl;
    }
    cout << endl;
    cout << "trainSampleDim : " << trainSampleDim << endl;
    cout << "testSampleDim  : " << testSampleDim << endl;
    cout << "trainfactorDim : " << trainfactorDim << endl;
    cout << "testfactorDim  : " << testfactorDim << endl;
///*
    cout << endl << endl << "-------------------------------------------------------------------------------------" << endl;
    cout << "CNNinference(testdataset, testdatalabel, testfactorDim, testSampleDim, CNNdate, cnnWeightsLen, cnnWeightsDims);" << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    CNNinference(testdataset, testdatalabel, testfactorDim, testSampleDim, CNNdate, cnnWeightsLen, cnnWeightsDims);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//*/
/*
    cout << endl << endl << "-------------------------------------------------------------------------------------" << endl;
    cout << "HE_SquareMatrixMult(long dim=64);" << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    HE_SquareMatrixMult(8);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/

	cout << endl << "END OF THE PROGRAMM" << endl;
	return 0;
}

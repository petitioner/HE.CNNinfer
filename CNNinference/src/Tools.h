/*
* Copyright (c) by CryptoLab inc.
* This program is licensed under a
* Creative Commons Attribution-NonCommercial 3.0 Unported License.
* You should have received a copy of the license along with this
* work.  If not, see <http://creativecommons.org/licenses/by-nc/3.0/>.
*/

////////////////////////////////////////////////////////////////////////////////////
#if defined(_WIN32)
#include <windows.h>
#include <psapi.h>

#elif defined(__unix__) || defined(__unix) || defined(unix) || (defined(__APPLE__) && defined(__MACH__))
#include <unistd.h>
#include <sys/resource.h>

#if defined(__APPLE__) && defined(__MACH__)
#include <mach/mach.h>

#elif (defined(_AIX) || defined(__TOS__AIX__)) || (defined(__sun__) || defined(__sun) || defined(sun) && (defined(__SVR4) || defined(__svr4__)))
#include <fcntl.h>
#include <procfs.h>

#elif defined(__linux__) || defined(__linux) || defined(linux) || defined(__gnu_linux__)
#include <stdio.h>

#endif

#else
#error "Cannot define getPeakRSS( ) or getCurrentRSS( ) for an unknown OS."
#endif
////////////////////////////////////////////////////////////////////////////////////

#ifndef IDASH2017_GD_H_
#define IDASH2017_GD_H_

#include <iostream>
#include <assert.h>
#include <cmath>

////////////////////////////////  For Full-Batch NAG  //////////////////////////////
//        Just Use The Polynomials Computed by Kim iDASH2017                      //        
//             Round 1  ~ 05 : |wTx| < 8                                          //
//             Round 05 ~ 10 : |wTx| < 8                                          //
//             Round 10 ~ 30 : |wTx| < 12                                         //
////////////////////////////////////////////////////////////////////////////////////
//static double degree1[2] = {0.5,0.25};
// y = 0.5  +  0.15012 x^1  -  0.0015930078125 x^3 (0.001593008)                polyfit(x,y,3)
static double degree3[3] = {+0.5, -0.15012, +0.00159300781};  // 1 - poly(-yWTx)
// y = 0.5  +  0.19131 x^1  -  0.0045963 x^3         +  4.123320007324219e-05 x^5  (0.000041233)
static double degree5[4] = {+0.5, -0.19131, +0.0045963,   -0.0000412332};
// y = 0.5  +  0.21687 x^1  -  0.00819154296875 x^3  +  0.0001658331298828125 x^5  -  1.1956167221069336e-06 x^7
//static double degree7[5] = {+0.5, -0.21687, +0.00819154297, -0.00016583313, +0.00000119562};
// y = 0.5  +  0.21687 *(0.666)^1 .*x.^1  -  0.00819154297 *(0.666)^3 .*x.^3  +  0.00016583313 *(0.666)^5 .*x.^5  -  0.00000119562 *(0.666)^7 .*x.^7;
// y = 0.5  +  0.14443542 .*x.^1  -  0.00241984975038 .*x.^3  +  0.00002172913528 .*x.^5  -  0.00000006948847 .*x.^7;
//static double degree7[5] = {+0.5, -0.14443542, +0.00241984975, -0.00002172914, +0.00000006949};//|wTx| < 12
static double degree7[5] = {+0.5, -0.10843500, +0.00102394287, -0.00000518229, +0.00000000934};  //|wTx| < 16
////////////////////////////////  For Full-Batch NAG  //////////////////////////////


////////////////////////////////  For Mini-Batch NAG  //////////////////////////////
//             Round 00 ~ 11 : |wTx| <  6                                         //
//             Round 12 ~ 23 : |wTx| < 12                                         //
//             Round 24 ~ 36 : |wTx| < 16                                         //
////////////////////////////////////////////////////////////////////////////////////
// z =  -4.7292e-06.*x.^7 +   3.9345e-04.*x.^5    -1.2329e-02.*x.^3  +  2.3514e-01.*x.^1 +  5.0000e-01 .*x.^0; |x| < 6
static double degree7_12[5] = {+0.5, -2.3514e-01, +1.2329e-02, -3.9345e-04, +4.7292e-06};  // 1 - poly(-yWTx)
// z = -6.3921e-07.*x.^7 + 1.1023e-04.*x.^5 -6.6579e-03.*x.^3 + 2.0683e-01.*x.^1 + 5.0000e-01; |x| < 9
// z = -6.3921e-07.*(9.0/12.*x).^7 + 1.1023e-04.*(9.0/12.*x).^5 -6.6579e-03.*(9.0/12.*x).^3 + 2.0683e-01.*(9.0/12.*x).^1 + 5.0000e-01;
static double degree7_24[5] = {+0.5, -0.15512, +0.0028088, -0.000026158,  +0.000000085324};
// z = -6.3921e-07.*x.^7 + 1.1023e-04.*x.^5 -6.6579e-03.*x.^3 + 2.0683e-01.*x.^1 + 5.0000e-01; |x| < 9
// z = -6.3921e-07.*(9.0/16.*x).^7 + 1.1023e-04.*(9.0/16.*x).^5 -6.6579e-03.*(9.0/16.*x).^3 + 2.0683e-01.*(9.0/16.*x).^1 + 5.0000e-01;
//static double degree7_36[5] = {+0.5, -0.14465, +0.0024308, -0.000021893,  +0.000000070222};
static double degree7_36[5] = {+0.5, -0.11634, +0.0011850, -0.0000062074, +0.000000011389};
////////////////////////////////  For Mini-Batch NAG  //////////////////////////////

using namespace std;

class Tools {

public:

	static long suggestLogN(long lambda, long logQ);
    static bool is_number(string& s);
	static double** dataFromFile(string& path, long& factorDim, long& sampleDim, double** &X, double* &Y);
	static double** dataFromCNNweightsFile(string& path, long& len, long* &dims);
	static double** zDataFromFile(string& path, long& factorDim, long& sampleDim, bool isfirst = true);

	static void shuffleDataSync(double** X, long factorDim, long sampleDim, double* Y);
	static void shuffleZData(double** zData, long factorDim, long sampleDim);

	static void normalizeZData(double** zData, long factorDim, long sampleDim);
	static void normalizezData2(double** zDataLearn, double** zDataTest, long factorDim, long sampleDimLearn, long sampleDimTest);

	static double trueIP(double* a, double* b, long size); 

	static double calculateAUC(double** zData, double* wData, long factorDim, long sampleDim, double& correctness, double& AUC);
	static double calculateMLE(double** zData, double* wData, long factorDim, long sampleDim, double& correctness, double& auc);
	static double calculateACC(double** zData, double* wData, long factorDim, long sampleDim, double& correctness, double& auc);
	
	static size_t getPeakRSS( );
	static size_t getCurrentRSS( );

	/////////////////////////////////////////////
	static bool apowerof2(double floatnumber);


};

#endif /* SGD_SGD_H_ */

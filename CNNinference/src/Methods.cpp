/*
* Copyright (c) by CryptoLab inc.
* This program is licensed under a
* Creative Commons Attribution-NonCommercial 3.0 Unported License.
* You should have received a copy of the license along with this
* work.  If not, see <http://creativecommons.org/licenses/by-nc/3.0/>.
*/
#include "Tools.h"
#include "Methods.h"

#include "Ciphertext.h"
#include "NTL/ZZX.h"
#include "Scheme.h"
#include "TestScheme.h"
#include "SecretKey.h"
#include "TimeUtils.h"
#include <cmath>

#include "Tools.h"
#include <EvaluatorUtils.h>
#include <NTL/BasicThreadPool.h>
#include <NTL/RR.h>
#include <NTL/ZZ.h>

#include <iomanip>
#include <set>
#include <map>
#include <typeinfo>
#include <vector>
#include <algorithm>    // std::shuffle
#include <vector>        // std::vector
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

#include <unistd.h>
#include "VolleyRevolverEncoding.h"


int CNNinference(double** testdata, double* testlabel, long factorDim, long sampleDim, double **CNNdate, long cnnWeightsLen, long *cnnWeightsDims)
{
  long fdimBits = (long)ceil(log2(factorDim)); //ceil(x) : Rounds x upward, returning the smallest integral value that is not less than x.
  long sdimBits = (long)ceil(log2(sampleDim)); //log2(x) : Returns the binary (base-2) logarithm of x.

  long wBits = 45;                             // Δ (delta)
  long pBits = 20;

  long logN = Tools::suggestLogN(80, logQ);    // it should be the Security Parameter λ
  long slots = 1 << (logN - 1);                // slots := 
  if ( slots > (1 << fdimBits) * (1 << sdimBits) ) slots = (1 << fdimBits) * (1 << sdimBits);
  long sBits = (long)ceil(log2(slots));    

  long batch = long( slots / (1 << fdimBits) );// batch is the Number of several sample dimensions.
  long bBits = (long)ceil(log2(batch));        

  long rnum = (long)ceil((double)sampleDim / batch); // To Divide the whole Test Data into Several Batches

  cout << endl << endl;
  cout << "factorDim = " << factorDim << endl << "sampleDim = " << sampleDim << endl;
  cout << "batch = " << batch << ", slots = " << slots << ", rnum = " << rnum << endl;
  cout << "logQ = " << logQ << ", logN = " << logN << ", sdimBits = " << sdimBits << ", fdimBits = " << fdimBits << endl;

  TimeUtils timeutils;
  timeutils.start("Scheme generating...");
  Ring ring;
  SecretKey secretKey(ring);
  Scheme scheme(secretKey, ring); 
  //std::set<int> leftset, rightset;
    //std::set<int>::iterator it;
  int pos[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,28,30,32,34,36,38,40,42,44,46,48,50,54,56,60,64,66,72,78,84,90,96,102,108,112,114,120,126,128,140,168,256,512,1024,2048,3072,4096,5120,6144,7168,8192,9216,10240,11264,12288,13312,14336,15360,16384,17408,18432,19456,20480,21504,22528,23552,24576,25600,26624,27648,28672,29696,30720,31744};
  for(long i=0; i < 90; ++i) {
    //leftset.insert(pos[i] );
    scheme.addLeftRotKey(secretKey, pos[i] );
  }
  int ppos[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,28,30,32,34,36,38,40,42,44,46,48,50,54,56,60,64,66,72,78,84,90,96,102,108,112,114,120,126,128,140,168,256,369,420,457,485,497,499,505,508,511,512,513,517,523,528,529,535,536,541,547,548,550,553,556,559,561,562,564,565,568,569,571,574,575,577,579,580,581,583,585,586,587,589,591,592,593,595,597,598,599,600,601,602,603,604,605,606,607,608,609,610,611,612,613,614,615,616,617,618,619,620,621,622,623,624,625,626,628,630,632,634,636,638,640,642,644,646,648,650,651,652,653,654,655,656,657,658,659,660,661,662,663,664,665,666,667,668,669,670,671,672,673,674,675,676,682,688,694,700,706,712,718,720,724,728,730,734,736,738,740,742,744,746,748,750,752,754,756,758,759,760,761,762,763,764,765,766,767,768,769,770,771,772,773,774,775,776,777,778,779,780,781,782,783,784,1024,2048,3072,4096,5120,6144,7168,8192,9216,10240,11264,12288,13312,14336,15360,16384,17408,18432,19456,20480,21504,22528,23552,24576,25600,26624,27648,28672,29696,30720,31744};
  for(long i=0; i < 253; ++i) {
    //rightset.insert(ppos[i] );
    scheme.addRightRotKey(secretKey, ppos[i] );
  }
  timeutils.stop("Scheme generation");
  
////////////////////////////////////////////////// Data owner //////////////////////////////////////////////////

////////////////////////////////////////////////// Data owner //////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
  Ciphertext encFirstData;                                                      //
    complex<double>* pzData = new complex<double>[slots]();                     //
    for (long j = 0; j < batch; ++j) {                                          //
      long rlen = (1 << fdimBits);                                              //
      for (long l = 0; l < factorDim; ++l) {                                    //
        pzData[(batch * 0 + j) * rlen + l].real(testdata[batch * 0 + j][l]);    //
        pzData[(batch * 0 + j) * rlen + l].imag(0);                             //
      }                                                                         //
    }                                                                           //
    scheme.encrypt(encFirstData, pzData, slots, wBits, logQ);                   //
    delete[] pzData;                                                            //
                                                                                //
  VolleyRevolverEncoding VRE(encFirstData, slots, 28, 28, NULL);                //
///////////////////////////////////////////////// Cloud server /////////////////////////////////////////////////
long this_rownum = VRE.rownum;
long this_colnum = VRE.colnum;
long this_datacolnum = VRE.datacolnum;
vector<int> indexsvec;
for (long i=0; i < 51; i+=2) 
  indexsvec.push_back(i);
indexsvec.push_back(1);
indexsvec.push_back(56);

std::map<long, Ciphertext> rotaterowincomplete_filterct;
Ciphertext leftfilterct, rightfilterct;
// Encoding Method: this->colnum * 10000 + pos*1000 + left(0)/right(1)
for (auto it = indexsvec.begin() ; it != indexsvec.end(); ++it) {
  long idx = this_colnum * 10000 + *it * 1000 + 1;
  complex<double>* leftfilter = new complex<double> [slots]();
  for (int rowidx=0; rowidx < this_rownum; ++rowidx) {
    for (int idx=0; idx < this_colnum - *it; ++idx) {
      leftfilter[rowidx * this_datacolnum + idx] = 1;
    }
  }
  scheme.encrypt(leftfilterct, leftfilter, slots, 60, logQ);
  rotaterowincomplete_filterct[idx] = leftfilterct;

  idx = this_colnum * 10000 + *it * 1000 + 0;
  complex<double>* rightfilter = new complex<double> [slots]();
  for (int rowidx=0; rowidx < this_rownum; ++rowidx) {
    for (int idx=0; idx < *it; ++idx) {
      rightfilter[rowidx * this_datacolnum + this_colnum-*it +idx] = 1;
    }
  }
  scheme.encrypt(rightfilterct, rightfilter, slots, 60, logQ);
  rotaterowincomplete_filterct[idx] = rightfilterct;
}

Ciphertext zeroct;
auto zeros = new complex<double>[slots]();
scheme.encrypt(zeroct, zeros, slots, 60, logQ);

long this__width = 28;
long this__height = 28;
long kernel_size = 3;
long this__colnum = 784;
long this__datacolnum = 1024;
Ciphertext* cleanct = new Ciphertext[this__height - kernel_size + 1];
for(long rowth=0; rowth < this__height - kernel_size + 1; ++rowth) { // ASSUME THAT: strides=(1, 1)
  // design a new matrix ....
  // rowfilter = [0] * ( rowth * (self.width - kernel_size + 1) ) +  [1] * (self.width - kernel_size + 1)
  // messagefilter = rowfilter + [0] * ( self.datacolnum - len(rowfilter) )
  auto messagefilter = new double[this__datacolnum]();
  for(long idx=rowth * (this__width - kernel_size + 1); idx < (rowth + 1) * (this__width - kernel_size + 1); ++idx ) {
    messagefilter[idx] = 1;
  }
  auto temp = VRE.fillfullof(messagefilter, this__datacolnum);
  
  scheme.encrypt(cleanct[rowth], temp, slots, 60, logQ);
}
Ciphertext* filterct = new Ciphertext[kernel_size*kernel_size];
for(long idx=0; idx < kernel_size*kernel_size; ++idx) {
  long x = idx / kernel_size;
    long y = idx % kernel_size;
    long shift_0 = x;
    long shift_1 = y;

  // Build a new designed matrix to filter out the garbage values, with the help of shift(,)
    double* filtermatrix = new double[this__colnum]();
    for (int h=0; h < this__height; ++h) {
      for (int w=0; w < this__width; ++w) {
        if ( (w - shift_0) % kernel_size == 0 && w + kernel_size <= this__width )
          if ( (h - shift_1) % kernel_size == 0 && h + kernel_size <= this__height )
            filtermatrix[h * this__width + w] = 1;
      }
    }
    auto filtermessage = VRE.fillfullof(filtermatrix, this__colnum);
 
    scheme.encrypt(filterct[idx], filtermessage, slots, 60, logQ);
 }
 ///////////
    double* filtermatrix = new double[slots]();
    for (long rowidx=0; rowidx < this_rownum; ++rowidx)
        filtermatrix[rowidx * this__datacolnum] = 1;
    Ciphertext vre_mul_four_filterct;
    scheme.encrypt(vre_mul_four_filterct, filtermatrix, slots, 60, logQ);

    Ciphertext* vre_mul_four_filterct0 = new Ciphertext[this_rownum];
    long offset = 0;
    for (long r=0; r < this_rownum; ++r) {
        filtermatrix = new double[slots]();
        for (long rowidx=0; rowidx < this_rownum; ++rowidx)
            filtermatrix[offset + rowidx * this__datacolnum + (rowidx + r) % this_rownum] = 1;
        //Ciphertext filterct;
        scheme.encrypt(vre_mul_four_filterct0[r], filtermatrix, slots, 60, logQ);
    }

    Ciphertext* vre_mul_four_filterct1 = new Ciphertext[this_rownum];
    offset = 32;
    for (long r=0; r < this_rownum; ++r) {
        filtermatrix = new double[slots]();
        for (long rowidx=0; rowidx < this_rownum; ++rowidx)
            filtermatrix[offset + rowidx * this__datacolnum + (rowidx + r) % this_rownum] = 1;
        //Ciphertext filterct;
        scheme.encrypt(vre_mul_four_filterct1[r], filtermatrix, slots, 60, logQ);
    }
///////////
    filtermatrix = new double[slots]();
    for (long rowidx=0; rowidx < this_rownum; ++rowidx)
        filtermatrix[rowidx * this__datacolnum] = 1;
    Ciphertext MyDense_filterct;
    scheme.encrypt(MyDense_filterct, filtermatrix, slots, 60, logQ);
    
    Ciphertext* MyDense_filterct0 = new Ciphertext[this_rownum];
    offset = 0;
    for (long r=0; r < this_rownum; ++r) {
        filtermatrix = new double[slots]();
        for (long rowidx=0; rowidx < this_rownum; ++rowidx)
            filtermatrix[offset + rowidx * this__datacolnum + (rowidx + r) % this_rownum] = 1;
        //Ciphertext filterct;
        scheme.encrypt(MyDense_filterct0[r], filtermatrix, slots, 60, logQ);
    }
///////////////////////////////////////////////// Cloud server ///////////////////////////////////////////////// 


//////////////////////////////////////////////// Model provider ////////////////////////////////////////////////
cout << "Model provider : begin : CurrentRSS (MB): " << ( Tools::getCurrentRSS() /1024.0/1024.0 ) << endl;
cout << "Model provider : begin : PeakRSS    (MB): " << ( Tools::getPeakRSS() /1024.0/1024.0 )    << endl;
cout << "----------------------------------------" << endl;
  double* filter0 = new double[9](); 
  double bias0 = CNNdate[1][0];
  for(int i=0; i < 36; i+=4) { filter0[i/4] = CNNdate[0][i]; }

  double* filter1 = new double[9](); 
  double bias1 = CNNdate[1][1];
  for(int i=1; i < 36; i+=4) { filter1[i/4] = CNNdate[0][i]; }

  double* filter2 = new double[9](); 
  double bias2 = CNNdate[1][2];
  for(int i=2; i < 36; i+=4) { filter2[i/4] = CNNdate[0][i]; }

  double* filter3 = new double[9](); 
  double bias3 = CNNdate[1][3];
  for(int i=3; i < 36; i+=4) { filter3[i/4] = CNNdate[0][i]; }
    
    auto encKernelimage0 = VRE.spanKernelimage(scheme, filter0, 9, 3);
    cout << "encKernelimage0[0].logp = " << encKernelimage0[0].logp << endl;

    auto encKernelimage1 = VRE.spanKernelimage(scheme, filter1, 9, 3);
    cout << "encKernelimage1[0].logp = " << encKernelimage1[0].logp << endl;

    auto encKernelimage2 = VRE.spanKernelimage(scheme, filter2, 9, 3);
    cout << "encKernelimage2[0].logp = " << encKernelimage2[0].logp << endl;

    auto encKernelimage3 = VRE.spanKernelimage(scheme, filter3, 9, 3);
    cout << "encKernelimage3[0].logp = " << encKernelimage3[0].logp << endl;

    Ciphertext* convbias = new Ciphertext[4];
    for (long n=0; n < 4; ++n) {
      auto biases_zeros = new complex<double>[slots]();
      for(long rowidx=0; rowidx < VRE.rownum; ++rowidx) {
        long width=VRE.width;// - kernel_size + 1;
        long height=VRE.height;// - kernel_size + 1;
        //cout << "width = " << width << endl;
        //cout << "height= " << height << endl;
        for(long i=0; i < width*height; ++i) {
          biases_zeros[rowidx * VRE.datacolnum + i].real( CNNdate[1][n] );
          biases_zeros[rowidx * VRE.datacolnum + i].imag(0);
        }

      }
      scheme.encrypt(convbias[n], biases_zeros, VRE.slots_number, 60, logQ);
    }
  double** wmatrix = new double*[2704](); 
  for(int i=0; i < 2704; ++i) {
    double* temp = new double[64](); 
    for(int j=0; j < 64; ++j) {
      temp[j] = CNNdate[6][i * 64 + j];
    }
    wmatrix[i] = temp;
  }
  double** wmatrixT = new double*[64](); 
  for(int j=0; j < 64; ++j) {
    double* temp = new double[2704]();
    for(int i=0; i < 2704; ++i) {
      temp[i] = wmatrix[i][j]; 
    }
    wmatrixT[j] = temp;
  }
  long datacolnum = 1024;
  long rownum = 32;
  long colnum = 676;
  Ciphertext* wCT0 = new Ciphertext[4];
  for (long n=0; n < 4; ++n) {
    complex<double>* dense1_0 = new complex<double>[slots]();
    for (long r = 0; r < rownum; ++r) {

      for (long i=n; i < 2704; i+=4) {
        dense1_0[r * datacolnum + i/4].real( wmatrixT[r][i] );
        dense1_0[r * datacolnum + i/4].imag(0);

        //if (i < 32) cout << wmatrixT[r][i] << " " ;
      }
      //cout << endl;
    }
    scheme.encrypt(wCT0[n], dense1_0, slots, wBits, logQ);
  }

  Ciphertext* wCT1 = new Ciphertext[4];
  for (long n=0; n < 4; ++n) {
    complex<double>* dense1_0 = new complex<double>[slots]();
    for (long r = 0; r < rownum; ++r) {

      for (long i=n; i < 2704; i+=4) {
        dense1_0[r * datacolnum + i/4].real( wmatrixT[rownum + r][i] );
        dense1_0[r * datacolnum + i/4].imag(0);
      }
    }
    scheme.encrypt(wCT1[n], dense1_0, slots, wBits, logQ);
  }

  Ciphertext biasCT0;
    complex<double>* bias_0 = new complex<double>[slots]();
    for (long r = 0; r < rownum; ++r) {

      for (long i=0; i < 32; ++i) {
        bias_0[r * datacolnum + i] = CNNdate[7][i];
      }
    }
    scheme.encrypt(biasCT0, bias_0, slots, wBits, logQ);
  Ciphertext biasCT1;
    complex<double>* bias_1 = new complex<double>[slots]();
    for (long r = 0; r < rownum; ++r) {

      for (long i=0; i < 32; ++i) {
        bias_1[r * datacolnum + 32 + i] = CNNdate[7][32 + i];
      }
    }
    scheme.encrypt(biasCT1, bias_1, slots, wBits, logQ);

  double** wmatrix1 = new double*[64](); 
  for(int i=0; i < 64; ++i) {
    double* temp = new double[10](); 
    for(int j=0; j < 10; ++j) {
      temp[j] = CNNdate[12][i * 10 + j];
    }
    wmatrix1[i] = temp;
  }

  double** wmatrixT1 = new double*[10](); 
  for(int j=0; j < 10; ++j) {
    double* temp = new double[64]();
    for(int i=0; i < 64; ++i) {
      temp[i] = wmatrix1[i][j]; 
    }
    wmatrixT1[j] = temp;
  }
    Ciphertext weightct;
    complex<double>* dense2 = new complex<double>[slots]();
    for (long r = 0; r < 10; ++r) {
      for (long i=0; i < 64; ++i) {
        dense2[r * datacolnum + i].real( wmatrixT1[r][i] );
        dense2[r * datacolnum + i].imag(0);
      }
    }
    scheme.encrypt(weightct, dense2, slots, wBits, logQ);

    Ciphertext biasct;
    complex<double>* biasvec = new complex<double>[slots]();
    for (long r = 0; r < 10; ++r) { 
      for (long i=0; i < 64; ++i) {
        biasvec[r * datacolnum + i].real( CNNdate[13][r] );
        biasvec[r * datacolnum + i].imag(0);
      }
    }
    scheme.encrypt(biasct, biasvec, slots, wBits, logQ);

cout << "----------------------------------------" << endl;
cout << "Model provider : end   : CurrentRSS (MB): " << ( Tools::getCurrentRSS() /1024.0/1024.0 ) << endl;
cout << "Model provider : end   : PeakRSS    (MB): " << ( Tools::getPeakRSS() /1024.0/1024.0 )    << endl;
//////////////////////////////////////////////// Model provider ////////////////////////////////////////////////

  long counterr = 0;
  long countall = 0;
  double clientsendMem = 0;
  long long  FourConv2DTime = 0;
  long long  FourMyReLUTime = 0;
  long long  VreMulFourTime = 0;
  long long  MyReLU_Time = 0;
  long long  MyDenseTime = 0;
  for (long n = 0; n < rnum; ++n) {
    cout << "----------------------------------------" << endl;
    cout << "START : " << n+1 << "-th ROUND" << endl;
    cout << "----------------------------------------" << endl;
    cout << "CurrentRSS (MB): " << ( Tools::getCurrentRSS() /1024.0/1024.0 ) << endl;
    cout << "PeakRSS    (MB): " << ( Tools::getPeakRSS() /1024.0/1024.0 )    << endl;
    
    complex<double> *pzData = new complex<double> [slots]();

    if (n < rnum - 1) {

      for (long r = 0; r < batch; ++r) {
        long rlen = (1 << fdimBits);
        for (long i = 0; i < factorDim; ++i) {
          pzData[r * datacolnum + i].real( testdata[batch * n + r][i] );
          pzData[r * datacolnum + i].imag(0);
        }
      }

    } else {

      long rest = sampleDim - batch * (rnum - 1);
      for (long j = 0; j < rest; ++j) {
        long rlen = (1 << fdimBits);
        for (long l = 0; l < factorDim; ++l) {
          pzData[j * rlen + l].real( testdata[batch * n + j][l] );
          pzData[j * rlen + l].imag(0);
        }
      }
    }
    auto currmem0 = Tools::getCurrentRSS() /1024.0/1024.0;
    Ciphertext encTestData;
    scheme.encrypt(encTestData, pzData, slots, wBits, logQ);
    auto currmem1 = Tools::getCurrentRSS() /1024.0/1024.0;
    clientsendMem += double(currmem1 - currmem0);

    delete[] pzData;

    VolleyRevolverEncoding curVRE(encTestData, slots, 28, 28, NULL);
    encTestData.kill();

    
    Ciphertext** encK = new Ciphertext*[4];
    encK[0] = encKernelimage0;
    encK[1] = encKernelimage1;
    encK[2] = encKernelimage2;
    encK[3] = encKernelimage3;
    timeutils.start("Conv2D for four Kernels");
    auto convre0 = curVRE.Conv2D(scheme, secretKey, encK[0], 3, convbias[0], zeroct, cleanct, filterct, rotaterowincomplete_filterct);//.printImages(secretKey, scheme, 1).print(secretKey, scheme, 1);
    auto convre1 = curVRE.Conv2D(scheme, secretKey, encK[1], 3, convbias[1], zeroct, cleanct, filterct, rotaterowincomplete_filterct);//.printImages(secretKey, scheme, 1).print(secretKey, scheme, 1);
    auto convre2 = curVRE.Conv2D(scheme, secretKey, encK[2], 3, convbias[2], zeroct, cleanct, filterct, rotaterowincomplete_filterct);//.printImages(secretKey, scheme, 1).print(secretKey, scheme, 1);
    auto convre3 = curVRE.Conv2D(scheme, secretKey, encK[3], 3, convbias[3], zeroct, cleanct, filterct, rotaterowincomplete_filterct);//.printImages(secretKey, scheme, 1).print(secretKey, scheme, 1);
    timeutils.stop("Conv2D for four Kernels");
    FourConv2DTime += timeutils.timeElapsed;
//cout << "CurrentRSS (MB): " << ( Tools::getCurrentRSS() /1024.0/1024.0 ) << endl;
    delete[] encK;

  
    timeutils.start("MyReLU for the outputs of four Kernels");
    auto myrelu0 = convre0->MyReLU(scheme, CNNdate[2][0], CNNdate[3][0], CNNdate[4][0], CNNdate[5][0]);
    auto myrelu1 = convre1->MyReLU(scheme, CNNdate[2][0], CNNdate[3][0], CNNdate[4][0], CNNdate[5][0]);
    auto myrelu2 = convre2->MyReLU(scheme, CNNdate[2][0], CNNdate[3][0], CNNdate[4][0], CNNdate[5][0]);
    auto myrelu3 = convre3->MyReLU(scheme, CNNdate[2][0], CNNdate[3][0], CNNdate[4][0], CNNdate[5][0]);
    timeutils.stop("MyReLU for the outputs of four Kernels");
    FourMyReLUTime += timeutils.timeElapsed;
    delete convre0;
    delete convre1;
    delete convre2;
    delete convre3;
//cout << "CurrentRSS (MB): " << ( Tools::getCurrentRSS() /1024.0/1024.0 ) << endl;
  

      VolleyRevolverEncoding** v = new VolleyRevolverEncoding*[4];
      v[0] = myrelu0;
      v[1] = myrelu1;
      v[2] = myrelu2;
      v[3] = myrelu3;

//cout << "CurrentRSS (MB): " << ( Tools::getCurrentRSS() /1024.0/1024.0 ) << endl;
      timeutils.start("vre_mul_four for dense1");
      auto vremydense1_0 = myrelu0->vre_mul_four(scheme, v, wCT0, 4, biasCT0, zeroct, vre_mul_four_filterct, vre_mul_four_filterct0, 0 );//.printImages(secretKey, scheme, 1).printparams().print(secretKey, scheme, 1);
      auto vremydense1_1 = myrelu0->vre_mul_four(scheme, v, wCT1, 4, biasCT1, zeroct, vre_mul_four_filterct, vre_mul_four_filterct1, 32 );//.printImages(secretKey, scheme, 1).printparams().print(secretKey, scheme, 1);
      auto vremydense10 = vremydense1_0->add(scheme, *vremydense1_1);
      timeutils.stop("vre_mul_four for dense1");
      VreMulFourTime += timeutils.timeElapsed;

      delete myrelu0;
      delete myrelu1;
      delete myrelu2;
      delete myrelu3;
      
      delete vremydense1_0;              delete vremydense1_1;
      auto vremydense1 = vremydense10->changeImagesize(64);
      delete vremydense10;

//cout << "CurrentRSS (MB): " << ( Tools::getCurrentRSS() /1024.0/1024.0 ) << endl;

      timeutils.start("myrelu3");
      auto vremyrelu3 = vremydense1->MyReLU(scheme, CNNdate[8][0], CNNdate[9][0], CNNdate[10][0], CNNdate[11][0]);//.printImages(secretKey, scheme, 1).printparams();
      timeutils.stop("myrelu3");
      MyReLU_Time += timeutils.timeElapsed;

      delete vremydense1;

//cout << "CurrentRSS (MB): " << ( Tools::getCurrentRSS() /1024.0/1024.0 ) << endl;

      timeutils.start("MyDense");
      auto vre_output = vremyrelu3->MyDense(scheme, weightct, 0, biasct, MyDense_filterct, MyDense_filterct0, 64);
      timeutils.stop("MyDense");
      MyDenseTime += timeutils.timeElapsed;

      delete vremyrelu3;

//cout << "CurrentRSS (MB): " << ( Tools::getCurrentRSS() /1024.0/1024.0 ) << endl;

      //vreoutput->printargmax(secretKey, scheme);
      auto vreoutput = vre_output->changeImagesize(10);
      auto res = vreoutput->returnargmax(secretKey, scheme);
      delete vre_output;
      delete vreoutput;
      for (long idx=0; idx < batch; ++idx) {
        if ( n == rnum - 1 && idx == sampleDim - batch * (rnum - 1) )
           break;
        cout << res[idx] << " ";

      }
      
      cout << endl << "-----------real------------" << endl;

      for (long idx=batch*n; idx < batch*n+batch; ++idx) {
        if ( n == rnum - 1 && idx == sampleDim )
          break;
        cout << int(testlabel[idx]) << " ";
      }
      cout << endl;

      for (long idx=batch*n; idx < batch*n+batch; ++idx) {
        if ( n == rnum - 1 && idx == sampleDim )
          break;
        ++countall;
        if ( long(testlabel[idx]) != res[idx - batch*n] ) {
          ++counterr;
          cout << "x" << " ";
        }
        else 
          cout << "-" << " ";

      }
      delete[] res;
      cout << endl << endl << endl;

    cout << "----- countall = " << countall 
             << ", counterr = " << counterr 
             << ", (countall - counterr) / countall = " << double(countall - counterr) / countall << " -----" << endl; 
    cout << "-------------------- clent >> cloud (MB)  :" <<  clientsendMem / (n+1) << "--------------------" << endl;
    cout << "-------------------- Four Conv2D Cost (ms):" <<  FourConv2DTime/ (n+1) << "--------------------" << endl;
    cout << "-------------------- Four MyReLU Cost (ms):" <<  FourMyReLUTime/ (n+1) << "--------------------" << endl;
    cout << "-------------------- Two VreMulFour Time = " <<  VreMulFourTime/ (n+1) << "--------------------" << endl;
    cout << "-------------------- MyReLU_Time         = " <<  MyReLU_Time   / (n+1) << "--------------------" << endl;
    cout << "-------------------- MyDenseTime         = " <<  MyDenseTime   / (n+1) << "--------------------" << endl;

    cout << endl << "-------------------- END OF THE " << n+1 << "-th BATCH --------------------" << endl;

  }
 cout << endl << "--------------- END ---------------" << endl;

  return 0;
}


int HE_SquareMatrixMult(long dim)  // dim = 4, 16, 64 
{
       
  long wBits = 45;                             // Δ (delta)
  long pBits = 20;

  long logN = Tools::suggestLogN(80, logQ);    // it should be the Security Parameter λ
  
  if ( !Tools::apowerof2(dim) ) {cout << "THE DIM IS NOT A POWER OF TWO!" << endl; exit(-1);}
  
  long slots = dim * dim;
  long sBits = (long)ceil(log2(slots));    

  
  cout << endl << endl;
  cout << "slots = " << slots << endl;
  cout << "logQ = " << logQ << ", logN = " << logN << endl;

  TimeUtils timeutils;
  timeutils.start("Scheme generating...");
  Ring ring;
  SecretKey secretKey(ring);
  Scheme scheme(secretKey, ring); 

    for (long r=0; r < dim; ++r) 
      scheme.addLeftRotKey(secretKey,  r * dim  );

    int lg = int( ceil( log(dim) / log(2) ) ); 
    for (long j=0; j < lg; ++j) 
      scheme.addLeftRotKey(secretKey,  int( pow(2, j) )  );
      
    for (long i=0; i < lg; ++i) 
      scheme.addRightRotKey(secretKey, int( pow(2, i) )  ); 

  timeutils.stop("Scheme generation");
  
    
  double lower_bound = 0.0;
  double upper_bound = 1.0;
  long count = 5;
  for (long n = 0; n < count; ++n) {
    cout << "----------------------------------------" << endl;
    cout << "START : " << n+1 << "-th ROUND" << endl;
    cout << "----------------------------------------" << endl;
    cout << "CurrentRSS (MB): " << ( Tools::getCurrentRSS() /1024.0/1024.0 ) << endl;
    cout << "PeakRSS    (MB): " << ( Tools::getPeakRSS() /1024.0/1024.0 )    << endl;
    

    // construct a trivial random generator engine from a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::uniform_real_distribution<double> distribution (lower_bound, upper_bound);
    //double a_random_double = distribution(generator);

    complex<double> *A = new complex<double> [slots]();
    for (long i=0; i < dim; ++i){
      for (long j=0; j < dim; ++j) {
        A[i * dim + j].real( distribution(generator) ); 
        A[i * dim + j].imag( 0 );
      }
    }
    Ciphertext encMatrixA;
    scheme.encrypt(encMatrixA, A, slots, wBits, logQ);

    complex<double> *B   = new complex<double> [slots]();
    complex<double> *B_T = new complex<double> [slots]();
    for (long i=0; i < dim; ++i){
      for (long j=0; j < dim; ++j) {
        auto temp = distribution(generator);
        B[j * dim + i].real( temp );
        B[j * dim + i].imag( 0 );
        B_T[i * dim + j].real( temp ); 
        B_T[i * dim + j].imag( 0 );
      }
    }
    Ciphertext encMatrixB_T;
    scheme.encrypt(encMatrixB_T, B_T, slots, wBits, logQ);

    complex<double> *C = new complex<double> [slots]();
    for (long ai=0; ai < dim; ++ai){
      for (long bj=0; bj < dim; ++bj) {
        double Cij = 0;
        for (long k=0; k < dim; ++k) {
          Cij += A[ai * dim + k].real() * B[k* dim + bj ].real();
        }
        C[ai * dim + bj].real( Cij ); 
        C[ai * dim + bj].imag( 0 );
      }
    }

cout << " A = " << endl;
    for (long i=0; i < dim; ++i){
      for (long j=0; j < dim; ++j) {
        printf("%+6.4f ",  A[i * dim + j].real() );
      }
      cout << endl;
    }
    cout << endl;
cout << " B = " << endl;
    for (long i=0; i < dim; ++i){
      for (long j=0; j < dim; ++j) {
        printf("%+6.4f ",  B[i * dim + j].real() );
      }
      cout << endl;
    }
    cout << endl;
cout << " B_T = " << endl;
    for (long i=0; i < dim; ++i){
      for (long j=0; j < dim; ++j) {
        printf("%+6.4f ",  B_T[i * dim + j].real() );
      }
      cout << endl;
    }
    cout << endl;
cout << " C = A x B = " << endl;
    for (long i=0; i < dim; ++i){
      for (long j=0; j < dim; ++j) {
        printf("%+6.4f ",  C[i * dim + j].real() );
      }
      cout << endl;
    }
    cout << endl;         
       

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    timeutils.start("HE_SquareMatrixMult...");
    //  encMatrixA   'x'   encMatrixB_T
    Ciphertext resultct;
    auto zeros = new complex<double>[slots]();
    scheme.encrypt(resultct, zeros, slots, wBits, logQ);

    Ciphertext* rotatedct = new Ciphertext[dim];
    NTL_EXEC_RANGE(dim, first, last);
    for (long r=first; r < last; ++r) {
        
        scheme.leftRotateFast(rotatedct[r], encMatrixB_T, r * dim);

        if(rotatedct[r].logq > encMatrixA.logq) scheme.modDownToAndEqual(rotatedct[r],  encMatrixA.logq);
        if(rotatedct[r].logq < encMatrixA.logq) scheme.modDownToAndEqual(encMatrixA,  rotatedct[r].logq);
        scheme.multAndEqual(rotatedct[r], encMatrixA);

        int lg = int( ceil( log(dim) / log(2) ) ); 
        Ciphertext* tempct = new Ciphertext[lg];
        NTL_EXEC_RANGE(lg, first, last);
        for (long i=first; i < last; ++i) {

            scheme.leftRotateFast(tempct[i], rotatedct[r], int( pow(2, i) ) );
            if(rotatedct[r].logp > tempct[i].logp) scheme.reScaleByAndEqual(rotatedct[r],  rotatedct[r].logp-tempct[i].logp);
            if(rotatedct[r].logp < tempct[i].logp) scheme.reScaleByAndEqual(tempct[i], tempct[i].logp-rotatedct[r].logp);
            if(rotatedct[r].logq > tempct[i].logq) scheme.modDownToAndEqual(rotatedct[r],  tempct[i].logq);
            if(rotatedct[r].logq < tempct[i].logq) scheme.modDownToAndEqual(tempct[i], rotatedct[r].logq);

            scheme.addAndEqual(rotatedct[r], tempct[i]);
            tempct[i].kill();
        }
        NTL_EXEC_RANGE_END;
        delete[] tempct;

        double* filtermatrix = new double[slots]();
        for (long rowidx=0; rowidx < dim; ++rowidx)
            filtermatrix[rowidx * dim] = 1;
        Ciphertext filterct;
        scheme.encrypt(filterct, filtermatrix, slots, wBits, rotatedct[r].logq); 
        
        if(rotatedct[r].logq > filterct.logq) scheme.modDownToAndEqual(rotatedct[r],  filterct.logq);
        if(rotatedct[r].logq < filterct.logq) scheme.modDownToAndEqual(filterct, rotatedct[r].logq);
        scheme.multAndEqual(rotatedct[r], filterct);
        
        Ciphertext* tempCT = new Ciphertext[lg];
        NTL_EXEC_RANGE(lg, first, last);
        for (long i=first; i < last; ++i) {
            //Ciphertext tempct;
            scheme.rightRotateFast(tempCT[i], rotatedct[r], int( pow(2, i) ) );

            if(rotatedct[r].logp > tempCT[i].logp) scheme.reScaleByAndEqual(rotatedct[r],  rotatedct[r].logp-tempCT[i].logp);
            if(rotatedct[r].logp < tempCT[i].logp) scheme.reScaleByAndEqual(tempCT[i], tempCT[i].logp-rotatedct[r].logp);
            if(rotatedct[r].logq > tempCT[i].logq) scheme.modDownToAndEqual(rotatedct[r],  tempCT[i].logq);
            if(rotatedct[r].logq < tempCT[i].logq) scheme.modDownToAndEqual(tempCT[i], rotatedct[r].logq);

            scheme.addAndEqual(rotatedct[r], tempCT[i]);
            tempCT[i].kill();      
        }
        NTL_EXEC_RANGE_END;
        delete[] tempCT;        

        filtermatrix = new double[slots]();
        for (long rowidx=0; rowidx < dim; ++rowidx)
            filtermatrix[rowidx * dim + (rowidx + r) % dim] = 1;
        //Ciphertext filterct;
        scheme.encrypt(filterct, filtermatrix, slots, wBits, rotatedct[r].logq);
        delete[] filtermatrix;
        

        if(rotatedct[r].logq > filterct.logq) scheme.modDownToAndEqual(rotatedct[r],  filterct.logq);
        if(rotatedct[r].logq < filterct.logq) scheme.modDownToAndEqual(filterct, rotatedct[r].logq);
        scheme.multAndEqual(rotatedct[r], filterct);   
        filterct.kill();     

        if(resultct.logp > rotatedct[r].logp) scheme.reScaleByAndEqual(resultct,  resultct.logp-rotatedct[r].logp);
        if(resultct.logp < rotatedct[r].logp) scheme.reScaleByAndEqual(rotatedct[r], rotatedct[r].logp-resultct.logp);
        if(resultct.logq > rotatedct[r].logq) scheme.modDownToAndEqual(resultct,  rotatedct[r].logq);
        if(resultct.logq < rotatedct[r].logq) scheme.modDownToAndEqual(rotatedct[r], resultct.logq);
    }
    NTL_EXEC_RANGE_END;
    for (long r=0; r < dim; ++r) {      
        scheme.addAndEqual(resultct, rotatedct[r]);
        rotatedct[r].kill();
    }
    delete[] rotatedct;
    timeutils.stop("HE_SquareMatrixMult");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << endl << endl << " Time : " << timeutils.timeElapsed << endl << endl;
    complex<double>* result = scheme.decrypt(secretKey, resultct);
cout << " result = " << endl;
    for (long i=0; i < dim; ++i){
      for (long j=0; j < dim; ++j) {
        printf("%+6.4f ",  result[i * dim + j].real() );
      }
      cout << endl;
    }
    cout << endl;






resultct.kill();
delete[] zeros;
delete[] result;
    encMatrixA.kill();
    encMatrixB_T.kill();
    delete[] A;
    delete[] B;
    delete[] B_T;
    cout << endl << "-------------------- END OF THE " << n+1 << "-th BATCH --------------------" << endl;

  }
 cout << endl << "--------------- END ---------------" << endl;

  return 0;
}

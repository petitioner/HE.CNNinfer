#ifndef IDASH2017_MYMETHODS_H_
#define IDASH2017_MYMETHODS_H_
#include "Tools.h"
#include "Scheme.h"
#include "Ciphertext.h"
#include <cmath>
#include "SecretKey.h"
#include <assert.h>
#include <string>

/*  def __init__(self, ciphertext, width=5, height=5, datacolnum=None):
        # ct0 is the left matrix of the multiplication of two matrix
        self.ciphertext = ciphertext 
        self.width = width
        self.height = height

        self.colnum = width*height
        self.slots_number = ciphertext.slots_number

        if datacolnum == None: 
          self.datacolnum = int( math.pow( 2, math.ceil(math.log(self.colnum , 2)) ) )
        else:
          self.datacolnum = datacolnum
        self.rownum = int( self.slots_number / self.datacolnum )
*/    
class VolleyRevolverEncoding {
public:
    Ciphertext ciphertext;
    int width;
    int height;
    int colnum;

    int slots_number;
    int datacolnum;
    int rownum;

    string name;

public:
    VolleyRevolverEncoding();
    VolleyRevolverEncoding(Ciphertext &ciphertext, int slots_number, int width=28, int height=28, int datacolnum=NULL);
    ~VolleyRevolverEncoding();
    void setName(string);

    VolleyRevolverEncoding& printparams();
    //VolleyRevolverEncoding copy(VolleyRevolverEncoding vre);
    //VolleyRevolverEncoding& operator=(VolleyRevolverEncoding other);
    bool apowerof2(double floatnumber);
    VolleyRevolverEncoding& print(SecretKey &secretKey, Scheme &scheme, int num=1);
    // print at most five two-dimensional images from the two-dimensional database
    VolleyRevolverEncoding& printImages(SecretKey &secretKey, Scheme &scheme, int num=1);
    //to left-rotate all the images inside each row of the database

    VolleyRevolverEncoding* leftrotaterowincomplete(Scheme &scheme, SecretKey &secretKey, int pos);
    VolleyRevolverEncoding* leftrotaterowincomplete(Scheme &scheme, SecretKey &secretKey, int pos, std::map<long, Ciphertext> &rotaterowincomplete_filterct);
    //to right-rotate all the images inside each row of the database
    VolleyRevolverEncoding* rightrotaterowincomplete(Scheme &scheme, SecretKey &secretKey, int pos);

    VolleyRevolverEncoding* add(Scheme &scheme, Ciphertext& ct);
    VolleyRevolverEncoding* add(Scheme &scheme, VolleyRevolverEncoding& vre);

    VolleyRevolverEncoding* mul(Scheme &scheme, Ciphertext& ct);
    VolleyRevolverEncoding* mul(Scheme &scheme, VolleyRevolverEncoding& vre);

    VolleyRevolverEncoding* changeImagesize(long size);

    /* Given a partrow (spanfilter) with the size of an image: 
       -- padding zeros to the rest of this row
       -- to fill the whole ciphertext (database) with the apartrow              */
    complex<double>* fillfullof(double* apartrow, int len);
    // return a partrow consisted of 2-d filters with special order
    double* spanfilterimage(double* filter, int filterlen, int kernel_size=3, int shift_0=0, int shift_1=0); //strides=(1, 1)

    Ciphertext* spanKernelimage(Scheme &scheme, double* filter, int filterlen, int kernel_size);
    /*
                                                                 X1 X2 X3     (X) 0  0 
      to sum some kernels to the top-left point of each kernel:  X4 X5 X6  >>  0  0  0 
                                                                 X7 X8 X9      0  0  0                                 */ 
    VolleyRevolverEncoding& sumsomekernelsforallrows(Scheme &scheme, SecretKey &secretKey, double* filter, int filterlen, int kernel_size, int shift_0, int shift_1, std::map<long, Ciphertext> &rotaterowincomplete_filterct);//, double bias);//strides=(1, 1) 
    VolleyRevolverEncoding& sumsomekernelsforallrows(Scheme &scheme, SecretKey &secretKey, double* filter, int filterlen, int kernel_size, int shift_0, int shift_1);//, double bias);//strides=(1, 1) 

    // Convolution Layer
    VolleyRevolverEncoding* Conv2D(Scheme &scheme, SecretKey &secretKey, Ciphertext* encKernelimage, int kernel_size, Ciphertext& biasct, Ciphertext& zeroct, Ciphertext* cleanct, Ciphertext* filterct, std::map<long, Ciphertext> &rotaterowincomplete_filterct); 
    // Activation Layer
    VolleyRevolverEncoding* MyReLU(Scheme &scheme, double a0, double a1, double a2, double a3);

    // Fully Connected Layer
    Ciphertext bias_ciphertext(Scheme &scheme, double* bias, int biaslen, int offset=0 );
    ///////////////////////////// PROBLEMS! /////////////////////////////
    VolleyRevolverEncoding* MyDense(Scheme &scheme, Ciphertext& ct, int offset, Ciphertext& biasct, Ciphertext& filterCT, Ciphertext* MyDense_filterct, int biaslen);// bias is the whole bias
    VolleyRevolverEncoding* vre_mul_four(Scheme &scheme, VolleyRevolverEncoding** v, Ciphertext* wCT, int len, Ciphertext& biasCT, Ciphertext& zeroct, Ciphertext& filterCT, Ciphertext* vre_mul_four_filterct, int offset=0 );
    

    int printargmax(SecretKey &secretKey, Scheme &scheme, int num=NULL);
    long* returnargmax(SecretKey &secretKey, Scheme &scheme, int num=NULL);


};

#endif /* MYMETHODS_H_ */

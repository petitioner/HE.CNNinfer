/*
* Copyright (c) by CryptoLab inc.
* This program is licensed under a
* Creative Commons Attribution-NonCommercial 3.0 Unported License.
* You should have received a copy of the license along with this
* work.  If not, see <http://creativecommons.org/licenses/by-nc/3.0/>.
*/

#include "VolleyRevolverEncoding.h"

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
#include <algorithm>    // std::shuffle
#include <vector>        // std::vector
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

#include <unistd.h>
#include <sstream>

VolleyRevolverEncoding::VolleyRevolverEncoding() {
};

VolleyRevolverEncoding::VolleyRevolverEncoding(Ciphertext &ciphertext, int slots_number, int width, int height, int datacolnum) {
    this->ciphertext.copy( ciphertext );
    this->width = width;
    this->height = height;
    this->slots_number = slots_number;

    this->colnum = int(width * height);
    if ( !datacolnum ) 
       this->datacolnum = int( pow( 2, ceil( log(this->colnum) / log(2) ) ) );
    else
       this->datacolnum = datacolnum;
    this->rownum = int( slots_number / (this->datacolnum) );
};

VolleyRevolverEncoding::~VolleyRevolverEncoding(){
    ciphertext.kill();
    width = NULL;
    height = NULL;
    colnum = NULL;
    slots_number = NULL;
    datacolnum = NULL;
    rownum = NULL;
    //cout << name << " ~ INVOKED !" << endl;
};

/*
        this.ciphertext = ciphertext;
        this.width = width;
        this.height = width;
        this.slots_number = slots_number;
*/
VolleyRevolverEncoding& VolleyRevolverEncoding::printparams() {
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "width  = " << this->width << endl;
    cout << "height = " << this->height << endl;
    cout << "colnum = " << this->colnum << endl;
    cout << endl;
    cout << "slots_number = " << this->slots_number << endl;
    cout << "datacolnum   = " << this->datacolnum << endl;
    cout << "rownum       = " << rownum << endl;
    cout << endl;
    cout << "this->ciphertext.n    = " << this->ciphertext.n << endl;
    cout << "this->ciphertext.logp = " << this->ciphertext.logp << endl;
    cout << "this->ciphertext.logq = " << this->ciphertext.logq << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

    return *this;
}

// l = math.log(floatnumber, 2)
// return l == int(l) 
bool VolleyRevolverEncoding::apowerof2(double floatnumber) {
    double l = log(floatnumber) / log(2) ;

    if ( l > int(l) ) return false;
    if ( l < int(l) ) return false;
    return true;    
}

VolleyRevolverEncoding& VolleyRevolverEncoding::print(SecretKey &secretKey, Scheme &scheme, int num){
    assert( num <= this->rownum );
    complex<double>* dcip = scheme.decrypt(secretKey, this->ciphertext );
    cout<<" --------------------- VolleyRevolverEncoding::print --------------------- "<<endl;
    for (long j = 0; j < num; ++j) {
        cout << "[][][] ";
        for (long l = 0; l < (this->colnum > 32 && num!=1? 32: this->colnum); ++l) {
            cout << setiosflags(ios::fixed) << setprecision(7) << dcip[this->datacolnum * j + l].real() << "  ";
        }
        cout << endl;
    }
    cout<<" --------------------- VolleyRevolverEncoding::print --------------------- "<<endl<<endl;

    return *this;
}

VolleyRevolverEncoding& VolleyRevolverEncoding::printImages(SecretKey &secretKey, Scheme &scheme, int num){
    assert( num <= this->rownum );
    complex<double>* dcip = scheme.decrypt(secretKey, this->ciphertext );
    cout<<" --------------------- VolleyRevolverEncoding::printImages --------------------- "<<endl;
    for (long k = 0; k < num; ++k) {

        for (int i=0; i < this->width; ++i) {
            for ( int j=0; j < this->height; ++j)
                //if( dcip[ this->datacolnum * k  +  this->width * i + j ].real() < 1e-2) cout << "     ";
                //else printf("%5.2f ", dcip[ this->datacolnum * k  +  this->width * i + j ].real() ) ;
                if(this->width < 26) 
                    printf("%+7.6f ", dcip[ this->datacolnum * k  +  this->width * i + j ].real() ) ;
                else
                    printf("%+12.10f ", dcip[ this->datacolnum * k  +  this->width * i + j ].real() ) ;
            cout << endl;
        }

        cout << endl;
    }
    cout<<" --------------------- VolleyRevolverEncoding::printImages --------------------- "<<endl<<endl;

    return *this;
}


VolleyRevolverEncoding* VolleyRevolverEncoding::leftrotaterowincomplete(Scheme &scheme, SecretKey &secretKey, int pos) {
    assert( 0 <= pos && pos <= this->colnum );
//cout << endl << "VolleyRevolverEncoding::leftrotaterowincomplete: colnum, pos = " << this->colnum << ", " << pos << endl;
    Ciphertext leftct, leftfilterct;
    //scheme.addLeftRotKey(secretKey, pos);

    scheme.leftRotateFast(leftct, this->ciphertext, pos);

    complex<double>* leftfilter = new complex<double> [this->slots_number]();
    for (int rowidx=0; rowidx < this->rownum; ++rowidx) {
        for (int idx=0; idx < this->colnum - pos; ++idx) {
            leftfilter[rowidx * this->datacolnum + idx] = 1;
        }
    }
    scheme.encrypt(leftfilterct, leftfilter, this->slots_number, 60, leftct.logq);

    assert(leftct.logq == leftfilterct.logq);
    scheme.multAndEqual(leftct, leftfilterct);

    Ciphertext rightct, rightfilterct;
    //scheme.addRightRotKey(secretKey, this->colnum - pos);
    scheme.rightRotateFast(rightct, this->ciphertext, this->colnum - pos);

    complex<double>* rightfilter = new complex<double> [this->slots_number]();
    for (int rowidx=0; rowidx < this->rownum; ++rowidx) {
        for (int idx=0; idx < pos; ++idx) {
            rightfilter[rowidx * this->datacolnum + this->colnum-pos +idx] = 1;
        }
    }
    scheme.encrypt(rightfilterct, rightfilter, this->slots_number, 60, this->ciphertext.logq);
    
    assert(rightct.logq == rightfilterct.logq);
    scheme.multAndEqual(rightct, rightfilterct);

    assert(leftct.logp == rightct.logp);
    assert(leftct.logq == rightct.logq);
    scheme.addAndEqual(leftct, rightct);
    VolleyRevolverEncoding* res = new VolleyRevolverEncoding(leftct, this->slots_number, this->width, this->height, this->datacolnum);
    //this->printImages(secretKey, scheme, 1);
    //res.printparams();
    //res.printImages(secretKey, scheme, 1);
    leftct.kill(); leftfilterct.kill();
    rightct.kill(); rightfilterct.kill();
    delete[] leftfilter;
    delete[] rightfilter;

    return res;
}

VolleyRevolverEncoding* VolleyRevolverEncoding::leftrotaterowincomplete(Scheme &scheme, SecretKey &secretKey, int pos, std::map<long, Ciphertext> &rotaterowincomplete_filterct) {
    assert( 0 <= pos && pos <= this->colnum );
    Ciphertext leftct, leftfilterct;
    //scheme.addLeftRotKey(secretKey, pos);

    scheme.leftRotateFast(leftct, this->ciphertext, pos);

    //std::map<long, Ciphertext> rotaterowincomplete_filterct;
    // Encoding Method: this->colnum * 10000 + pos*1000 + left(0)/right(1)
    long idx = this->colnum * 10000 + pos*1000 + 1;
    auto it = rotaterowincomplete_filterct.find(idx);
    if (it == rotaterowincomplete_filterct.end()) {
        cout << endl << "VolleyRevolverEncoding::leftrotaterowincomplete: colnum, pos = " << this->colnum << ", " << pos << endl;
        exit(-1);
    }
    leftfilterct.copy( it->second );
        if(leftct.logq > leftfilterct.logq) scheme.modDownToAndEqual(leftct, leftfilterct.logq);
        if(leftct.logq < leftfilterct.logq) scheme.modDownToAndEqual(leftfilterct, leftct.logq);
    scheme.multAndEqual(leftct, leftfilterct);

    Ciphertext rightct, rightfilterct;
    //scheme.addRightRotKey(secretKey, this->colnum - pos);
    scheme.rightRotateFast(rightct, this->ciphertext, this->colnum - pos);

    idx = this->colnum * 10000 + pos*1000 + 0;
    it = rotaterowincomplete_filterct.find(idx);
    if (it == rotaterowincomplete_filterct.end()) {
        cout << endl << "VolleyRevolverEncoding::leftrotaterowincomplete: colnum, pos = " << this->colnum << ", " << pos << endl;
        exit(-1);
    }
    rightfilterct.copy( it->second );
        if(rightct.logq > rightfilterct.logq) scheme.modDownToAndEqual(rightct, rightfilterct.logq);
        if(rightct.logq < rightfilterct.logq) scheme.modDownToAndEqual(rightfilterct, rightct.logq);
    scheme.multAndEqual(rightct, rightfilterct);

    assert(leftct.logp == rightct.logp);
    assert(leftct.logq == rightct.logq);
    scheme.addAndEqual(leftct, rightct);
    VolleyRevolverEncoding* res = new VolleyRevolverEncoding(leftct, this->slots_number, this->width, this->height, this->datacolnum);
    //this->printImages(secretKey, scheme, 1);
    //res.printparams();
    //res.printImages(secretKey, scheme, 1);
    leftct.kill(); leftfilterct.kill();
    rightct.kill(); rightfilterct.kill();

    return res;
}


VolleyRevolverEncoding* VolleyRevolverEncoding::rightrotaterowincomplete(Scheme &scheme, SecretKey &secretKey, int pos) {
    assert( 0 <= pos && pos <= this->colnum );

    return this->leftrotaterowincomplete(scheme, secretKey, this->colnum - pos);
}


VolleyRevolverEncoding* VolleyRevolverEncoding::add(Scheme &scheme, Ciphertext& ct) {
    assert( this->ciphertext.logq == ct.logq && this->ciphertext.logp == ct.logp );

    Ciphertext resultct;
    resultct.copy( this->ciphertext );

    scheme.addAndEqual(resultct, ct);
    VolleyRevolverEncoding* res = new VolleyRevolverEncoding(resultct, this->slots_number, this->width, this->height, this->datacolnum);
    resultct.kill();

    return res;
}

VolleyRevolverEncoding* VolleyRevolverEncoding::add(Scheme &scheme, VolleyRevolverEncoding& vre) {
    assert( this->ciphertext.logq == vre.ciphertext.logq && this->ciphertext.logp == vre.ciphertext.logp );

    return this->add(scheme, vre.ciphertext);
}


VolleyRevolverEncoding* VolleyRevolverEncoding::mul(Scheme &scheme, Ciphertext& ct) {
    assert( this->ciphertext.logq == ct.logq );

    Ciphertext resultct;
    resultct.copy( this->ciphertext );

    scheme.multAndEqual(resultct, ct);
    VolleyRevolverEncoding* res = new VolleyRevolverEncoding(resultct, this->slots_number, this->width, this->height, this->datacolnum);
    resultct.kill();

    return res;
}

VolleyRevolverEncoding* VolleyRevolverEncoding::mul(Scheme &scheme, VolleyRevolverEncoding& vre) {
    assert( this->ciphertext.logq == vre.ciphertext.logq );

    return this->mul(scheme, vre.ciphertext);
}

VolleyRevolverEncoding* VolleyRevolverEncoding::changeImagesize(long size) {
    long root0 = size;
    long root1 = 1;
    while(root1 < root0) {
        if (root0 % 2 != 0) break; 
        root0 = root0 / 2; root1 = root1 * 2; 
    }
    VolleyRevolverEncoding* res_vre = new VolleyRevolverEncoding(this->ciphertext, this->slots_number, root0, root1, this->datacolnum);

    return res_vre;
}

/* Given a partrow (spanfilter) with the size of an image: 
   -- padding zeros to the rest of this row
   -- to fill the whole ciphertext (database) with the apartrow              */
complex<double>* VolleyRevolverEncoding::fillfullof(double* apartrow, int len) {
    assert( len <= this->datacolnum );

    long leftnumb = this->datacolnum - len;
    double* resultrow = new double[this->datacolnum]();
    for(long i=0; i < len; ++i) resultrow[i] = apartrow[i];

    complex<double>* pzData = new complex<double>[this->slots_number]();
    for(long rowidx=0; rowidx < this->rownum; ++rowidx) {

        for(long i=0; i < this->datacolnum; ++i) {
            pzData[rowidx * this->datacolnum + i].real( resultrow[i] );
            pzData[rowidx * this->datacolnum + i].imag(0);
        }

    }
    //Ciphertext resultct;
    //scheme.encrypt(resultct, pzData, this->slots_number, 30, logQ);

    //VolleyRevolverEncoding res(resultct, this->slots_number, this->width, this->height, this->datacolnum);

    //return res;

    return pzData;
}


// return a partrow consisted of 2-d filters with special order
double* VolleyRevolverEncoding::spanfilterimage(double* filter, int filterlen, int kernel_size, int shift_0, int shift_1) { //strides=(1, 1)
        assert( filterlen == kernel_size * kernel_size );
        assert( shift_0 < kernel_size && shift_1 < kernel_size );

        double** kernel_rows = new double*[kernel_size]; // store each row of the kernel
        for (int size=0; size < kernel_size; ++size) {
            double* row = new double[kernel_size]();
            for (int i=0; i < kernel_size; ++i) {
                row[i] = filter[size*kernel_size + i];
            }
            kernel_rows[size] = row;
        }

        // for (int size=0; size < kernel_size; ++size) {
        //     double* row = kernel_rows[size];
        //     for (int i=0; i < kernel_size; ++i) {
        //      cout << row[i] << "  ";
        //     }
        //     cout << endl;
        // }

        double* rowfilter = new double[this->colnum]();
        for (int h=0; h < this->height; ++h) 
            for (int w=0; w < this->width; ++w) 
                if ( (w - shift_0) % kernel_size == 0 && w + kernel_size <= this->width ) 
                   if ( (h - shift_1) % kernel_size == 0 && h + kernel_size <= this->height )
                      //filtermatrix[h * self.width + w] = 1
                      for (int kernelrowidx=0; kernelrowidx < kernel_size; ++kernelrowidx)
                          for (int kernelcolidx=0; kernelcolidx < kernel_size; ++kernelcolidx)  
                              rowfilter[h * this->width + w  + kernelrowidx * this->width   + kernelcolidx ] = kernel_rows[kernelrowidx][kernelcolidx];


        return rowfilter;
}

Ciphertext* VolleyRevolverEncoding::spanKernelimage(Scheme &scheme, double* filter, int filterlen, int kernel_size) {//strides=(1, 1) 
    assert( filterlen == kernel_size * kernel_size );
    
    Ciphertext* encResult = new Ciphertext[ kernel_size * kernel_size ];
    NTL_EXEC_RANGE(kernel_size*kernel_size, first, last);
    for (long idx=first; idx < last; ++idx) {
        long x = idx / kernel_size;
        long y = idx % kernel_size;
        long shift_0 = x;
        long shift_1 = y;
        auto imagefilter = this->spanfilterimage(filter, filterlen, kernel_size, shift_0, shift_1); 
        auto message = this->fillfullof(imagefilter, this->colnum);

        scheme.encrypt(encResult[x * kernel_size + y], message, this->slots_number, 60, this->ciphertext.logq);
    }
    NTL_EXEC_RANGE_END;

    return encResult;
}

VolleyRevolverEncoding& VolleyRevolverEncoding::sumsomekernelsforallrows(Scheme &scheme, SecretKey &secretKey, double* filter, int filterlen, int kernel_size, int shift_0, int shift_1, std::map<long, Ciphertext> &rotaterowincomplete_filterct) {//strides=(1, 1) 
    assert( filterlen == kernel_size * kernel_size );
    assert( shift_0 < kernel_size && shift_1 < kernel_size );

    auto imagefilter = this->spanfilterimage(filter, filterlen, kernel_size, shift_0, shift_1); 
    auto message = this->fillfullof(imagefilter, this->colnum);
    Ciphertext ct;
    scheme.encrypt(ct, message, this->slots_number, 60, this->ciphertext.logq);

    auto new_vre = this->mul(scheme, ct);

    Ciphertext resultct;
    auto zeros = new complex<double>[this->slots_number]();
    scheme.encrypt(resultct, zeros, this->slots_number, 60, logQ);
    
    VolleyRevolverEncoding resultvre( new_vre->ciphertext, this->slots_number, this->width, this->height, this->datacolnum );

    // Accumulate columns
    for (int ks=0; ks < kernel_size; ++ ks) {
        auto rotateres = resultvre.leftrotaterowincomplete(scheme, secretKey, ks, rotaterowincomplete_filterct)->ciphertext;

        if(resultct.logp > rotateres.logp) scheme.reScaleByAndEqual(resultct,  resultct.logp-rotateres.logp);
        if(resultct.logp < rotateres.logp) scheme.reScaleByAndEqual(rotateres, rotateres.logp-resultct.logp);
        if(resultct.logq > rotateres.logq) scheme.modDownToAndEqual(resultct,  rotateres.logq);
        if(resultct.logq < rotateres.logq) scheme.modDownToAndEqual(rotateres, resultct.logq);
        assert(resultct.logp == rotateres.logp);
        assert(resultct.logq == rotateres.logq);
        scheme.addAndEqual(resultct, rotateres);
    }
    // Accumulate rows
    VolleyRevolverEncoding res_vre( resultct, this->slots_number, this->width, this->height, this->datacolnum );
    for (int ks=1; ks < kernel_size; ++ks) {
        auto rotateres = res_vre.leftrotaterowincomplete(scheme, secretKey, ks * this->width, rotaterowincomplete_filterct)->ciphertext;

        if(resultct.logp > rotateres.logp) scheme.reScaleByAndEqual(resultct,  resultct.logp-rotateres.logp);
        if(resultct.logp < rotateres.logp) scheme.reScaleByAndEqual(rotateres, rotateres.logp-resultct.logp);
        if(resultct.logq > rotateres.logq) scheme.modDownToAndEqual(resultct,  rotateres.logq);
        if(resultct.logq < rotateres.logq) scheme.modDownToAndEqual(rotateres, resultct.logq);
        assert(resultct.logp == rotateres.logp);
        assert(resultct.logq == rotateres.logq);
        scheme.addAndEqual(resultct, rotateres);
    } 
    
    // Build a new designed matrix to filter out the garbage values, with the help of shift(,)
    double* filtermatrix = new double[this->colnum]();
    for (int h=0; h < this->height; ++h) {
        for (int w=0; w < this->width; ++w) {
            if ( (w - shift_0) % kernel_size == 0 && w + kernel_size <= this->width )
                if ( (h - shift_1) % kernel_size == 0 && h + kernel_size <= this->height )
                    filtermatrix[h * this->width + w] = 1;
        }
    }
    auto filtermessage = this->fillfullof(filtermatrix, this->colnum);
    Ciphertext filterct;
    scheme.encrypt(filterct, filtermessage, this->slots_number, 60, resultct.logq);
    assert(resultct.logq == filterct.logq);
    scheme.multAndEqual(resultct, filterct);

    VolleyRevolverEncoding* result_vre = new VolleyRevolverEncoding(resultct, this->slots_number, this->width, this->height, this->datacolnum );

    return *result_vre;

}

VolleyRevolverEncoding& VolleyRevolverEncoding::sumsomekernelsforallrows(Scheme &scheme, SecretKey &secretKey, double* filter, int filterlen, int kernel_size, int shift_0, int shift_1) {//strides=(1, 1) 
    assert( filterlen == kernel_size * kernel_size );
    assert( shift_0 < kernel_size && shift_1 < kernel_size );

    auto imagefilter = this->spanfilterimage(filter, filterlen, kernel_size, shift_0, shift_1); 
    auto message = this->fillfullof(imagefilter, this->colnum);
    Ciphertext ct;
    scheme.encrypt(ct, message, this->slots_number, 60, this->ciphertext.logq);

    auto new_vre = this->mul(scheme, ct);

    Ciphertext resultct;
    auto zeros = new complex<double>[this->slots_number]();
    scheme.encrypt(resultct, zeros, this->slots_number, 60, logQ);
    
    VolleyRevolverEncoding resultvre( new_vre->ciphertext, this->slots_number, this->width, this->height, this->datacolnum );

    // Accumulate columns
    for (int ks=0; ks < kernel_size; ++ ks) {
        auto rotateres = resultvre.leftrotaterowincomplete(scheme, secretKey, ks)->ciphertext;

        if(resultct.logp > rotateres.logp) scheme.reScaleByAndEqual(resultct,  resultct.logp-rotateres.logp);
        if(resultct.logp < rotateres.logp) scheme.reScaleByAndEqual(rotateres, rotateres.logp-resultct.logp);
        if(resultct.logq > rotateres.logq) scheme.modDownToAndEqual(resultct,  rotateres.logq);
        if(resultct.logq < rotateres.logq) scheme.modDownToAndEqual(rotateres, resultct.logq);
        assert(resultct.logp == rotateres.logp);
        assert(resultct.logq == rotateres.logq);
        scheme.addAndEqual(resultct, rotateres);
    }
    // Accumulate rows
    VolleyRevolverEncoding res_vre( resultct, this->slots_number, this->width, this->height, this->datacolnum );
    for (int ks=1; ks < kernel_size; ++ks) {
        auto rotateres = res_vre.leftrotaterowincomplete(scheme, secretKey, ks * this->width)->ciphertext;

        if(resultct.logp > rotateres.logp) scheme.reScaleByAndEqual(resultct,  resultct.logp-rotateres.logp);
        if(resultct.logp < rotateres.logp) scheme.reScaleByAndEqual(rotateres, rotateres.logp-resultct.logp);
        if(resultct.logq > rotateres.logq) scheme.modDownToAndEqual(resultct,  rotateres.logq);
        if(resultct.logq < rotateres.logq) scheme.modDownToAndEqual(rotateres, resultct.logq);
        assert(resultct.logp == rotateres.logp);
        assert(resultct.logq == rotateres.logq);
        scheme.addAndEqual(resultct, rotateres);
    } 
    
    // Build a new designed matrix to filter out the garbage values, with the help of shift(,)
    double* filtermatrix = new double[this->colnum]();
    for (int h=0; h < this->height; ++h) {
        for (int w=0; w < this->width; ++w) {
            if ( (w - shift_0) % kernel_size == 0 && w + kernel_size <= this->width )
                if ( (h - shift_1) % kernel_size == 0 && h + kernel_size <= this->height )
                    filtermatrix[h * this->width + w] = 1;
        }
    }
    auto filtermessage = this->fillfullof(filtermatrix, this->colnum);
    Ciphertext filterct;
    scheme.encrypt(filterct, filtermessage, this->slots_number, 60, resultct.logq);
    assert(resultct.logq == filterct.logq);
    scheme.multAndEqual(resultct, filterct);

    VolleyRevolverEncoding* result_vre = new VolleyRevolverEncoding(resultct, this->slots_number, this->width, this->height, this->datacolnum );

    return *result_vre;

}

void VolleyRevolverEncoding::setName(string name) {
    this->name = name;
}

VolleyRevolverEncoding* VolleyRevolverEncoding::Conv2D(Scheme &scheme, SecretKey &secretKey, Ciphertext* encKernelimage,  int kernel_size, Ciphertext& biasct, Ciphertext& zeroct, Ciphertext* CleanCt, Ciphertext* FilterCt, std::map<long, Ciphertext> &rotaterowincomplete_filterct) {//strides=(1, 1) 

    //Ciphertext*  kernelImage = this->spanKernelimage(scheme, filter, filterlen, kernel_size);
    //Ciphertext*  kernelImage = encKernelimage;

///////////////////////// put the encrypt method at the beginning of initialation of a class object ///////////////////////////
    Ciphertext ciphertextsums;
    ciphertextsums.copy(biasct);

    Ciphertext* result_ct = new Ciphertext[ kernel_size * kernel_size ];

    NTL_EXEC_RANGE(kernel_size*kernel_size, first, last);
    //long first = 0; long last = kernel_size*kernel_size;
    for(long idx=first; idx < last; ++idx) {
        long x = idx / kernel_size;
        long y = idx % kernel_size;
        long shift_0 = x;
        long shift_1 = y;
        
        //auto sumsomekernels = this->sumsomekernelsforallrows(scheme, secretKey, filter, filterlen, kernel_size, shift_0, shift_1).ciphertext;
        auto new_vre = this->mul(scheme, encKernelimage[idx]);

        result_ct[idx].copy(zeroct);    
        VolleyRevolverEncoding* resultvre = new VolleyRevolverEncoding( new_vre->ciphertext, this->slots_number, this->width, this->height, this->datacolnum );
        delete new_vre;

        // Accumulate columns
        Ciphertext* leftrotateres = new Ciphertext[kernel_size];
        NTL_EXEC_RANGE(kernel_size, first, last);
        for (int ks=first; ks < last; ++ ks) {
            auto tempvre = resultvre->leftrotaterowincomplete(scheme, secretKey, ks, rotaterowincomplete_filterct);
           leftrotateres[ks].copy(tempvre->ciphertext);
           delete tempvre;
        }
        NTL_EXEC_RANGE_END;
        delete resultvre;
 
        for (int ks=0; ks < kernel_size; ++ ks) {
            if(result_ct[idx].logp > leftrotateres[ks].logp) scheme.reScaleByAndEqual(result_ct[idx],  result_ct[idx].logp-leftrotateres[ks].logp);
            if(result_ct[idx].logp < leftrotateres[ks].logp) scheme.reScaleByAndEqual(leftrotateres[ks], leftrotateres[ks].logp-result_ct[idx].logp);
            if(result_ct[idx].logq > leftrotateres[ks].logq) scheme.modDownToAndEqual(result_ct[idx],  leftrotateres[ks].logq);
            if(result_ct[idx].logq < leftrotateres[ks].logq) scheme.modDownToAndEqual(leftrotateres[ks], result_ct[idx].logq);
            scheme.addAndEqual(result_ct[idx], leftrotateres[ks]);

            leftrotateres[ks].kill();
        }
        delete[] leftrotateres;
      
        // Accumulate rows
        VolleyRevolverEncoding* res_vre = new VolleyRevolverEncoding( result_ct[idx], this->slots_number, this->width, this->height, this->datacolnum );
        Ciphertext* rotateres = new Ciphertext[kernel_size];
        NTL_EXEC_RANGE(kernel_size-1, first, last);
        for (int ks=first; ks < last; ++ks) {
            auto tempvre = res_vre->leftrotaterowincomplete(scheme, secretKey, (ks+1) * this->width, rotaterowincomplete_filterct);
            rotateres[ks+1].copy(tempvre->ciphertext);
            delete tempvre;
        }
        NTL_EXEC_RANGE_END;
        delete res_vre;
        for (int ks=0; ks < kernel_size-1; ++ks) {
            if(result_ct[idx].logp > rotateres[ks+1].logp) scheme.reScaleByAndEqual(result_ct[idx],  result_ct[idx].logp-rotateres[ks+1].logp);
            if(result_ct[idx].logp < rotateres[ks+1].logp) scheme.reScaleByAndEqual(rotateres[ks+1], rotateres[ks+1].logp-result_ct[idx].logp);
            if(result_ct[idx].logq > rotateres[ks+1].logq) scheme.modDownToAndEqual(result_ct[idx],  rotateres[ks+1].logq);
            if(result_ct[idx].logq < rotateres[ks+1].logq) scheme.modDownToAndEqual(rotateres[ks+1], result_ct[idx].logq);
            assert(result_ct[idx].logp == rotateres[ks+1].logp);
            assert(result_ct[idx].logq == rotateres[ks+1].logq);
            scheme.addAndEqual(result_ct[idx], rotateres[ks+1]);

            rotateres[ks+1].kill();
        } 
        rotateres[0].kill();
        delete[] rotateres;
        // Build a new designed matrix to filter out the garbage values, with the help of shift(,)
        Ciphertext filterct;
        filterct.copy(FilterCt[idx]);

        if(result_ct[idx].logq > filterct.logq) scheme.modDownToAndEqual(result_ct[idx],  filterct.logq);
        if(result_ct[idx].logq < filterct.logq) scheme.modDownToAndEqual(filterct, result_ct[idx].logq);
        assert(result_ct[idx].logq == filterct.logq);
        scheme.multAndEqual(result_ct[idx], filterct);
        scheme.reScaleByAndEqual(result_ct[idx],  result_ct[idx].logp-filterct.logp);

        filterct.kill();
    }
    NTL_EXEC_RANGE_END;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    for(long idx=0; idx < kernel_size*kernel_size; ++idx) {
        if(ciphertextsums.logp > result_ct[idx].logp) scheme.reScaleByAndEqual(ciphertextsums, ciphertextsums.logp-result_ct[idx].logp);
        if(ciphertextsums.logp < result_ct[idx].logp) scheme.reScaleByAndEqual(result_ct[idx], result_ct[idx].logp-ciphertextsums.logp);
        if(ciphertextsums.logq > result_ct[idx].logq) scheme.modDownToAndEqual(ciphertextsums, result_ct[idx].logq);
        if(ciphertextsums.logq < result_ct[idx].logq) scheme.modDownToAndEqual(result_ct[idx], ciphertextsums.logq);
        assert(ciphertextsums.logp == result_ct[idx].logp);
        assert(ciphertextsums.logq == result_ct[idx].logq);
        scheme.addAndEqual(ciphertextsums, result_ct[idx]); 

        result_ct[idx].kill();        
    }
    delete[] result_ct;
 
    VolleyRevolverEncoding* vre_res = new VolleyRevolverEncoding(ciphertextsums, this->slots_number, this->width, this->height, this->datacolnum);

    Ciphertext resultct;
    resultct.copy(zeroct);
    Ciphertext* cleanct = new Ciphertext[this->height - kernel_size + 1];
     NTL_EXEC_RANGE(this->height - kernel_size + 1, first, last);
    for(long rowth=first; rowth < last; ++rowth) { // ASSUME THAT: strides=(1, 1)
        // design a new matrix ....
        // rowfilter = [0] * ( rowth * (self.width - kernel_size + 1) ) +  [1] * (self.width - kernel_size + 1)
        // messagefilter = rowfilter + [0] * ( self.datacolnum - len(rowfilter) )
        cleanct[rowth].copy(CleanCt[rowth]);
        auto tempvre = vre_res->leftrotaterowincomplete(scheme, secretKey, rowth * (kernel_size - 1), rotaterowincomplete_filterct); 
        Ciphertext tempct; tempct.copy( tempvre->ciphertext );
        if(tempct.logq > cleanct[rowth].logq) scheme.modDownToAndEqual(tempct,  cleanct[rowth].logq);
        if(tempct.logq < cleanct[rowth].logq) scheme.modDownToAndEqual(cleanct[rowth], tempct.logq);
        assert(cleanct[rowth].logq == tempct.logq);
        scheme.multAndEqual(cleanct[rowth], tempct);

        delete tempvre;
        tempct.kill();
    }
    NTL_EXEC_RANGE_END;
    delete vre_res;
    for(long rowth=0; rowth < this->height - kernel_size + 1; ++rowth) {
        if(resultct.logp > cleanct[rowth].logp) scheme.reScaleByAndEqual(resultct, resultct.logp-cleanct[rowth].logp);
        if(resultct.logp < cleanct[rowth].logp) scheme.reScaleByAndEqual(cleanct[rowth],  cleanct[rowth].logp-resultct.logp);
        if(resultct.logq > cleanct[rowth].logq) scheme.modDownToAndEqual(resultct, cleanct[rowth].logq);
        if(resultct.logq < cleanct[rowth].logq) scheme.modDownToAndEqual(cleanct[rowth],  resultct.logq);
        assert(resultct.logp == cleanct[rowth].logp);
        assert(resultct.logq == cleanct[rowth].logq);
        scheme.addAndEqual(resultct, cleanct[rowth]); 

        cleanct[rowth].kill();
    }
    delete[] cleanct;

ciphertextsums.kill();
    VolleyRevolverEncoding* result_vre = new VolleyRevolverEncoding(resultct, this->slots_number, this->width - kernel_size + 1, this->height - kernel_size + 1, this->datacolnum);
    resultct.kill();

    return result_vre;
}

// Activation Layer
VolleyRevolverEncoding* VolleyRevolverEncoding::MyReLU(Scheme &scheme, double a0, double a1, double a2, double a3) {
    assert(a3 > 0 || a3 < 0);
    
        Ciphertext ctx, ctx2, ctres;
        ctx.copy(this->ciphertext);
        ctres.copy(this->ciphertext);
        scheme.square(ctx2, ctx);
        scheme.multAndEqual(ctres, ctx2);
        scheme.reScaleByAndEqual(ctres,  ctx.logp);

        scheme.multByConstAndEqual(ctx, a1, ctx.logp);
        scheme.multByConstAndEqual(ctx2, a2, ctx2.logp);
        scheme.multByConstAndEqual(ctres, a3, ctres.logp);


        if(ctres.logp > ctx2.logp) scheme.reScaleByAndEqual(ctres,  ctres.logp-ctx2.logp);
        if(ctres.logp < ctx2.logp) scheme.reScaleByAndEqual(ctx2, ctx2.logp-ctres.logp);
        if(ctres.logq > ctx2.logq) scheme.modDownToAndEqual(ctres,  ctx2.logq);
        if(ctres.logq < ctx2.logq) scheme.modDownToAndEqual(ctx2, ctres.logq);
        scheme.addAndEqual(ctres, ctx2);

        if(ctres.logp > ctx.logp) scheme.reScaleByAndEqual(ctres,  ctres.logp-ctx.logp);
        if(ctres.logp < ctx.logp) scheme.reScaleByAndEqual(ctx, ctx.logp-ctres.logp);
        if(ctres.logq > ctx.logq) scheme.modDownToAndEqual(ctres,  ctx.logq);
        if(ctres.logq < ctx.logq) scheme.modDownToAndEqual(ctx, ctres.logq);
        scheme.addAndEqual(ctres, ctx);

        scheme.addConstAndEqual(ctres, a0, ctres.logp);
        scheme.reScaleByAndEqual(ctres,  this->ciphertext.logp);
        //cout << "{}{}{}{}{}{}{}:  " << ctres.logp << "  :{}{}{}{}{}{}{}" << endl;


        VolleyRevolverEncoding* result_vre = new VolleyRevolverEncoding(ctres, this->slots_number, this->width, this->height, this->datacolnum );
        ctx.kill();
        ctx2.kill();
        ctres.kill();
        return result_vre;        
}


// Fully Connected Layer
Ciphertext VolleyRevolverEncoding::bias_ciphertext(Scheme &scheme, double* bias, int biaslen, int offset ) {
    Ciphertext resultct;
    auto zeros = new complex<double>[this->slots_number]();
    if (biaslen > this->rownum)
        biaslen = this->rownum;
    for (long j=0; j < biaslen; ++j) {
        for (long i=0; i < this->rownum; ++i) {
            zeros[i * this->datacolnum + offset + j] = bias[offset + j];
        }
    }
    scheme.encrypt(resultct, zeros, this->slots_number, 60, logQ);

    return resultct;
}
VolleyRevolverEncoding* VolleyRevolverEncoding::MyDense(Scheme &scheme, Ciphertext& ct, int offset, Ciphertext& biasct, Ciphertext& filterCT, Ciphertext* MyDense_filterct, int biaslen) {
                                                                                                      // bias is the whole bias
    assert( offset + this->rownum <= this->datacolnum );

    Ciphertext resultct;
    resultct.copy(biasct);

    Ciphertext* rotatedct = new Ciphertext[this->rownum];
    NTL_EXEC_RANGE(this->rownum, first, last);
    for (long r=first; r < last; ++r) {
        
        scheme.leftRotateFast(rotatedct[r], ct, r * this->datacolnum);

        if(rotatedct[r].logq > this->ciphertext.logq) scheme.modDownToAndEqual(rotatedct[r],  this->ciphertext.logq);
        if(rotatedct[r].logq < this->ciphertext.logq) scheme.modDownToAndEqual(this->ciphertext, rotatedct[r].logq);
        assert(this->ciphertext.logq == rotatedct[r].logq);
        scheme.multAndEqual(rotatedct[r], this->ciphertext);

        int lg = int( ceil( log(this->colnum) / log(2) ) ); 
        Ciphertext* tempct = new Ciphertext[int( ceil( log(this->colnum) / log(2) ) )];
        NTL_EXEC_RANGE(lg, first, last);
        for (long i=first; i < last; ++i) {
            //Ciphertext tempct;
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

        //double* filtermatrix = new double[this->slots_number]();
        //for (long rowidx=0; rowidx < this->rownum; ++rowidx)
        //    filtermatrix[rowidx * this->datacolnum] = 1;
        Ciphertext filterct;
        //scheme.encrypt(filterct, filtermatrix, this->slots_number, 60, rotatedct[r].logq);
        filterct.copy(filterCT);

        if(rotatedct[r].logq > filterct.logq) scheme.modDownToAndEqual(rotatedct[r],  filterct.logq);
        if(rotatedct[r].logq < filterct.logq) scheme.modDownToAndEqual(filterct, rotatedct[r].logq);
        scheme.multAndEqual(rotatedct[r], filterct);

        lg = int( ceil( log(this->datacolnum) / log(2) ) );
        
        Ciphertext* tempCT = new Ciphertext[int( ceil( log(this->datacolnum) / log(2) ) )];
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

        //filtermatrix = new double[this->slots_number]();
        //for (long rowidx=0; rowidx < this->rownum; ++rowidx)
        //    filtermatrix[offset + rowidx * this->datacolnum + (rowidx + r) % this->rownum] = 1;
        //Ciphertext filterct;
        //scheme.encrypt(filterct, filtermatrix, this->slots_number, 60, rotatedct[r].logq);
        filterct.copy(MyDense_filterct[r]);

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
    for (long r=0; r < this->rownum; ++r) {      
        scheme.addAndEqual(resultct, rotatedct[r]);
        rotatedct[r].kill();
    }
    delete[] rotatedct;

    VolleyRevolverEncoding* result_vre = new VolleyRevolverEncoding(resultct, this->slots_number, this->width, this->height, this->datacolnum );
    resultct.kill();
    return result_vre;
}

VolleyRevolverEncoding* VolleyRevolverEncoding::vre_mul_four(Scheme &scheme, VolleyRevolverEncoding** v, Ciphertext* wCT, int len, Ciphertext& biasCT, Ciphertext& zeroct, Ciphertext& filterCT, Ciphertext* vre_mul_four_filterct, int offset ) {
    //assert( offset + this->rownum <= this->datacolnum );
    //assert( v[0].ciphertext.logq == wCT[0].logq );

    Ciphertext resultct;
    resultct.copy(biasCT);
    //auto zeros = new complex<double>[this->slots_number]();
    //scheme.encrypt(resultct, zeros, this->slots_number, 60, logQ);
    
        Ciphertext* combinect = new Ciphertext[this->rownum];
        //Ciphertext combinectemp;
        //auto zeros = new complex<double>[this->slots_number]();
        //scheme.encrypt(combinectemp, zeros, this->slots_number, 60, logQ);
        //combinectemp.copy(zeroct);

    NTL_EXEC_RANGE(this->rownum, first, last);
    for (long r=first; r < last; ++r) {
        combinect[r].copy(zeroct);

        Ciphertext* rotatedct = new Ciphertext[len];
        NTL_EXEC_RANGE(len, first, last);
        for (long L=first; L < last; ++L) {
            scheme.leftRotateFast(rotatedct[L], wCT[L], r * this->datacolnum);
            Ciphertext vtemp;
            vtemp.copy(v[L]->ciphertext);
            if(rotatedct[L].logq > vtemp.logq) scheme.modDownToAndEqual(rotatedct[L],  vtemp.logq);
            if(rotatedct[L].logq < vtemp.logq) scheme.modDownToAndEqual(vtemp, rotatedct[L].logq);
            scheme.multAndEqual(rotatedct[L], vtemp);
            vtemp.kill();

            //scheme.reScaleByAndEqual(rotatedct[L],  rotatedct[L].logp-v[L].ciphertext.logp);
            if(combinect[r].logp > rotatedct[L].logp) scheme.reScaleByAndEqual(combinect[r],  combinect[r].logp-rotatedct[L].logp);
            if(combinect[r].logp < rotatedct[L].logp) scheme.reScaleByAndEqual(rotatedct[L], rotatedct[L].logp-combinect[r].logp);
            if(combinect[r].logq > rotatedct[L].logq) scheme.modDownToAndEqual(combinect[r],  rotatedct[L].logq);
            if(combinect[r].logq < rotatedct[L].logq) scheme.modDownToAndEqual(rotatedct[L], combinect[r].logq);
        }
        NTL_EXEC_RANGE_END;
        for (long L=0; L < len; ++L) {
            scheme.addAndEqual(combinect[r], rotatedct[L]);
            rotatedct[L].kill();
        }
        delete[] rotatedct;

        int lg = int( ceil( log(this->colnum) / log(2) ) ); 
        Ciphertext* tempct = new Ciphertext[int( ceil( log(this->colnum) / log(2) ) )];
        NTL_EXEC_RANGE(lg, first, last);
        for (long i=first; i < last; ++i) {
            //Ciphertext tempct;
            scheme.leftRotateFast(tempct[i], combinect[r], int( pow(2, i) ) );

            if(combinect[r].logp > tempct[i].logp) scheme.reScaleByAndEqual(combinect[r],  combinect[r].logp-tempct[i].logp);
            if(combinect[r].logp < tempct[i].logp) scheme.reScaleByAndEqual(tempct[i], tempct[i].logp-combinect[r].logp);
            if(combinect[r].logq > tempct[i].logq) scheme.modDownToAndEqual(combinect[r],  tempct[i].logq);
            if(combinect[r].logq < tempct[i].logq) scheme.modDownToAndEqual(tempct[i], combinect[r].logq);
            scheme.addAndEqual(combinect[r], tempct[i]);

            tempct[i].kill();
        }
        NTL_EXEC_RANGE_END;
        delete[] tempct;

        Ciphertext filterct;
        filterct.copy(filterCT);
        scheme.modDownToAndEqual(filterct, combinect[r].logq);
        
        if(combinect[r].logq > filterct.logq) scheme.modDownToAndEqual(combinect[r],  filterct.logq);
        if(combinect[r].logq < filterct.logq) scheme.modDownToAndEqual(filterct, combinect[r].logq);
        scheme.multAndEqual(combinect[r], filterct);
        scheme.reScaleByAndEqual(combinect[r], combinect[r].logp-filterct.logp);


        lg = int( ceil( log(this->datacolnum) / log(2) ) );
        
        Ciphertext* tempCT = new Ciphertext[int( ceil( log(this->datacolnum) / log(2) ) )];
        NTL_EXEC_RANGE(lg, first, last);
        for (long i=first; i < last; ++i) {
            //Ciphertext tempct;
            scheme.rightRotateFast(tempCT[i], combinect[r], int( pow(2, i) ) );

            if(combinect[r].logp > tempCT[i].logp) scheme.reScaleByAndEqual(combinect[r],  combinect[r].logp-tempCT[i].logp);
            if(combinect[r].logp < tempCT[i].logp) scheme.reScaleByAndEqual(tempCT[i], tempCT[i].logp-combinect[r].logp);
            if(combinect[r].logq > tempCT[i].logq) scheme.modDownToAndEqual(combinect[r],  tempCT[i].logq);
            if(combinect[r].logq < tempCT[i].logq) scheme.modDownToAndEqual(tempCT[i], combinect[r].logq);
            scheme.addAndEqual(combinect[r], tempCT[i]);

            tempCT[i].kill();
        }
        NTL_EXEC_RANGE_END;
        delete[] tempCT;
        

        //Ciphertext filterct;
        filterct.copy(vre_mul_four_filterct[r]);
        scheme.modDownToAndEqual(filterct, combinect[r].logq);

        if(combinect[r].logq > filterct.logq) scheme.modDownToAndEqual(combinect[r],  filterct.logq);
        if(combinect[r].logq < filterct.logq) scheme.modDownToAndEqual(filterct, combinect[r].logq);
        scheme.multAndEqual(combinect[r], filterct); 
        filterct.kill(); 

        if(resultct.logp > combinect[r].logp) scheme.reScaleByAndEqual(resultct,  resultct.logp-combinect[r].logp);
        if(resultct.logp < combinect[r].logp) scheme.reScaleByAndEqual(combinect[r], combinect[r].logp-resultct.logp);
        if(resultct.logq > combinect[r].logq) scheme.modDownToAndEqual(resultct,  combinect[r].logq);
        if(resultct.logq < combinect[r].logq) scheme.modDownToAndEqual(combinect[r], resultct.logq);          
    }
    NTL_EXEC_RANGE_END;

    for (long r=0; r < this->rownum; ++r) {     
        scheme.addAndEqual(resultct, combinect[r]);
        combinect[r].kill();
    }
    delete[] combinect;
    //if(resultct.logp > biasCT.logp) scheme.reScaleByAndEqual(resultct,  resultct.logp-biasCT.logp);
    //if(resultct.logp < biasCT.logp) scheme.reScaleByAndEqual(biasCT, biasCT.logp-resultct.logp);
    //if(resultct.logq > biasCT.logq) scheme.modDownToAndEqual(resultct,  biasCT.logq);
    //if(resultct.logq < biasCT.logq) scheme.modDownToAndEqual(biasCT, resultct.logq);      
    //scheme.addAndEqual(resultct, biasCT);
    VolleyRevolverEncoding* result_vre = new VolleyRevolverEncoding(resultct, this->slots_number, this->width, this->height, this->datacolnum );
    resultct.kill();
    
    return result_vre;
}


int VolleyRevolverEncoding::printargmax(SecretKey &secretKey, Scheme &scheme, int num) {
    if(num == NULL) num = this->rownum;
    assert( num <= this->rownum );

    complex<double>* mess = scheme.decrypt(secretKey, this->ciphertext );
    cout<<" --------------------- VolleyRevolverEncoding::printargmax --------------------- "<<endl;
    for (long i = 0; i < num; ++i) {
        long argmaxindex = 0;
        auto argmaxvalue = mess[i * this->datacolnum].real();
        for (int j=0; j < this->colnum; ++j) {
            if (argmaxvalue < mess[i * this->datacolnum + j].real()) {
                argmaxvalue = mess[i * this->datacolnum + j].real();
                argmaxindex = j;
            }
        }
        cout << argmaxindex << "  ";
    }
    cout << endl;
    cout <<" ------------------------------------------------------------------------------- " << endl << endl;

    return 0;
}
long* VolleyRevolverEncoding::returnargmax(SecretKey &secretKey, Scheme &scheme, int num) {
    if(num == NULL) num = this->rownum;
    assert( num <= this->rownum );

    complex<double>* mess = scheme.decrypt(secretKey, this->ciphertext );
    long* result = new long[num]();

    for (long i = 0; i < num; ++i) {
        long argmaxindex = 0;
        auto argmaxvalue = mess[i * this->datacolnum].real();
        for (int j=0; j < this->colnum; ++j) {
            if (argmaxvalue < mess[i * this->datacolnum + j].real()) {
                argmaxvalue = mess[i * this->datacolnum + j].real();
                argmaxindex = j;
            }
        }
        result[i] = argmaxindex; 
    }

    return result;
}


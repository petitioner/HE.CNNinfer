# How To Run：
```shell
Welcome to Ubuntu 24.04 LTS (GNU/Linux 6.8.0-39-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/pro

 System information as of Mon Aug 12 03:50:19 PM UTC 2024

  System load:             0.1
  Usage of /:              24.8% of 22.88GB
  Memory usage:            9%
  Swap usage:              0%
  Processes:               136
  Users logged in:         0
  IPv4 address for enp1s0: 107.191.42.70
  IPv6 address for enp1s0: 2001:19f0:1000:34e4:5400:5ff:fe0e:4ae5


Expanded Security Maintenance for Applications is not enabled.

0 updates can be applied immediately.

Enable ESM Apps to receive additional future security updates.
See https://ubuntu.com/esm or run: sudo pro status


The list of available updates is more than a week old.
To check for new updates run: sudo apt update


The programs included with the Ubuntu system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Ubuntu comes with ABSOLUTELY NO WARRANTY, to the extent permitted by
applicable law.

root@vultr:~# cd /home
root@vultr:/home# mkdir john
root@vultr:/home# cd john
root@vultr:/home/john# mkdir smith
root@vultr:/home/john# cd smith/
root@vultr:/home/john/smith# git clone  https://github.com/petitioner/HE.CNNinfer
Cloning into 'HE.CNNinfer'...
remote: Enumerating objects: 2784, done.
remote: Counting objects: 100% (676/676), done.
remote: Compressing objects: 100% (361/361), done.
remote: Total 2784 (delta 241), reused 567 (delta 186), pack-reused 2108
Receiving objects: 100% (2784/2784), 1.03 GiB | 85.68 MiB/s, done.
Resolving deltas: 100% (1329/1329), done.
Updating files: 100% (314/314), done.
root@vultr:/home/john/smith# ls
HE.CNNinfer
root@vultr:/home/john/smith# cd HE.CNNinfer/CNNinference/lib/lib/
root@vultr:/home/john/smith/HE.CNNinfer/CNNinference/lib/lib# unzip libntl.a.zip 
Archive:  libntl.a.zip
  inflating: libntl.a                
root@vultr:/home/john/smith/HE.CNNinfer/CNNinference/lib/lib# cd ..
root@vultr:/home/john/smith/HE.CNNinfer/CNNinference/lib# cd ..
root@vultr:/home/john/smith/HE.CNNinfer/CNNinference# cd Default/
root@vultr:/home/john/smith/HE.CNNinfer/CNNinference/Default# make clean
rm      ./src/CNNinference.o ./src/VolleyRevolverEncoding.o ./src/Methods.o ./src/Tools.o  ./HEAAN/HEAAN/src/BootContext.o ./HEAAN/HEAAN/src/Ciphertext.o ./HEAAN/HEAAN/src/EvaluatorUtils.o ./HEAAN/HEAAN/src/HEAAN.o ./HEAAN/HEAAN/src/Key.o ./HEAAN/HEAAN/src/Plaintext.o ./HEAAN/HEAAN/src/Ring.o ./HEAAN/HEAAN/src/RingMultiplier.o ./HEAAN/HEAAN/src/Scheme.o ./HEAAN/HEAAN/src/SchemeAlgo.o ./HEAAN/HEAAN/src/SecretKey.o ./HEAAN/HEAAN/src/SerializationUtils.o ./HEAAN/HEAAN/src/StringUtils.o ./HEAAN/HEAAN/src/TestScheme.o ./HEAAN/HEAAN/src/TimeUtils.o  ./src/CNNinference.d ./src/VolleyRevolverEncoding.d ./src/Methods.d ./src/Tools.d  ./HEAAN/HEAAN/src/BootContext.d ./HEAAN/HEAAN/src/Ciphertext.d ./HEAAN/HEAAN/src/EvaluatorUtils.d ./HEAAN/HEAAN/src/HEAAN.d ./HEAAN/HEAAN/src/Key.d ./HEAAN/HEAAN/src/Plaintext.d ./HEAAN/HEAAN/src/Ring.d ./HEAAN/HEAAN/src/RingMultiplier.d ./HEAAN/HEAAN/src/Scheme.d ./HEAAN/HEAAN/src/SchemeAlgo.d ./HEAAN/HEAAN/src/SecretKey.d ./HEAAN/HEAAN/src/SerializationUtils.d ./HEAAN/HEAAN/src/StringUtils.d ./HEAAN/HEAAN/src/TestScheme.d ./HEAAN/HEAAN/src/TimeUtils.d   CNNinference
 
root@vultr:/home/john/smith/HE.CNNinfer/CNNinference/Default# make all
Building file: ../src/CNNinference.cpp
Invoking: GCC C++ Compiler [CNNinference/Default/src/subdir.mk]
g++ -I/home/john/smith/HE.CNNinfer/CNNinference/lib/include -I/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"src/CNNinference.d" -MT"src/CNNinference.o" -o "src/CNNinference.o" "../src/CNNinference.cpp"
In file included from ../src/Methods.h:3,
                 from ../src/CNNinference.cpp:8:
../src/VolleyRevolverEncoding.h:41:114: warning: converting to non-pointer type ‘int’ from NULL [-Wconversion-null]
   41 |     VolleyRevolverEncoding(Ciphertext &ciphertext, int slots_number, int width=28, int height=28, int datacolnum=NULL);
      |                                                                                                                  ^~~~
../src/VolleyRevolverEncoding.h:94:67: warning: converting to non-pointer type ‘int’ from NULL [-Wconversion-null]
   94 |     int printargmax(SecretKey &secretKey, Scheme &scheme, int num=NULL);
      |                                                                   ^~~~
../src/VolleyRevolverEncoding.h:95:70: warning: converting to non-pointer type ‘int’ from NULL [-Wconversion-null]
   95 |     long* returnargmax(SecretKey &secretKey, Scheme &scheme, int num=NULL);
      |                                                                      ^~~~
../src/CNNinference.cpp: In function ‘int main(int, char**)’:
../src/CNNinference.cpp:37:18: warning: unused variable ‘traindataset’ [-Wunused-variable]
   37 |         double **traindataset, **testdataset;
      |                  ^~~~~~~~~~~~
../src/CNNinference.cpp:38:17: warning: unused variable ‘traindatalabel’ [-Wunused-variable]
   38 |         double *traindatalabel, *testdatalabel;
      |                 ^~~~~~~~~~~~~~
../src/CNNinference.cpp:41:18: warning: unused variable ‘zDate’ [-Wunused-variable]
   41 |         double **zDate = Tools::dataFromFile(testfile, testfactorDim, testSampleDim, testdataset, testdatalabel);
      |                  ^~~~~
In file included from ../src/Methods.h:2:
/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src/Scheme.h: At global scope:
/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src/Scheme.h:28:13: warning: ‘CONJUGATION’ defined but not used [-Wunused-variable]
   28 | static long CONJUGATION = 2;
      |             ^~~~~~~~~~~
/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src/Scheme.h:27:13: warning: ‘MULTIPLICATION’ defined but not used [-Wunused-variable]
   27 | static long MULTIPLICATION  = 1;
      |             ^~~~~~~~~~~~~~
/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src/Scheme.h:26:13: warning: ‘ENCRYPTION’ defined but not used [-Wunused-variable]
   26 | static long ENCRYPTION = 0;
      |             ^~~~~~~~~~
In file included from ../src/Methods.h:1:
../src/Tools.h:67:15: warning: ‘degree7_36’ defined but not used [-Wunused-variable]
   67 | static double degree7_36[5] = {+0.5, -0.11634, +0.0011850, -0.0000062074, +0.000000011389};
      |               ^~~~~~~~~~
../src/Tools.h:63:15: warning: ‘degree7_24’ defined but not used [-Wunused-variable]
   63 | static double degree7_24[5] = {+0.5, -0.15512, +0.0028088, -0.000026158,  +0.000000085324};
      |               ^~~~~~~~~~
../src/Tools.h:60:15: warning: ‘degree7_12’ defined but not used [-Wunused-variable]
   60 | static double degree7_12[5] = {+0.5, -2.3514e-01, +1.2329e-02, -3.9345e-04, +4.7292e-06};  // 1 - poly(-yWTx)
      |               ^~~~~~~~~~
../src/Tools.h:50:15: warning: ‘degree7’ defined but not used [-Wunused-variable]
   50 | static double degree7[5] = {+0.5, -0.10843500, +0.00102394287, -0.00000518229, +0.00000000934};  //|wTx| < 16
      |               ^~~~~~~
../src/Tools.h:44:15: warning: ‘degree5’ defined but not used [-Wunused-variable]
   44 | static double degree5[4] = {+0.5, -0.19131, +0.0045963,   -0.0000412332};
      |               ^~~~~~~
../src/Tools.h:42:15: warning: ‘degree3’ defined but not used [-Wunused-variable]
   42 | static double degree3[3] = {+0.5, -0.15012, +0.00159300781};  // 1 - poly(-yWTx)
      |               ^~~~~~~
Finished building: ../src/CNNinference.cpp
 
Building file: ../src/VolleyRevolverEncoding.cpp
Invoking: GCC C++ Compiler [CNNinference/Default/src/subdir.mk]
g++ -I/home/john/smith/HE.CNNinfer/CNNinference/lib/include -I/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"src/VolleyRevolverEncoding.d" -MT"src/VolleyRevolverEncoding.o" -o "src/VolleyRevolverEncoding.o" "../src/VolleyRevolverEncoding.cpp"
In file included from ../src/VolleyRevolverEncoding.cpp:1:
../src/VolleyRevolverEncoding.h:41:114: warning: converting to non-pointer type ‘int’ from NULL [-Wconversion-null]
   41 |     VolleyRevolverEncoding(Ciphertext &ciphertext, int slots_number, int width=28, int height=28, int datacolnum=NULL);
      |                                                                                                                  ^~~~
../src/VolleyRevolverEncoding.h:94:67: warning: converting to non-pointer type ‘int’ from NULL [-Wconversion-null]
   94 |     int printargmax(SecretKey &secretKey, Scheme &scheme, int num=NULL);
      |                                                                   ^~~~
../src/VolleyRevolverEncoding.h:95:70: warning: converting to non-pointer type ‘int’ from NULL [-Wconversion-null]
   95 |     long* returnargmax(SecretKey &secretKey, Scheme &scheme, int num=NULL);
      |                                                                      ^~~~
../src/VolleyRevolverEncoding.cpp: In destructor ‘VolleyRevolverEncoding::~VolleyRevolverEncoding()’:
../src/VolleyRevolverEncoding.cpp:47:13: warning: converting to non-pointer type ‘int’ from NULL [-Wconversion-null]
   47 |     width = NULL;
      |             ^~~~
../src/VolleyRevolverEncoding.cpp:48:14: warning: converting to non-pointer type ‘int’ from NULL [-Wconversion-null]
   48 |     height = NULL;
      |              ^~~~
../src/VolleyRevolverEncoding.cpp:49:14: warning: converting to non-pointer type ‘int’ from NULL [-Wconversion-null]
   49 |     colnum = NULL;
      |              ^~~~
../src/VolleyRevolverEncoding.cpp:50:20: warning: converting to non-pointer type ‘int’ from NULL [-Wconversion-null]
   50 |     slots_number = NULL;
      |                    ^~~~
../src/VolleyRevolverEncoding.cpp:51:18: warning: converting to non-pointer type ‘int’ from NULL [-Wconversion-null]
   51 |     datacolnum = NULL;
      |                  ^~~~
../src/VolleyRevolverEncoding.cpp:52:14: warning: converting to non-pointer type ‘int’ from NULL [-Wconversion-null]
   52 |     rownum = NULL;
      |              ^~~~
../src/VolleyRevolverEncoding.cpp: In member function ‘std::complex<double>* VolleyRevolverEncoding::fillfullof(double*, int)’:
../src/VolleyRevolverEncoding.cpp:293:10: warning: unused variable ‘leftnumb’ [-Wunused-variable]
  293 |     long leftnumb = this->datacolnum - len;
      |          ^~~~~~~~
../src/VolleyRevolverEncoding.cpp: In lambda function:
../src/VolleyRevolverEncoding.cpp:521:14: warning: unused variable ‘shift_0’ [-Wunused-variable]
  521 |         long shift_0 = x;
      |              ^~~~~~~
../src/VolleyRevolverEncoding.cpp:522:14: warning: unused variable ‘shift_1’ [-Wunused-variable]
  522 |         long shift_1 = y;
      |              ^~~~~~~
../src/VolleyRevolverEncoding.cpp: In member function ‘int VolleyRevolverEncoding::printargmax(SecretKey&, Scheme&, int)’:
../src/VolleyRevolverEncoding.cpp:922:15: warning: NULL used in arithmetic [-Wpointer-arith]
  922 |     if(num == NULL) num = this->rownum;
      |               ^~~~
../src/VolleyRevolverEncoding.cpp: In member function ‘long int* VolleyRevolverEncoding::returnargmax(SecretKey&, Scheme&, int)’:
../src/VolleyRevolverEncoding.cpp:944:15: warning: NULL used in arithmetic [-Wpointer-arith]
  944 |     if(num == NULL) num = this->rownum;
      |               ^~~~
In file included from ../src/VolleyRevolverEncoding.h:4:
/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src/Scheme.h: At global scope:
/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src/Scheme.h:28:13: warning: ‘CONJUGATION’ defined but not used [-Wunused-variable]
   28 | static long CONJUGATION = 2;
      |             ^~~~~~~~~~~
/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src/Scheme.h:27:13: warning: ‘MULTIPLICATION’ defined but not used [-Wunused-variable]
   27 | static long MULTIPLICATION  = 1;
      |             ^~~~~~~~~~~~~~
/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src/Scheme.h:26:13: warning: ‘ENCRYPTION’ defined but not used [-Wunused-variable]
   26 | static long ENCRYPTION = 0;
      |             ^~~~~~~~~~
In file included from ../src/VolleyRevolverEncoding.h:3:
../src/Tools.h:67:15: warning: ‘degree7_36’ defined but not used [-Wunused-variable]
   67 | static double degree7_36[5] = {+0.5, -0.11634, +0.0011850, -0.0000062074, +0.000000011389};
      |               ^~~~~~~~~~
../src/Tools.h:63:15: warning: ‘degree7_24’ defined but not used [-Wunused-variable]
   63 | static double degree7_24[5] = {+0.5, -0.15512, +0.0028088, -0.000026158,  +0.000000085324};
      |               ^~~~~~~~~~
../src/Tools.h:60:15: warning: ‘degree7_12’ defined but not used [-Wunused-variable]
   60 | static double degree7_12[5] = {+0.5, -2.3514e-01, +1.2329e-02, -3.9345e-04, +4.7292e-06};  // 1 - poly(-yWTx)
      |               ^~~~~~~~~~
../src/Tools.h:50:15: warning: ‘degree7’ defined but not used [-Wunused-variable]
   50 | static double degree7[5] = {+0.5, -0.10843500, +0.00102394287, -0.00000518229, +0.00000000934};  //|wTx| < 16
      |               ^~~~~~~
../src/Tools.h:44:15: warning: ‘degree5’ defined but not used [-Wunused-variable]
   44 | static double degree5[4] = {+0.5, -0.19131, +0.0045963,   -0.0000412332};
      |               ^~~~~~~
../src/Tools.h:42:15: warning: ‘degree3’ defined but not used [-Wunused-variable]
   42 | static double degree3[3] = {+0.5, -0.15012, +0.00159300781};  // 1 - poly(-yWTx)
      |               ^~~~~~~
Finished building: ../src/VolleyRevolverEncoding.cpp
 
Building file: ../src/Methods.cpp
Invoking: GCC C++ Compiler [CNNinference/Default/src/subdir.mk]
g++ -I/home/john/smith/HE.CNNinfer/CNNinference/lib/include -I/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Methods.d" -MT"src/Methods.o" -o "src/Methods.o" "../src/Methods.cpp"
In file included from ../src/Methods.h:3,
                 from ../src/Methods.cpp:2:
../src/VolleyRevolverEncoding.h:41:114: warning: converting to non-pointer type ‘int’ from NULL [-Wconversion-null]
   41 |     VolleyRevolverEncoding(Ciphertext &ciphertext, int slots_number, int width=28, int height=28, int datacolnum=NULL);
      |                                                                                                                  ^~~~
../src/VolleyRevolverEncoding.h:94:67: warning: converting to non-pointer type ‘int’ from NULL [-Wconversion-null]
   94 |     int printargmax(SecretKey &secretKey, Scheme &scheme, int num=NULL);
      |                                                                   ^~~~
../src/VolleyRevolverEncoding.h:95:70: warning: converting to non-pointer type ‘int’ from NULL [-Wconversion-null]
   95 |     long* returnargmax(SecretKey &secretKey, Scheme &scheme, int num=NULL);
      |                                                                      ^~~~
../src/Methods.cpp: In function ‘int CNNinference(double**, double*, long int, long int, double**, long int, long int*)’:
../src/Methods.cpp:95:63: warning: passing NULL to non-pointer argument 5 of ‘VolleyRevolverEncoding::VolleyRevolverEncoding(Ciphertext&, int, int, int, int)’ [-Wconversion-null]
   95 |   VolleyRevolverEncoding VRE(encFirstData, slots, 28, 28, NULL);                //
      |                                                               ^
../src/VolleyRevolverEncoding.h:41:103: note:   declared here
   41 |     VolleyRevolverEncoding(Ciphertext &ciphertext, int slots_number, int width=28, int height=28, int datacolnum=NULL);
      |                                                                                                       ^
../src/Methods.cpp:413:14: warning: unused variable ‘rlen’ [-Wunused-variable]
  413 |         long rlen = (1 << fdimBits);
      |              ^~~~
../src/Methods.cpp:439:67: warning: passing NULL to non-pointer argument 5 of ‘VolleyRevolverEncoding::VolleyRevolverEncoding(Ciphertext&, int, int, int, int)’ [-Wconversion-null]
  439 |     VolleyRevolverEncoding curVRE(encTestData, slots, 28, 28, NULL);
      |                                                                   ^
../src/VolleyRevolverEncoding.h:41:103: note:   declared here
   41 |     VolleyRevolverEncoding(Ciphertext &ciphertext, int slots_number, int width=28, int height=28, int datacolnum=NULL);
      |                                                                                                       ^
../src/Methods.cpp:512:41: warning: converting to non-pointer type ‘int’ from NULL [-Wconversion-null]
  512 |       auto res = vreoutput->returnargmax(secretKey, scheme);
      |                  ~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~
../src/Methods.cpp:41:8: warning: unused variable ‘pBits’ [-Wunused-variable]
   41 |   long pBits = 20;
      |        ^~~~~
../src/Methods.cpp:46:8: warning: unused variable ‘sBits’ [-Wunused-variable]
   46 |   long sBits = (long)ceil(log2(slots));
      |        ^~~~~
../src/Methods.cpp:49:8: warning: unused variable ‘bBits’ [-Wunused-variable]
   49 |   long bBits = (long)ceil(log2(batch));
      |        ^~~~~
../src/Methods.cpp:223:10: warning: unused variable ‘bias0’ [-Wunused-variable]
  223 |   double bias0 = CNNdate[1][0];
      |          ^~~~~
../src/Methods.cpp:227:10: warning: unused variable ‘bias1’ [-Wunused-variable]
  227 |   double bias1 = CNNdate[1][1];
      |          ^~~~~
../src/Methods.cpp:231:10: warning: unused variable ‘bias2’ [-Wunused-variable]
  231 |   double bias2 = CNNdate[1][2];
      |          ^~~~~
../src/Methods.cpp:235:10: warning: unused variable ‘bias3’ [-Wunused-variable]
  235 |   double bias3 = CNNdate[1][3];
      |          ^~~~~
../src/Methods.cpp:293:8: warning: unused variable ‘colnum’ [-Wunused-variable]
  293 |   long colnum = 676;
      |        ^~~~~~
../src/Methods.cpp: In function ‘int HE_SquareMatrixMult(long int)’:
../src/Methods.cpp:569:8: warning: unused variable ‘pBits’ [-Wunused-variable]
  569 |   long pBits = 20;
      |        ^~~~~
../src/Methods.cpp:576:8: warning: unused variable ‘sBits’ [-Wunused-variable]
  576 |   long sBits = (long)ceil(log2(slots));
      |        ^~~~~
In file included from ../src/Methods.h:2:
/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src/Scheme.h: At global scope:
/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src/Scheme.h:28:13: warning: ‘CONJUGATION’ defined but not used [-Wunused-variable]
   28 | static long CONJUGATION = 2;
      |             ^~~~~~~~~~~
/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src/Scheme.h:27:13: warning: ‘MULTIPLICATION’ defined but not used [-Wunused-variable]
   27 | static long MULTIPLICATION  = 1;
      |             ^~~~~~~~~~~~~~
/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src/Scheme.h:26:13: warning: ‘ENCRYPTION’ defined but not used [-Wunused-variable]
   26 | static long ENCRYPTION = 0;
      |             ^~~~~~~~~~
In file included from ../src/Methods.cpp:1:
../src/Tools.h:67:15: warning: ‘degree7_36’ defined but not used [-Wunused-variable]
   67 | static double degree7_36[5] = {+0.5, -0.11634, +0.0011850, -0.0000062074, +0.000000011389};
      |               ^~~~~~~~~~
../src/Tools.h:63:15: warning: ‘degree7_24’ defined but not used [-Wunused-variable]
   63 | static double degree7_24[5] = {+0.5, -0.15512, +0.0028088, -0.000026158,  +0.000000085324};
      |               ^~~~~~~~~~
../src/Tools.h:60:15: warning: ‘degree7_12’ defined but not used [-Wunused-variable]
   60 | static double degree7_12[5] = {+0.5, -2.3514e-01, +1.2329e-02, -3.9345e-04, +4.7292e-06};  // 1 - poly(-yWTx)
      |               ^~~~~~~~~~
../src/Tools.h:50:15: warning: ‘degree7’ defined but not used [-Wunused-variable]
   50 | static double degree7[5] = {+0.5, -0.10843500, +0.00102394287, -0.00000518229, +0.00000000934};  //|wTx| < 16
      |               ^~~~~~~
../src/Tools.h:44:15: warning: ‘degree5’ defined but not used [-Wunused-variable]
   44 | static double degree5[4] = {+0.5, -0.19131, +0.0045963,   -0.0000412332};
      |               ^~~~~~~
../src/Tools.h:42:15: warning: ‘degree3’ defined but not used [-Wunused-variable]
   42 | static double degree3[3] = {+0.5, -0.15012, +0.00159300781};  // 1 - poly(-yWTx)
      |               ^~~~~~~
Finished building: ../src/Methods.cpp
 
Building file: ../src/Tools.cpp
Invoking: GCC C++ Compiler [CNNinference/Default/src/subdir.mk]
g++ -I/home/john/smith/HE.CNNinfer/CNNinference/lib/include -I/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Tools.d" -MT"src/Tools.o" -o "src/Tools.o" "../src/Tools.cpp"
../src/Tools.cpp: In static member function ‘static double** Tools::zDataFromFile(std::string&, long int&, long int&, bool)’:
../src/Tools.cpp:46:52: warning: comparison of integer expressions of different signedness: ‘long int’ and ‘std::__cxx11::basic_string<char>::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   46 |                                 for (long i = 0; i < line.length(); ++i)
      |                                                  ~~^~~~~~~~~~~~~~~
../src/Tools.cpp: In static member function ‘static double** Tools::dataFromFile(std::string&, long int&, long int&, double**&, double*&)’:
../src/Tools.cpp:117:52: warning: comparison of integer expressions of different signedness: ‘long int’ and ‘std::__cxx11::basic_string<char>::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
  117 |                                 for (long i = 0; i < line.length(); ++i)
      |                                                  ~~^~~~~~~~~~~~~~~
../src/Tools.cpp: In static member function ‘static double** Tools::dataFromCNNweightsFile(std::string&, long int&, long int*&)’:
../src/Tools.cpp:181:44: warning: comparison of integer expressions of different signedness: ‘long int’ and ‘std::__cxx11::basic_string<char>::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
  181 |                         for (long i = 0; i < line.length(); ++i)
      |                                          ~~^~~~~~~~~~~~~~~
../src/Tools.cpp: In static member function ‘static double Tools::calculateAUC(double**, double*, long int, long int, double&, double&)’:
../src/Tools.cpp:319:27: warning: comparison of integer expressions of different signedness: ‘long int’ and ‘std::vector<double>::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
  319 |         for(long i = 0; i < thetaTN.size(); ++i){
      |                         ~~^~~~~~~~~~~~~~~~
../src/Tools.cpp:320:31: warning: comparison of integer expressions of different signedness: ‘long int’ and ‘std::vector<double>::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
  320 |             for(long j = 0; j < thetaFP.size(); ++j){
      |                             ~~^~~~~~~~~~~~~~~~
../src/Tools.cpp: In static member function ‘static double Tools::calculateACC(double**, double*, long int, long int, double&, double&)’:
../src/Tools.cpp:360:27: warning: comparison of integer expressions of different signedness: ‘long int’ and ‘std::vector<double>::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
  360 |         for(long i = 0; i < thetaTN.size(); ++i){
      |                         ~~^~~~~~~~~~~~~~~~
../src/Tools.cpp:361:31: warning: comparison of integer expressions of different signedness: ‘long int’ and ‘std::vector<double>::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
  361 |             for(long j = 0; j < thetaFP.size(); ++j){
      |                             ~~^~~~~~~~~~~~~~~~
In file included from ../src/Tools.cpp:1:
../src/Tools.h: At global scope:
../src/Tools.h:67:15: warning: ‘degree7_36’ defined but not used [-Wunused-variable]
   67 | static double degree7_36[5] = {+0.5, -0.11634, +0.0011850, -0.0000062074, +0.000000011389};
      |               ^~~~~~~~~~
../src/Tools.h:63:15: warning: ‘degree7_24’ defined but not used [-Wunused-variable]
   63 | static double degree7_24[5] = {+0.5, -0.15512, +0.0028088, -0.000026158,  +0.000000085324};
      |               ^~~~~~~~~~
../src/Tools.h:60:15: warning: ‘degree7_12’ defined but not used [-Wunused-variable]
   60 | static double degree7_12[5] = {+0.5, -2.3514e-01, +1.2329e-02, -3.9345e-04, +4.7292e-06};  // 1 - poly(-yWTx)
      |               ^~~~~~~~~~
../src/Tools.h:50:15: warning: ‘degree7’ defined but not used [-Wunused-variable]
   50 | static double degree7[5] = {+0.5, -0.10843500, +0.00102394287, -0.00000518229, +0.00000000934};  //|wTx| < 16
      |               ^~~~~~~
../src/Tools.h:44:15: warning: ‘degree5’ defined but not used [-Wunused-variable]
   44 | static double degree5[4] = {+0.5, -0.19131, +0.0045963,   -0.0000412332};
      |               ^~~~~~~
../src/Tools.h:42:15: warning: ‘degree3’ defined but not used [-Wunused-variable]
   42 | static double degree3[3] = {+0.5, -0.15012, +0.00159300781};  // 1 - poly(-yWTx)
      |               ^~~~~~~
Finished building: ../src/Tools.cpp
 
Building file: ../HEAAN/HEAAN/src/BootContext.cpp
Invoking: GCC C++ Compiler 4 Testing
g++ -I"/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src" -I"/home/john/smith/HE.CNNinfer/CNNinference/lib/include" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"HEAAN/HEAAN/src/BootContext.d" -MT"HEAAN/HEAAN/src/BootContext.o" -o "HEAAN/HEAAN/src/BootContext.o" "../HEAAN/HEAAN/src/BootContext.cpp"
Finished building: ../HEAAN/HEAAN/src/BootContext.cpp
 
Building file: ../HEAAN/HEAAN/src/Ciphertext.cpp
Invoking: GCC C++ Compiler 4 Testing
g++ -I"/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src" -I"/home/john/smith/HE.CNNinfer/CNNinference/lib/include" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"HEAAN/HEAAN/src/Ciphertext.d" -MT"HEAAN/HEAAN/src/Ciphertext.o" -o "HEAAN/HEAAN/src/Ciphertext.o" "../HEAAN/HEAAN/src/Ciphertext.cpp"
Finished building: ../HEAAN/HEAAN/src/Ciphertext.cpp
 
Building file: ../HEAAN/HEAAN/src/EvaluatorUtils.cpp
Invoking: GCC C++ Compiler 4 Testing
g++ -I"/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src" -I"/home/john/smith/HE.CNNinfer/CNNinference/lib/include" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"HEAAN/HEAAN/src/EvaluatorUtils.d" -MT"HEAAN/HEAAN/src/EvaluatorUtils.o" -o "HEAAN/HEAAN/src/EvaluatorUtils.o" "../HEAAN/HEAAN/src/EvaluatorUtils.cpp"
Finished building: ../HEAAN/HEAAN/src/EvaluatorUtils.cpp
 
Building file: ../HEAAN/HEAAN/src/HEAAN.cpp
Invoking: GCC C++ Compiler 4 Testing
g++ -I"/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src" -I"/home/john/smith/HE.CNNinfer/CNNinference/lib/include" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"HEAAN/HEAAN/src/HEAAN.d" -MT"HEAAN/HEAAN/src/HEAAN.o" -o "HEAAN/HEAAN/src/HEAAN.o" "../HEAAN/HEAAN/src/HEAAN.cpp"
Finished building: ../HEAAN/HEAAN/src/HEAAN.cpp
 
Building file: ../HEAAN/HEAAN/src/Key.cpp
Invoking: GCC C++ Compiler 4 Testing
g++ -I"/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src" -I"/home/john/smith/HE.CNNinfer/CNNinference/lib/include" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"HEAAN/HEAAN/src/Key.d" -MT"HEAAN/HEAAN/src/Key.o" -o "HEAAN/HEAAN/src/Key.o" "../HEAAN/HEAAN/src/Key.cpp"
Finished building: ../HEAAN/HEAAN/src/Key.cpp
 
Building file: ../HEAAN/HEAAN/src/Plaintext.cpp
Invoking: GCC C++ Compiler 4 Testing
g++ -I"/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src" -I"/home/john/smith/HE.CNNinfer/CNNinference/lib/include" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"HEAAN/HEAAN/src/Plaintext.d" -MT"HEAAN/HEAAN/src/Plaintext.o" -o "HEAAN/HEAAN/src/Plaintext.o" "../HEAAN/HEAAN/src/Plaintext.cpp"
Finished building: ../HEAAN/HEAAN/src/Plaintext.cpp
 
Building file: ../HEAAN/HEAAN/src/Ring.cpp
Invoking: GCC C++ Compiler 4 Testing
g++ -I"/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src" -I"/home/john/smith/HE.CNNinfer/CNNinference/lib/include" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"HEAAN/HEAAN/src/Ring.d" -MT"HEAAN/HEAAN/src/Ring.o" -o "HEAAN/HEAAN/src/Ring.o" "../HEAAN/HEAAN/src/Ring.cpp"
../HEAAN/HEAAN/src/Ring.cpp: In member function ‘void Ring::addBootContext(long int, long int)’:
../HEAAN/HEAAN/src/Ring.cpp:305:152: warning: ‘rp1’ may be used uninitialized [-Wmaybe-uninitialized]
  305 |       bootContextMap.insert(pair<long, BootContext*>(logSlots, new BootContext(rpvec, rpvecInv, rp1, rp2, bndvec, bndvecInv, bnd1, bnd2, logp)));
      |                                                                                                                                              ^

../HEAAN/HEAAN/src/Ring.cpp:167:27: note: ‘rp1’ was declared here
  167 |                 uint64_t* rp1;
      |                           ^~~
../HEAAN/HEAAN/src/Ring.cpp:305:152: warning: ‘rp2’ may be used uninitialized [-Wmaybe-uninitialized]
  305 |       bootContextMap.insert(pair<long, BootContext*>(logSlots, new BootContext(rpvec, rpvecInv, rp1, rp2, bndvec, bndvecInv, bnd1, bnd2, logp)));
      |                                                                                                                                              ^

../HEAAN/HEAAN/src/Ring.cpp:168:27: note: ‘rp2’ was declared here
  168 |                 uint64_t* rp2;
      |                           ^~~
../HEAAN/HEAAN/src/Ring.cpp:305:152: warning: ‘bnd1’ may be used uninitialized [-Wmaybe-uninitialized]
  305 |       bootContextMap.insert(pair<long, BootContext*>(logSlots, new BootContext(rpvec, rpvecInv, rp1, rp2, bndvec, bndvecInv, bnd1, bnd2, logp)));
      |                                                                                                                                              ^

../HEAAN/HEAAN/src/Ring.cpp:172:22: note: ‘bnd1’ was declared here
  172 |                 long bnd1;
      |                      ^~~~
../HEAAN/HEAAN/src/Ring.cpp:305:152: warning: ‘bnd2’ may be used uninitialized [-Wmaybe-uninitialized]
  305 |       bootContextMap.insert(pair<long, BootContext*>(logSlots, new BootContext(rpvec, rpvecInv, rp1, rp2, bndvec, bndvecInv, bnd1, bnd2, logp)));
      |                                                                                                                                              ^

../HEAAN/HEAAN/src/Ring.cpp:173:22: note: ‘bnd2’ was declared here
  173 |                 long bnd2;
      |                      ^~~~
Finished building: ../HEAAN/HEAAN/src/Ring.cpp
 
Building file: ../HEAAN/HEAAN/src/RingMultiplier.cpp
Invoking: GCC C++ Compiler 4 Testing
g++ -I"/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src" -I"/home/john/smith/HE.CNNinfer/CNNinference/lib/include" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"HEAAN/HEAAN/src/RingMultiplier.d" -MT"HEAAN/HEAAN/src/RingMultiplier.o" -o "HEAAN/HEAAN/src/RingMultiplier.o" "../HEAAN/HEAAN/src/RingMultiplier.cpp"
../HEAAN/HEAAN/src/RingMultiplier.cpp: In member function ‘void RingMultiplier::multAndEqual(NTL::ZZ*, NTL::ZZ*, long int, const NTL::ZZ&)’:
../HEAAN/HEAAN/src/RingMultiplier.cpp:304:13: warning: unused variable ‘pHatnp’ [-Wunused-variable]
  304 |         ZZ* pHatnp = pHat[np - 1];
      |             ^~~~~~
../HEAAN/HEAAN/src/RingMultiplier.cpp:305:19: warning: unused variable ‘pHatInvModpnp’ [-Wunused-variable]
  305 |         uint64_t* pHatInvModpnp = pHatInvModp[np - 1];
      |                   ^~~~~~~~~~~~~
../HEAAN/HEAAN/src/RingMultiplier.cpp: In member function ‘void RingMultiplier::multNTTAndEqual(NTL::ZZ*, uint64_t*, long int, const NTL::ZZ&)’:
../HEAAN/HEAAN/src/RingMultiplier.cpp:334:13: warning: unused variable ‘pHatnp’ [-Wunused-variable]
  334 |         ZZ* pHatnp = pHat[np - 1];
      |             ^~~~~~
../HEAAN/HEAAN/src/RingMultiplier.cpp:335:19: warning: unused variable ‘pHatInvModpnp’ [-Wunused-variable]
  335 |         uint64_t* pHatInvModpnp = pHatInvModp[np - 1];
      |                   ^~~~~~~~~~~~~
../HEAAN/HEAAN/src/RingMultiplier.cpp: In member function ‘void RingMultiplier::square(NTL::ZZ*, NTL::ZZ*, long int, const NTL::ZZ&)’:
../HEAAN/HEAAN/src/RingMultiplier.cpp:365:13: warning: unused variable ‘pHatnp’ [-Wunused-variable]
  365 |         ZZ* pHatnp = pHat[np - 1];
      |             ^~~~~~
../HEAAN/HEAAN/src/RingMultiplier.cpp:366:19: warning: unused variable ‘pHatInvModpnp’ [-Wunused-variable]
  366 |         uint64_t* pHatInvModpnp = pHatInvModp[np - 1];
      |                   ^~~~~~~~~~~~~
Finished building: ../HEAAN/HEAAN/src/RingMultiplier.cpp
 
Building file: ../HEAAN/HEAAN/src/Scheme.cpp
Invoking: GCC C++ Compiler 4 Testing
g++ -I"/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src" -I"/home/john/smith/HE.CNNinfer/CNNinference/lib/include" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"HEAAN/HEAAN/src/Scheme.d" -MT"HEAAN/HEAAN/src/Scheme.o" -o "HEAAN/HEAAN/src/Scheme.o" "../HEAAN/HEAAN/src/Scheme.cpp"
Finished building: ../HEAAN/HEAAN/src/Scheme.cpp
 
Building file: ../HEAAN/HEAAN/src/SchemeAlgo.cpp
Invoking: GCC C++ Compiler 4 Testing
g++ -I"/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src" -I"/home/john/smith/HE.CNNinfer/CNNinference/lib/include" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"HEAAN/HEAAN/src/SchemeAlgo.d" -MT"HEAAN/HEAAN/src/SchemeAlgo.o" -o "HEAAN/HEAAN/src/SchemeAlgo.o" "../HEAAN/HEAAN/src/SchemeAlgo.cpp"
In file included from ../HEAAN/HEAAN/src/SchemeAlgo.h:18,
                 from ../HEAAN/HEAAN/src/SchemeAlgo.cpp:8:
../HEAAN/HEAAN/src/Scheme.h:28:13: warning: ‘CONJUGATION’ defined but not used [-Wunused-variable]
   28 | static long CONJUGATION = 2;
      |             ^~~~~~~~~~~
../HEAAN/HEAAN/src/Scheme.h:27:13: warning: ‘MULTIPLICATION’ defined but not used [-Wunused-variable]
   27 | static long MULTIPLICATION  = 1;
      |             ^~~~~~~~~~~~~~
../HEAAN/HEAAN/src/Scheme.h:26:13: warning: ‘ENCRYPTION’ defined but not used [-Wunused-variable]
   26 | static long ENCRYPTION = 0;
      |             ^~~~~~~~~~
Finished building: ../HEAAN/HEAAN/src/SchemeAlgo.cpp
 
Building file: ../HEAAN/HEAAN/src/SecretKey.cpp
Invoking: GCC C++ Compiler 4 Testing
g++ -I"/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src" -I"/home/john/smith/HE.CNNinfer/CNNinference/lib/include" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"HEAAN/HEAAN/src/SecretKey.d" -MT"HEAAN/HEAAN/src/SecretKey.o" -o "HEAAN/HEAAN/src/SecretKey.o" "../HEAAN/HEAAN/src/SecretKey.cpp"
Finished building: ../HEAAN/HEAAN/src/SecretKey.cpp
 
Building file: ../HEAAN/HEAAN/src/SerializationUtils.cpp
Invoking: GCC C++ Compiler 4 Testing
g++ -I"/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src" -I"/home/john/smith/HE.CNNinfer/CNNinference/lib/include" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"HEAAN/HEAAN/src/SerializationUtils.d" -MT"HEAAN/HEAAN/src/SerializationUtils.o" -o "HEAAN/HEAAN/src/SerializationUtils.o" "../HEAAN/HEAAN/src/SerializationUtils.cpp"
../HEAAN/HEAAN/src/SerializationUtils.cpp: In static member function ‘static Ciphertext* SerializationUtils::readCiphertext(std::string)’:
../HEAAN/HEAAN/src/SerializationUtils.cpp:56:16: warning: address of local variable ‘cipher’ returned [-Wreturn-local-addr]
   56 |         return &cipher;
      |                ^~~~~~~
../HEAAN/HEAAN/src/SerializationUtils.cpp:46:20: note: declared here
   46 |         Ciphertext cipher(logp, logq, n);
      |                    ^~~~~~
../HEAAN/HEAAN/src/SerializationUtils.cpp: In static member function ‘static Key* SerializationUtils::readKey(std::string)’:
../HEAAN/HEAAN/src/SerializationUtils.cpp:74:16: warning: address of local variable ‘key’ returned [-Wreturn-local-addr]
   74 |         return &key;
      |                ^~~~
../HEAAN/HEAAN/src/SerializationUtils.cpp:68:13: note: declared here
   68 |         Key key;
      |             ^~~
Finished building: ../HEAAN/HEAAN/src/SerializationUtils.cpp
 
Building file: ../HEAAN/HEAAN/src/StringUtils.cpp
Invoking: GCC C++ Compiler 4 Testing
g++ -I"/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src" -I"/home/john/smith/HE.CNNinfer/CNNinference/lib/include" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"HEAAN/HEAAN/src/StringUtils.d" -MT"HEAAN/HEAAN/src/StringUtils.o" -o "HEAAN/HEAAN/src/StringUtils.o" "../HEAAN/HEAAN/src/StringUtils.cpp"
Finished building: ../HEAAN/HEAAN/src/StringUtils.cpp
 
Building file: ../HEAAN/HEAAN/src/TestScheme.cpp
Invoking: GCC C++ Compiler 4 Testing
g++ -I"/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src" -I"/home/john/smith/HE.CNNinfer/CNNinference/lib/include" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"HEAAN/HEAAN/src/TestScheme.d" -MT"HEAAN/HEAAN/src/TestScheme.o" -o "HEAAN/HEAAN/src/TestScheme.o" "../HEAAN/HEAAN/src/TestScheme.cpp"
In file included from ../HEAAN/HEAAN/src/TestScheme.cpp:16:
../HEAAN/HEAAN/src/Scheme.h:28:13: warning: ‘CONJUGATION’ defined but not used [-Wunused-variable]
   28 | static long CONJUGATION = 2;
      |             ^~~~~~~~~~~
../HEAAN/HEAAN/src/Scheme.h:27:13: warning: ‘MULTIPLICATION’ defined but not used [-Wunused-variable]
   27 | static long MULTIPLICATION  = 1;
      |             ^~~~~~~~~~~~~~
../HEAAN/HEAAN/src/Scheme.h:26:13: warning: ‘ENCRYPTION’ defined but not used [-Wunused-variable]
   26 | static long ENCRYPTION = 0;
      |             ^~~~~~~~~~
Finished building: ../HEAAN/HEAAN/src/TestScheme.cpp
 
Building file: ../HEAAN/HEAAN/src/TimeUtils.cpp
Invoking: GCC C++ Compiler 4 Testing
g++ -I"/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/src" -I"/home/john/smith/HE.CNNinfer/CNNinference/lib/include" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"HEAAN/HEAAN/src/TimeUtils.d" -MT"HEAAN/HEAAN/src/TimeUtils.o" -o "HEAAN/HEAAN/src/TimeUtils.o" "../HEAAN/HEAAN/src/TimeUtils.cpp"
Finished building: ../HEAAN/HEAAN/src/TimeUtils.cpp
 
Building target: CNNinference
Invoking: GCC C++ Linker4Testing
g++ -L/home/john/smith/HE.CNNinfer/CNNinference/lib/lib -L/home/john/smith/HE.CNNinfer/CNNinference/HEAAN/HEAAN/lib -pthread -o CNNinference ./src/CNNinference.o ./src/VolleyRevolverEncoding.o ./src/Methods.o ./src/Tools.o  ./HEAAN/HEAAN/src/BootContext.o ./HEAAN/HEAAN/src/Ciphertext.o ./HEAAN/HEAAN/src/EvaluatorUtils.o ./HEAAN/HEAAN/src/HEAAN.o ./HEAAN/HEAAN/src/Key.o ./HEAAN/HEAAN/src/Plaintext.o ./HEAAN/HEAAN/src/Ring.o ./HEAAN/HEAAN/src/RingMultiplier.o ./HEAAN/HEAAN/src/Scheme.o ./HEAAN/HEAAN/src/SchemeAlgo.o ./HEAAN/HEAAN/src/SecretKey.o ./HEAAN/HEAAN/src/SerializationUtils.o ./HEAAN/HEAAN/src/StringUtils.o ./HEAAN/HEAAN/src/TestScheme.o ./HEAAN/HEAAN/src/TimeUtils.o   -lntl -lgmp -lHEAAN -lm
Finished building target: CNNinference
 
root@vultr:/home/john/smith/HE.CNNinfer/CNNinference/Default# ./CNNinference 

7
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                 84  185  159  151   60   36                                                                                
                                222  254  254  254  254  241  198  198  198  198  198  198  198  198  170   52                              
                                 67  114   72  114  163  227  254  225  254  254  254  250  229  254  254  140                              
                                                          17   66   14   67   67   67   59   21  236  254  106                              
                                                                                             83  253  209   18                              
                                                                                        22  233  255   83                                   
                                                                                       129  254  238   44                                   
                                                                                   59  249  254   62                                        
                                                                                  133  254  187    5                                        
                                                                               9  205  248   58                                             
                                                                             126  254  182                                                  
                                                                         75  251  240   57                                                  
                                                                    19  221  254  166                                                       
                                                                3  203  254  219   35                                                       
                                                               38  254  254   77                                                            
                                                          31  224  254  115    1                                                            
                                                         133  254  254   52                                                                 
                                                     61  242  254  254   52                                                                 
                                                    121  254  254  219   40                                                                 
                                                    121  254  207   18                                                                      
                                                                                                                                            

2
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                    116  125  171  255  255  150   93                                                       
                                               169  253  253  253  253  253  253  218   30                                                  
                                          169  253  253  253  213  142  176  253  253  122                                                  
                                      52  250  253  210   32   12         6  206  253  140                                                  
                                      77  251  210   25                 122  248  253   65                                                  
                                           31   18                      209  253  253   65                                                  
                                                                   117  247  253  198   10                                                  
                                                               76  247  253  231   63                                                       
                                                              128  253  253  144                                                            
                                                         176  246  253  159   12                                                            
                                                     25  234  253  233   35                                                                 
                                                    198  253  253  141                                                                      
                                                78  248  253  189   12                                                                      
                                           19  200  253  253  141                                                                           
                                          134  253  253  173   12                                                                           
                                          248  253  253   25                                                                                
                                          248  253  253   43   20   20   20   20    5         5   20   20   37  150  150  150  147   10     
                                          248  253  253  253  253  253  253  253  168  143  166  253  253  253  253  253  253  253  123     
                                          174  253  253  253  253  253  253  253  253  253  253  253  249  247  247  169  117  117   57     
                                               118  123  123  123  166  253  253  253  155  123  123   41                                   
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            

1
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                   38  254  109                                             
                                                                                   87  252   82                                             
                                                                                  135  241                                                  
                                                                              45  244  150                                                  
                                                                              84  254   63                                                  
                                                                             202  223   11                                                  
                                                                         32  254  216                                                       
                                                                         95  254  195                                                       
                                                                        140  254   77                                                       
                                                                    57  237  205    8                                                       
                                                                   124  255  165                                                            
                                                                   171  254   81                                                            
                                                               24  232  215                                                                 
                                                              120  254  159                                                                 
                                                              151  254  142                                                                 
                                                              228  254   66                                                                 
                                                          61  251  254   66                                                                 
                                                         141  254  205    3                                                                 
                                                     10  215  254  121                                                                      
                                                      5  198  176   10                                                                      
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            

0
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                               11  150  253  202   31                                                       
                                                               37  251  251  253  107                                                       
                                                          21  197  251  251  253  107                                                       
                                                    110  190  251  251  251  253  169  109   62                                             
                                                    253  251  251  251  251  253  251  251  220   51                                        
                                               182  255  253  253  253  253  234  222  253  253  253                                        
                                           63  221  253  251  251  251  147   77   62  128  251  251  105                                   
                                      32  231  251  253  251  220  137   10             31  230  251  243  113    5                         
                                      37  251  251  253  188   20                           109  251  253  251   35                         
                                      37  251  251  201   30                                 31  200  253  251   35                         
                                      37  253  253                                           32  202  255  253  164                         
                                     140  251  251                                          109  251  253  251   35                         
                                     217  251  251                                 21   63  231  251  253  230   30                         
                                     217  251  251                                144  251  251  251  221   61                              
                                     217  251  251                           182  221  251  251  251  180                                   
                                     218  253  253   73   73  228  253  253  255  253  253  253  253                                        
                                     113  251  251  253  251  251  251  251  253  251  251  251  147                                        
                                      31  230  251  253  251  251  251  251  253  230  189   35   10                                        
                                           62  142  253  251  251  251  251  253  107                                                       
                                                     72  174  251  173   71   72   30                                                       
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            

4
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                     50  224                                      70   29                                   
                                                    121  231                                     148  168                                   
                                                 4  195  231                                      96  210   11                              
                                                69  252  134                                     114  252   21                              
                                           45  236  217   12                                     192  252   21                              
                                          168  247   53                                      18  255  253   21                              
                                      84  242  211                                          141  253  189    5                              
                                     169  252  106                                      32  232  250   66                                   
                                 15  225  252                                          134  252  211                                        
                                 22  252  164                                          169  252  167                                        
                                  9  204  209   18                                 22  253  253  107                                        
                                     169  252  199   85   85   85   85  129  164  195  252  252  106                                        
                                      41  170  245  252  252  252  252  232  231  251  252  252    9                                        
                                                49   84   84   84   84            161  252  252                                             
                                                                                  127  252  252   45                                        
                                                                                  128  253  253                                             
                                                                                  127  252  252                                             
                                                                                  135  252  244                                             
                                                                                  232  236  111                                             
                                                                                  179   66                                                  
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            

7
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                               0.33 0.73 0.62 0.59 0.24 0.14                                                                                
                               0.87 1.00 1.00 1.00 1.00 0.95 0.78 0.78 0.78 0.78 0.78 0.78 0.78 0.78 0.67 0.20                              
                               0.26 0.45 0.28 0.45 0.64 0.89 1.00 0.88 1.00 1.00 1.00 0.98 0.90 1.00 1.00 0.55                              
                                                        0.07 0.26 0.05 0.26 0.26 0.26 0.23 0.08 0.93 1.00 0.42                              
                                                                                           0.33 0.99 0.82 0.07                              
                                                                                      0.09 0.91 1.00 0.33                                   
                                                                                      0.51 1.00 0.93 0.17                                   
                                                                                 0.23 0.98 1.00 0.24                                        
                                                                                 0.52 1.00 0.73 0.02                                        
                                                                            0.04 0.80 0.97 0.23                                             
                                                                            0.49 1.00 0.71                                                  
                                                                       0.29 0.98 0.94 0.22                                                  
                                                                  0.07 0.87 1.00 0.65                                                       
                                                             0.01 0.80 1.00 0.86 0.14                                                       
                                                             0.15 1.00 1.00 0.30                                                            
                                                        0.12 0.88 1.00 0.45                                                                 
                                                        0.52 1.00 1.00 0.20                                                                 
                                                   0.24 0.95 1.00 1.00 0.20                                                                 
                                                   0.47 1.00 1.00 0.86 0.16                                                                 
                                                   0.47 1.00 0.81 0.07                                                                      
                                                                                                                                            

2
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                   0.45 0.49 0.67 1.00 1.00 0.59 0.36                                                       
                                              0.66 0.99 0.99 0.99 0.99 0.99 0.99 0.85 0.12                                                  
                                         0.66 0.99 0.99 0.99 0.84 0.56 0.69 0.99 0.99 0.48                                                  
                                    0.20 0.98 0.99 0.82 0.13 0.05      0.02 0.81 0.99 0.55                                                  
                                    0.30 0.98 0.82 0.10                0.48 0.97 0.99 0.25                                                  
                                         0.12 0.07                     0.82 0.99 0.99 0.25                                                  
                                                                  0.46 0.97 0.99 0.78 0.04                                                  
                                                             0.30 0.97 0.99 0.91 0.25                                                       
                                                             0.50 0.99 0.99 0.56                                                            
                                                        0.69 0.96 0.99 0.62 0.05                                                            
                                                   0.10 0.92 0.99 0.91 0.14                                                                 
                                                   0.78 0.99 0.99 0.55                                                                      
                                              0.31 0.97 0.99 0.74 0.05                                                                      
                                         0.07 0.78 0.99 0.99 0.55                                                                           
                                         0.53 0.99 0.99 0.68 0.05                                                                           
                                         0.97 0.99 0.99 0.10                                                                                
                                         0.97 0.99 0.99 0.17 0.08 0.08 0.08 0.08 0.02      0.02 0.08 0.08 0.15 0.59 0.59 0.59 0.58 0.04     
                                         0.97 0.99 0.99 0.99 0.99 0.99 0.99 0.99 0.66 0.56 0.65 0.99 0.99 0.99 0.99 0.99 0.99 0.99 0.48     
                                         0.68 0.99 0.99 0.99 0.99 0.99 0.99 0.99 0.99 0.99 0.99 0.99 0.98 0.97 0.97 0.66 0.46 0.46 0.22     
                                              0.46 0.48 0.48 0.48 0.65 0.99 0.99 0.99 0.61 0.48 0.48 0.16                                   
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            

1
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                 0.15 1.00 0.43                                             
                                                                                 0.34 0.99 0.32                                             
                                                                                 0.53 0.95                                                  
                                                                            0.18 0.96 0.59                                                  
                                                                            0.33 1.00 0.25                                                  
                                                                            0.79 0.87 0.04                                                  
                                                                       0.13 1.00 0.85                                                       
                                                                       0.37 1.00 0.76                                                       
                                                                       0.55 1.00 0.30                                                       
                                                                  0.22 0.93 0.80 0.03                                                       
                                                                  0.49 1.00 0.65                                                            
                                                                  0.67 1.00 0.32                                                            
                                                             0.09 0.91 0.84                                                                 
                                                             0.47 1.00 0.62                                                                 
                                                             0.59 1.00 0.56                                                                 
                                                             0.89 1.00 0.26                                                                 
                                                        0.24 0.98 1.00 0.26                                                                 
                                                        0.55 1.00 0.80 0.01                                                                 
                                                   0.04 0.84 1.00 0.47                                                                      
                                                   0.02 0.78 0.69 0.04                                                                      
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            

0
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                             0.04 0.59 0.99 0.79 0.12                                                       
                                                             0.15 0.98 0.98 0.99 0.42                                                       
                                                        0.08 0.77 0.98 0.98 0.99 0.42                                                       
                                                   0.43 0.75 0.98 0.98 0.98 0.99 0.66 0.43 0.24                                             
                                                   0.99 0.98 0.98 0.98 0.98 0.99 0.98 0.98 0.86 0.20                                        
                                              0.71 1.00 0.99 0.99 0.99 0.99 0.92 0.87 0.99 0.99 0.99                                        
                                         0.25 0.87 0.99 0.98 0.98 0.98 0.58 0.30 0.24 0.50 0.98 0.98 0.41                                   
                                    0.13 0.91 0.98 0.99 0.98 0.86 0.54 0.04           0.12 0.90 0.98 0.95 0.44 0.02                         
                                    0.15 0.98 0.98 0.99 0.74 0.08                          0.43 0.98 0.99 0.98 0.14                         
                                    0.15 0.98 0.98 0.79 0.12                               0.12 0.78 0.99 0.98 0.14                         
                                    0.15 0.99 0.99                                         0.13 0.79 1.00 0.99 0.64                         
                                    0.55 0.98 0.98                                         0.43 0.98 0.99 0.98 0.14                         
                                    0.85 0.98 0.98                               0.08 0.25 0.91 0.98 0.99 0.90 0.12                         
                                    0.85 0.98 0.98                               0.56 0.98 0.98 0.98 0.87 0.24                              
                                    0.85 0.98 0.98                          0.71 0.87 0.98 0.98 0.98 0.71                                   
                                    0.85 0.99 0.99 0.29 0.29 0.89 0.99 0.99 1.00 0.99 0.99 0.99 0.99                                        
                                    0.44 0.98 0.98 0.99 0.98 0.98 0.98 0.98 0.99 0.98 0.98 0.98 0.58                                        
                                    0.12 0.90 0.98 0.99 0.98 0.98 0.98 0.98 0.99 0.90 0.74 0.14 0.04                                        
                                         0.24 0.56 0.99 0.98 0.98 0.98 0.98 0.99 0.42                                                       
                                                   0.28 0.68 0.98 0.68 0.28 0.28 0.12                                                       
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            

4
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                   0.20 0.88                                    0.27 0.11                                   
                                                   0.47 0.91                                    0.58 0.66                                   
                                              0.02 0.76 0.91                                    0.38 0.82 0.04                              
                                              0.27 0.99 0.53                                    0.45 0.99 0.08                              
                                         0.18 0.93 0.85 0.05                                    0.75 0.99 0.08                              
                                         0.66 0.97 0.21                                    0.07 1.00 0.99 0.08                              
                                    0.33 0.95 0.83                                         0.55 0.99 0.74 0.02                              
                                    0.66 0.99 0.42                                    0.13 0.91 0.98 0.26                                   
                               0.06 0.88 0.99                                         0.53 0.99 0.83                                        
                               0.09 0.99 0.64                                         0.66 0.99 0.65                                        
                               0.04 0.80 0.82 0.07                               0.09 0.99 0.99 0.42                                        
                                    0.66 0.99 0.78 0.33 0.33 0.33 0.33 0.51 0.64 0.76 0.99 0.99 0.42                                        
                                    0.16 0.67 0.96 0.99 0.99 0.99 0.99 0.91 0.91 0.98 0.99 0.99 0.04                                        
                                              0.19 0.33 0.33 0.33 0.33           0.63 0.99 0.99                                             
                                                                                 0.50 0.99 0.99 0.18                                        
                                                                                 0.50 0.99 0.99                                             
                                                                                 0.50 0.99 0.99                                             
                                                                                 0.53 0.99 0.96                                             
                                                                                 0.91 0.93 0.44                                             
                                                                                 0.70 0.26                                                  
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            

14
36  0.00891031  0.00547238  0.0556582  -0.0624588  -0.0290292  0.00207458  0.0410367  -0.0735912  -0.041323  -0.00285371  0.0431689  0.0124397  
4  0.00972362  -0.0112392  -0.00325043  0.000300504  
1  -0.000151207  
1  0.461015  
1  2.02251  
1  -1.4512  
173056  0.167695  -0.081655  -0.00333838  0.140233  0.137073  0.0744552  -0.119433  0.0804925  0.112451  0.0341361  -0.0625043  0.0526174  
64  0.182612  -0.0131861  -0.135619  0.265851  0.25788  0.126585  0.198147  0.108104  0.392075  0.292347  0.0693141  0.403202  
1  -1.56505  
1  -0.994377  
1  1.67945  
1  0.535026  
640  -0.392846  0.153355  0.334662  -0.295713  -0.236986  -0.0082478  -0.581584  -0.809267  0.158561  0.311421  0.306745  -0.491186  
10  -0.248632  -0.480076  0.130825  0.288885  -0.547682  -0.130282  -0.836737  0.125101  0.766865  -0.08444  

trainSampleDim : 0
testSampleDim  : 10000
trainfactorDim : 0
testfactorDim  : 784


-------------------------------------------------------------------------------------
CNNinference(testdataset, testdatalabel, testfactorDim, testSampleDim, CNNdate, cnnWeightsLen, cnnWeightsDims);
-------------------------------------------------------------------------------------


factorDim = 784
sampleDim = 10000
batch = 32, slots = 32768, rnum = 313
logQ = 1200, logN = 16, sdimBits = 14, fdimBits = 10
------------------
Start Scheme generating...
Killed
root@vultr:/home/john/smith/HE.CNNinfer/CNNinference/Default# 

```

# There is NO ';' after NTL_EXEC_RANGE... 
        such as at line 697 from HE.CNNinfer/CNNinference/src/Methods.cpp 
        

# CNNinference

CNNinference is a project for implementing our CNN inference on  encrypted MNIST images (Volley Revolver: A Novel Matrix-Encoding Method for Privacy-Preserving Neural Networks (Inference) )

## How to run this program? 

### Dependencies

On a Ubuntu cloud, our implementation requires the following libraries in order:
* `g++`:      
```sh
               # apt install g++ 
```

* `make`:       
```sh
                # apt install make
```

* `m4`: #        
```sh
                 # apt install m4
```

* `GMP`(ver. 6.1.2):      
```sh
                           # cd gmp-x.x.x  
                           # ./configure --enable-cxx  
                           # make
                           # make install
                           # ldconfig
```

* `NTL`(ver. 11.3.0): 
```sh
                     # cd ntl-x.x.x
                     # cd src
                     # ./configure NTL_THREADS=on NTL_THREAD_BOOST=on NTL_EXCEPTIONS=on
                     # make
                     # make install
```

### Running CNNinference 

You need to configure and build the CNNinference project. If on a Ubuntu 22.04 x64 you placed the project in the path:
```sh
/home/YourName/eclipse-workspace/CNNinference/$ls
data  Debug  Default  HEAAN  lib  result  run  src
```
It might be much easy to configure and build the project.  

After that, in the 'Default' folder, you can run our project by the following command lines:

```sh
# make clean
# make all
# ./CNNinference
``` 

You can change the source codes and then repeat the above lines to debug your own project.

## Running a test source code

In the 'Default' folder, you can find two running results:   

        'CNNinferArchiveFile20220407.7z_SetNumThreads(42)_nohup.out'  
        
        'CNNinferArchiveFile20220409.7z_SetNumThreads(42)_nohup.out'
        
        
Also, you can find the CSV file storing the weights of our well-trained CNN inference model at:

         HE.CNNinfer/CNNinference/data/CNNweightsMNIST.csv
         


            
            
    


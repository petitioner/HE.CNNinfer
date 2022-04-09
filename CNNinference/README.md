# CNNinference

CNNinference is a project for implementing our CNN inference on  encrypted MNIST images (A Novel Matrix-Encoding Method for Privacy-Preserving Neural Networks (Inference) (https://arxiv.org/abs/2201.12577))

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
/home/john/eclipse-workspace/CNNinference/$ls
data  Debug  Default  HEAAN  lib  result  run  src
```
It might be much easy to configure and build the project.  

In the 'Default' folder, you can run our programming by the following command lines:

```sh
# make clean
# make all
# ./CNNinference
``` 

You can change the source codes and then repeat above lines to debug your own programming.

## Running a test source code

In the 'Default' folder, you can find two running results: 
'CNNinferArchiveFile20220407.7z_SetNumThreads(42)_nohup.out'
'CNNinferArchiveFile20220409.7z_SetNumThreads(42)_nohup.out'


Welcome to run this project, enjoy it!

by 西星 者, 宫本新野, John C. Smith
at 2022-04-09 13:12 GMT+08

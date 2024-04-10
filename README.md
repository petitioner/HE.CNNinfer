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
         


            
            
    


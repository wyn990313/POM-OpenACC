#!/usr/bin/bash
echo '      parameter(im=65, jm=49, kb=21)' >  grid
echo '      iproblem=  1                  ' >  params
echo '      days=      0.025              ' >> params
echo '      prtd1=     0.025            ' >> params
echo '      dte=       6.                 ' >> params


module load netCDF-All/NVHPC-23.1 

pgfortran -o b.out pom-openacc.f -cuda -acc=gpu -mcmodel=medium -I/public/software/.local/easybuild/software/netCDF-All/NVHPC-23.1/include -L/public/software/.local/easybuild/software/netCDF-All/NVHPC-23.1/lib -lnetcdff

./b.out > f.log
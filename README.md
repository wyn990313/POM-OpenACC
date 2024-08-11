# This program is the source code of parallel POM based on OpenACC 
#Here are the instructions for use	


#Before compiling, You need to load the NVHPC so that you can use the pgi compiler
# For example,
			module load netCDF-All/NVHPC-23.1 
# -- SEAMOUNT TEST CASE (initial cond. calc. in pom-openacc.f)
		
		 echo '      parameter(im=650, jm=490, kb=21)' >  grid        #setting the resolution
		 echo '      iproblem=  1                  ' >  params
		 echo '      days=      0.025              ' >> params      #setting the simulation time
		 echo '      prtd1=     0.0125             ' >> params      #output interval
		 echo '      dte=       6.                 ' >> params
# ------------------ COMPILE ----------------------------
	#netCDF output without OpenACC(serial) (link to your own path)
	#pgfortran -o  a.out pom-openacc.f -cuda -acc=gpu -mcmodel=medium -I/public/software/.local/easybuild/software/netCDF-All/NVHPC-23.1/include -L/public/software/.local/easybuild/software/netCDF-All/NVHPC-23.1/lib -lnetcdff
	
	#netCDF output with OpenACC(parallel) (link to your own path)
	#pgfortran -o -cuda -acc=gpu a.out pom-openacc.f  -mcmodel=medium -I/public/software/.local/easybuild/software/netCDF-All/NVHPC-23.1/include -L/public/software/.local/easybuild/software/netCDF-All/NVHPC-23.1/lib -lnetcdff
	
	#No netcdf nor openacc(parallel)
	#gfortran -o -cuda -acc=gpu a.out pom-openacc-nonet.f #pom-openacc-nonet.f annotated with all options related to netcdf
	
	#Using openacc without netcdf(serial)
	#pgfortran -o -cuda -acc=gpu a.out pom-openacc-nonet.f 

# ------------------ RUN ----------------------------
	./a.out > pom2k.out  #printout file

# run.sh is to run the script, you can copy the above required options to it.

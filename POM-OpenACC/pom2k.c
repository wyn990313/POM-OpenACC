C***********************************************************************
C
C     Common blocks for pom2k.f
C
C***********************************************************************
C
C     source_c should agree with source in pom2k.f.
C
      character*40 source_c
      parameter(source_c='pom2k  2006-05-03')
C
C***********************************************************************
C
C     Array sizes:
C
      integer
     $  im             ,imm1           ,imm2           ,jm             ,
     $  jmm1           ,jmm2           ,kb             ,kbm1           ,
     $  kbm2 
C
C***********************************************************************
C
C     Set size of problem here:
C
c     parameter
c -- file2ic (iproblem=3)
c    $ (im=41          ,jm=61          ,kb=16)
c -- seamount (iproblem=1)
c    $ (im=65          ,jm=49          ,kb=21)
C ---- from parameter file generated by runpom2k ----
      include 'grid'
C
C***********************************************************************
C                                     
      parameter
     $ (imm1=im-1      ,imm2=im-2      ,jmm1=jm-1      ,jmm2=jm-2      ,
     $  kbm1=kb-1      ,kbm2=kb-2      )
C
C-----------------------------------------------------------------------
C
C     Scalars:
C
      real
     $  alpha          ,dte            ,dti            ,dti2           ,  
     $  grav           ,hmax           ,kappa          ,pi             ,
     $  ramp           ,rfe            ,rfn            ,rfs            ,
     $  rfw            ,rhoref         ,sbias          ,slmax          ,
     $  small          ,tbias          ,time           ,tprni          ,
     $  umol           ,vmaxl

      integer
     $  iint           ,iprint         ,iskp           ,jskp           ,
     $  kl1            ,kl2            ,mode           ,ntp
C
      common/blkcon/ 
     $  alpha          ,dte            ,dti            ,dti2           ,
     $  grav           ,hmax           ,kappa          ,pi             ,
     $  ramp           ,rfe            ,rfn            ,rfs            ,
     $  rfw            ,rhoref         ,sbias          ,slmax          ,
     $  small          ,tbias          ,time           ,tprni          ,
     $  umol           ,vmaxl          ,
     $  iint           ,iprint         ,iskp           ,jskp           ,
     $  kl1            ,kl2            ,mode           ,ntp
C
C-----------------------------------------------------------------------
C
C     1-D arrays:
C
      real
     $  dz             ,dzz            ,z              ,zz
C
      common/blk1d/ 
     $  dz(kb)         ,dzz(kb)        ,z(kb)          ,zz(kb) 
C
C-----------------------------------------------------------------------
C
C     2-D arrays:
C
      real
     $  aam2d          ,advua          ,advva          ,adx2d          ,
     $  ady2d          ,art            ,aru            ,arv            ,
     $  cbc            ,cor            ,d              ,drx2d          ,
     $  dry2d          ,dt             ,dum            ,dvm            ,
     $  dx             ,dy             ,east_c         ,east_e         ,
     $  east_u         ,east_v         ,e_atmos        ,egb            ,
     $  egf            ,el             ,elb            ,elf            ,
     $  et             ,etb            ,etf            ,fluxua         ,
     $  fluxva         ,fsm            ,h              ,north_c        ,
     $  north_e        ,north_u        ,north_v        ,psi            ,
     $  rot            ,ssurf          ,swrad          ,vfluxb         ,
     $  tps            ,tsurf          ,ua             ,vfluxf         ,
     $  uab            ,uaf            ,utb            ,utf            ,
     $  va             ,vab            ,vaf            ,
     $  vtb            ,vtf            ,wssurf         ,wtsurf         ,
     $  wubot          ,wusurf         ,wvbot          ,wvsurf
C
      common/blk2d/
     $  aam2d(im,jm)   ,advua(im,jm)   ,advva(im,jm)   ,adx2d(im,jm)   ,
     $  ady2d(im,jm)   ,art(im,jm)     ,aru(im,jm)     ,arv(im,jm)     ,
     $  cbc(im,jm)     ,cor(im,jm)     ,d(im,jm)       ,drx2d(im,jm)   ,
     $  dry2d(im,jm)   ,dt(im,jm)      ,dum(im,jm)     ,dvm(im,jm)     ,
     $  dx(im,jm)      ,dy(im,jm)      ,east_c(im,jm)  ,east_e(im,jm)  ,
     $  east_u(im,jm)  ,east_v(im,jm)  ,e_atmos(im,jm) ,egb(im,jm)     ,
     $  egf(im,jm)     ,el(im,jm)      ,elb(im,jm)     ,elf(im,jm)     ,
     $  et(im,jm)      ,etb(im,jm)     ,etf(im,jm)     ,fluxua(im,jm)  ,
     $  fluxva(im,jm)  ,fsm(im,jm)     ,h(im,jm)       ,north_c(im,jm) ,
     $  north_e(im,jm) ,north_u(im,jm) ,north_v(im,jm) ,psi(im,jm)     ,
     $  rot(im,jm)     ,ssurf(im,jm)   ,swrad(im,jm)   ,vfluxb(im,jm)  ,
     $  tps(im,jm)     ,tsurf(im,jm)   ,ua(im,jm)      ,vfluxf(im,jm)  ,
     $  uab(im,jm)     ,uaf(im,jm)     ,utb(im,jm)     ,utf(im,jm)     ,
     $  va(im,jm)      ,vab(im,jm)     ,vaf(im,jm)     ,
     $  vtb(im,jm)     ,vtf(im,jm)     ,wssurf(im,jm)  ,wtsurf(im,jm)  ,
     $  wubot(im,jm)   ,wusurf(im,jm)  ,wvbot(im,jm)   ,wvsurf(im,jm)
C
C-----------------------------------------------------------------------
C
C     3-D arrays:
C
      real 
     $  aam            ,advx           ,advy           ,a              ,
     $  c              ,drhox          ,drhoy          ,dtef           ,
     $  ee             ,gg             ,kh             ,km             ,
     $  kq             ,l              ,q2b            ,q2             ,
     $  q2lb           ,q2l            ,rho            ,rmean          ,
     $  sb             ,sclim          ,s              ,tb             ,
     $  tclim          ,t              ,ub             ,uf             ,
     $  u              ,vb             ,vf             ,v              ,
     $  w              ,zflux
C
      common/blk3d/
     $  aam(im,jm,kb)  ,advx(im,jm,kb) ,advy(im,jm,kb) ,a(im,jm,kb)    ,
     $  c(im,jm,kb)    ,drhox(im,jm,kb),drhoy(im,jm,kb),dtef(im,jm,kb) ,
     $  ee(im,jm,kb)   ,gg(im,jm,kb)   ,kh(im,jm,kb)   ,km(im,jm,kb)   ,
     $  kq(im,jm,kb)   ,l(im,jm,kb)    ,q2b(im,jm,kb)  ,q2(im,jm,kb)   ,
     $  q2lb(im,jm,kb) ,q2l(im,jm,kb)  ,rho(im,jm,kb)  ,rmean(im,jm,kb),
     $  sb(im,jm,kb)   ,sclim(im,jm,kb),s(im,jm,kb)    ,tb(im,jm,kb)   ,
     $  tclim(im,jm,kb),t(im,jm,kb)    ,ub(im,jm,kb)   ,uf(im,jm,kb)   ,
     $  u(im,jm,kb)    ,vb(im,jm,kb)   ,vf(im,jm,kb)   ,v(im,jm,kb)    ,
     $  w(im,jm,kb)    ,zflux(im,jm,kb)
C
C-----------------------------------------------------------------------
C
C     1 and 2-D boundary value arrays:
C
      real
     $  ele            ,eln            ,els            ,elw            ,
     $  sbe            ,sbn            ,sbs            ,sbw            ,
     $  tbe            ,tbn            ,tbs            ,tbw            ,
     $  uabe           ,uabw           ,ube            ,ubw            ,
     $  vabn           ,vabs           ,vbn            ,vbs       
C
      common/bdry/
     $  ele(jm)        ,eln(im)        ,els(im)        ,elw(jm)        ,
     $  sbe(jm,kb)     ,sbn(im,kb)     ,sbs(im,kb)     ,sbw(jm,kb)     ,
     $  tbe(jm,kb)     ,tbn(im,kb)     ,tbs(im,kb)     ,tbw(jm,kb)     ,
     $  uabe(jm)       ,uabw(jm)       ,ube(jm,kb)     ,ubw(jm,kb)     ,
     $  vabn(im)       ,vabs(im)       ,vbn(im,kb)     ,vbs(im,kb)
C
C-----------------------------------------------------------------------
C
C     Character variables:
C
      character*26
     $  time_start
C
      character*40
     $  source,title
C
      common/blkchar/
     $  time_start     ,source         ,title
C
C-----------------------------------------------------------------------
C
C     End of common blocks
C
C-----------------------------------------------------------------------
C






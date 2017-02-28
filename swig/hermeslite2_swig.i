/* -*- c++ -*- */

#define HERMESLITE2_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "hermeslite2_swig_doc.i"

%{
#include "hermeslite2/hermesNB.h"
#include "hermeslite2/hermesWB.h"
%}


%include "hermeslite2/hermesNB.h"
GR_SWIG_BLOCK_MAGIC2(hermeslite2, hermesNB);

%include "hermeslite2/hermesWB.h"
GR_SWIG_BLOCK_MAGIC2(hermeslite2, hermesWB);

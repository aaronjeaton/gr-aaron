/* -*- c++ -*- */

#define AARON_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "aaron_swig_doc.i"

%{
#include "aaron/priority_streamer_ff.h"
%}


%include "aaron/priority_streamer_ff.h"
GR_SWIG_BLOCK_MAGIC2(aaron, priority_streamer_ff);

/* -*- c++ -*- */
/* 
 * Copyright 2014 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gr_io_signature.h>
#include "priority_streamer_ff_impl.h"
#include <stdio.h>

namespace gr {
  namespace aaron {

    priority_streamer_ff::sptr
    priority_streamer_ff::make()
    {
      return gnuradio::get_initial_sptr
        (new priority_streamer_ff_impl());
    }

    /*
     * The private constructor
     */
    priority_streamer_ff_impl::priority_streamer_ff_impl()
      : gr_sync_block("priority_streamer_ff",
		      gr_make_io_signature(2, 2, sizeof(float)),
		      gr_make_io_signature(1, 1, sizeof(float)))
    {}

    /*
     * Our virtual destructor.
     */
    priority_streamer_ff_impl::~priority_streamer_ff_impl()
    {
    }

    int
    priority_streamer_ff_impl::work(int noutput_items,
			  gr_vector_const_void_star &input_items,
			  gr_vector_void_star &output_items)
    {
        const float *in2 = (const float *) input_items[1];
        const float *in = (const float *) input_items[0];
        float *out = (float *) output_items[0];

        // Do <+signal processing+>


		for (int i=0; i < noutput_items; i++) 
		    { 
				if (in[i] == 0)
				{
			       // no input signalat priority input
					
					out[i] = in2[i];
					//printf ("\n%d no priority signal in %f %f out %f", i, in[i], in2[i], out[i]);
				}
			    else
			    {
					
					out[i] = in[i];
			        //printf ("\n%d priority signal in %f %f out %f", i, in[i], in2[i], out[i]);
			    }
			}








        // Tell runtime system how many output items we produced.
        return noutput_items;
    }

  } /* namespace aaron */
} /* namespace gr */


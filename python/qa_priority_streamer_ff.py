#!/usr/bin/env python
# 
# Copyright 2014 <+YOU OR YOUR COMPANY+>.
# 
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
# 
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this software; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
# 

from gnuradio import gr, gr_unittest, blocks
import aaron_swig as aaron

class qa_priority_streamer_ff (gr_unittest.TestCase):

    def setUp (self):
        self.tb = gr.top_block ()

    def tearDown (self):
        self.tb = None

    def test_001_t (self):
        # set up fg
       print 'starting test ...'
       src_data_0 = (0,0,0,3,-2,1,9,-3,0,0,0,0,0)
       src_data_1 = (1,1,1,1,1,1,1,1,1,1,1,1,1)
       print "src_data_0 Tuple length ", len(src_data_0)
       print "src_data_1 Tuple length ", len(src_data_1)
       expected_result = (1,1,1,3,-2,1,9,-3,1,1,1,1,1)
       print "expected_result Tuple length ", len(expected_result)
       stream_block = aaron.priority_streamer_ff()
       dst = blocks.vector_sink_f()
       src_0 = blocks.vector_source_f(src_data_0)
       src_1 = blocks.vector_source_f(src_data_1)
       
       print 'connecting blocks'
       self.tb.connect(src_0, (stream_block,0))
       self.tb.connect(src_1, (stream_block,1))
       self.tb.connect(stream_block, dst)
       
       print 'running flow graph'
       self.tb.run ()
        # check data

       print 'comparing results'
       result_data = dst.data()
       print "result_data Tuple length ", len(result_data)
       self.assertFloatTuplesAlmostEqual(expected_result, result_data)


       print 'finished'


       self.tb.run ()
        # check data


if __name__ == '__main__':
       gr_unittest.run(qa_priority_streamer_ff, "qa_priority_streamer_ff.xml")

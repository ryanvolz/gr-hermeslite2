/* -*- c++ -*- */
/* 
 * Copyright 2013-2015 Thomas C. McDermott, N5EG.
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

#ifndef INCLUDED_HERMESLITE2_HERMESNB_IMPL_H
#define INCLUDED_HERMESLITE2_HERMESNB_IMPL_H

#include <hermeslite2/hermesNB.h>

namespace gr {
  namespace hermeslite2 {

    class hermesNB_impl : public hermesNB
    {
     private:
      // Nothing to declare in this block.

     public:

/*! \brief Construct a HermesNB module
 * \param RxFreq0    Receiver 0 frequency, Hz.
 * \param RxFreq1    Receiver 1 frequency, Hz.
 * \param RxFreq2    Receiver 2 frequency, Hz.
 * \param RxFreq3    Receiver 3 frequency, Hz.
 * \param RxFreq4    Receiver 4 frequency, Hz.
 * \param RxFreq5    Receiver 5 frequency, Hz.
 * \param RxFreq6    Receiver 6 frequency, Hz.
 * \param RxFreq7    Receiver 7 frequency, Hz.
 * \param TxFreq     Transmitter frequency, Hz.
 * \param PTTModeSel PTT mode selector off (0), VOX (1), on (2)
 * \param PTTTxMute  Mute Tx on PTT
 * \param PTTRxMute  Mute Rx on PTT
 * \param TxDr       Transmit Drive Level (0..255)
 * \param RxSmp  Receive Sample Rate, 192000, 96000, or 48000
 * \param Intfc  Ethernet interface to use
 * \param Verbose  Turns Verbose mode on (=1) or off (=0)
 * \param NumRx  Number of Receivers (1 or 2)
 * \param MACAddr MAC Address of target or * for first detected
 * \param AGC HL2 Hardware AGC
 * \param LNAG HL2 LNA gain
 * \param PA HL2 onboard PA enable
 * \param Q5 HL2 enable Q5 switch external PTT in low power mode
 *
 */
      hermesNB_impl(int RxFreq0, int RxFreq1, int RxFreq2, int RxFreq3,
		    int RxFreq4, int RxFreq5, int RxFreq6, int RxFreq7,
		    int TxFreq,
		   int PTTModeSel, bool PTTTxMute, bool PTTRxMute,
		   unsigned char TxDr, int RxSmp, const char* Intfc, 
		   int Verbose, int NumRx,
		   const char* MACAddr, bool AGC, int LNAG, bool PA, bool Q5);
      ~hermesNB_impl();

      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
		       gr_vector_int &ninput_items,
		       gr_vector_const_void_star &input_items,
		       gr_vector_void_star &output_items);
    };

  } // namespace hermeslite2
} // namespace gr

#endif /* INCLUDED_HERMESLITE2_HERMESNB_IMPL_H */


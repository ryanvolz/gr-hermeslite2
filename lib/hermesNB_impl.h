/* -*- c++ -*- */
/*
 * Copyright 2017-2023 Daniel Estevez <daniel@destevez.net>
 * Copyright 2013-2015 Thomas C. McDermott, N5EG.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_HERMESLITE2_HERMESNB_IMPL_H
#define INCLUDED_HERMESLITE2_HERMESNB_IMPL_H

#include <gnuradio/hermeslite2/hermesNB.h>

namespace gr {
namespace hermeslite2 {

class hermesNB_impl : public hermesNB
{
private:
    // Nothing to declare in this block.

public:
    hermesNB_impl(int RxFreq0,
                  int RxFreq1,
                  int RxFreq2,
                  int RxFreq3,
                  int RxFreq4,
                  int RxFreq5,
                  int RxFreq6,
                  int RxFreq7,
                  int TxFreq,
                  int PTTModeSel,
                  bool PTTTxMute,
                  bool PTTRxMute,
                  unsigned char TxDr,
                  int RxSmp,
                  const char* Intfc,
                  int Verbose,
                  int NumRx,
                  const char* MACAddr,
                  bool AGC,
                  int LNAG,
                  bool PA,
                  bool Q5);
    ~hermesNB_impl() override;

    void forecast(int noutput_items, gr_vector_int& ninput_items_required) override;

    int general_work(int noutput_items,
                     gr_vector_int& ninput_items,
                     gr_vector_const_void_star& input_items,
                     gr_vector_void_star& output_items) override;
};

} // namespace hermeslite2
} // namespace gr

#endif /* INCLUDED_HERMESLITE2_HERMESNB_IMPL_H */

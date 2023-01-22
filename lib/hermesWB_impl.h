/* -*- c++ -*- */
/*
 * Copyright 2017-2023 Daniel Estevez <daniel@destevez.net>
 * Copyright 2013-2015 Thomas C. McDermott, N5EG
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_HERMESLITE2_HERMESWB_IMPL_H
#define INCLUDED_HERMESLITE2_HERMESWB_IMPL_H

#include <gnuradio/hermeslite2/hermesWB.h>

namespace gr {
namespace hermeslite2 {

class hermesWB_impl : public hermesWB
{
private:
    // Nothing to declare in this block.

public:
    hermesWB_impl(bool RxPre,
                  const char* Intfc,
                  const char* ClkS,
                  int AlexRA,
                  int AlexTA,
                  int AlexHPF,
                  int AlexLPF,
                  const char* MACAddr);
    ~hermesWB_impl() override;

    void forecast(int noutput_items, gr_vector_int& ninput_items_required) override;

    int general_work(int noutput_items,
                     gr_vector_int& ninput_items,
                     gr_vector_const_void_star& input_items,
                     gr_vector_void_star& output_items) override;
};

} // namespace hermeslite2
} // namespace gr

#endif /* INCLUDED_HERMESLITE2_HERMESWB_IMPL_H */

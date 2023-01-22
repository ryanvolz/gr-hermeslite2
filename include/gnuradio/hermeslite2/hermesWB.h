/* -*- c++ -*- */
/*
 * Copyright 2017-2023 Daniel Estevez <daniel@destevez.net>
 * Copyright 2013-2015 Thomas C. McDermott, N5EG
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_HERMESLITE2_HERMESWB_H
#define INCLUDED_HERMESLITE2_HERMESWB_H

#include <gnuradio/block.h>
#include <gnuradio/hermeslite2/api.h>

namespace gr {
namespace hermeslite2 {

/*!
 * \brief Hermes WB receiver
 * \ingroup hermeslite2
 *
 */
class HERMESLITE2_API hermesWB : virtual public gr::block
{
public:
    typedef std::shared_ptr<hermesWB> sptr;

    /*! \brief Construct a HermesWB block
     * \param RxPre      Rx Preamp on (1) / off (0)
     * \param Intfc  Ethernet interface to use
     * \param ClkS   HPSDR Clock Source (register C1 when C0 = 0x00)
     * \param AlexRA  HPSDR Alex Rx Ant Selector
     * \param AlexTA  HPSDR Alex Tx Ant Selector
     * \param AlexHPF  HPSDR Alex Rx High Pass Filter Selector
     * \param AlexLPF  HPSDR Alex Tx Low Pass Filter Selector
     *
     */
    static sptr make(bool RxPre,
                     const char* Intfc,
                     const char* ClkS,
                     int AlexRA,
                     int AlexTA,
                     int AlexHPF,
                     int AlexLPF,
                     const char* MACAddr);

    void set_RxPreamp(int);            // callback
    void set_ClockSource(const char*); // callback
    void set_AlexRxAntenna(int);       // callback
    void set_AlexTxAntenna(int);       // callback
    void set_AlexRxHPF(int);           // callback
    void set_AlexTxLPF(int);           // callback

    bool stop();  // override
    bool start(); // override
};

} // namespace hermeslite2
} // namespace gr

#endif /* INCLUDED_HERMESLITE2_HERMESWB_H */

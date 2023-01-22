/* -*- c++ -*- */
/*
 * Copyright 2017-2023 Daniel Estevez <daniel@destevez.net>
 * Copyright 2013-2015 Thomas C. McDermott, N5EG
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_HERMESLITE2_HERMESNB_H
#define INCLUDED_HERMESLITE2_HERMESNB_H

#include <gnuradio/block.h>
#include <gnuradio/hermeslite2/api.h>

namespace gr {
namespace hermeslite2 {

/*!
 * \brief <+description of block+>
 * \ingroup hermeslite2
 *
 */
class HERMESLITE2_API hermesNB : virtual public gr::block
{
public:
    typedef std::shared_ptr<hermesNB> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of hermeslite2::hermesNB.
     *
     * To avoid accidental use of raw pointers, hermeslite2::hermesNB's
     * constructor is in a private implementation
     * class. hermeslite2::hermesNB::make is the public interface for
     * creating new instances.
     */
    static sptr make(int RxFreq0,
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

    void set_Receive0Frequency(float); // callback
    void set_Receive1Frequency(float); // callback
    void set_Receive2Frequency(float); // callback
    void set_Receive3Frequency(float); // callback
    void set_Receive4Frequency(float); // callback
    void set_Receive5Frequency(float); // callback
    void set_Receive6Frequency(float); // callback
    void set_Receive7Frequency(float); // callback
    void set_TransmitFrequency(float); // callback
    void set_RxSampRate(int);          // callback
    void set_PTTMode(int);             // callback
    void set_PTTOffMutesTx(int);       // callback
    void set_PTTOnMutesRx(int);        // callback
    void set_TxDrive(int);             // callback
                                       //
                                       // Turn Verbose mode on / off
                                       //
    void set_Verbose(int);             // callback

    // Callbacks for HL2 Parameters
    void set_HardwareAGC(bool AGC);
    void set_LNAGain(int LNAG);
    void set_OnboardPA(bool PA);
    void set_Q5Switch(bool Q5);

    bool stop();  // override
    bool start(); // override
};

} // namespace hermeslite2
} // namespace gr

#endif /* INCLUDED_HERMESLITE2_HERMESNB_H */

/* -*- C++ -*- */
#pragma once

#include "../base.h"
#include "../printers.h"
#include <LiquidCrystal.h>

namespace AM5 {
  template<
    LiquidCrystal& device,
    typename O=Void<>,
    typename P=DefaultPrinters
  > struct LCDOut:public O {
    using Printers=P;
    using This=LCDOut<device,O>;
    template<typename Nav,typename T>
    static inline void raw(T o) {
      device.setCursor(Nav::posX(),Nav::posY());
      Nav::useX(device.print(o));
    }
    template<typename Nav>
    static inline void printMenu() {Nav::template printMenuRaw<This>();}
  };
};//AM5 namespace

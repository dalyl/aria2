/* <!-- copyright */
/*
 * aria2 - The high speed download utility
 *
 * Copyright (C) 2006 Tatsuhiro Tsujikawa
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */
/* copyright --> */
#ifndef D_SIMPLE_RANDOMIZER_H
#define D_SIMPLE_RANDOMIZER_H

#include "Randomizer.h"

#include <memory>

#ifdef __MINGW32__
# include <wincrypt.h>
#endif // __MINGW32__

namespace aria2 {

class SimpleRandomizer : public Randomizer {
private:
  static std::unique_ptr<SimpleRandomizer> randomizer_;

#ifdef __MINGW32__
  HCRYPTPROV cryProvider_;
#endif //__MINGW32__

  SimpleRandomizer();
public:

  static const std::unique_ptr<SimpleRandomizer>& getInstance();

  static void init();

  virtual ~SimpleRandomizer();

  virtual long int getRandomNumber() CXX11_OVERRIDE;

  virtual long int getMaxRandomNumber() CXX11_OVERRIDE;

  /**
   * Returns random number in [0, to).
   */
  virtual long int getRandomNumber(long int to) CXX11_OVERRIDE;

  void getRandomBytes(unsigned char *buf, size_t len);

  long int operator()(long int to);
};

} // namespace aria2

#endif // D_SIMPLE_RANDOMIZER_H

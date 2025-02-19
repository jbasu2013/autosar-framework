/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <iterator>
#include <algorithm>
#include <Bsw/Common/Std_Types.h>


EXTERN_C
{
  struct ctor_type
  {
    typedef void(*function_type)();
    typedef std::reverse_iterator<const function_type*> const_reverse_iterator;
  };

  extern ctor_type::function_type _ctors_end[];
  extern ctor_type::function_type _ctors_begin[];
}

namespace crt
{
  void init_ctors();
}

void crt::init_ctors()
{
  std::for_each(ctor_type::const_reverse_iterator(_ctors_end),
                ctor_type::const_reverse_iterator(_ctors_begin),
                [](const ctor_type::function_type pf)
                {
                  pf();
                });
}

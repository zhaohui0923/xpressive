////////////////////////////////////////////////////////////////////////////
// marker_compiler.hpp
//
//  Copyright 2004 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_XPRESSIVE_DETAIL_STATIC_PRODUCTIONS_MARKER_COMPILER_HPP_EAN_10_04_2005
#define BOOST_XPRESSIVE_DETAIL_STATIC_PRODUCTIONS_MARKER_COMPILER_HPP_EAN_10_04_2005

#include <boost/type_traits/is_same.hpp>
#include <boost/xpressive/detail/detail_fwd.hpp>
#include <boost/xpressive/proto2/proto.hpp>
#include <boost/xpressive/proto2/compiler/branch.hpp>
#include <boost/xpressive/proto2/compiler/conditional.hpp>
#include <boost/xpressive/proto2/compiler/transform.hpp>
#include <boost/xpressive/detail/static/productions/domain_tags.hpp>
#include <boost/xpressive/detail/static/productions/marker_transform.hpp>
#include <boost/xpressive/detail/static/productions/set_compilers.hpp>

namespace boost { namespace xpressive { namespace detail
{

    ///////////////////////////////////////////////////////////////////////////////
    // assign_compiler
    //  could be (s1= 'a') or (set= 'a')
    struct assign_compiler
      : proto2::conditional_compiler
        <
            is_marker_predicate
          , proto2::transform_compiler<marker_replace_transform, seq_tag>
          , proto2::branch_compiler<list_branch, lst_tag>
        >
    {
    };

}}}

namespace boost { namespace proto2
{

    template<>
    struct compiler<assign_tag, xpressive::detail::seq_tag, void>
      : xpressive::detail::assign_compiler
    {
    };

}}

#endif

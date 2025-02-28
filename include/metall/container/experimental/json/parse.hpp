// Copyright 2021 Lawrence Livermore National Security, LLC and other Metall Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (Apache-2.0 OR MIT)

#ifndef METALL_CONTAINER_EXPERIMENT_JSON_PARSE_HPP
#define METALL_CONTAINER_EXPERIMENT_JSON_PARSE_HPP

#include <iostream>
#include <string_view>
#include <memory>

#include <boost/json/src.hpp>

#include <metall/container/experimental/json/json_fwd.hpp>

namespace metall::container::experimental::json {

namespace {
namespace bj = boost::json;
}

/// \brief Parses a JSON represented as a string.
/// \tparam allocator_type An allocator type.
/// \param input_json_string An input JSON string.
/// \param allocator An allocator object.
/// \return Returns a constructed value.
template <typename allocator_type = std::allocator<std::byte>>
inline value<allocator_type> parse(std::string_view input_json_string,
                                   const allocator_type &allocator = allocator_type()) {
  bj::error_code ec;
  auto bj_value = bj::parse(input_json_string.data(), ec);
  if (ec) {
    std::cerr << "Failed to parse: " << ec.message() << std::endl;
    return value<allocator_type>{allocator};
  }

  return metall::container::experimental::json::value_from(std::move(bj_value), allocator);
}

}

#endif //METALL_CONTAINER_EXPERIMENT_JSON_PARSE_HPP

//
// Copyright (C) 2013 Mateusz Loskot <mateusz@loskot.net>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include "json_benchmark.hpp"
#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>
#include <rapidjson/filestream.h>
#include <rapidjson/prettywriter.h>
namespace rj = rapidjson;
int main()
{
    try
    {
        jsonbench::run_benchmark("rapidjson", [](std::string const& s) {
            rj::Document d;
            d.Parse<0>(s.c_str());
#ifdef JSON_BENCHMARK_DUMP_PARSED_JSON
            rj::FileStream f(stdout);
            rj::PrettyWriter<rj::FileStream> writer(f);
            d.Accept(writer);
#endif
            return !d.IsNull();
        });

        return EXIT_SUCCESS;
    }
    catch (std::exception const& e)
    {
        std::cerr << e.what() <<std::endl;
    }
    return EXIT_FAILURE;
}

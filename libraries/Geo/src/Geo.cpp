#include "Geo_impl.h"
#include <Sandbox/Geo/Geo.h>

namespace Sandbox { namespace Geo {
    size_t get_point_index() {
        return Sg::get_point_index_impl();
    }
}}

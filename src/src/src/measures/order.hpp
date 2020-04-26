/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_MEASURES_ORDER_H_
#define UU_MEASURES_ORDER_H_

namespace uu {
namespace net {

/**
 * Returns the number of vertices in the graph.
 */
template<typename G>
size_t
order(
    const G* g
);

}
}

#include "order.ipp"

#endif

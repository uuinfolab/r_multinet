/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_OPERATIONS_COMPLEMENT_H_
#define UU_OPERATIONS_COMPLEMENT_H_

#include <memory>
#include <string>

namespace uu {
namespace net {

/**
 * Returns the complement of a graph.
 * The set of vertices is the same, and there is an edge
 * for each pair of vertices that are not adjacent in the
 * input graph.
 *
 * @param g input graph
 */
template<typename G>
std::unique_ptr<G>
graph_complement(
    const G* g,
    const std::string& name = ""
);

}
}

#include "complement.ipp"

#endif

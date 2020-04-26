/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_NETWORKS_NETWORK_H_
#define UU_NETWORKS_NETWORK_H_

#include <memory>
#include <string>
#include "net/datastructures/graphs/Graph.hpp"
#include "net/datastructures/stores/AttrVertexStore.hpp"
#include "net/datastructures/stores/AttrSimpleEdgeStore.hpp"

namespace uu {
namespace net {

/**
 * A Network is a graph with at most one edge between each pair of vertices.
 * The Network class also provides vertex and edge attributes, which are local to the network.
 * That is, the same vertex inside another network will have different attributes.
 *
 * Depending on its parameters, a Network can allow or disallow loops (default: disallow) and
 * be directed or undirected (default: undirected). That is, a Network by default corresponds to
 * a simple graph.
 */
class Network
{

  public:

    const std::string name;

    /**
     * Creates a graph with directed or undirected simple edges and allowing or not loops.
     */
    Network(
        const std::string& name,
        EdgeDir dir = EdgeDir::UNDIRECTED,
        bool allow_loops = false
    );


    /**
     * Returns a pointer to the Network's vertex set.
     */
    AttrVertexStore*
    vertices(
    );


    /**
     * Returns a pointer to the Network's vertex set.
     */
    const AttrVertexStore*
    vertices(
    ) const;


    /**
     * Returns a pointer to the Network's edge set.
     */
    AttrSimpleEdgeStore*
    edges(
    );


    /**
     * Returns a pointer to the Network's edge set.
     */
    const AttrSimpleEdgeStore*
    edges(
    ) const;


    /**
     * Checks if the Network in this graph are directed.
     */
    virtual
    bool
    is_directed(
    ) const;


    /**
     * Checks if the Network is weighted.
     */
    virtual
    bool
    is_weighted(
    ) const;


    /**
     * Checks if the Network is probabilistic.
     */
    virtual
    bool
    is_probabilistic(
    ) const;


    /**
     * Checks if the Network has temporal information on its edges.
     */
    virtual
    bool
    is_temporal(
    ) const;


    /**
     * Checks if the Network allows users to define their own generic attributes.
     * Always returns true.
     */
    virtual
    bool
    is_attributed(
    ) const;


    /**
     * Checks if the Network allows multi-edges.
     * Always returns false.
     */
    virtual
    bool
    allows_multi_edges(
    ) const;


    /**
     * Checks if the graph allows loops.
     */
    virtual
    bool
    allows_loops(
    ) const;


    /**
     * Returns a string providing a summary of the Network structure.
     */
    virtual
    std::string
    summary(
    ) const;


  private:

    std::unique_ptr<Graph<AttrVertexStore, AttrSimpleEdgeStore>> data_;

};

}
}

#endif

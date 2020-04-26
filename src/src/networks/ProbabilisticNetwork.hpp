/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_NETWORKS_PROBABILISTICNETWORK_H_
#define UU_NETWORKS_PROBABILISTICNETWORK_H_

#include "networks/Network.hpp"

namespace uu {
namespace net {


class ProbabilisticNetwork
    : public Network
{

  private:

    std::string KPROB_ATTR_NAME = "prob";

    typedef Network super;

  public:

    /**
     * Creates a network with directed or undirected simple edges and with or without loops.
     */
    ProbabilisticNetwork(
        const std::string& name,
        EdgeDir dir = EdgeDir::UNDIRECTED,
        bool allow_loops = false
    );

    /**
     * Checks if the graph is weighted.
     */
    bool
    is_probabilistic(
    ) const override;

    /**
     * Sets the weight of an edge.
     */
    void
    set_prob(
        const Edge* e,
        double p
    );

    /**
     * Sets the weight of an edge.
     */
    core::Value<double>
    get_prob(
        const Edge* e
    ) const;

    /**
     * Returns a string providing a summary of the network.
     */
    std::string
    summary(
    ) const override;

};

}
}

#endif

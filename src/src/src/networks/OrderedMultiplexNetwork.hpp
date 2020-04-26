/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_MNET_DATASTRUCTURE_GRAPHS_ATTRIBUTEDORDEREDHOMOGENEOUSMULTILAYERNETWORK_H_
#define UU_MNET_DATASTRUCTURE_GRAPHS_ATTRIBUTEDORDEREDHOMOGENEOUSMULTILAYERNETWORK_H_

#include <memory>
#include <string>
#include "net/datastructures/stores/AttrVertexStore.hpp"
#include "mnet/datastructures/stores/UserDefinedAttrs.hpp"
#include "mnet/datastructures/stores/Attributed.hpp"
#include "mnet/datastructures/stores/Attributes.hpp"
#include "mnet/datastructures/stores/EmptyEdgeStore.hpp"
#include "objects/Vertex.hpp"
#include "net/datastructures/stores2/GenericSimpleEdgeStore.hpp"
#include "networks/Network.hpp"
#include "mnet/datastructures/stores/VertexOverlappingOrderedLayerStore.hpp"
#include "mnet/datastructures/graphs/MultilayerNetwork.hpp"

namespace uu {
namespace net {

class
    OrderedMultiplexNetwork
    : public MultilayerNetwork<
      AttrVertexStore,
      VertexOverlappingOrderedLayerStore<Network>,
      EmptyEdgeStore
      >
{

    typedef MultilayerNetwork<
    AttrVertexStore,
    VertexOverlappingOrderedLayerStore<Network>,
    EmptyEdgeStore
    > super;

  public:

    typedef Network layer_type;
    typedef Vertex vertex_type;

    //using super::super;

    using super::interlayer_edges;

    OrderedMultiplexNetwork(
        const std::string& name,
        MultilayerNetworkType t,

        std::unique_ptr<AttrVertexStore> v,
        std::unique_ptr<VertexOverlappingOrderedLayerStore<Network>> l,
        std::unique_ptr<EmptyEdgeStore> e);

    std::string
    summary(
    ) const;


    bool
    is_ordered() const
    {
        return true;
    }

};

/**
 * Creates a multilayer network.
 */
std::shared_ptr<OrderedMultiplexNetwork>
create_shared_ordered_multiplex_network(
    const std::string& name
);

/**
 * Creates a multilayer network.
 */
std::unique_ptr<OrderedMultiplexNetwork>
create_ordered_multiplex_network(
    const std::string& name
);

}
}

#endif

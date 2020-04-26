/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */
#include "networks/OrderedMultiplexNetwork.hpp"
#include "net/datastructures/observers/PropagateObserver.hpp"
#include "mnet/datastructures/observers/LayerObserver.hpp"
#include "net/datastructures/observers/PropagateAddEraseObserver.hpp"

namespace uu {
namespace net {


OrderedMultiplexNetwork::
OrderedMultiplexNetwork(
    const std::string& name,
    MultilayerNetworkType t,
    std::unique_ptr<AttrVertexStore> v,
    std::unique_ptr<VertexOverlappingOrderedLayerStore<Network>> l,
    std::unique_ptr<EmptyEdgeStore> e
) :
    super(name, t, std::move(v), std::move(l), std::move(e))
{
}

std::string
OrderedMultiplexNetwork::
summary(
) const
{

    size_t num_intra_edges = 0;

    for (auto&& layer: *layers_)
    {
        num_intra_edges += layer->edges()->size();
    }

    size_t num_inter_edges = 0;

    size_t num_actors = vertices()->size();

    size_t num_layers = layers()->size();

    size_t num_nodes = 0;

    for (auto&& layer: *layers_)
    {
        num_nodes += layer->vertices()->size();
    }

    size_t num_edges = num_intra_edges + num_inter_edges;

    std::string summary =
        "Multilayer Network [" +
        std::to_string(num_actors) + (num_actors==1?" actor, ":" actors, ") +
        std::to_string(num_layers) + (num_layers==1?" layer, ":" layers, ") +
        std::to_string(num_nodes) + (num_nodes==1?" vertex, ":" vertices, ") +
        std::to_string(num_edges) + (num_edges==1?" edge ":" edges ") +
        "(" + std::to_string(num_intra_edges) + "," +  std::to_string(num_inter_edges) + ")]";
    return summary;
}



std::unique_ptr<OrderedMultiplexNetwork>
create_ordered_multiplex_network(
    const std::string& name
)
{
    auto vs = std::make_unique<AttrVertexStore>();

    auto ls = std::make_unique<VertexOverlappingOrderedLayerStore<Network>>();

    auto es = std::make_unique<EmptyEdgeStore>();

    // Add observers @todo

    MultilayerNetworkType t;

    auto net = std::make_unique<OrderedMultiplexNetwork>(
                   name,
                   t,
                   std::move(vs),
                   std::move(ls),
                   std::move(es)
               );


    // register an observer to check that new edges have end-vertices in the network


    return net;

}


std::shared_ptr<OrderedMultiplexNetwork>
create_shared_ordered_multiplex_network(
    const std::string& name
)
{
    auto vs = std::make_unique<AttrVertexStore>();

    auto ls = std::make_unique<VertexOverlappingOrderedLayerStore<Network>>();

    auto es = std::make_unique<EmptyEdgeStore>();

    // Add observers @todo

    MultilayerNetworkType t;

    auto net = std::make_shared<OrderedMultiplexNetwork>(
                   name,
                   t,
                   std::move(vs),
                   std::move(ls),
                   std::move(es)
               );



    // register an observer to check that new edges have end-vertices in the network


    return net;

}

}
}


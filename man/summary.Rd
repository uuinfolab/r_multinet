\name{summary}
\title{
Summarise a multilayer network
}
\description{
This function produces a summary of the network, flattened and layer-by-layer
}
\usage{
\S3method{summary}{Rcpp_RMLNetwork}(x)
}
\arguments{
\item{x}{A multilayer network.}
}
\value{A data frame with the following columns: n: number of actors/vertices, m: number of edges, dir: directionality (0:undirected, 1:directed), nc: number of components (strongly connected components for directed graphs), slc: size of largest component, dens: density, cc: clustering coefficient (corresponding to transitivity in igraph), apl: average path length, dia: diameter}
\examples{
net <- ml_aucs()
summary(net)
}

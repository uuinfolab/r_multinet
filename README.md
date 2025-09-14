# multinet library (R version)

This repository contains the R version of the _multinet_ library for the analysis of multilayer networks.

The library is available on CRAN (the Comprehensive R Archive Network), and can be installed directly from an R terminal or RStudio. This repository is mainly useful if you want to develop the library.

This library was originally based on the book: Multilayer Social Networks, by Dickison, Magnani & Rossi, Cambridge University Press (2016). The methods contained in the library and described in the book have been developed by many different authors: extensive references are available in the book, and in the documentation of each function we indicate the main reference we have followed for the implementation. For some methods developed after the book was published we give references to the corresponding literature. Additional information, including material such as survey articles and datasets, is available at [our lab's Web site](https://uuinfolab.github.io).

## Requirements

To use the library only a recent version of R is required.

If you are interested in participating in the development of the library, or if you just want to play with the code and modify it, please look at Section _Contribute_ below.

## Installation

The stable version of the library can be installed directly from R by typing:

```sh
install.packages("multinet")
```

## Contribute

To modify the library, one should consider that a large part of its code is written in C++ and comes from the [uunet repository](https://github.com/uuinfolab/uunet).

If you only want to modify the functions written in R, this can be done directly in this repository. These functions are in the R/ directory:

- datasets.R contains functions to load existing datasets, such as ml_aucs(), whose data is stored in inst/extdata.
- igraph.R contains the functions: as.igraph(), as.list() and add_igraph_layer_ml().
- functions.R contains print(), str(), summary(), values2graphics() and plot().

After modifying the functions, you can launch R from the main folder in the repository and install the new version including your changes (the first command is necessary only if you do not have devtools installed yet):

```sh
install.packages("devtools")
library(devtools)
devtools::check()
devtools::install()
```

The directory src/ contains the files exporting C++ functions from uunet to R, using Rcpp. These functions can also be updated directly in this repository:

- rcpp_module_definition.cpp contains the definitions of the R functions implemented in C++.
- r_functions.cpp contains the functions referenced in rcpp_module_definition.cpp, themselves calling functions from uunet.
- rcpp_utils.cpp contains some utility functions automating some common tasks used in r_functions.cpp.

If you need to modify any of the files in the directories eclat/, infomap/ and src/, they are imported from uunet and should be modified in the [uunet repository](https://github.com/uuinfolab/uunet). One can then get the latest code from uunet by running:

```sh
cd ext/uunet
git checkout master
git pull
cd ..
cd ..
git add ext/uunet
git commit -m "moved submodule to v0.9"
git push
./copy_uunet_files.sh
```

copy_uunet_files.sh copies the needed files from ext/ into src/ and also produces the src/Makevars and src/Makevars.win files.

## Contact

For any inquiries regarding this repository you can contact <matteo.magnani@it.uu.se>.


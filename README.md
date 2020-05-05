# multinet library (R version)

This repository contains the R version of the _multinet_ library for the analysis of multilayer networks.

The library is available on CRAN (the Comprehensive R Archive Network), and can be installed directly from an R terminal or RStudio. This repository is mainly useful if you want to develop the library.

This library was originally based on the book: Multilayer Social Networks, by Dickison, Magnani & Rossi, Cambridge University Press (2016). The methods contained in the library and described in the book have been developed by many different authors: extensive references are available in the book, and in the documentation of each function we indicate the main reference we have followed for the implementation. For some methods developed after the book was published we give references to the corresponding literature. Additional information, including material such as survey articles and datasets, is available at http://multilayer.it.uu.se/.

## Requirements

To use the library only a recent version of R is required.

If you are interested in participating in the development of the library, or if you just want to play with the code and modify it, please look at Section _Contribute_ below.

## Installation

The stable version of the library can be installed directly from R by typing:

```sh
install.packages("multinet")
```

## Contribute

TBD

```sh
install.packages("devtools")
```
devtools::check()

git submodule update --remote --merge
git commit
(for R: copy_uunet_files.sh)

## Contact

For any inquiries regarding this repository you can contact <matteo.magnani@it.uu.se>.


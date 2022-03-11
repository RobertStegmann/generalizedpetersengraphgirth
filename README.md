# Generalized Petersen Graph girth calculator
An algorithm which calculates the girth of all generalized Petersen graphs of GP(n,k), n ≤ LARGESTGP, which is 32 by default. LARGESTGP can be modified in girth.h

girth.c calculates the girth of every graph in pairs of GP(n, k) and GP(n, n−k) using a algorithm based on original research.

girth2.c calculates the girth of every isomorphic graph using an algorithm based on the research of Daniela Ferrero and Sarah Hanusch

Daniela Ferrero and Sarah Hanusch, Component connectivity of generalized
petersen graphs, International Journal of Computer Mathematics 91 (2014),
1940–1963

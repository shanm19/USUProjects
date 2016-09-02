// Disjoint Sets - C++ //

This one creates a board and randomly flips the binary values until there is a connecting line anywhere, from top to bottom.  If so, it is said to 'percolate'.  And it is optimized with Disjoint Sets.  Every time a value is flipped it is connected all the way up to the dummy rows on the top and bottom, so you only have to check if the parent of each set points to them.
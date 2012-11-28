#!/bin/sh

name="Status"

# convert -scale 1000 -background none $name.svg $name-big.png

convert -scale 36 -background none $name.svg $name@2x.png || exit
convert -scale 18 -background none $name.svg $name.png || exit

sips $name.png -s dpiWidth 72 -s dpiHeight 72
sips $name@2x.png -s dpiWidth 72 -s dpiHeight 72

convert -negate -modulate 130% $name.png ${name}Highlighted.png
convert -negate -modulate 130% $name@2x.png ${name}Highlighted@2x.png


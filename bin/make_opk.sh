#!/bin/sh

rm -f fba-rg350.opk

mksquashfs skin fbasdl.dge fbasdl_icon.png default.gcw0.desktop ../readme.txt fba-rg350.opk -all-root -no-xattrs -noappend -no-exports

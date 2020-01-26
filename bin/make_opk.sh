#!/bin/sh

rm -f fba-option-analog-l2-r2.opk

mksquashfs skin fbasdl.dge skin/fba_icon.png default.gcw0.desktop fba-option-analog-l2-r2.opk -all-root -no-xattrs -noappend -no-exports

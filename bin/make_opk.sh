#!/bin/sh

rm -f fba-000.opk

mksquashfs skin fbasdl.dge skin/fba_icon.png default.gcw0.desktop fba-000.opk -all-root -no-xattrs -noappend -no-exports

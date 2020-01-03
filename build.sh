#!/bin/bash
make -f Makefile.dingux && pushd ./bin && ./make_opk.sh && popd

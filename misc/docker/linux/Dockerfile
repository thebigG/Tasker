FROM ubuntu:18.04

RUN apt-get update && apt-get install -y qt5-default libqt5charts5-dev libx11-dev \
                                                   libxtst-dev \
                                                   libxt-dev \
                                                   libxinerama-dev \
                                                   libx11-xcb-dev \
                                                   libxkbcommon-dev \
                                                   libxkbcommon-x11-dev \
                                                   libxkbfile-dev \
                                                   autoconf \
                                                   automake \
                                                   autopoint \
                                                   bash \
                                                   bison \
                                                   bzip2 \
                                                   flex \
                                                   g++ \
                                                   g++-multilib \
                                                   gettext \
                                                   git \
                                                   gperf \
                                                   intltool \
                                                   libc6-dev-i386 \
                                                   libgdk-pixbuf2.0-dev \
                                                   libltdl-dev \
                                                   libssl-dev \
                                                   libtool-bin \
                                                   libxml-parser-perl \
                                                   lzip \
                                                   make \
                                                   openssl \
                                                   p7zip-full \
                                                   patch \
                                                   perl \
                                                   python \
                                                   ruby \
                                                   sed \
                                                   unzip \
                                                   wget \
                                                   xz-utils\
                                                   python3-pip

RUN pip3 install cmake

RUN git clone https://github.com/thebigG/Tasker.git
#RUN git submodule update --init --recursive
#
#RUN export PATH=$PATH:/home/Tasker/mxe/usr/bin/
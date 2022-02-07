FROM ubuntu:18.04
USER root

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

RUN git clone https://github.com/thebigG/mxe.git
RUN make -C mxe -j8 qt5
#The COPY command does not work for some reason in Github Actions. When running locally, this works with no problem.
#COPY "Qt5CoreConfigExtras.cmake.patch" /
#RUN patch /mxe/usr/i686-w64-mingw32.static/qt5/lib/cmake/Qt5Core/Qt5CoreConfigExtras.cmake Qt5CoreConfigExtras.cmake.patch
RUN echo "export PATH=\$PATH:/mxe/usr/bin" >> /root/.bashrc
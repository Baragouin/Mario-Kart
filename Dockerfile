FROM fedora:34
LABEL maintainer="Timothé MEDICO <medico.timothe@gmail.com>"

RUN dnf -y upgrade && dnf -y install dnf-plugins-core && dnf -y --refresh install \
    SFML.x86_64 \
    SFML-devel.x86_64 \
    CSFML.x86_64 \
    CSFML-devel.x86_64 \
    cmake.x86_64 \
    curl.x86_64 \
    gcc.x86_64  \
    gdb.x86_64  \
    git \
    glibc-devel.x86_64 \
    glibc-locale-source.x86_64 \
    glibc.x86_64 \
    libX11-devel.x86_64 \
    libXext-devel.x86_64 \
    libXrandr-devel.x86_64 \
    libXinerama-devel.x86_64 \
    libXcursor-devel.x86_64 \
    libXi-devel.x86_64 \
    libgudev-devel \
    libjpeg-turbo-devel.x86_64 \
    libtsan \
    libvorbis-devel.x86_64 \
    llvm.x86_64 \
    llvm-devel.x86_64 \
    ltrace.x86_64 \
    make.x86_64 \
    sudo.x86_64 \
    tree.x86_64 \
    unzip.x86_64 \
    valgrind.x86_64 \
    tar.x86_64 \
    xz.x86_64 \
    wget.x86_64

RUN dnf clean all -y

RUN mkdir -p /tmp

RUN cd /tmp \
    && curl -sSL "https://github.com/Snaipe/Criterion/releases/download/v2.4.0/criterion-2.4.0-linux-x86_64.tar.xz" -o /tmp/criterion-2.4.0.tar.xz \
    && tar xf criterion-2.4.0.tar.xz \
    && cp -r /tmp/criterion-2.4.0/* /usr/local/ \
    && echo "/usr/local/lib" > /etc/ld.so.conf.d/usr-local.conf \
    && ldconfig

RUN rm -rf /tmp/* \
    && chmod 1777 /tmp
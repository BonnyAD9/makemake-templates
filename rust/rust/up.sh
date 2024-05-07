#!/usr/bin/sh

# install script for ${pname}
# wget -nv -O - https://raw.githubusercontent.com/${author_github}/${pname}/master/${pname}up.sh | sh && sudo cp /tmp/${pname}/target/release/${pname} /usr/bin/${pname}

check_exists() {
    if type $1 1>/dev/null 2> /dev/null; then
        true
    else
        echo "Missing the program '$1'."
        exit 1
    fi
}

check_exists wget
check_exists cargo
check_exists tar

VERSION=TODO
PKG="https://github.com/${author_github}/${pname}/archive/refs/tags/v$VERSION.tar.gz"

cd /tmp

if wget -nv -O - "$PKG" | tar xz; then
    true
else
    exit 1
fi

mv "${pname}-$VERSION" "${pname}"
cd "${pname}"

if cargo build -r; then
    true
else
    exit 1
fi

echo 'sudo cp /tmp/${pname}/target/release/${pname} /usr/bin/${pname}'

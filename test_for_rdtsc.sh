set -eu

CC=${CC:-cc}
CFLAGS="-fPIC -std=gnu99 \
  -Wall -Wextra -Wno-missing-field-initializers \
  -O3 ${CFLAGS:--march=native -mtune=native -ggdb}"
LDFLAGS=${LDFLAGS:-}
if [ "$(uname -s)" = Darwin ]; then
    LDFLAGS="$LDFLAGS -flat_namespace -undefined suppress"
fi

SRC=./c_src
BUILD=./build

mkdir -p $BUILD

"$CC" -O -o $BUILD/test_for_rdtsc $SRC/test_for_rdtsc.c && $BUILD/test_for_rdtsc

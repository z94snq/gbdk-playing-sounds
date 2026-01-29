param(
    [switch]$Debug,
    [switch]$Clean
)

if ($Clean) {
    rm -Recurse -Force build -ErrorAction SilentlyContinue
}

$buildType = if ($Debug) { "Debug" } else { "Release" }

mkdir build -Force
cd build
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE="$buildType"
make
cd ..

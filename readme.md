# glfw

## links

- [compile](https://www.glfw.org/docs/latest/compile.html)

## how-to-create-github-conan-package

1. `cmake -P cmake/util.cmake -- conan_create_github_package URL https://github.com/glfw/glfw/archive/refs/tags/3.4.zip EXPECTED_MD5 770b7cc3751f71a4fa0a95386a6ea415 NAME github-glfw VERSION 3.4.0 USER exqudens CHANNEL development`
1. *(optional)* check `conan list 'github-glfw/3.4.0:*'`
1. *(optional)* check ``conan cache path 'github-glfw/3.4.0:${conan list-output-packages[0]}'``
1. *(optional)* check ``ls -1a ${conan-cache-path-output}``
1. *(optional)* `conan upload github-glfw/3.4.0 --remote gitlab`

## cmake-vars
- `-DGLFW_BUILD_EXAMPLES=1` Build the GLFW example programs (default: `0`)
- `-DGLFW_BUILD_TESTS=1` Build the GLFW test programs (default: `0`)
- `-DGLFW_BUILD_DOCS=1` Build the GLFW documentation (default: `0`)
- `-DGLFW_INSTALL=1` Generate installation target (default: `1`)

## how-to-configure
1. `cmake --preset ${preset}` where `${preset}` is one of `cmake --list-presets`

## how-to-build
1. follow `how-to-configure`
1. `cmake --build --preset ${preset} --target cmake-install`

## how-to-export
1. follow `how-to-configure`
1. `cmake --build --preset ${preset} --target conan-remove`
1. `cmake --build --preset ${preset} --target conan-export`

## how-to-export-all-packages
1. `conan remove -c glfw`
1. `git clean -xdf`
1. `cmake --list-presets | cut -d ':' -f2 | xargs -I '{}' echo '{}' | xargs -I '{}' bash -c "cmake --preset {} || exit 255"`
1. `cmake --list-presets | cut -d ':' -f2 | xargs -I '{}' echo '{}' | xargs -I '{}' bash -c "cmake --build --preset {} --target conan-export || exit 255"`

### examples

#### build-example
1. `cmake --preset windows.ninja.msvc-x64-x64.debug.shared`
1. `cmake --build --preset windows.ninja.msvc-x64-x64.debug.shared --target cmake-install`

## linux

### Ubuntu-22.04

1. to check `wayland` or `x11` run `echo "XDG_SESSION_TYPE: '${XDG_SESSION_TYPE}'"`
1. for `wayland-scanner` run `sudo apt install libwayland-bin`
1. for `pkg-config` run `sudo apt install pkg-config`
1. for `wayland-client;wayland-cursor;wayland-egl` run `sudo apt install libwayland-dev`
1. for `xkbcommon` run `sudo apt install libxkbcommon-dev`

# glfw

## cmake-vars
- `-DGLFW_BUILD_EXAMPLES=1` Build the GLFW example programs (default: `0`)
- `-DGLFW_BUILD_TESTS=1` Build the GLFW test programs (default: `0`)
- `-DGLFW_BUILD_DOCS=1` Build the GLFW documentation (default: `0`)
- `-DGLFW_INSTALL=1` Generate installation target (default: `1`)

## how-to-configure
1. `cmake --preset ${preset}` where `${preset}` is one of `cmake --list-presets`

## how-to-build
1. follow `how-to-configure`
2. `cmake --build --preset ${preset} --target cmake-install`

## how-to-export
1. follow `how-to-configure`
2. `cmake --build --preset ${preset} --target conan-remove`
3. `cmake --build --preset ${preset} --target conan-export`

## how-to-export-all-packages
1. `conan remove -c glfw`
2. `git clean -xdf`
3. `cmake --list-presets | cut -d ':' -f2 | xargs -I '{}' echo '{}' | xargs -I '{}' bash -c "cmake --preset {} || exit 255"`
5. `cmake --list-presets | cut -d ':' -f2 | xargs -I '{}' echo '{}' | xargs -I '{}' bash -c "cmake --build --preset {} --target conan-export || exit 255"`

### examples

#### build-example
1. `cmake --preset windows.ninja.msvc-x64-x64.debug.shared`
3. `cmake --build --preset windows.ninja.msvc-x64-x64.debug.shared --target cmake-install`

# Clang & nlohmann/json compilation bug

```
mkdir cmake-build-clang && cd cmake-build-clang
cmake -DCMAKE_CXX_COMPILER="C:/Program Files/LLVM/bin/clang++.exe" -GNinja ..
cmake --build .
```

## Error

```
$ cmake --build .
[1/3] Building CXX object CMakeFiles/JsonBug.dir/cmake_pch.hxx.pch
FAILED: CMakeFiles/JsonBug.dir/cmake_pch.hxx.pch
C:\PROGRA~1\LLVM\bin\CLANG_~1.EXE   -I../include -g -Xclang -gcodeview -O0 -D_DEBUG -D_DLL -D_MT -Xclang --dependent-lib=msvcrtd   -std=gnu++17 -Xclang -emit-pch -Xclang -include -Xclang D:/Source/JsonBug/cmake-build-clang/CMakeFiles/JsonBug.dir/cmake_pch.hxx -MD -MT CMakeFiles/JsonBug.dir/cmake_pch.hxx.pch -MF CMakeFiles\JsonBug.dir\cmake_pch.hxx.pch.d -o CMakeFiles/JsonBug.dir/cmake_pch.hxx.pch -c CMakeFiles/JsonBug.dir/cmake_pch.hxx.cxx
In file included from <built-in>:1:
In file included from D:/Source/JsonBug/cmake-build-clang/CMakeFiles/JsonBug.dir/cmake_pch.hxx:5:
In file included from ../include\nlohmann/json.hpp:51:
In file included from ../include\nlohmann/adl_serializer.hpp:5:
In file included from ../include\nlohmann/detail/conversions/from_json.hpp:19:
../include\nlohmann/detail/meta/type_traits.hpp:87:28: error: expected '>'
           enable_if_t<not is_basic_json<T>::value>>
                           ^
../include\nlohmann/detail/meta/type_traits.hpp:87:28: error: missing 'typename' prior to dependent type name 'is_basic_json<T>::value'
           enable_if_t<not is_basic_json<T>::value>>
                           ^~~~~~~~~~~~~~~~~~~~~~~
../include\nlohmann/detail/meta/type_traits.hpp:87:52: error: expected unqualified-id
           enable_if_t<not is_basic_json<T>::value>>
                                                   ^
../include\nlohmann/detail/meta/type_traits.hpp:102:68: error: expected '>'
struct has_non_default_from_json<BasicJsonType, T, enable_if_t<not is_basic_json<T>::value>>
                                                                   ^
../include\nlohmann/detail/meta/type_traits.hpp:102:68: error: missing 'typename' prior to dependent type name 'is_basic_json<T>::value'
struct has_non_default_from_json<BasicJsonType, T, enable_if_t<not is_basic_json<T>::value>>
                                                                   ^~~~~~~~~~~~~~~~~~~~~~~
../include\nlohmann/detail/meta/type_traits.hpp:102:92: error: expected unqualified-id
struct has_non_default_from_json<BasicJsonType, T, enable_if_t<not is_basic_json<T>::value>>
                                                                                           ^
../include\nlohmann/detail/meta/type_traits.hpp:117:54: error: expected '>'
struct has_to_json<BasicJsonType, T, enable_if_t<not is_basic_json<T>::value>>
                                                     ^
../include\nlohmann/detail/meta/type_traits.hpp:117:54: error: missing 'typename' prior to dependent type name 'is_basic_json<T>::value'
struct has_to_json<BasicJsonType, T, enable_if_t<not is_basic_json<T>::value>>
                                                     ^~~~~~~~~~~~~~~~~~~~~~~
../include\nlohmann/detail/meta/type_traits.hpp:117:78: error: expected unqualified-id
struct has_to_json<BasicJsonType, T, enable_if_t<not is_basic_json<T>::value>>
                                                                             ^
../include\nlohmann/detail/meta/type_traits.hpp:164:17: error: missing 'typename' prior to dependent type name 'is_detected<mapped_type_t, CompatibleObjectType>::value'
    enable_if_t<is_detected<mapped_type_t, CompatibleObjectType>::value and
                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
../include\nlohmann/detail/meta/type_traits.hpp:164:73: error: expected '>'
    enable_if_t<is_detected<mapped_type_t, CompatibleObjectType>::value and
                                                                        ^
../include\nlohmann/detail/meta/type_traits.hpp:165:5: error: expected '>'
    is_detected<key_type_t, CompatibleObjectType>::value >>
    ^
../include\nlohmann/detail/meta/type_traits.hpp:189:17: error: missing 'typename' prior to dependent type name 'is_detected<mapped_type_t, ConstructibleObjectType>::value'
    enable_if_t<is_detected<mapped_type_t, ConstructibleObjectType>::value and
                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
../include\nlohmann/detail/meta/type_traits.hpp:189:76: error: expected '>'
    enable_if_t<is_detected<mapped_type_t, ConstructibleObjectType>::value and
                                                                           ^
../include\nlohmann/detail/meta/type_traits.hpp:190:5: error: expected '>'
    is_detected<key_type_t, ConstructibleObjectType>::value >>
    ^
../include\nlohmann/detail/meta/type_traits.hpp:258:17: error: missing 'typename' prior to dependent type name 'is_detected<value_type_t, CompatibleArrayType>::value'
    enable_if_t<is_detected<value_type_t, CompatibleArrayType>::value and
                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
../include\nlohmann/detail/meta/type_traits.hpp:258:71: error: expected '>'
    enable_if_t<is_detected<value_type_t, CompatibleArrayType>::value and
                                                                      ^
../include\nlohmann/detail/meta/type_traits.hpp:259:5: error: expected '>'
    is_detected<iterator_t, CompatibleArrayType>::value and
    ^
../include\nlohmann/detail/meta/type_traits.hpp:288:21: error: expected '>'
    enable_if_t<not std::is_same<ConstructibleArrayType,
                    ^
fatal error: too many errors emitted, stopping now [-ferror-limit=]
20 errors generated.
ninja: build stopped: subcommand failed.
```
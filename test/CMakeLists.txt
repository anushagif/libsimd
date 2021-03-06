include_directories(${PROJECT_SOURCE_DIR})

# nosimd
add_executable(test-common test-common.cpp)
add_executable(test-convert test-convert.cpp)
add_executable(test-arithm test-arithm.cpp)
#
set_target_properties(test-common PROPERTIES COMPILE_FLAGS "-DNO_SIMD")
set_target_properties(test-convert PROPERTIES COMPILE_FLAGS "-DNO_SIMD")
set_target_properties(test-arithm PROPERTIES COMPILE_FLAGS "-DNO_SIMD")

# sse
add_executable(test-common-sse test-common.cpp)
add_executable(test-common-sse-unroll test-common.cpp)
add_executable(test-common-sse-a16 test-common.cpp)
add_executable(test-common-sse-a64 test-common.cpp)
add_executable(test-arithm-sse test-arithm.cpp)
add_executable(test-arithm-sse-unroll test-arithm.cpp)
add_executable(test-arithm-sse-a16 test-arithm.cpp)
add_executable(test-arithm-sse-a64 test-arithm.cpp)
add_executable(test-convert-sse test-convert.cpp)
add_executable(test-convert-sse-a16 test-convert.cpp)
#
set_target_properties(test-common-sse PROPERTIES COMPILE_FLAGS "")
set_target_properties(test-common-sse-unroll PROPERTIES COMPILE_FLAGS "-DUNROLL_MORE")
set_target_properties(test-common-sse-a16 PROPERTIES COMPILE_FLAGS "-DSSE_ALIGNED=16")
set_target_properties(test-common-sse-a64 PROPERTIES COMPILE_FLAGS "-DSSE_ALIGNED=64")
set_target_properties(test-arithm-sse PROPERTIES COMPILE_FLAGS "")
set_target_properties(test-arithm-sse-unroll PROPERTIES COMPILE_FLAGS "-DUNROLL_MORE")
set_target_properties(test-arithm-sse-a16 PROPERTIES COMPILE_FLAGS "-DSSE_ALIGNED=16")
set_target_properties(test-arithm-sse-a64 PROPERTIES COMPILE_FLAGS "-DSSE_ALIGNED=64")
set_target_properties(test-convert-sse PROPERTIES COMPILE_FLAGS "")
set_target_properties(test-convert-sse-a16 PROPERTIES COMPILE_FLAGS "-DSSE_ALIGNED=16")

if(AVX)
add_executable(test-common-avx test-common.cpp)
add_executable(test-common-avx-a32 test-common.cpp)
add_executable(test-convert-avx test-convert.cpp)
add_executable(test-convert-avx-a32 test-convert.cpp)
add_executable(test-arithm-avx test-arithm.cpp)
add_executable(test-arithm-avx-a32 test-arithm.cpp)
add_executable(test-arithm-avx-moredata test-arithm.cpp)
#
set_target_properties(test-common-avx PROPERTIES COMPILE_FLAGS "-DSIMD_AVX")
set_target_properties(test-common-avx-a32 PROPERTIES COMPILE_FLAGS "-DSIMD_AVX -DSSE_ALIGNED=32")
set_target_properties(test-convert-avx PROPERTIES COMPILE_FLAGS "-DSIMD_AVX")
set_target_properties(test-convert-avx-a32 PROPERTIES COMPILE_FLAGS "-DSIMD_AVX -DSSE_ALIGNED=32")
set_target_properties(test-arithm-avx PROPERTIES COMPILE_FLAGS "-DSIMD_AVX")
set_target_properties(test-arithm-avx-a32 PROPERTIES COMPILE_FLAGS "-DSIMD_AVX -DSSE_ALIGNED=32")
set_target_properties(test-arithm-avx-moredata PROPERTIES COMPILE_FLAGS "-DSIMD_AVX -DMORE_DATA")
endif(AVX)

if(SIMD_OPENCL)
add_executable(info-ocl opencl_info.cpp)
add_executable(test-arithm-ocl test-arithm.cpp)
add_executable(test-arithm-ocl-moredata test-arithm.cpp)
#
set_target_properties(test-arithm-ocl PROPERTIES COMPILE_FLAGS "-DSIMD_OPENCL -DALLOW_TRASH")
set_target_properties(test-arithm-ocl-moredata PROPERTIES COMPILE_FLAGS "-DSIMD_OPENCL -DALLOW_TRASH -DNO_8_16 -DMORE_DATA")
#
target_link_libraries(info-ocl OpenCL)
target_link_libraries(test-arithm-ocl simdocl)
target_link_libraries(test-arithm-ocl-moredata simdocl)
endif()

if(IPP_DIR)
# ipp
add_executable(test-common-ipp test-common.cpp)
add_executable(test-convert-ipp test-convert.cpp)
add_executable(test-arithm-ipp test-arithm.cpp)
add_executable(test-arithm-fixed-ipp test-arithm.cpp)
#
set_target_properties(test-common-ipp PROPERTIES COMPILE_FLAGS -DSIMD_IPP)
set_target_properties(test-convert-ipp PROPERTIES COMPILE_FLAGS -DSIMD_IPP)
set_target_properties(test-arithm-ipp PROPERTIES COMPILE_FLAGS -DSIMD_IPP)
set_target_properties(test-arithm-fixed-ipp PROPERTIES COMPILE_FLAGS "-DSIMD_IPP -DTEST_FIXED")
#
target_link_libraries(test-common-ipp simdipp)
target_link_libraries(test-convert-ipp simdipp)
target_link_libraries(test-arithm-ipp simdipp)
target_link_libraries(test-arithm-fixed-ipp simdipp)
endif(IPP_DIR)

#

add_test(common         test-common)
add_test(common-sse     test-common-sse)
add_test(common-sse-ur  test-common-sse-unroll)
add_test(common-sse-a16 test-common-sse-a16)
add_test(common-sse-a64 test-common-sse-a64)
add_test(convert        test-convert)
add_test(convert-sse     test-convert-sse)
add_test(convert-sse-a16 test-convert-sse-a16)
add_test(arithm         test-arithm)
add_test(arithm-sse     test-arithm-sse)
add_test(arithm-sse-ur  test-arithm-sse-unroll)
add_test(arithm-sse-a16 test-arithm-sse-a16)
add_test(arithm-sse-a64 test-arithm-sse-a64)

if(AVX)
add_test(common-avx     test-common-avx)
add_test(common-avx-a32 test-common-avx-a32)
add_test(convert-avx     test-convert-avx)
add_test(convert-avx-a32 test-convert-avx-a32)
add_test(arithm-avx     test-arithm-avx)
add_test(arithm-avx-a32 test-arithm-avx-a32)
add_test(arithm-avx-1m  test-arithm-avx-moredata)
endif()

if(SIMD_OPENCL)
add_test(arithm-ocl     test-arithm-ocl)
add_test(arithm-ocl-1m  test-arithm-ocl-moredata)
endif()

if(IPP_DIR)
add_test(common_ipp     test-common-ipp)
add_test(convert_ipp    test-convert-ipp)
add_test(arithm_ipp     test-arithm-ipp)
add_test(arithm_fixed   test-arithm-fixed-ipp)
endif()

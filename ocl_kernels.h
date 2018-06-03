#include <cstdint>

namespace ocl
{
namespace internals
{
    ///
    struct Kernel
    {
        enum class Func : uint32_t
        {
            Add_32f,
            Sub_32f,
            Mul_32f,
            Div_32f,
            AddC_32f,
            SubC_32f,
            MulC_32f,
            DivC_32f,
            SubCRev_32f,
            DivCRev_32f,
            Abs_32f,
            Count
        };

        ///
        struct TextProgram
        {
            const char * name = nullptr;
            const char * text = nullptr;

            template <typename _T>
            static constexpr TextProgram create()
            {
                return {_T::programName(), _T::programText()};
            }
        };

        static constexpr uint32_t funcCount() { return (uint32_t)Func::Count; }

        template <typename _T>
        struct PtrPtrPtr
        {
            using ItemType = _T;
            using DataTypeSrc1 = const _T*;
            using DataTypeSrc2 = const _T*;
            using DataTypeDst = _T*;
            using BaseType = PtrPtrPtr<_T>;
        };

        template <typename _T>
        struct PtrValPtr
        {
            using ItemType = _T;
            using DataTypeSrc1 = const _T*;
            using DataTypeSrc2 = _T;
            using DataTypeDst = _T*;
            using BaseType = PtrValPtr<_T>;
        };

        struct Add_32f : public PtrPtrPtr<float>
        {
            static constexpr const Func id() { return Func::Add_32f; }
            static constexpr const char * programName() { return "add_32f"; }
            static constexpr const char * programText()
            {
                return R"(
                __kernel void add_32f(__global const float* a, __global const float* b, __global float* c, int size)
                {
                    int iGID = get_global_id(0);
                    if (iGID >= size)
                        return;
                    c[iGID] = a[iGID] + b[iGID];
                })";
            }
        };

        struct Sub_32f : public PtrPtrPtr<float>
        {
            static constexpr const Func id() { return Func::Sub_32f; }
            static constexpr const char * programName() { return "sub_32f"; }
            static constexpr const char * programText()
            {
                return R"(
                __kernel void sub_32f(__global const float* a, __global const float* b, __global float* c, int size)
                {
                    int iGID = get_global_id(0);
                    if (iGID >= size)
                        return;
                    c[iGID] = a[iGID] - b[iGID];
                })";
            }
        };

        struct Mul_32f : public PtrPtrPtr<float>
        {
            static constexpr const Func id() { return Func::Mul_32f; }
            static constexpr const char * programName() { return "mul_32f"; }
            static constexpr const char * programText()
            {
                return R"(
                __kernel void mul_32f(__global const float* a, __global const float* b, __global float* c, int size)
                {
                    int iGID = get_global_id(0);
                    if (iGID >= size)
                        return;
                    c[iGID] = a[iGID] * b[iGID];
                })";
            }
        };

        struct Div_32f : public PtrPtrPtr<float>
        {
            static constexpr const Func id() { return Func::Div_32f; }
            static constexpr const char * programName() { return "div_32f"; }
            static constexpr const char * programText()
            {
                return R"(
                __kernel void div_32f(__global const float* a, __global const float* b, __global float* c, int size)
                {
                    int iGID = get_global_id(0);
                    if (iGID >= size)
                        return;
                    c[iGID] = a[iGID] / b[iGID];
                })";
            }
        };

        struct AddC_32f : public PtrValPtr<float>
        {
            static constexpr const Func id() { return Func::AddC_32f; }
            static constexpr const char * programName() { return "addC_32f"; }
            static constexpr const char * programText()
            {
                return R"(
                __kernel void addC_32f(__global const float* a, float b, __global float* c, int size)
                {
                    int iGID = get_global_id(0);
                    if (iGID >= size)
                        return;
                    c[iGID] = a[iGID] + b;
                })";
            }
        };

        struct SubC_32f : public PtrValPtr<float>
        {
            static constexpr const Func id() { return Func::SubC_32f; }
            static constexpr const char * programName() { return "subC_32f"; }
            static constexpr const char * programText()
            {
                return R"(
                __kernel void subC_32f(__global const float* a, float b, __global float* c, int size)
                {
                    int iGID = get_global_id(0);
                    if (iGID >= size)
                        return;
                    c[iGID] = a[iGID] - b;
                })";
            }
        };

        struct SubCRev_32f : public PtrValPtr<float>
        {
            static constexpr const Func id() { return Func::SubCRev_32f; }
            static constexpr const char * programName() { return "subCRev_32f"; }
            static constexpr const char * programText()
            {
                return R"(
                __kernel void subCRev_32f(__global const float* a, float b, __global float* c, int size)
                {
                    int iGID = get_global_id(0);
                    if (iGID >= size)
                        return;
                    c[iGID] = b - a[iGID];
                })";
            }
        };

        struct MulC_32f : public PtrValPtr<float>
        {
            static constexpr const Func id() { return Func::MulC_32f; }
            static constexpr const char * programName() { return "mulC_32f"; }
            static constexpr const char * programText()
            {
                return R"(
                __kernel void mulC_32f(__global const float* a, float b, __global float* c, int size)
                {
                    int iGID = get_global_id(0);
                    if (iGID >= size)
                        return;
                    c[iGID] = a[iGID] * b;
                })";
            }
        };

        struct DivC_32f : public PtrValPtr<float>
        {
            static constexpr const Func id() { return Func::DivC_32f; }
            static constexpr const char * programName() { return "divC_32f"; }
            static constexpr const char * programText()
            {
                return R"(
                __kernel void divC_32f(__global const float* a, float b, __global float* c, int size)
                {
                    int iGID = get_global_id(0);
                    if (iGID >= size)
                        return;
                    c[iGID] = a[iGID] / b;
                })";
            }
        };

        struct DivCRev_32f : public PtrValPtr<float>
        {
            static constexpr const Func id() { return Func::DivCRev_32f; }
            static constexpr const char * programName() { return "divCRev_32f"; }
            static constexpr const char * programText()
            {
                return R"(
                __kernel void divCRev_32f(__global const float* a, float b, __global float* c, int size)
                {
                    int iGID = get_global_id(0);
                    if (iGID >= size)
                        return;
                    c[iGID] = b / a[iGID];
                })";
            }
        };

        struct Abs_32f : public PtrValPtr<float>
        {
            static constexpr const Func id() { return Func::Abs_32f; }
            static constexpr const char * programName() { return "abs_32f"; }
            static constexpr const char * programText()
            {
                return R"(
                __kernel void abs_32f(__global const float* a, float b, __global float* c, int size)
                {
                    int iGID = get_global_id(0);
                    if (iGID >= size)
                        return;
                    if (a[iGID] < 0)
                        c[iGID] = -a[iGID];
                    else
                        c[iGID] = a[iGID];
                })";
            }
        };

        static constexpr TextProgram program(Func func)
        {
            switch (func) {
                case Func::Add_32f: return TextProgram::create<Add_32f>();
                case Func::Sub_32f: return TextProgram::create<Sub_32f>();
                case Func::Mul_32f: return TextProgram::create<Mul_32f>();
                case Func::Div_32f: return TextProgram::create<Div_32f>();
                //
                case Func::AddC_32f: return TextProgram::create<AddC_32f>();
                case Func::SubC_32f: return TextProgram::create<SubC_32f>();
                case Func::MulC_32f: return TextProgram::create<MulC_32f>();
                case Func::DivC_32f: return TextProgram::create<DivC_32f>();
                case Func::SubCRev_32f: return TextProgram::create<SubCRev_32f>();
                case Func::DivCRev_32f: return TextProgram::create<DivCRev_32f>();
                //
                case Func::Abs_32f: return TextProgram::create<Abs_32f>();
                case Func::Count:
                    break;
            }
            return {nullptr, nullptr};
        }
    };
} // internals
} // ocl
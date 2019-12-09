#ifndef ZOO_META_COPYABLE_H
#define ZOO_META_COPYABLE_H

namespace zoo::meta {
template<bool, bool = true>
struct CopyAndMoveAbilities;

template<>
struct CopyAndMoveAbilities<true, true> {
    CopyAndMoveAbilities() = default;
    CopyAndMoveAbilities(const CopyAndMoveAbilities &) = default;
    CopyAndMoveAbilities(CopyAndMoveAbilities &&) = default;
};

template<>
struct CopyAndMoveAbilities<true, false> {
    CopyAndMoveAbilities() = default;
    CopyAndMoveAbilities(const CopyAndMoveAbilities &) = default;
    CopyAndMoveAbilities(CopyAndMoveAbilities &&) = delete;
};

template<>
struct CopyAndMoveAbilities<false, true> {
    CopyAndMoveAbilities() = default;
    CopyAndMoveAbilities(const CopyAndMoveAbilities &) = delete;
    CopyAndMoveAbilities(CopyAndMoveAbilities &&) = default;
};

template<>
struct CopyAndMoveAbilities<false, false> {
    CopyAndMoveAbilities() = default;
    CopyAndMoveAbilities(const CopyAndMoveAbilities &) = delete;
    CopyAndMoveAbilities(CopyAndMoveAbilities &&) = delete;
};

}

#endif

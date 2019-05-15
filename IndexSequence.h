#ifndef SCROLLING_TEXT_INDEXSEQUENCE_H
#define SCROLLING_TEXT_INDEXSEQUENCE_H

template <size_t ...args>
struct IndexSequence {};

template <size_t M, size_t ...N>
struct MakeIndexSequenceImpl : MakeIndexSequenceImpl<M - 1, M, N...> {};

template <size_t ...N>
struct MakeIndexSequenceImpl<0, N...> : IndexSequence<0, N...> {};

template <size_t N>
struct MakeIndexSequence : MakeIndexSequenceImpl<N - 1> {};

template <>
struct MakeIndexSequence<0> : IndexSequence<> {};

#endif //SCROLLING_TEXT_INDEXSEQUENCE_H
